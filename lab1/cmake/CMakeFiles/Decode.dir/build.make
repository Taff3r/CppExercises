# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/simont/git/CppExercises/lab1/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simont/git/CppExercises/lab1/cmake

# Include any dependencies generated for this target.
include CMakeFiles/Decode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Decode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Decode.dir/flags.make

CMakeFiles/Decode.dir/decode.cc.o: CMakeFiles/Decode.dir/flags.make
CMakeFiles/Decode.dir/decode.cc.o: decode.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simont/git/CppExercises/lab1/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Decode.dir/decode.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Decode.dir/decode.cc.o -c /home/simont/git/CppExercises/lab1/cmake/decode.cc

CMakeFiles/Decode.dir/decode.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Decode.dir/decode.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simont/git/CppExercises/lab1/cmake/decode.cc > CMakeFiles/Decode.dir/decode.cc.i

CMakeFiles/Decode.dir/decode.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Decode.dir/decode.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simont/git/CppExercises/lab1/cmake/decode.cc -o CMakeFiles/Decode.dir/decode.cc.s

# Object files for target Decode
Decode_OBJECTS = \
"CMakeFiles/Decode.dir/decode.cc.o"

# External object files for target Decode
Decode_EXTERNAL_OBJECTS =

Decode: CMakeFiles/Decode.dir/decode.cc.o
Decode: CMakeFiles/Decode.dir/build.make
Decode: liblab1/libcoding.a
Decode: CMakeFiles/Decode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/simont/git/CppExercises/lab1/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Decode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Decode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Decode.dir/build: Decode

.PHONY : CMakeFiles/Decode.dir/build

CMakeFiles/Decode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Decode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Decode.dir/clean

CMakeFiles/Decode.dir/depend:
	cd /home/simont/git/CppExercises/lab1/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simont/git/CppExercises/lab1/cmake /home/simont/git/CppExercises/lab1/cmake /home/simont/git/CppExercises/lab1/cmake /home/simont/git/CppExercises/lab1/cmake /home/simont/git/CppExercises/lab1/cmake/CMakeFiles/Decode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Decode.dir/depend

