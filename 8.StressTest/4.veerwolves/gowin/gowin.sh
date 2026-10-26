#!/bin/bash
# gowin_launch_fixed.sh - Try full Qt isolation + no OpenGL rendering

export GOWIN_ROOT="/home/tarik/Downloads/gowin_eda/IDE"

# Use system libstdc++ only
export LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libstdc++.so.6

# Force Gowin to use its own Qt libs
export LD_LIBRARY_PATH="$GOWIN_ROOT/lib:$LD_LIBRARY_PATH"

# Set plugin paths for Qt
export QT_QPA_PLATFORM_PLUGIN_PATH="$GOWIN_ROOT/plugins/qt/platforms"
export QT_PLUGIN_PATH="$GOWIN_ROOT/plugins/qt"

# Prevent fallback to system Qt styles
unset QT_STYLE_OVERRIDE

# Turn off Qt debug output
export QT_LOGGING_RULES="*.debug=false"

# Disable OpenGL rendering entirely
export QT_QPA_PLATFORM=offscreen

# Launch Gowin IDE Tcl shell
gw_sh gowin.tcl
