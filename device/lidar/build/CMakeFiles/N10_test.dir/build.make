# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\cmake\bin\cmake.exe

# The command to remove a file.
RM = E:\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\myGitDir\ros2\device\lidar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\myGitDir\ros2\device\lidar\build

# Include any dependencies generated for this target.
include CMakeFiles/N10_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/N10_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/N10_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/N10_test.dir/flags.make

CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.obj: CMakeFiles/N10_test.dir/flags.make
CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.obj: ../wheeltec-N10/N10_test_main.cc
CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.obj: CMakeFiles/N10_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\myGitDir\ros2\device\lidar\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.obj"
	C:\Strawberry\c\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.obj -MF CMakeFiles\N10_test.dir\wheeltec-N10\N10_test_main.cc.obj.d -o CMakeFiles\N10_test.dir\wheeltec-N10\N10_test_main.cc.obj -c G:\myGitDir\ros2\device\lidar\wheeltec-N10\N10_test_main.cc

CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.i"
	C:\Strawberry\c\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\myGitDir\ros2\device\lidar\wheeltec-N10\N10_test_main.cc > CMakeFiles\N10_test.dir\wheeltec-N10\N10_test_main.cc.i

CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.s"
	C:\Strawberry\c\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\myGitDir\ros2\device\lidar\wheeltec-N10\N10_test_main.cc -o CMakeFiles\N10_test.dir\wheeltec-N10\N10_test_main.cc.s

# Object files for target N10_test
N10_test_OBJECTS = \
"CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.obj"

# External object files for target N10_test
N10_test_EXTERNAL_OBJECTS =

N10_test.exe: CMakeFiles/N10_test.dir/wheeltec-N10/N10_test_main.cc.obj
N10_test.exe: CMakeFiles/N10_test.dir/build.make
N10_test.exe: CMakeFiles/N10_test.dir/linklibs.rsp
N10_test.exe: CMakeFiles/N10_test.dir/objects1.rsp
N10_test.exe: CMakeFiles/N10_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\myGitDir\ros2\device\lidar\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable N10_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\N10_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/N10_test.dir/build: N10_test.exe
.PHONY : CMakeFiles/N10_test.dir/build

CMakeFiles/N10_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\N10_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/N10_test.dir/clean

CMakeFiles/N10_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\myGitDir\ros2\device\lidar G:\myGitDir\ros2\device\lidar G:\myGitDir\ros2\device\lidar\build G:\myGitDir\ros2\device\lidar\build G:\myGitDir\ros2\device\lidar\build\CMakeFiles\N10_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/N10_test.dir/depend

