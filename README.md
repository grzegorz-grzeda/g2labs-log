# g2labs-log
Logging library for G2Labs C code architecture

This is a [G2EPM](https://github.com/grzegorz-grzeda/g2epm) library.

## How to compile and link it?

Just include this directory in your CMake project. Remember to specify the event handler buffer size.

Example `CMakeLists.txt` content:
```
...

add_subdirectory(<PATH TO LOG LIBRARY>)

target_link_libraries(${PROJECT_NAME} PRIVATE g2labs-log)

...
```

Also specify the `G2LABS_PLATFORM_TARGET` to select a platform to compile for during cmake configuration. If not, an empty `default` implementation will be selected.

## Documentation
If you want, you can run `doxygen` to generate HTML documentation. It will be available in `documentation` 
directory.


# Copyright
This library was written by Grzegorz Grzęda, and is distributed under MIT Licence. Check the `LICENSE` file for
more details.
