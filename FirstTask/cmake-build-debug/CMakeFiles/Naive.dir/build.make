# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/voland/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/voland/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/voland/Workspace/SkiPod2/FirstTask

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Naive.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Naive.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Naive.dir/flags.make

CMakeFiles/Naive.dir/naive.cpp.o: CMakeFiles/Naive.dir/flags.make
CMakeFiles/Naive.dir/naive.cpp.o: ../naive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Naive.dir/naive.cpp.o"
	mpicxx  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Naive.dir/naive.cpp.o -c /home/voland/Workspace/SkiPod2/FirstTask/naive.cpp

CMakeFiles/Naive.dir/naive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Naive.dir/naive.cpp.i"
	mpicxx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/voland/Workspace/SkiPod2/FirstTask/naive.cpp > CMakeFiles/Naive.dir/naive.cpp.i

CMakeFiles/Naive.dir/naive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Naive.dir/naive.cpp.s"
	mpicxx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/voland/Workspace/SkiPod2/FirstTask/naive.cpp -o CMakeFiles/Naive.dir/naive.cpp.s

# Object files for target Naive
Naive_OBJECTS = \
"CMakeFiles/Naive.dir/naive.cpp.o"

# External object files for target Naive
Naive_EXTERNAL_OBJECTS =

Naive: CMakeFiles/Naive.dir/naive.cpp.o
Naive: CMakeFiles/Naive.dir/build.make
Naive: CMakeFiles/Naive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Naive"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Naive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Naive.dir/build: Naive

.PHONY : CMakeFiles/Naive.dir/build

CMakeFiles/Naive.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Naive.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Naive.dir/clean

CMakeFiles/Naive.dir/depend:
	cd /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/voland/Workspace/SkiPod2/FirstTask /home/voland/Workspace/SkiPod2/FirstTask /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug/CMakeFiles/Naive.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Naive.dir/depend

