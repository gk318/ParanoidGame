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
CMAKE_COMMAND = /opt/cmake-3.17.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.17.1-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gaurav/paranoid_ws/ParanoidGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gaurav/paranoid_ws/ParanoidGame/build

# Include any dependencies generated for this target.
include CMakeFiles/ParanoidGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ParanoidGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ParanoidGame.dir/flags.make

CMakeFiles/ParanoidGame.dir/src/main.cpp.o: CMakeFiles/ParanoidGame.dir/flags.make
CMakeFiles/ParanoidGame.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaurav/paranoid_ws/ParanoidGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ParanoidGame.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParanoidGame.dir/src/main.cpp.o -c /home/gaurav/paranoid_ws/ParanoidGame/src/main.cpp

CMakeFiles/ParanoidGame.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParanoidGame.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaurav/paranoid_ws/ParanoidGame/src/main.cpp > CMakeFiles/ParanoidGame.dir/src/main.cpp.i

CMakeFiles/ParanoidGame.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParanoidGame.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaurav/paranoid_ws/ParanoidGame/src/main.cpp -o CMakeFiles/ParanoidGame.dir/src/main.cpp.s

CMakeFiles/ParanoidGame.dir/src/game.cpp.o: CMakeFiles/ParanoidGame.dir/flags.make
CMakeFiles/ParanoidGame.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaurav/paranoid_ws/ParanoidGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ParanoidGame.dir/src/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParanoidGame.dir/src/game.cpp.o -c /home/gaurav/paranoid_ws/ParanoidGame/src/game.cpp

CMakeFiles/ParanoidGame.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParanoidGame.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaurav/paranoid_ws/ParanoidGame/src/game.cpp > CMakeFiles/ParanoidGame.dir/src/game.cpp.i

CMakeFiles/ParanoidGame.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParanoidGame.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaurav/paranoid_ws/ParanoidGame/src/game.cpp -o CMakeFiles/ParanoidGame.dir/src/game.cpp.s

CMakeFiles/ParanoidGame.dir/src/controller.cpp.o: CMakeFiles/ParanoidGame.dir/flags.make
CMakeFiles/ParanoidGame.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaurav/paranoid_ws/ParanoidGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ParanoidGame.dir/src/controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParanoidGame.dir/src/controller.cpp.o -c /home/gaurav/paranoid_ws/ParanoidGame/src/controller.cpp

CMakeFiles/ParanoidGame.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParanoidGame.dir/src/controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaurav/paranoid_ws/ParanoidGame/src/controller.cpp > CMakeFiles/ParanoidGame.dir/src/controller.cpp.i

CMakeFiles/ParanoidGame.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParanoidGame.dir/src/controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaurav/paranoid_ws/ParanoidGame/src/controller.cpp -o CMakeFiles/ParanoidGame.dir/src/controller.cpp.s

CMakeFiles/ParanoidGame.dir/src/renderer.cpp.o: CMakeFiles/ParanoidGame.dir/flags.make
CMakeFiles/ParanoidGame.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaurav/paranoid_ws/ParanoidGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ParanoidGame.dir/src/renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParanoidGame.dir/src/renderer.cpp.o -c /home/gaurav/paranoid_ws/ParanoidGame/src/renderer.cpp

CMakeFiles/ParanoidGame.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParanoidGame.dir/src/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaurav/paranoid_ws/ParanoidGame/src/renderer.cpp > CMakeFiles/ParanoidGame.dir/src/renderer.cpp.i

CMakeFiles/ParanoidGame.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParanoidGame.dir/src/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaurav/paranoid_ws/ParanoidGame/src/renderer.cpp -o CMakeFiles/ParanoidGame.dir/src/renderer.cpp.s

