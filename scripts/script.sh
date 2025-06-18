#!/bin/bash
# =============================================================================
#  Common Shell Script Utilities
#  Provides logging, system detection, and helper functions for any project.
# =============================================================================

# ===========================
# Constants & Configuration
# ===========================
PROJECT_NAME="MyProject"
PROJECT_VERSION="1.0.0"

# Color Codes for Pretty Logging
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# ===========================
# Logging Functions
# ===========================
log_info() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

log_warn() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# ===========================
# System Checks
# ===========================
get_os() {
    unameOut="$(uname -s)"
    case "${unameOut}" in
        Linux*)     OS="Linux";;
        Darwin*)    OS="MacOS";;
        CYGWIN*|MINGW32*|MSYS*|MINGW*) OS="Windows";;
        *)          OS="Unknown"
    esac
    echo "$OS"
}

get_cpu_cores() {
    case "$(get_os)" in
        Linux|MacOS) nproc;;
        Windows) echo "$(WMIC CPU Get NumberOfCores | awk 'NR>1' | xargs)";;
        *) echo "Unknown";;
    esac
}

get_memory() {
    case "$(get_os)" in
        Linux) free -m | awk '/Mem:/ {print $2 " MB"}';;
        MacOS) vm_stat | awk '/Pages free/ {print $3*4096/1024/1024 " MB"}';;
        Windows) systeminfo | awk '/Total Physical Memory:/ {print $4}';;
        *) echo "Unknown";;
    esac
}

# ===========================
# Utility Functions
# ===========================
check_command() {
    command -v "$1" >/dev/null 2>&1 || {
        log_error "'$1' is not installed. Please install it and try again."
        exit 1
    }
}

format_bytes() {
    local bytes=$1
    if [[ $bytes -lt 1024 ]]; then echo "${bytes} B"; return; fi
    if [[ $bytes -lt $((1024**2)) ]]; then echo "$((bytes/1024)) KB"; return; fi
    if [[ $bytes -lt $((1024**3)) ]]; then echo "$((bytes/1024/1024)) MB"; return; fi
    echo "$((bytes/1024/1024/1024)) GB"
}

# ===========================
# Main Execution (Example Usage)
# ===========================
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    log_info "Starting $PROJECT_NAME v$PROJECT_VERSION..."
    
    log_info "Operating System: $(get_os)"
    log_info "CPU Cores: $(get_cpu_cores)"
    log_info "Memory: $(get_memory)"

    check_command "git"
    check_command "cmake"

    log_info "Setup complete!"
fi
