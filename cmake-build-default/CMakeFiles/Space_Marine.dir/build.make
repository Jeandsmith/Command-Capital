# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/jeandsmith/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.4127.32/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jeandsmith/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.4127.32/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeandsmith/Desktop/Command-Capital

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeandsmith/Desktop/Command-Capital/cmake-build-default

# Include any dependencies generated for this target.
include CMakeFiles/Space_Marine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Space_Marine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Space_Marine.dir/flags.make

CMakeFiles/Space_Marine.dir/Source/main.cpp.o: CMakeFiles/Space_Marine.dir/flags.make
CMakeFiles/Space_Marine.dir/Source/main.cpp.o: ../Source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeandsmith/Desktop/Command-Capital/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Space_Marine.dir/Source/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Space_Marine.dir/Source/main.cpp.o -c /home/jeandsmith/Desktop/Command-Capital/Source/main.cpp

CMakeFiles/Space_Marine.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Space_Marine.dir/Source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeandsmith/Desktop/Command-Capital/Source/main.cpp > CMakeFiles/Space_Marine.dir/Source/main.cpp.i

CMakeFiles/Space_Marine.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Space_Marine.dir/Source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeandsmith/Desktop/Command-Capital/Source/main.cpp -o CMakeFiles/Space_Marine.dir/Source/main.cpp.s

CMakeFiles/Space_Marine.dir/Source/main.cpp.o.requires:

.PHONY : CMakeFiles/Space_Marine.dir/Source/main.cpp.o.requires

CMakeFiles/Space_Marine.dir/Source/main.cpp.o.provides: CMakeFiles/Space_Marine.dir/Source/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Space_Marine.dir/build.make CMakeFiles/Space_Marine.dir/Source/main.cpp.o.provides.build
.PHONY : CMakeFiles/Space_Marine.dir/Source/main.cpp.o.provides

CMakeFiles/Space_Marine.dir/Source/main.cpp.o.provides.build: CMakeFiles/Space_Marine.dir/Source/main.cpp.o


CMakeFiles/Space_Marine.dir/Source/character.cpp.o: CMakeFiles/Space_Marine.dir/flags.make
CMakeFiles/Space_Marine.dir/Source/character.cpp.o: ../Source/character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeandsmith/Desktop/Command-Capital/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Space_Marine.dir/Source/character.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Space_Marine.dir/Source/character.cpp.o -c /home/jeandsmith/Desktop/Command-Capital/Source/character.cpp

CMakeFiles/Space_Marine.dir/Source/character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Space_Marine.dir/Source/character.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeandsmith/Desktop/Command-Capital/Source/character.cpp > CMakeFiles/Space_Marine.dir/Source/character.cpp.i

CMakeFiles/Space_Marine.dir/Source/character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Space_Marine.dir/Source/character.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeandsmith/Desktop/Command-Capital/Source/character.cpp -o CMakeFiles/Space_Marine.dir/Source/character.cpp.s

CMakeFiles/Space_Marine.dir/Source/character.cpp.o.requires:

.PHONY : CMakeFiles/Space_Marine.dir/Source/character.cpp.o.requires

CMakeFiles/Space_Marine.dir/Source/character.cpp.o.provides: CMakeFiles/Space_Marine.dir/Source/character.cpp.o.requires
	$(MAKE) -f CMakeFiles/Space_Marine.dir/build.make CMakeFiles/Space_Marine.dir/Source/character.cpp.o.provides.build
.PHONY : CMakeFiles/Space_Marine.dir/Source/character.cpp.o.provides

CMakeFiles/Space_Marine.dir/Source/character.cpp.o.provides.build: CMakeFiles/Space_Marine.dir/Source/character.cpp.o


CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o: CMakeFiles/Space_Marine.dir/flags.make
CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o: ../Source/command_repo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeandsmith/Desktop/Command-Capital/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o -c /home/jeandsmith/Desktop/Command-Capital/Source/command_repo.cpp

CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeandsmith/Desktop/Command-Capital/Source/command_repo.cpp > CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.i

CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeandsmith/Desktop/Command-Capital/Source/command_repo.cpp -o CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.s

CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o.requires:

.PHONY : CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o.requires

CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o.provides: CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o.requires
	$(MAKE) -f CMakeFiles/Space_Marine.dir/build.make CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o.provides.build
.PHONY : CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o.provides

CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o.provides.build: CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o


CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o: CMakeFiles/Space_Marine.dir/flags.make
CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o: ../Source/economy_controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeandsmith/Desktop/Command-Capital/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o -c /home/jeandsmith/Desktop/Command-Capital/Source/economy_controller.cpp

CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeandsmith/Desktop/Command-Capital/Source/economy_controller.cpp > CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.i

CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeandsmith/Desktop/Command-Capital/Source/economy_controller.cpp -o CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.s

CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o.requires:

.PHONY : CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o.requires

CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o.provides: CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o.requires
	$(MAKE) -f CMakeFiles/Space_Marine.dir/build.make CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o.provides.build
.PHONY : CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o.provides

CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o.provides.build: CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o


CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o: CMakeFiles/Space_Marine.dir/flags.make
CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o: ../Source/input_check.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeandsmith/Desktop/Command-Capital/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o -c /home/jeandsmith/Desktop/Command-Capital/Source/input_check.cpp

