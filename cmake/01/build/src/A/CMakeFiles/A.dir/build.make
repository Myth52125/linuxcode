# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/myth52125/github/linuxcode/cmake/01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/myth52125/github/linuxcode/cmake/01/build

# Include any dependencies generated for this target.
include src/A/CMakeFiles/A.dir/depend.make

# Include the progress variables for this target.
include src/A/CMakeFiles/A.dir/progress.make

# Include the compile flags for this target's objects.
include src/A/CMakeFiles/A.dir/flags.make

src/A/CMakeFiles/A.dir/A.o: src/A/CMakeFiles/A.dir/flags.make
src/A/CMakeFiles/A.dir/A.o: ../src/A/A.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myth52125/github/linuxcode/cmake/01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/A/CMakeFiles/A.dir/A.o"
	cd /home/myth52125/github/linuxcode/cmake/01/build/src/A && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A.dir/A.o -c /home/myth52125/github/linuxcode/cmake/01/src/A/A.cc

src/A/CMakeFiles/A.dir/A.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A.dir/A.i"
	cd /home/myth52125/github/linuxcode/cmake/01/build/src/A && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myth52125/github/linuxcode/cmake/01/src/A/A.cc > CMakeFiles/A.dir/A.i

src/A/CMakeFiles/A.dir/A.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A.dir/A.s"
	cd /home/myth52125/github/linuxcode/cmake/01/build/src/A && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myth52125/github/linuxcode/cmake/01/src/A/A.cc -o CMakeFiles/A.dir/A.s

src/A/CMakeFiles/A.dir/A.o.requires:

.PHONY : src/A/CMakeFiles/A.dir/A.o.requires

src/A/CMakeFiles/A.dir/A.o.provides: src/A/CMakeFiles/A.dir/A.o.requires
	$(MAKE) -f src/A/CMakeFiles/A.dir/build.make src/A/CMakeFiles/A.dir/A.o.provides.build
.PHONY : src/A/CMakeFiles/A.dir/A.o.provides

src/A/CMakeFiles/A.dir/A.o.provides.build: src/A/CMakeFiles/A.dir/A.o


# Object files for target A
A_OBJECTS = \
"CMakeFiles/A.dir/A.o"

# External object files for target A
A_EXTERNAL_OBJECTS =

src/A/libA.a: src/A/CMakeFiles/A.dir/A.o
src/A/libA.a: src/A/CMakeFiles/A.dir/build.make
src/A/libA.a: src/A/CMakeFiles/A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/myth52125/github/linuxcode/cmake/01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libA.a"
	cd /home/myth52125/github/linuxcode/cmake/01/build/src/A && $(CMAKE_COMMAND) -P CMakeFiles/A.dir/cmake_clean_target.cmake
	cd /home/myth52125/github/linuxcode/cmake/01/build/src/A && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/A/CMakeFiles/A.dir/build: src/A/libA.a

.PHONY : src/A/CMakeFiles/A.dir/build

src/A/CMakeFiles/A.dir/requires: src/A/CMakeFiles/A.dir/A.o.requires

.PHONY : src/A/CMakeFiles/A.dir/requires

src/A/CMakeFiles/A.dir/clean:
	cd /home/myth52125/github/linuxcode/cmake/01/build/src/A && $(CMAKE_COMMAND) -P CMakeFiles/A.dir/cmake_clean.cmake
.PHONY : src/A/CMakeFiles/A.dir/clean

src/A/CMakeFiles/A.dir/depend:
	cd /home/myth52125/github/linuxcode/cmake/01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/myth52125/github/linuxcode/cmake/01 /home/myth52125/github/linuxcode/cmake/01/src/A /home/myth52125/github/linuxcode/cmake/01/build /home/myth52125/github/linuxcode/cmake/01/build/src/A /home/myth52125/github/linuxcode/cmake/01/build/src/A/CMakeFiles/A.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/A/CMakeFiles/A.dir/depend

