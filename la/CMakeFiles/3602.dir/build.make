# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/li/algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/algorithm

# Include any dependencies generated for this target.
include la/CMakeFiles/3602.dir/depend.make

# Include the progress variables for this target.
include la/CMakeFiles/3602.dir/progress.make

# Include the compile flags for this target's objects.
include la/CMakeFiles/3602.dir/flags.make

la/CMakeFiles/3602.dir/3602.o: la/CMakeFiles/3602.dir/flags.make
la/CMakeFiles/3602.dir/3602.o: la/3602.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/li/algorithm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object la/CMakeFiles/3602.dir/3602.o"
	cd /home/li/algorithm/la && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/3602.dir/3602.o -c /home/li/algorithm/la/3602.cpp

la/CMakeFiles/3602.dir/3602.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3602.dir/3602.i"
	cd /home/li/algorithm/la && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/li/algorithm/la/3602.cpp > CMakeFiles/3602.dir/3602.i

la/CMakeFiles/3602.dir/3602.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3602.dir/3602.s"
	cd /home/li/algorithm/la && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/li/algorithm/la/3602.cpp -o CMakeFiles/3602.dir/3602.s

la/CMakeFiles/3602.dir/3602.o.requires:
.PHONY : la/CMakeFiles/3602.dir/3602.o.requires

la/CMakeFiles/3602.dir/3602.o.provides: la/CMakeFiles/3602.dir/3602.o.requires
	$(MAKE) -f la/CMakeFiles/3602.dir/build.make la/CMakeFiles/3602.dir/3602.o.provides.build
.PHONY : la/CMakeFiles/3602.dir/3602.o.provides

la/CMakeFiles/3602.dir/3602.o.provides.build: la/CMakeFiles/3602.dir/3602.o

# Object files for target 3602
3602_OBJECTS = \
"CMakeFiles/3602.dir/3602.o"

# External object files for target 3602
3602_EXTERNAL_OBJECTS =

la/3602: la/CMakeFiles/3602.dir/3602.o
la/3602: la/CMakeFiles/3602.dir/build.make
la/3602: la/CMakeFiles/3602.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable 3602"
	cd /home/li/algorithm/la && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3602.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
la/CMakeFiles/3602.dir/build: la/3602
.PHONY : la/CMakeFiles/3602.dir/build

la/CMakeFiles/3602.dir/requires: la/CMakeFiles/3602.dir/3602.o.requires
.PHONY : la/CMakeFiles/3602.dir/requires

la/CMakeFiles/3602.dir/clean:
	cd /home/li/algorithm/la && $(CMAKE_COMMAND) -P CMakeFiles/3602.dir/cmake_clean.cmake
.PHONY : la/CMakeFiles/3602.dir/clean

la/CMakeFiles/3602.dir/depend:
	cd /home/li/algorithm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/algorithm /home/li/algorithm/la /home/li/algorithm /home/li/algorithm/la /home/li/algorithm/la/CMakeFiles/3602.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : la/CMakeFiles/3602.dir/depend

