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
include CMakeFiles/Normal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Normal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Normal.dir/flags.make

CMakeFiles/Normal.dir/main.cpp.o: CMakeFiles/Normal.dir/flags.make
CMakeFiles/Normal.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Normal.dir/main.cpp.o"
	mpicxx  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Normal.dir/main.cpp.o -c /home/voland/Workspace/SkiPod2/FirstTask/main.cpp

CMakeFiles/Normal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Normal.dir/main.cpp.i"
	mpicxx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/voland/Workspace/SkiPod2/FirstTask/main.cpp > CMakeFiles/Normal.dir/main.cpp.i

CMakeFiles/Normal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Normal.dir/main.cpp.s"
	mpicxx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/voland/Workspace/SkiPod2/FirstTask/main.cpp -o CMakeFiles/Normal.dir/main.cpp.s

# Object files for target Normal
Normal_OBJECTS = \
"CMakeFiles/Normal.dir/main.cpp.o"

# External object files for target Normal
Normal_EXTERNAL_OBJECTS =

Normal: CMakeFiles/Normal.dir/main.cpp.o
Normal: CMakeFiles/Normal.dir/build.make
Normal: CMakeFiles/Normal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Normal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Normal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Normal.dir/build: Normal

.PHONY : CMakeFiles/Normal.dir/build

CMakeFiles/Normal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Normal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Normal.dir/clean

CMakeFiles/Normal.dir/depend:
	cd /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/voland/Workspace/SkiPod2/FirstTask /home/voland/Workspace/SkiPod2/FirstTask /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug /home/voland/Workspace/SkiPod2/FirstTask/cmake-build-debug/CMakeFiles/Normal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Normal.dir/depend

