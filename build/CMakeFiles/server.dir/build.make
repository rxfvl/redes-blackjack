# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/build

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/aux.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/aux.c.o: ../aux.c
CMakeFiles/server.dir/aux.c.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/server.dir/aux.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/server.dir/aux.c.o -MF CMakeFiles/server.dir/aux.c.o.d -o CMakeFiles/server.dir/aux.c.o -c /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/aux.c

CMakeFiles/server.dir/aux.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/aux.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/aux.c > CMakeFiles/server.dir/aux.c.i

CMakeFiles/server.dir/aux.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/aux.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/aux.c -o CMakeFiles/server.dir/aux.c.s

CMakeFiles/server.dir/servidorChat.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/servidorChat.c.o: ../servidorChat.c
CMakeFiles/server.dir/servidorChat.c.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/server.dir/servidorChat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/server.dir/servidorChat.c.o -MF CMakeFiles/server.dir/servidorChat.c.o.d -o CMakeFiles/server.dir/servidorChat.c.o -c /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/servidorChat.c

CMakeFiles/server.dir/servidorChat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/servidorChat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/servidorChat.c > CMakeFiles/server.dir/servidorChat.c.i

CMakeFiles/server.dir/servidorChat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/servidorChat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/servidorChat.c -o CMakeFiles/server.dir/servidorChat.c.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/aux.c.o" \
"CMakeFiles/server.dir/servidorChat.c.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/aux.c.o
server: CMakeFiles/server.dir/servidorChat.c.o
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/build /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/build /mnt/c/Users/TESTER/Desktop/Universidad/3º/Redes/PRÁCTICAS/redes-blackjack-main/build/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