CMakeFiles/ParanoidGame.dir/src/bat.cpp.o: CMakeFiles/ParanoidGame.dir/flags.make
CMakeFiles/ParanoidGame.dir/src/bat.cpp.o: ../src/bat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaurav/paranoid_ws/ParanoidGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ParanoidGame.dir/src/bat.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParanoidGame.dir/src/bat.cpp.o -c /home/gaurav/paranoid_ws/ParanoidGame/src/bat.cpp

CMakeFiles/ParanoidGame.dir/src/bat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParanoidGame.dir/src/bat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaurav/paranoid_ws/ParanoidGame/src/bat.cpp > CMakeFiles/ParanoidGame.dir/src/bat.cpp.i

CMakeFiles/ParanoidGame.dir/src/bat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParanoidGame.dir/src/bat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaurav/paranoid_ws/ParanoidGame/src/bat.cpp -o CMakeFiles/ParanoidGame.dir/src/bat.cpp.s

CMakeFiles/ParanoidGame.dir/src/ball.cpp.o: CMakeFiles/ParanoidGame.dir/flags.make
CMakeFiles/ParanoidGame.dir/src/ball.cpp.o: ../src/ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaurav/paranoid_ws/ParanoidGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ParanoidGame.dir/src/ball.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParanoidGame.dir/src/ball.cpp.o -c /home/gaurav/paranoid_ws/ParanoidGame/src/ball.cpp

CMakeFiles/ParanoidGame.dir/src/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParanoidGame.dir/src/ball.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaurav/paranoid_ws/ParanoidGame/src/ball.cpp > CMakeFiles/ParanoidGame.dir/src/ball.cpp.i

CMakeFiles/ParanoidGame.dir/src/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParanoidGame.dir/src/ball.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaurav/paranoid_ws/ParanoidGame/src/ball.cpp -o CMakeFiles/ParanoidGame.dir/src/ball.cpp.s

# Object files for target ParanoidGame
ParanoidGame_OBJECTS = \
"CMakeFiles/ParanoidGame.dir/src/main.cpp.o" \
"CMakeFiles/ParanoidGame.dir/src/game.cpp.o" \
"CMakeFiles/ParanoidGame.dir/src/controller.cpp.o" \
"CMakeFiles/ParanoidGame.dir/src/renderer.cpp.o" \
"CMakeFiles/ParanoidGame.dir/src/bat.cpp.o" \
"CMakeFiles/ParanoidGame.dir/src/ball.cpp.o"

# External object files for target ParanoidGame
ParanoidGame_EXTERNAL_OBJECTS =

ParanoidGame: CMakeFiles/ParanoidGame.dir/src/main.cpp.o
ParanoidGame: CMakeFiles/ParanoidGame.dir/src/game.cpp.o
ParanoidGame: CMakeFiles/ParanoidGame.dir/src/controller.cpp.o
ParanoidGame: CMakeFiles/ParanoidGame.dir/src/renderer.cpp.o
ParanoidGame: CMakeFiles/ParanoidGame.dir/src/bat.cpp.o
ParanoidGame: CMakeFiles/ParanoidGame.dir/src/ball.cpp.o
ParanoidGame: CMakeFiles/ParanoidGame.dir/build.make
ParanoidGame: CMakeFiles/ParanoidGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gaurav/paranoid_ws/ParanoidGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ParanoidGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ParanoidGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ParanoidGame.dir/build: ParanoidGame

.PHONY : CMakeFiles/ParanoidGame.dir/build

CMakeFiles/ParanoidGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ParanoidGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ParanoidGame.dir/clean

CMakeFiles/ParanoidGame.dir/depend:
	cd /home/gaurav/paranoid_ws/ParanoidGame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gaurav/paranoid_ws/ParanoidGame /home/gaurav/paranoid_ws/ParanoidGame /home/gaurav/paranoid_ws/ParanoidGame/build /home/gaurav/paranoid_ws/ParanoidGame/build /home/gaurav/paranoid_ws/ParanoidGame/build/CMakeFiles/ParanoidGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ParanoidGame.dir/depend

