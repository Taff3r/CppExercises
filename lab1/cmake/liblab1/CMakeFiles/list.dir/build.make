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
include liblab1/CMakeFiles/list.dir/depend.make

# Include the progress variables for this target.
include liblab1/CMakeFiles/list.dir/progress.make

# Include the compile flags for this target's objects.
include liblab1/CMakeFiles/list.dir/flags.make

liblab1/CMakeFiles/list.dir/list.cc.o: liblab1/CMakeFiles/list.dir/flags.make
liblab1/CMakeFiles/list.dir/list.cc.o: liblab1/list.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simont/git/CppExercises/lab1/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object liblab1/CMakeFiles/list.dir/list.cc.o"
	cd /home/simont/git/CppExercises/lab1/cmake/liblab1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/list.dir/list.cc.o -c /home/simont/git/CppExercises/lab1/cmake/liblab1/list.cc

liblab1/CMakeFiles/list.dir/list.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/list.dir/list.cc.i"
	cd /home/simont/git/CppExercises/lab1/cmake/liblab1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simont/git/CppExercises/lab1/cmake/liblab1/list.cc > CMakeFiles/list.dir/list.cc.i

liblab1/CMakeFiles/list.dir/list.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/list.dir/list.cc.s"
	cd /home/simont/git/CppExercises/lab1/cmake/liblab1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simont/git/CppExercises/lab1/cmake/liblab1/list.cc -o CMakeFiles/list.dir/list.cc.s

# Object files for target list
list_OBJECTS = \
"CMakeFiles/list.dir/list.cc.o"

# External object files for target list
list_EXTERNAL_OBJECTS =

liblab1/liblist.a: liblab1/CMakeFiles/list.dir/list.cc.o
liblab1/liblist.a: liblab1/CMakeFiles/list.dir/build.make
liblab1/liblist.a: liblab1/CMakeFiles/list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/simont/git/CppExercises/lab1/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblist.a"
	cd /home/simont/git/CppExercises/lab1/cmake/liblab1 && $(CMAKE_COMMAND) -P CMakeFiles/list.dir/cmake_clean_target.cmake
	cd /home/simont/git/CppExercises/lab1/cmake/liblab1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
liblab1/CMakeFiles/list.dir/build: liblab1/liblist.a

.PHONY : liblab1/CMakeFiles/list.dir/build

liblab1/CMakeFiles/list.dir/clean:
	cd /home/simont/git/CppExercises/lab1/cmake/liblab1 && $(CMAKE_COMMAND) -P CMakeFiles/list.dir/cmake_clean.cmake
.PHONY : liblab1/CMakeFiles/list.dir/clean

liblab1/CMakeFiles/list.dir/depend:
	cd /home/simont/git/CppExercises/lab1/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simont/git/CppExercises/lab1/cmake /home/simont/git/CppExercises/lab1/cmake/liblab1 /home/simont/git/CppExercises/lab1/cmake /home/simont/git/CppExercises/lab1/cmake/liblab1 /home/simont/git/CppExercises/lab1/cmake/liblab1/CMakeFiles/list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : liblab1/CMakeFiles/list.dir/depend

