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
CMAKE_SOURCE_DIR = /home/rafa/Desktop/redes-blackjack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rafa/Desktop/redes-blackjack/build

# Include any dependencies generated for this target.
include CMakeFiles/cliente.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cliente.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cliente.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cliente.dir/flags.make

CMakeFiles/cliente.dir/aux.c.o: CMakeFiles/cliente.dir/flags.make
CMakeFiles/cliente.dir/aux.c.o: ../aux.c
CMakeFiles/cliente.dir/aux.c.o: CMakeFiles/cliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rafa/Desktop/redes-blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cliente.dir/aux.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cliente.dir/aux.c.o -MF CMakeFiles/cliente.dir/aux.c.o.d -o CMakeFiles/cliente.dir/aux.c.o -c /home/rafa/Desktop/redes-blackjack/aux.c

CMakeFiles/cliente.dir/aux.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cliente.dir/aux.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rafa/Desktop/redes-blackjack/aux.c > CMakeFiles/cliente.dir/aux.c.i

CMakeFiles/cliente.dir/aux.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cliente.dir/aux.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rafa/Desktop/redes-blackjack/aux.c -o CMakeFiles/cliente.dir/aux.c.s

CMakeFiles/cliente.dir/clienteChat.c.o: CMakeFiles/cliente.dir/flags.make
CMakeFiles/cliente.dir/clienteChat.c.o: ../clienteChat.c
CMakeFiles/cliente.dir/clienteChat.c.o: CMakeFiles/cliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rafa/Desktop/redes-blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cliente.dir/clienteChat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cliente.dir/clienteChat.c.o -MF CMakeFiles/cliente.dir/clienteChat.c.o.d -o CMakeFiles/cliente.dir/clienteChat.c.o -c /home/rafa/Desktop/redes-blackjack/clienteChat.c

CMakeFiles/cliente.dir/clienteChat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cliente.dir/clienteChat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rafa/Desktop/redes-blackjack/clienteChat.c > CMakeFiles/cliente.dir/clienteChat.c.i

CMakeFiles/cliente.dir/clienteChat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cliente.dir/clienteChat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rafa/Desktop/redes-blackjack/clienteChat.c -o CMakeFiles/cliente.dir/clienteChat.c.s

# Object files for target cliente
cliente_OBJECTS = \
"CMakeFiles/cliente.dir/aux.c.o" \
"CMakeFiles/cliente.dir/clienteChat.c.o"

# External object files for target cliente
cliente_EXTERNAL_OBJECTS =

cliente: CMakeFiles/cliente.dir/aux.c.o
cliente: CMakeFiles/cliente.dir/clienteChat.c.o
cliente: CMakeFiles/cliente.dir/build.make
cliente: CMakeFiles/cliente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rafa/Desktop/redes-blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable cliente"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cliente.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cliente.dir/build: cliente
.PHONY : CMakeFiles/cliente.dir/build

CMakeFiles/cliente.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cliente.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cliente.dir/clean

CMakeFiles/cliente.dir/depend:
	cd /home/rafa/Desktop/redes-blackjack/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafa/Desktop/redes-blackjack /home/rafa/Desktop/redes-blackjack /home/rafa/Desktop/redes-blackjack/build /home/rafa/Desktop/redes-blackjack/build /home/rafa/Desktop/redes-blackjack/build/CMakeFiles/cliente.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cliente.dir/depend

