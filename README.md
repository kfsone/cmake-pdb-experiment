CMake :: Windows :: Stripped executable + PDB generation
========================================================

Copyright (C) Oliver 'kfsone' Smith <oliver@kfs.org> 2024


Demonstrates how to configure CMake to build release builds that do not include symbols
in the executable but provide a complete symbol table for the respective binary as a pdb
file.

Generator expressions are used to cope with multi-config gerators such as visual studio.

I.e. this should work with both

```pwsh
    cmake -G "Visual Studio 16 2019" -S . -B ./build -DCMAKE_BUILD_TYPE="Release"
    cmake --build ./build
```
and
```pwsh
    cmake -G "Visual Studio 16 2019" -S . -B ./build --config Release
```
