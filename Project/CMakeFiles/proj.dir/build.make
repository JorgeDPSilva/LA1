# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jorgesilva/Desktop/LA1_PL1_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj.dir/flags.make

CMakeFiles/proj.dir/interpretador.c.o: CMakeFiles/proj.dir/flags.make
CMakeFiles/proj.dir/interpretador.c.o: interpretador.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/proj.dir/interpretador.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/proj.dir/interpretador.c.o   -c /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/interpretador.c

CMakeFiles/proj.dir/interpretador.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/proj.dir/interpretador.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/interpretador.c > CMakeFiles/proj.dir/interpretador.c.i

CMakeFiles/proj.dir/interpretador.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/proj.dir/interpretador.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/interpretador.c -o CMakeFiles/proj.dir/interpretador.c.s

CMakeFiles/proj.dir/main.c.o: CMakeFiles/proj.dir/flags.make
CMakeFiles/proj.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/proj.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/proj.dir/main.c.o   -c /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/main.c

CMakeFiles/proj.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/proj.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/main.c > CMakeFiles/proj.dir/main.c.i

CMakeFiles/proj.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/proj.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/main.c -o CMakeFiles/proj.dir/main.c.s

CMakeFiles/proj.dir/estado.c.o: CMakeFiles/proj.dir/flags.make
CMakeFiles/proj.dir/estado.c.o: estado.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/proj.dir/estado.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/proj.dir/estado.c.o   -c /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/estado.c

CMakeFiles/proj.dir/estado.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/proj.dir/estado.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/estado.c > CMakeFiles/proj.dir/estado.c.i

CMakeFiles/proj.dir/estado.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/proj.dir/estado.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/estado.c -o CMakeFiles/proj.dir/estado.c.s

CMakeFiles/proj.dir/stack.c.o: CMakeFiles/proj.dir/flags.make
CMakeFiles/proj.dir/stack.c.o: stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/proj.dir/stack.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/proj.dir/stack.c.o   -c /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/stack.c

CMakeFiles/proj.dir/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/proj.dir/stack.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/stack.c > CMakeFiles/proj.dir/stack.c.i

CMakeFiles/proj.dir/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/proj.dir/stack.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/stack.c -o CMakeFiles/proj.dir/stack.c.s

# Object files for target proj
proj_OBJECTS = \
"CMakeFiles/proj.dir/interpretador.c.o" \
"CMakeFiles/proj.dir/main.c.o" \
"CMakeFiles/proj.dir/estado.c.o" \
"CMakeFiles/proj.dir/stack.c.o"

# External object files for target proj
proj_EXTERNAL_OBJECTS =

proj: CMakeFiles/proj.dir/interpretador.c.o
proj: CMakeFiles/proj.dir/main.c.o
proj: CMakeFiles/proj.dir/estado.c.o
proj: CMakeFiles/proj.dir/stack.c.o
proj: CMakeFiles/proj.dir/build.make
proj: CMakeFiles/proj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable proj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj.dir/build: proj

.PHONY : CMakeFiles/proj.dir/build

CMakeFiles/proj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj.dir/clean

CMakeFiles/proj.dir/depend:
	cd /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jorgesilva/Desktop/LA1_PL1_2 /Users/jorgesilva/Desktop/LA1_PL1_2 /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug /Users/jorgesilva/Desktop/LA1_PL1_2/cmake-build-debug/CMakeFiles/proj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj.dir/depend

