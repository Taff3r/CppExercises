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
CMAKE_SOURCE_DIR = /home/simont/git/CppExercises/lab1/cmake-example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simont/git/CppExercises/lab1/cmake-example

# Include any dependencies generated for this target.
include CMakeFiles/SimpleMain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleMain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleMain.dir/flags.make

CMakeFiles/SimpleMain.dir/main.cc.o: CMakeFiles/SimpleMain.dir/flags.make
CMakeFiles/SimpleMain.dir/main.cc.o: main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simont/git/CppExercises/lab1/cmake-example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimpleMain.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleMain.dir/main.cc.o -c /home/simont/git/CppExercises/lab1/cmake-example/main.cc

CMakeFiles/SimpleMain.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleMain.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simont/git/CppExercises/lab1/cmake-example/main.cc > CMakeFiles/SimpleMain.dir/main.cc.i

CMakeFiles/SimpleMain.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleMain.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simont/git/CppExercises/lab1/cmake-example/main.cc -o CMakeFiles/SimpleMain.dir/main.cc.s

# Object files for target SimpleMain
SimpleMain_OBJECTS = \
"CMakeFiles/SimpleMain.dir/main.cc.o"

# External object files for target SimpleMain
SimpleMain_EXTERNAL_OBJECTS =

SimpleMain: CMakeFiles/SimpleMain.dir/main.cc.o
SimpleMain: CMakeFiles/SimpleMain.dir/build.make
SimpleMain: testlib/libTestLib.a
SimpleMain: CMakeFiles/SimpleMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/simont/git/CppExercises/lab1/cmake-example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SimpleMain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleMain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleMain.dir/build: SimpleMain

.PHONY : CMakeFiles/SimpleMain.dir/build

CMakeFiles/SimpleMain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleMain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleMain.dir/clean

CMakeFiles/SimpleMain.dir/depend:
	cd /home/simont/git/CppExercises/lab1/cmake-example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simont/git/CppExercises/lab1/cmake-example /home/simont/git/CppExercises/lab1/cmake-example /home/simont/git/CppExercises/lab1/cmake-example /home/simont/git/CppExercises/lab1/cmake-example /home/simont/git/CppExercises/lab1/cmake-example/CMakeFiles/SimpleMain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleMain.dir/depend
