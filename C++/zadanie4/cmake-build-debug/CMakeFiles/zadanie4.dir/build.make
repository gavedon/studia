# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/clion-2019.3.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/clion-2019.3.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/krzysztof/CLionProjects/zadanie4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/krzysztof/CLionProjects/zadanie4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zadanie4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zadanie4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zadanie4.dir/flags.make

CMakeFiles/zadanie4.dir/main.cpp.o: CMakeFiles/zadanie4.dir/flags.make
CMakeFiles/zadanie4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krzysztof/CLionProjects/zadanie4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zadanie4.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zadanie4.dir/main.cpp.o -c /home/krzysztof/CLionProjects/zadanie4/main.cpp

CMakeFiles/zadanie4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zadanie4.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krzysztof/CLionProjects/zadanie4/main.cpp > CMakeFiles/zadanie4.dir/main.cpp.i

CMakeFiles/zadanie4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zadanie4.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krzysztof/CLionProjects/zadanie4/main.cpp -o CMakeFiles/zadanie4.dir/main.cpp.s

CMakeFiles/zadanie4.dir/stos.cpp.o: CMakeFiles/zadanie4.dir/flags.make
CMakeFiles/zadanie4.dir/stos.cpp.o: ../stos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krzysztof/CLionProjects/zadanie4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zadanie4.dir/stos.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zadanie4.dir/stos.cpp.o -c /home/krzysztof/CLionProjects/zadanie4/stos.cpp

CMakeFiles/zadanie4.dir/stos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zadanie4.dir/stos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krzysztof/CLionProjects/zadanie4/stos.cpp > CMakeFiles/zadanie4.dir/stos.cpp.i

CMakeFiles/zadanie4.dir/stos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zadanie4.dir/stos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krzysztof/CLionProjects/zadanie4/stos.cpp -o CMakeFiles/zadanie4.dir/stos.cpp.s

# Object files for target zadanie4
zadanie4_OBJECTS = \
"CMakeFiles/zadanie4.dir/main.cpp.o" \
"CMakeFiles/zadanie4.dir/stos.cpp.o"

# External object files for target zadanie4
zadanie4_EXTERNAL_OBJECTS =

zadanie4: CMakeFiles/zadanie4.dir/main.cpp.o
zadanie4: CMakeFiles/zadanie4.dir/stos.cpp.o
zadanie4: CMakeFiles/zadanie4.dir/build.make
zadanie4: CMakeFiles/zadanie4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krzysztof/CLionProjects/zadanie4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable zadanie4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zadanie4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zadanie4.dir/build: zadanie4

.PHONY : CMakeFiles/zadanie4.dir/build

CMakeFiles/zadanie4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zadanie4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zadanie4.dir/clean

CMakeFiles/zadanie4.dir/depend:
	cd /home/krzysztof/CLionProjects/zadanie4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krzysztof/CLionProjects/zadanie4 /home/krzysztof/CLionProjects/zadanie4 /home/krzysztof/CLionProjects/zadanie4/cmake-build-debug /home/krzysztof/CLionProjects/zadanie4/cmake-build-debug /home/krzysztof/CLionProjects/zadanie4/cmake-build-debug/CMakeFiles/zadanie4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zadanie4.dir/depend

