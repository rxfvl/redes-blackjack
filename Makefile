# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/dani/Escritorio/redes-blackjack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dani/Escritorio/redes-blackjack

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dani/Escritorio/redes-blackjack/CMakeFiles /home/dani/Escritorio/redes-blackjack//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dani/Escritorio/redes-blackjack/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named server

# Build rule for target.
server: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 server
.PHONY : server

# fast build rule for target.
server/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/build
.PHONY : server/fast

#=============================================================================
# Target rules for targets named cliente

# Build rule for target.
cliente: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 cliente
.PHONY : cliente

# fast build rule for target.
cliente/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cliente.dir/build.make CMakeFiles/cliente.dir/build
.PHONY : cliente/fast

aux.o: aux.c.o
.PHONY : aux.o

# target to build an object file
aux.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/aux.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cliente.dir/build.make CMakeFiles/cliente.dir/aux.c.o
.PHONY : aux.c.o

aux.i: aux.c.i
.PHONY : aux.i

# target to preprocess a source file
aux.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/aux.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cliente.dir/build.make CMakeFiles/cliente.dir/aux.c.i
.PHONY : aux.c.i

aux.s: aux.c.s
.PHONY : aux.s

# target to generate assembly for a file
aux.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/aux.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cliente.dir/build.make CMakeFiles/cliente.dir/aux.c.s
.PHONY : aux.c.s

clienteChat.o: clienteChat.c.o
.PHONY : clienteChat.o

# target to build an object file
clienteChat.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cliente.dir/build.make CMakeFiles/cliente.dir/clienteChat.c.o
.PHONY : clienteChat.c.o

clienteChat.i: clienteChat.c.i
.PHONY : clienteChat.i

# target to preprocess a source file
clienteChat.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cliente.dir/build.make CMakeFiles/cliente.dir/clienteChat.c.i
.PHONY : clienteChat.c.i

clienteChat.s: clienteChat.c.s
.PHONY : clienteChat.s

# target to generate assembly for a file
clienteChat.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cliente.dir/build.make CMakeFiles/cliente.dir/clienteChat.c.s
.PHONY : clienteChat.c.s

servidorChat.o: servidorChat.c.o
.PHONY : servidorChat.o

# target to build an object file
servidorChat.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/servidorChat.c.o
.PHONY : servidorChat.c.o

servidorChat.i: servidorChat.c.i
.PHONY : servidorChat.i

# target to preprocess a source file
servidorChat.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/servidorChat.c.i
.PHONY : servidorChat.c.i

servidorChat.s: servidorChat.c.s
.PHONY : servidorChat.s

# target to generate assembly for a file
servidorChat.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/servidorChat.c.s
.PHONY : servidorChat.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... cliente"
	@echo "... server"
	@echo "... aux.o"
	@echo "... aux.i"
	@echo "... aux.s"
	@echo "... clienteChat.o"
	@echo "... clienteChat.i"
	@echo "... clienteChat.s"
	@echo "... servidorChat.o"
	@echo "... servidorChat.i"
	@echo "... servidorChat.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

