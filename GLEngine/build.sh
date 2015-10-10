#!/bin/bash 

clang++ *.cpp -o pazuzu \
-g -Wall -std=c++11 \
-framework OpenGL \
-framework IOKit \
-framework QuartzCore \
-framework Cocoa \
-I/Users/jack/Documents/Programming/C++/Libraries/glew-1.12.0/include \
-I/Users/jack/Documents/Programming/C++/Libraries/glfw-3.1/include \
-I/Users/jack/Documents/Programming/C++/Libraries/glm \
-L/Users/jack/Documents/Programming/C++/Libraries/glew-1.12.0/lib -lglew \
-L/Users/jack/Documents/Programming/C++/Libraries/glfw-3.1/src -lglfw3
echo 'Compiled successfully!'
