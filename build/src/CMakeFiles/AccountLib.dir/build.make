# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = "/home/dragos/Documents/Lab Paoo teme"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/dragos/Documents/Lab Paoo teme/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/AccountLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/AccountLib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/AccountLib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/AccountLib.dir/flags.make

src/CMakeFiles/AccountLib.dir/Account.cpp.o: src/CMakeFiles/AccountLib.dir/flags.make
src/CMakeFiles/AccountLib.dir/Account.cpp.o: /home/dragos/Documents/Lab\ Paoo\ teme/src/Account.cpp
src/CMakeFiles/AccountLib.dir/Account.cpp.o: src/CMakeFiles/AccountLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dragos/Documents/Lab Paoo teme/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/AccountLib.dir/Account.cpp.o"
	cd "/home/dragos/Documents/Lab Paoo teme/build/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/AccountLib.dir/Account.cpp.o -MF CMakeFiles/AccountLib.dir/Account.cpp.o.d -o CMakeFiles/AccountLib.dir/Account.cpp.o -c "/home/dragos/Documents/Lab Paoo teme/src/Account.cpp"

src/CMakeFiles/AccountLib.dir/Account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AccountLib.dir/Account.cpp.i"
	cd "/home/dragos/Documents/Lab Paoo teme/build/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dragos/Documents/Lab Paoo teme/src/Account.cpp" > CMakeFiles/AccountLib.dir/Account.cpp.i

src/CMakeFiles/AccountLib.dir/Account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AccountLib.dir/Account.cpp.s"
	cd "/home/dragos/Documents/Lab Paoo teme/build/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dragos/Documents/Lab Paoo teme/src/Account.cpp" -o CMakeFiles/AccountLib.dir/Account.cpp.s

# Object files for target AccountLib
AccountLib_OBJECTS = \
"CMakeFiles/AccountLib.dir/Account.cpp.o"

# External object files for target AccountLib
AccountLib_EXTERNAL_OBJECTS =

src/libAccountLib.a: src/CMakeFiles/AccountLib.dir/Account.cpp.o
src/libAccountLib.a: src/CMakeFiles/AccountLib.dir/build.make
src/libAccountLib.a: src/CMakeFiles/AccountLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/dragos/Documents/Lab Paoo teme/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libAccountLib.a"
	cd "/home/dragos/Documents/Lab Paoo teme/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/AccountLib.dir/cmake_clean_target.cmake
	cd "/home/dragos/Documents/Lab Paoo teme/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AccountLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/AccountLib.dir/build: src/libAccountLib.a
.PHONY : src/CMakeFiles/AccountLib.dir/build

src/CMakeFiles/AccountLib.dir/clean:
	cd "/home/dragos/Documents/Lab Paoo teme/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/AccountLib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/AccountLib.dir/clean

src/CMakeFiles/AccountLib.dir/depend:
	cd "/home/dragos/Documents/Lab Paoo teme/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/dragos/Documents/Lab Paoo teme" "/home/dragos/Documents/Lab Paoo teme/src" "/home/dragos/Documents/Lab Paoo teme/build" "/home/dragos/Documents/Lab Paoo teme/build/src" "/home/dragos/Documents/Lab Paoo teme/build/src/CMakeFiles/AccountLib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/AccountLib.dir/depend

