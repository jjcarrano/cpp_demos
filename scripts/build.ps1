param(
    [string]$Preset  = "Debug",
    [string]$Run = ""
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

# Run the executable if provided
if ($Run -ne "") {
    # Try to find the executable path relative to known output directories
    $buildDir = ".\build\default\$Preset"
    $exePath = Join-Path $buildDir $Run

    Write-Host "Running executable: $exePath"
    & $exePath
}