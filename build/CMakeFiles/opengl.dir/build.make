# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kubuski/Projects/1pOpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kubuski/Projects/1pOpenGL/build

# Include any dependencies generated for this target.
include CMakeFiles/opengl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/opengl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl.dir/flags.make

CMakeFiles/opengl.dir/src/main.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/src/main.cpp.o: /home/kubuski/Projects/1pOpenGL/src/main.cpp
CMakeFiles/opengl.dir/src/main.cpp.o: CMakeFiles/opengl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kubuski/Projects/1pOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/opengl.dir/src/main.cpp.o -MF CMakeFiles/opengl.dir/src/main.cpp.o.d -o CMakeFiles/opengl.dir/src/main.cpp.o -c /home/kubuski/Projects/1pOpenGL/src/main.cpp

CMakeFiles/opengl.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/opengl.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kubuski/Projects/1pOpenGL/src/main.cpp > CMakeFiles/opengl.dir/src/main.cpp.i

CMakeFiles/opengl.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kubuski/Projects/1pOpenGL/src/main.cpp -o CMakeFiles/opengl.dir/src/main.cpp.s

CMakeFiles/opengl.dir/src/glad.c.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/src/glad.c.o: /home/kubuski/Projects/1pOpenGL/src/glad.c
CMakeFiles/opengl.dir/src/glad.c.o: CMakeFiles/opengl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kubuski/Projects/1pOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/opengl.dir/src/glad.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opengl.dir/src/glad.c.o -MF CMakeFiles/opengl.dir/src/glad.c.o.d -o CMakeFiles/opengl.dir/src/glad.c.o -c /home/kubuski/Projects/1pOpenGL/src/glad.c

CMakeFiles/opengl.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/opengl.dir/src/glad.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kubuski/Projects/1pOpenGL/src/glad.c > CMakeFiles/opengl.dir/src/glad.c.i

CMakeFiles/opengl.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/opengl.dir/src/glad.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kubuski/Projects/1pOpenGL/src/glad.c -o CMakeFiles/opengl.dir/src/glad.c.s

CMakeFiles/opengl.dir/src/shader.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/src/shader.cpp.o: /home/kubuski/Projects/1pOpenGL/src/shader.cpp
CMakeFiles/opengl.dir/src/shader.cpp.o: CMakeFiles/opengl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kubuski/Projects/1pOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/opengl.dir/src/shader.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/opengl.dir/src/shader.cpp.o -MF CMakeFiles/opengl.dir/src/shader.cpp.o.d -o CMakeFiles/opengl.dir/src/shader.cpp.o -c /home/kubuski/Projects/1pOpenGL/src/shader.cpp

CMakeFiles/opengl.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/opengl.dir/src/shader.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kubuski/Projects/1pOpenGL/src/shader.cpp > CMakeFiles/opengl.dir/src/shader.cpp.i

CMakeFiles/opengl.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/src/shader.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kubuski/Projects/1pOpenGL/src/shader.cpp -o CMakeFiles/opengl.dir/src/shader.cpp.s

CMakeFiles/opengl.dir/src/camera.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/src/camera.cpp.o: /home/kubuski/Projects/1pOpenGL/src/camera.cpp
CMakeFiles/opengl.dir/src/camera.cpp.o: CMakeFiles/opengl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kubuski/Projects/1pOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/opengl.dir/src/camera.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/opengl.dir/src/camera.cpp.o -MF CMakeFiles/opengl.dir/src/camera.cpp.o.d -o CMakeFiles/opengl.dir/src/camera.cpp.o -c /home/kubuski/Projects/1pOpenGL/src/camera.cpp

CMakeFiles/opengl.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/opengl.dir/src/camera.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kubuski/Projects/1pOpenGL/src/camera.cpp > CMakeFiles/opengl.dir/src/camera.cpp.i

CMakeFiles/opengl.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/src/camera.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kubuski/Projects/1pOpenGL/src/camera.cpp -o CMakeFiles/opengl.dir/src/camera.cpp.s

CMakeFiles/opengl.dir/src/movement.cpp.o: CMakeFiles/opengl.dir/flags.make
CMakeFiles/opengl.dir/src/movement.cpp.o: /home/kubuski/Projects/1pOpenGL/src/movement.cpp
CMakeFiles/opengl.dir/src/movement.cpp.o: CMakeFiles/opengl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kubuski/Projects/1pOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/opengl.dir/src/movement.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/opengl.dir/src/movement.cpp.o -MF CMakeFiles/opengl.dir/src/movement.cpp.o.d -o CMakeFiles/opengl.dir/src/movement.cpp.o -c /home/kubuski/Projects/1pOpenGL/src/movement.cpp

CMakeFiles/opengl.dir/src/movement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/opengl.dir/src/movement.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kubuski/Projects/1pOpenGL/src/movement.cpp > CMakeFiles/opengl.dir/src/movement.cpp.i

CMakeFiles/opengl.dir/src/movement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/src/movement.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kubuski/Projects/1pOpenGL/src/movement.cpp -o CMakeFiles/opengl.dir/src/movement.cpp.s

# Object files for target opengl
opengl_OBJECTS = \
"CMakeFiles/opengl.dir/src/main.cpp.o" \
"CMakeFiles/opengl.dir/src/glad.c.o" \
"CMakeFiles/opengl.dir/src/shader.cpp.o" \
"CMakeFiles/opengl.dir/src/camera.cpp.o" \
"CMakeFiles/opengl.dir/src/movement.cpp.o"

# External object files for target opengl
opengl_EXTERNAL_OBJECTS =

opengl: CMakeFiles/opengl.dir/src/main.cpp.o
opengl: CMakeFiles/opengl.dir/src/glad.c.o
opengl: CMakeFiles/opengl.dir/src/shader.cpp.o
opengl: CMakeFiles/opengl.dir/src/camera.cpp.o
opengl: CMakeFiles/opengl.dir/src/movement.cpp.o
opengl: CMakeFiles/opengl.dir/build.make
opengl: /usr/lib64/libGL.so
opengl: /usr/lib64/libglfw.so.3.3
opengl: /usr/lib64/libX11.so
opengl: /usr/lib64/libXext.so
opengl: CMakeFiles/opengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kubuski/Projects/1pOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable opengl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl.dir/build: opengl
.PHONY : CMakeFiles/opengl.dir/build

CMakeFiles/opengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl.dir/clean

CMakeFiles/opengl.dir/depend:
	cd /home/kubuski/Projects/1pOpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kubuski/Projects/1pOpenGL /home/kubuski/Projects/1pOpenGL /home/kubuski/Projects/1pOpenGL/build /home/kubuski/Projects/1pOpenGL/build /home/kubuski/Projects/1pOpenGL/build/CMakeFiles/opengl.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/opengl.dir/depend
