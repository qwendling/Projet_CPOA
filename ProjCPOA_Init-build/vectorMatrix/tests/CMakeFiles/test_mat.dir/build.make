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
CMAKE_SOURCE_DIR = /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build

# Include any dependencies generated for this target.
include vectorMatrix/tests/CMakeFiles/test_mat.dir/depend.make

# Include the progress variables for this target.
include vectorMatrix/tests/CMakeFiles/test_mat.dir/progress.make

# Include the compile flags for this target's objects.
include vectorMatrix/tests/CMakeFiles/test_mat.dir/flags.make

vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o: vectorMatrix/tests/CMakeFiles/test_mat.dir/flags.make
vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o: /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests/testMatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o"
	cd /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_mat.dir/testMatrix.cpp.o -c /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests/testMatrix.cpp

vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_mat.dir/testMatrix.cpp.i"
	cd /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests/testMatrix.cpp > CMakeFiles/test_mat.dir/testMatrix.cpp.i

vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_mat.dir/testMatrix.cpp.s"
	cd /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests/testMatrix.cpp -o CMakeFiles/test_mat.dir/testMatrix.cpp.s

vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o.requires:

.PHONY : vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o.requires

vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o.provides: vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o.requires
	$(MAKE) -f vectorMatrix/tests/CMakeFiles/test_mat.dir/build.make vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o.provides.build
.PHONY : vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o.provides

vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o.provides.build: vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o


# Object files for target test_mat
test_mat_OBJECTS = \
"CMakeFiles/test_mat.dir/testMatrix.cpp.o"

# External object files for target test_mat
test_mat_EXTERNAL_OBJECTS =

vectorMatrix/tests/test_mat: vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o
vectorMatrix/tests/test_mat: vectorMatrix/tests/CMakeFiles/test_mat.dir/build.make
vectorMatrix/tests/test_mat: vectorMatrix/libvector_matrix.a
vectorMatrix/tests/test_mat: vectorMatrix/tests/CMakeFiles/test_mat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_mat"
	cd /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_mat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vectorMatrix/tests/CMakeFiles/test_mat.dir/build: vectorMatrix/tests/test_mat

.PHONY : vectorMatrix/tests/CMakeFiles/test_mat.dir/build

vectorMatrix/tests/CMakeFiles/test_mat.dir/requires: vectorMatrix/tests/CMakeFiles/test_mat.dir/testMatrix.cpp.o.requires

.PHONY : vectorMatrix/tests/CMakeFiles/test_mat.dir/requires

vectorMatrix/tests/CMakeFiles/test_mat.dir/clean:
	cd /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_mat.dir/cmake_clean.cmake
.PHONY : vectorMatrix/tests/CMakeFiles/test_mat.dir/clean

vectorMatrix/tests/CMakeFiles/test_mat.dir/depend:
	cd /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init/vectorMatrix/tests /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests /adhome/q/qw/q.wendling/Projet_CPOA/ProjCPOA_Init-build/vectorMatrix/tests/CMakeFiles/test_mat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vectorMatrix/tests/CMakeFiles/test_mat.dir/depend
