# Cutie demo

## Windows build

Use https://winlibs.com/

## Python package

- gcovr

  pip install --user <package_name>

## Build, Run, Test

Generate build system:

  cmake --preset cutie_demo

Build:

  cmake --build --preset cutie_demo

Clean:

  cmake --build --preset cutie_demo --target clean

Run Unit tests:

  ctest --preset cutie_demo

Build gcovr HTML report:

  cmake.exe --build --preset cutie_demo --target coverage_gcovr_html_target
