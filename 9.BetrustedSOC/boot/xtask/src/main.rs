use std::{
    env,
    path::{Path, PathBuf},
    process::Command,
};

type DynError = Box<dyn std::error::Error>;

const TARGET: &str = "riscv32imac-unknown-none-elf";

#[derive(Debug)]
enum BuildError {
    #[allow(dead_code)]
    PathConversionError,
}

impl std::fmt::Display for BuildError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match *self {
            BuildError::PathConversionError => write!(f, "could not convert path to UTF-8"),
        }
    }
}

impl std::error::Error for BuildError {}

fn main() {
    if let Err(e) = try_main() {
        eprintln!("{}", e);
        std::process::exit(-1);
    }
}

fn try_main() -> Result<(), DynError> {
    let hw_pkgs = [
        "betrusted-boot",
    ];
    let mut args = env::args();
    let task = args.nth(1);
    match task.as_deref() {
        Some("boot-image") => build_hw_image(false, env::args().nth(2), &hw_pkgs)?,
        _ => print_help(),
    }
    Ok(())
}

fn print_help() {
    eprintln!(
        "Tasks:
boot-image [soc.svd]      builds a boot image
"
    )
}

fn build_hw_image(
    debug: bool,
    svd: Option<String>,
    packages: &[&str],
) -> Result<(), DynError> {
    let svd_file = match svd {
        Some(s) => s,
        None => "../build/software/soc.svd".to_string(),
    };

    let path = std::path::Path::new(&svd_file);
    if !path.exists() {
        return Err("svd file does not exist".into());
    }

    // Tools use this environment variable to know when to rebuild the UTRA crate.
    std::env::set_var("XOUS_SVD_FILE", path.canonicalize().unwrap());

    // build the assembly binary
    #[cfg(target_os = "windows")]
    let status = Command::new("powershell")
        .args(&["-Command", ".\\assemble.ps1"])
        .current_dir(project_root().join("betrusted-boot"))
        .status()?;
    #[cfg(not(target_os = "windows"))]
    let status = Command::new("sh")
        .args(&["-c", "./assemble.sh"])
    .current_dir(project_root().join("betrusted-boot"))
    .status()?;

    if !status.success() {
        return Err("assembly failed".into())
    }


    // make the ELF file
    let mut boot = build(
        packages,
        debug,
        Some(TARGET),
        Some("betrusted-boot".into()),
        None,
    )?;

    boot.push("betrusted-boot");
    println!("debug: boot path: {}", boot.as_os_str().to_str().unwrap());
    let mut boot_bin = project_root();
    boot_bin.push("boot.bin");

    // dump the ELF file
    let listing = std::fs::File::create("boot.map")?;
    let status = Command::new(objdump())
    .current_dir(project_root())
    .args(&[
        "-d",
        "-S",
        boot.as_os_str().to_str().unwrap(),
    ])
    .stdout(std::process::Stdio::from(listing))
    .status()?;
    if !status.success() {
        return Err("cargo build failed".into());
    }

    // output the binary
    let status = Command::new(objcopy())
    .current_dir(project_root())
    .args(&[
        "-S",
        "-O",
        "binary",
        boot.as_os_str().to_str().unwrap(),
        boot_bin.as_os_str().to_str().unwrap(),
    ]).status()?;
    if !status.success() {
        return Err("cargo build failed".into());
    }

    println!();
    println!("Bootloader binary file created at {}", boot.as_os_str().to_str().unwrap());

    Ok(())
}

fn build(
    packages: &[&str],
    debug: bool,
    target: Option<&str>,
    directory: Option<PathBuf>,
    extra_args: Option<&[&str]>,
) -> Result<PathBuf, DynError> {
    let stream = if debug { "debug" } else { "release" };
    let mut args = vec!["build"];
    print!("Building");
    for package in packages {
        print!(" {}", package);
        args.push("--package");
        args.push(package);
    }
    println!();
    let mut target_path = "".to_owned();
    if let Some(t) = target {
        args.push("--target");
        args.push(t);
        target_path = format!("{}/", t);
    }

    if !debug {
        args.push("--release");
    }

    if let Some(extra) = extra_args {
        for &a in extra {
            args.push(a);
        }
    }

    let mut dir = project_root();
    if let Some(subdir) = &directory {
        dir.push(subdir);
    }

    let status = Command::new(cargo())
        .current_dir(dir)
        .args(&args)
        .status()?;

    if !status.success() {
        return Err("cargo build failed".into());
    }

    /*
    if let Some(base_dir) = &directory {
        Ok(project_root().join(&format!(
            "{}/target/{}{}/",
            base_dir.to_str().ok_or(BuildError::PathConversionError)?,
            target_path,
            stream,
        )))
    } else {*/
        Ok(project_root().join(&format!("target/{}{}/", target_path, stream)))
    //}
}

fn cargo() -> String {
    env::var("CARGO").unwrap_or_else(|_| "cargo".to_string())
}

fn objcopy() -> String {
    env::var("OBJCOPY").unwrap_or_else(|_| "riscv64-unknown-elf-objcopy".to_string())
}
fn objdump() -> String {
    env::var("OBJDUMP").unwrap_or_else(|_| "riscv64-unknown-elf-objdump".to_string())
}

fn project_root() -> PathBuf {
    Path::new(&env!("CARGO_MANIFEST_DIR"))
        .ancestors()
        .nth(1)
        .unwrap()
        .to_path_buf()
}
