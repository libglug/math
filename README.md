![](https://github.com/libglug/math/actions/workflows/build.yml/badge.svg)
# math
3d maths

### Building
```
mkdir build && cd build
cmake [path/to/repo]
cmake --build . --target glug_math
```

### Running tests
```
mkdir build && cd build
cmake [path/to/repo]
cmake --build . --target check
ctest -V
```
