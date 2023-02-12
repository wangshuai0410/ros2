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
CMAKE_SOURCE_DIR = G:\myGitDir\ros2\common\libsnp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\myGitDir\ros2\common\libsnp\build

# Include any dependencies generated for this target.
include CMakeFiles/snp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/snp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/snp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snp.dir/flags.make

CMakeFiles/snp.dir/src/snp.c.obj: CMakeFiles/snp.dir/flags.make
CMakeFiles/snp.dir/src/snp.c.obj: CMakeFiles/snp.dir/includes_C.rsp
CMakeFiles/snp.dir/src/snp.c.obj: ../src/snp.c
CMakeFiles/snp.dir/src/snp.c.obj: CMakeFiles/snp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\myGitDir\ros2\common\libsnp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/snp.dir/src/snp.c.obj"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snp.dir/src/snp.c.obj -MF CMakeFiles\snp.dir\src\snp.c.obj.d -o CMakeFiles\snp.dir\src\snp.c.obj -c G:\myGitDir\ros2\common\libsnp\src\snp.c

CMakeFiles/snp.dir/src/snp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snp.dir/src/snp.c.i"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\myGitDir\ros2\common\libsnp\src\snp.c > CMakeFiles\snp.dir\src\snp.c.i

CMakeFiles/snp.dir/src/snp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snp.dir/src/snp.c.s"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\myGitDir\ros2\common\libsnp\src\snp.c -o CMakeFiles\snp.dir\src\snp.c.s

CMakeFiles/snp.dir/src/snp_node.c.obj: CMakeFiles/snp.dir/flags.make
CMakeFiles/snp.dir/src/snp_node.c.obj: CMakeFiles/snp.dir/includes_C.rsp
CMakeFiles/snp.dir/src/snp_node.c.obj: ../src/snp_node.c
CMakeFiles/snp.dir/src/snp_node.c.obj: CMakeFiles/snp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\myGitDir\ros2\common\libsnp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/snp.dir/src/snp_node.c.obj"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snp.dir/src/snp_node.c.obj -MF CMakeFiles\snp.dir\src\snp_node.c.obj.d -o CMakeFiles\snp.dir\src\snp_node.c.obj -c G:\myGitDir\ros2\common\libsnp\src\snp_node.c

CMakeFiles/snp.dir/src/snp_node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snp.dir/src/snp_node.c.i"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\myGitDir\ros2\common\libsnp\src\snp_node.c > CMakeFiles\snp.dir\src\snp_node.c.i

CMakeFiles/snp.dir/src/snp_node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snp.dir/src/snp_node.c.s"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\myGitDir\ros2\common\libsnp\src\snp_node.c -o CMakeFiles\snp.dir\src\snp_node.c.s

CMakeFiles/snp.dir/src/snp_parse.c.obj: CMakeFiles/snp.dir/flags.make
CMakeFiles/snp.dir/src/snp_parse.c.obj: CMakeFiles/snp.dir/includes_C.rsp
CMakeFiles/snp.dir/src/snp_parse.c.obj: ../src/snp_parse.c
CMakeFiles/snp.dir/src/snp_parse.c.obj: CMakeFiles/snp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\myGitDir\ros2\common\libsnp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/snp.dir/src/snp_parse.c.obj"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snp.dir/src/snp_parse.c.obj -MF CMakeFiles\snp.dir\src\snp_parse.c.obj.d -o CMakeFiles\snp.dir\src\snp_parse.c.obj -c G:\myGitDir\ros2\common\libsnp\src\snp_parse.c

CMakeFiles/snp.dir/src/snp_parse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snp.dir/src/snp_parse.c.i"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\myGitDir\ros2\common\libsnp\src\snp_parse.c > CMakeFiles\snp.dir\src\snp_parse.c.i

CMakeFiles/snp.dir/src/snp_parse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snp.dir/src/snp_parse.c.s"
	C:\Strawberry\c\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\myGitDir\ros2\common\libsnp\src\snp_parse.c -o CMakeFiles\snp.dir\src\snp_parse.c.s

# Object files for target snp
snp_OBJECTS = \
"CMakeFiles/snp.dir/src/snp.c.obj" \
"CMakeFiles/snp.dir/src/snp_node.c.obj" \
"CMakeFiles/snp.dir/src/snp_parse.c.obj"

# External object files for target snp
snp_EXTERNAL_OBJECTS =

libsnp.dll: CMakeFiles/snp.dir/src/snp.c.obj
libsnp.dll: CMakeFiles/snp.dir/src/snp_node.c.obj
libsnp.dll: CMakeFiles/snp.dir/src/snp_parse.c.obj
libsnp.dll: CMakeFiles/snp.dir/build.make
libsnp.dll: CMakeFiles/snp.dir/linklibs.rsp
libsnp.dll: CMakeFiles/snp.dir/objects1.rsp
libsnp.dll: CMakeFiles/snp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\myGitDir\ros2\common\libsnp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C shared library libsnp.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\snp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snp.dir/build: libsnp.dll
.PHONY : CMakeFiles/snp.dir/build

CMakeFiles/snp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\snp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/snp.dir/clean

CMakeFiles/snp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\myGitDir\ros2\common\libsnp G:\myGitDir\ros2\common\libsnp G:\myGitDir\ros2\common\libsnp\build G:\myGitDir\ros2\common\libsnp\build G:\myGitDir\ros2\common\libsnp\build\CMakeFiles\snp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snp.dir/depend

