# Cutie demo
---

# Build, Run, Test

Generate build system:

  cmake --preset cutie_demo

Build:

  cmake --build --preset cutie_demo

Clean:

  cmake --build --preset cutie_demo --target clean

Run Unit tests:

  ctest --preset cutie_demo