CMakeFiles/Space_Marine.dir/Source/input_check.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Space_Marine.dir/Source/input_check.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeandsmith/Desktop/Command-Capital/Source/input_check.cpp > CMakeFiles/Space_Marine.dir/Source/input_check.cpp.i

CMakeFiles/Space_Marine.dir/Source/input_check.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Space_Marine.dir/Source/input_check.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeandsmith/Desktop/Command-Capital/Source/input_check.cpp -o CMakeFiles/Space_Marine.dir/Source/input_check.cpp.s

CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o.requires:

.PHONY : CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o.requires

CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o.provides: CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o.requires
	$(MAKE) -f CMakeFiles/Space_Marine.dir/build.make CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o.provides.build
.PHONY : CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o.provides

CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o.provides.build: CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o


CMakeFiles/Space_Marine.dir/Source/console.cpp.o: CMakeFiles/Space_Marine.dir/flags.make
CMakeFiles/Space_Marine.dir/Source/console.cpp.o: ../Source/console.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeandsmith/Desktop/Command-Capital/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Space_Marine.dir/Source/console.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Space_Marine.dir/Source/console.cpp.o -c /home/jeandsmith/Desktop/Command-Capital/Source/console.cpp

CMakeFiles/Space_Marine.dir/Source/console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Space_Marine.dir/Source/console.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeandsmith/Desktop/Command-Capital/Source/console.cpp > CMakeFiles/Space_Marine.dir/Source/console.cpp.i

CMakeFiles/Space_Marine.dir/Source/console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Space_Marine.dir/Source/console.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeandsmith/Desktop/Command-Capital/Source/console.cpp -o CMakeFiles/Space_Marine.dir/Source/console.cpp.s

CMakeFiles/Space_Marine.dir/Source/console.cpp.o.requires:

.PHONY : CMakeFiles/Space_Marine.dir/Source/console.cpp.o.requires

CMakeFiles/Space_Marine.dir/Source/console.cpp.o.provides: CMakeFiles/Space_Marine.dir/Source/console.cpp.o.requires
	$(MAKE) -f CMakeFiles/Space_Marine.dir/build.make CMakeFiles/Space_Marine.dir/Source/console.cpp.o.provides.build
.PHONY : CMakeFiles/Space_Marine.dir/Source/console.cpp.o.provides

CMakeFiles/Space_Marine.dir/Source/console.cpp.o.provides.build: CMakeFiles/Space_Marine.dir/Source/console.cpp.o


# Object files for target Space_Marine
Space_Marine_OBJECTS = \
"CMakeFiles/Space_Marine.dir/Source/main.cpp.o" \
"CMakeFiles/Space_Marine.dir/Source/character.cpp.o" \
"CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o" \
"CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o" \
"CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o" \
"CMakeFiles/Space_Marine.dir/Source/console.cpp.o"

# External object files for target Space_Marine
Space_Marine_EXTERNAL_OBJECTS =

Space_Marine: CMakeFiles/Space_Marine.dir/Source/main.cpp.o
Space_Marine: CMakeFiles/Space_Marine.dir/Source/character.cpp.o
Space_Marine: CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o
Space_Marine: CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o
Space_Marine: CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o
Space_Marine: CMakeFiles/Space_Marine.dir/Source/console.cpp.o
Space_Marine: CMakeFiles/Space_Marine.dir/build.make
Space_Marine: CMakeFiles/Space_Marine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeandsmith/Desktop/Command-Capital/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Space_Marine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Space_Marine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Space_Marine.dir/build: Space_Marine

.PHONY : CMakeFiles/Space_Marine.dir/build

CMakeFiles/Space_Marine.dir/requires: CMakeFiles/Space_Marine.dir/Source/main.cpp.o.requires
CMakeFiles/Space_Marine.dir/requires: CMakeFiles/Space_Marine.dir/Source/character.cpp.o.requires
CMakeFiles/Space_Marine.dir/requires: CMakeFiles/Space_Marine.dir/Source/command_repo.cpp.o.requires
CMakeFiles/Space_Marine.dir/requires: CMakeFiles/Space_Marine.dir/Source/economy_controller.cpp.o.requires
CMakeFiles/Space_Marine.dir/requires: CMakeFiles/Space_Marine.dir/Source/input_check.cpp.o.requires
CMakeFiles/Space_Marine.dir/requires: CMakeFiles/Space_Marine.dir/Source/console.cpp.o.requires

.PHONY : CMakeFiles/Space_Marine.dir/requires

CMakeFiles/Space_Marine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Space_Marine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Space_Marine.dir/clean

CMakeFiles/Space_Marine.dir/depend:
	cd /home/jeandsmith/Desktop/Command-Capital/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeandsmith/Desktop/Command-Capital /home/jeandsmith/Desktop/Command-Capital /home/jeandsmith/Desktop/Command-Capital/cmake-build-default /home/jeandsmith/Desktop/Command-Capital/cmake-build-default /home/jeandsmith/Desktop/Command-Capital/cmake-build-default/CMakeFiles/Space_Marine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Space_Marine.dir/depend

