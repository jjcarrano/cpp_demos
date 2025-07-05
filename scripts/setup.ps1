<#
.SYNOPSIS
Run once after cloning to set up CMake and vcpkg.
#>
param(
    [string]$Preset  = "default"
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

git submodule update --init --recursive
& ".\vcpkg\bootstrap-vcpkg.bat"

& ".\vcpkg\vcpkg.exe" install

# Use the CMake bundled with vcpkg for consistency
$cmakeDir = Get-ChildItem ".\vcpkg\downloads\tools\cmake*" -Directory |
            Sort-Object LastWriteTime -Descending |
            Select-Object -First 1

$cmake = Join-Path $cmakeDir 'cmake*\bin\cmake.exe'

# Configure using the chosen preset
& $cmake --preset $Preset