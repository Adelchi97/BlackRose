# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ElenaFaillace/Desktop/BlackRose

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ElenaFaillace/Desktop/BlackRose/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BlackRose.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BlackRose.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BlackRose.dir/flags.make

CMakeFiles/BlackRose.dir/main.cpp.o: CMakeFiles/BlackRose.dir/flags.make
CMakeFiles/BlackRose.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ElenaFaillace/Desktop/BlackRose/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BlackRose.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BlackRose.dir/main.cpp.o -c /Users/ElenaFaillace/Desktop/BlackRose/main.cpp

CMakeFiles/BlackRose.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BlackRose.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ElenaFaillace/Desktop/BlackRose/main.cpp > CMakeFiles/BlackRose.dir/main.cpp.i

CMakeFiles/BlackRose.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BlackRose.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ElenaFaillace/Desktop/BlackRose/main.cpp -o CMakeFiles/BlackRose.dir/main.cpp.s

CMakeFiles/BlackRose.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/BlackRose.dir/main.cpp.o.requires

CMakeFiles/BlackRose.dir/main.cpp.o.provides: CMakeFiles/BlackRose.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BlackRose.dir/build.make CMakeFiles/BlackRose.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/BlackRose.dir/main.cpp.o.provides

CMakeFiles/BlackRose.dir/main.cpp.o.provides.build: CMakeFiles/BlackRose.dir/main.cpp.o


# Object files for target BlackRose
BlackRose_OBJECTS = \
"CMakeFiles/BlackRose.dir/main.cpp.o"

# External object files for target BlackRose
BlackRose_EXTERNAL_OBJECTS =

BlackRose: CMakeFiles/BlackRose.dir/main.cpp.o
BlackRose: CMakeFiles/BlackRose.dir/build.make
BlackRose: CMakeFiles/BlackRose.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ElenaFaillace/Desktop/BlackRose/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BlackRose"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BlackRose.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BlackRose.dir/build: BlackRose

.PHONY : CMakeFiles/BlackRose.dir/build

CMakeFiles/BlackRose.dir/requires: CMakeFiles/BlackRose.dir/main.cpp.o.requires

.PHONY : CMakeFiles/BlackRose.dir/requires

CMakeFiles/BlackRose.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BlackRose.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BlackRose.dir/clean

CMakeFiles/BlackRose.dir/depend:
	cd /Users/ElenaFaillace/Desktop/BlackRose/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ElenaFaillace/Desktop/BlackRose /Users/ElenaFaillace/Desktop/BlackRose /Users/ElenaFaillace/Desktop/BlackRose/cmake-build-debug /Users/ElenaFaillace/Desktop/BlackRose/cmake-build-debug /Users/ElenaFaillace/Desktop/BlackRose/cmake-build-debug/CMakeFiles/BlackRose.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BlackRose.dir/depend

