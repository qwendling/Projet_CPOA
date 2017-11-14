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
CMAKE_SOURCE_DIR = /home/quentin/Projet_CPOA/ProjCPOA_Init

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quentin/Projet_CPOA/ProjCPOA_Init-build

# Include any dependencies generated for this target.
include vectorMatrix/tests/CMakeFiles/test_array.dir/depend.make

# Include the progress variables for this target.
include vectorMatrix/tests/CMakeFiles/test_array.dir/progress.make

# Include the compile flags for this target's objects.
include vectorMatrix/tests/CMakeFiles/test_array.dir/flags.make

vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o: vectorMatrix/tests/CMakeFiles/test_array.dir/flags.make
vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o: /home/quentin/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests/testArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quentin/Projet_CPOA/ProjCPOA_Init-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o"
	cd /home/quentin/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_array.dir/testArray.cpp.o -c /home/quentin/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests/testArray.cpp

vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_array.dir/testArray.cpp.i"
	cd /home/quentin/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quentin/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests/testArray.cpp > CMakeFiles/test_array.dir/testArray.cpp.i

vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_array.dir/testArray.cpp.s"
	cd /home/quentin/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quentin/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests/testArray.cpp -o CMakeFiles/test_array.dir/testArray.cpp.s

vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o.requires:

.PHONY : vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o.requires

vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o.provides: vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o.requires
	$(MAKE) -f vectorMatrix/tests/CMakeFiles/test_array.dir/build.make vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o.provides.build
.PHONY : vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o.provides

vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o.provides.build: vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o


# Object files for target test_array
test_array_OBJECTS = \
"CMakeFiles/test_array.dir/testArray.cpp.o"

# External object files for target test_array
test_array_EXTERNAL_OBJECTS =

vectorMatrix/tests/test_array: vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o
vectorMatrix/tests/test_array: vectorMatrix/tests/CMakeFiles/test_array.dir/build.make
vectorMatrix/tests/test_array: vectorMatrix/libvector_matrix.a
vectorMatrix/tests/test_array: vectorMatrix/tests/CMakeFiles/test_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quentin/Projet_CPOA/ProjCPOA_Init-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_array"
	cd /home/quentin/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vectorMatrix/tests/CMakeFiles/test_array.dir/build: vectorMatrix/tests/test_array

.PHONY : vectorMatrix/tests/CMakeFiles/test_array.dir/build

vectorMatrix/tests/CMakeFiles/test_array.dir/requires: vectorMatrix/tests/CMakeFiles/test_array.dir/testArray.cpp.o.requires

.PHONY : vectorMatrix/tests/CMakeFiles/test_array.dir/requires

vectorMatrix/tests/CMakeFiles/test_array.dir/clean:
	cd /home/quentin/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_array.dir/cmake_clean.cmake
.PHONY : vectorMatrix/tests/CMakeFiles/test_array.dir/clean

vectorMatrix/tests/CMakeFiles/test_array.dir/depend:
	cd /home/quentin/Projet_CPOA/ProjCPOA_Init-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quentin/Projet_CPOA/ProjCPOA_Init /home/quentin/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests /home/quentin/Projet_CPOA/ProjCPOA_Init-build /home/quentin/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests /home/quentin/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests/CMakeFiles/test_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vectorMatrix/tests/CMakeFiles/test_array.dir/depend

