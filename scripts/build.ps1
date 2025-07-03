param(
    [string]$Preset  = "Debug"
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

# Use the CMake bundled with vcpkg for consistency
$cmakeDir = Get-ChildItem ".\vcpkg\downloads\tools\cmake*" -Directory |
            Sort-Object LastWriteTime -Descending |
            Select-Object -First 1

$cmake = Join-Path $cmakeDir 'cmake*\bin\cmake.exe'

# Build using the chosen preset
& $cmake --build  --preset $Preset