//! Error and result types.
//!
//! Configuration errors return specific information to help
//! the developer to build correct code.  All runtime errors
//! return the generic empty `Error` struct, because granular
//! error reporting in cryptographic libraries can be fraught.

/// A runtime error in the signal protocol.
#[derive(Clone, PartialEq, Eq)]
pub struct Error;

impl no_std_compat::fmt::Debug for Error {
    fn fmt(&self, f: &mut no_std_compat::fmt::Formatter) -> no_std_compat::fmt::Result {
        write!(f, "crypto error in Signal protocol")
    }
}

impl no_std_compat::fmt::Display for Error {
    fn fmt(&self, f: &mut no_std_compat::fmt::Formatter) -> no_std_compat::fmt::Result {
        <Self as no_std_compat::fmt::Debug>::fmt(self, f)
    }
}

//impl core::error::Error for Error {}

impl From<ed25519_dalek::SignatureError> for Error {
    fn from(_: ed25519_dalek::SignatureError) -> Error { Error }
}

impl From<()> for Error {
    fn from(_: ()) -> Error { Error }
}

/// A helful alias for a `Result` with our `Error`.
pub type Result<T> = no_std_compat::result::Result<T, Error>;

/// Errors that arise from parameter configuration.
#[derive(Clone, PartialEq, Eq)]
pub enum ParameterError {
    /// The curve specified is unsupported by this implementation.
    UnsupportedCurve,
    /// The supplied info value is not valid ASCII.
    InvalidAscii,
}

impl no_std_compat::fmt::Debug for ParameterError {
    fn fmt(&self, f: &mut no_std_compat::fmt::Formatter) -> no_std_compat::fmt::Result {
        match self {
            ParameterError::UnsupportedCurve=> write!(f, "CURVE X448 is not supported."),
            ParameterError::InvalidAscii => write!(f, "INFO must be ASCII."),
        }
    }
}

impl no_std_compat::fmt::Display for ParameterError {
    fn fmt(&self, f: &mut no_std_compat::fmt::Formatter) -> no_std_compat::fmt::Result {
        <Self as no_std_compat::fmt::Debug>::fmt(self, f)
    }
}

//impl no_std_compat::error::Error for ParameterError {}

/// Errors that arise during parameter configuration when using
/// the operating system's random number generator.
pub enum WithOsRngError {
    /// A parameter configuration error.
    Parameter(ParameterError),
    /// An error getting the OS random number generator.
    OsRng(rand::Error),
}

impl no_std_compat::fmt::Debug for WithOsRngError {
    fn fmt(&self, f: &mut no_std_compat::fmt::Formatter) -> no_std_compat::fmt::Result {
        match self {
            WithOsRngError::Parameter(p) => p.fmt(f),
            WithOsRngError::OsRng(r) => r.fmt(f),
        }
    }
}

impl no_std_compat::fmt::Display for WithOsRngError {
    fn fmt(&self, f: &mut no_std_compat::fmt::Formatter) -> no_std_compat::fmt::Result {
        <Self as no_std_compat::fmt::Debug>::fmt(self, f)
    }
}

//impl no_std_compat::Error for WithOsRngError {}

impl From<ParameterError> for WithOsRngError {
    fn from(err: ParameterError) -> WithOsRngError {
        WithOsRngError::Parameter(err)
    }
}

impl From<rand::Error> for WithOsRngError {
    fn from(err: rand::Error) -> WithOsRngError {
        WithOsRngError::OsRng(err)
    }
}
