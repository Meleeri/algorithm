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
include uva/CMakeFiles/10382.dir/depend.make

# Include the progress variables for this target.
include uva/CMakeFiles/10382.dir/progress.make

# Include the compile flags for this target's objects.
include uva/CMakeFiles/10382.dir/flags.make

uva/CMakeFiles/10382.dir/10382.o: uva/CMakeFiles/10382.dir/flags.make
uva/CMakeFiles/10382.dir/10382.o: uva/10382.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/li/algorithm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object uva/CMakeFiles/10382.dir/10382.o"
	cd /home/li/algorithm/uva && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/10382.dir/10382.o -c /home/li/algorithm/uva/10382.cpp

uva/CMakeFiles/10382.dir/10382.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/10382.dir/10382.i"
	cd /home/li/algorithm/uva && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/li/algorithm/uva/10382.cpp > CMakeFiles/10382.dir/10382.i

uva/CMakeFiles/10382.dir/10382.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/10382.dir/10382.s"
	cd /home/li/algorithm/uva && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/li/algorithm/uva/10382.cpp -o CMakeFiles/10382.dir/10382.s

uva/CMakeFiles/10382.dir/10382.o.requires:
.PHONY : uva/CMakeFiles/10382.dir/10382.o.requires

uva/CMakeFiles/10382.dir/10382.o.provides: uva/CMakeFiles/10382.dir/10382.o.requires
	$(MAKE) -f uva/CMakeFiles/10382.dir/build.make uva/CMakeFiles/10382.dir/10382.o.provides.build
.PHONY : uva/CMakeFiles/10382.dir/10382.o.provides

uva/CMakeFiles/10382.dir/10382.o.provides.build: uva/CMakeFiles/10382.dir/10382.o

# Object files for target 10382
10382_OBJECTS = \
"CMakeFiles/10382.dir/10382.o"

# External object files for target 10382
10382_EXTERNAL_OBJECTS =

uva/10382: uva/CMakeFiles/10382.dir/10382.o
uva/10382: uva/CMakeFiles/10382.dir/build.make
uva/10382: uva/CMakeFiles/10382.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable 10382"
	cd /home/li/algorithm/uva && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/10382.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
uva/CMakeFiles/10382.dir/build: uva/10382
.PHONY : uva/CMakeFiles/10382.dir/build

uva/CMakeFiles/10382.dir/requires: uva/CMakeFiles/10382.dir/10382.o.requires
.PHONY : uva/CMakeFiles/10382.dir/requires

uva/CMakeFiles/10382.dir/clean:
	cd /home/li/algorithm/uva && $(CMAKE_COMMAND) -P CMakeFiles/10382.dir/cmake_clean.cmake
.PHONY : uva/CMakeFiles/10382.dir/clean

uva/CMakeFiles/10382.dir/depend:
	cd /home/li/algorithm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/algorithm /home/li/algorithm/uva /home/li/algorithm /home/li/algorithm/uva /home/li/algorithm/uva/CMakeFiles/10382.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : uva/CMakeFiles/10382.dir/depend

