# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrey/Desktop/DREC/ilab/ParaCL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrey/Desktop/DREC/ilab/ParaCL/build

# Include any dependencies generated for this target.
include CMakeFiles/ParaCL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ParaCL.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ParaCL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ParaCL.dir/flags.make

parser.cc: ../generators/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][parser] Building parser with bison 3.8"
	cd /home/andrey/Desktop/DREC/ilab/ParaCL && /usr/bin/bison --defines=/home/andrey/Desktop/DREC/ilab/ParaCL/build/grammar.tab.hh -d -o /home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc generators/parser.y

parser.hh: parser.cc
	@$(CMAKE_COMMAND) -E touch_nocreate parser.hh

lexer.cc: ../generators/lexer.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][scanner] Building scanner with flex 2.6.4"
	cd /home/andrey/Desktop/DREC/ilab/ParaCL && /usr/bin/flex -o/home/andrey/Desktop/DREC/ilab/ParaCL/build/lexer.cc generators/lexer.l

CMakeFiles/ParaCL.dir/src/main.cpp.o: CMakeFiles/ParaCL.dir/flags.make
CMakeFiles/ParaCL.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/ParaCL.dir/src/main.cpp.o: CMakeFiles/ParaCL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ParaCL.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ParaCL.dir/src/main.cpp.o -MF CMakeFiles/ParaCL.dir/src/main.cpp.o.d -o CMakeFiles/ParaCL.dir/src/main.cpp.o -c /home/andrey/Desktop/DREC/ilab/ParaCL/src/main.cpp

CMakeFiles/ParaCL.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParaCL.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/Desktop/DREC/ilab/ParaCL/src/main.cpp > CMakeFiles/ParaCL.dir/src/main.cpp.i

CMakeFiles/ParaCL.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParaCL.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/Desktop/DREC/ilab/ParaCL/src/main.cpp -o CMakeFiles/ParaCL.dir/src/main.cpp.s

CMakeFiles/ParaCL.dir/src/driver.cpp.o: CMakeFiles/ParaCL.dir/flags.make
CMakeFiles/ParaCL.dir/src/driver.cpp.o: ../src/driver.cpp
CMakeFiles/ParaCL.dir/src/driver.cpp.o: CMakeFiles/ParaCL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ParaCL.dir/src/driver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ParaCL.dir/src/driver.cpp.o -MF CMakeFiles/ParaCL.dir/src/driver.cpp.o.d -o CMakeFiles/ParaCL.dir/src/driver.cpp.o -c /home/andrey/Desktop/DREC/ilab/ParaCL/src/driver.cpp

CMakeFiles/ParaCL.dir/src/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParaCL.dir/src/driver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/Desktop/DREC/ilab/ParaCL/src/driver.cpp > CMakeFiles/ParaCL.dir/src/driver.cpp.i

CMakeFiles/ParaCL.dir/src/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParaCL.dir/src/driver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/Desktop/DREC/ilab/ParaCL/src/driver.cpp -o CMakeFiles/ParaCL.dir/src/driver.cpp.s

CMakeFiles/ParaCL.dir/src/node.cpp.o: CMakeFiles/ParaCL.dir/flags.make
CMakeFiles/ParaCL.dir/src/node.cpp.o: ../src/node.cpp
CMakeFiles/ParaCL.dir/src/node.cpp.o: CMakeFiles/ParaCL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ParaCL.dir/src/node.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ParaCL.dir/src/node.cpp.o -MF CMakeFiles/ParaCL.dir/src/node.cpp.o.d -o CMakeFiles/ParaCL.dir/src/node.cpp.o -c /home/andrey/Desktop/DREC/ilab/ParaCL/src/node.cpp

CMakeFiles/ParaCL.dir/src/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParaCL.dir/src/node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/Desktop/DREC/ilab/ParaCL/src/node.cpp > CMakeFiles/ParaCL.dir/src/node.cpp.i

CMakeFiles/ParaCL.dir/src/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParaCL.dir/src/node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/Desktop/DREC/ilab/ParaCL/src/node.cpp -o CMakeFiles/ParaCL.dir/src/node.cpp.s

CMakeFiles/ParaCL.dir/src/symtab.cpp.o: CMakeFiles/ParaCL.dir/flags.make
CMakeFiles/ParaCL.dir/src/symtab.cpp.o: ../src/symtab.cpp
CMakeFiles/ParaCL.dir/src/symtab.cpp.o: CMakeFiles/ParaCL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ParaCL.dir/src/symtab.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ParaCL.dir/src/symtab.cpp.o -MF CMakeFiles/ParaCL.dir/src/symtab.cpp.o.d -o CMakeFiles/ParaCL.dir/src/symtab.cpp.o -c /home/andrey/Desktop/DREC/ilab/ParaCL/src/symtab.cpp

CMakeFiles/ParaCL.dir/src/symtab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParaCL.dir/src/symtab.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/Desktop/DREC/ilab/ParaCL/src/symtab.cpp > CMakeFiles/ParaCL.dir/src/symtab.cpp.i

CMakeFiles/ParaCL.dir/src/symtab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParaCL.dir/src/symtab.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/Desktop/DREC/ilab/ParaCL/src/symtab.cpp -o CMakeFiles/ParaCL.dir/src/symtab.cpp.s

CMakeFiles/ParaCL.dir/src/lexer.cpp.o: CMakeFiles/ParaCL.dir/flags.make
CMakeFiles/ParaCL.dir/src/lexer.cpp.o: ../src/lexer.cpp
CMakeFiles/ParaCL.dir/src/lexer.cpp.o: CMakeFiles/ParaCL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ParaCL.dir/src/lexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ParaCL.dir/src/lexer.cpp.o -MF CMakeFiles/ParaCL.dir/src/lexer.cpp.o.d -o CMakeFiles/ParaCL.dir/src/lexer.cpp.o -c /home/andrey/Desktop/DREC/ilab/ParaCL/src/lexer.cpp

CMakeFiles/ParaCL.dir/src/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParaCL.dir/src/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/Desktop/DREC/ilab/ParaCL/src/lexer.cpp > CMakeFiles/ParaCL.dir/src/lexer.cpp.i

CMakeFiles/ParaCL.dir/src/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParaCL.dir/src/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/Desktop/DREC/ilab/ParaCL/src/lexer.cpp -o CMakeFiles/ParaCL.dir/src/lexer.cpp.s

CMakeFiles/ParaCL.dir/parser.cc.o: CMakeFiles/ParaCL.dir/flags.make
CMakeFiles/ParaCL.dir/parser.cc.o: parser.cc
CMakeFiles/ParaCL.dir/parser.cc.o: CMakeFiles/ParaCL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ParaCL.dir/parser.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ParaCL.dir/parser.cc.o -MF CMakeFiles/ParaCL.dir/parser.cc.o.d -o CMakeFiles/ParaCL.dir/parser.cc.o -c /home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc

CMakeFiles/ParaCL.dir/parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParaCL.dir/parser.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc > CMakeFiles/ParaCL.dir/parser.cc.i

CMakeFiles/ParaCL.dir/parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParaCL.dir/parser.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc -o CMakeFiles/ParaCL.dir/parser.cc.s

CMakeFiles/ParaCL.dir/lexer.cc.o: CMakeFiles/ParaCL.dir/flags.make
CMakeFiles/ParaCL.dir/lexer.cc.o: lexer.cc
CMakeFiles/ParaCL.dir/lexer.cc.o: parser.hh
CMakeFiles/ParaCL.dir/lexer.cc.o: CMakeFiles/ParaCL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ParaCL.dir/lexer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ParaCL.dir/lexer.cc.o -MF CMakeFiles/ParaCL.dir/lexer.cc.o.d -o CMakeFiles/ParaCL.dir/lexer.cc.o -c /home/andrey/Desktop/DREC/ilab/ParaCL/build/lexer.cc

CMakeFiles/ParaCL.dir/lexer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParaCL.dir/lexer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/Desktop/DREC/ilab/ParaCL/build/lexer.cc > CMakeFiles/ParaCL.dir/lexer.cc.i

CMakeFiles/ParaCL.dir/lexer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParaCL.dir/lexer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/Desktop/DREC/ilab/ParaCL/build/lexer.cc -o CMakeFiles/ParaCL.dir/lexer.cc.s

# Object files for target ParaCL
ParaCL_OBJECTS = \
"CMakeFiles/ParaCL.dir/src/main.cpp.o" \
"CMakeFiles/ParaCL.dir/src/driver.cpp.o" \
"CMakeFiles/ParaCL.dir/src/node.cpp.o" \
"CMakeFiles/ParaCL.dir/src/symtab.cpp.o" \
"CMakeFiles/ParaCL.dir/src/lexer.cpp.o" \
"CMakeFiles/ParaCL.dir/parser.cc.o" \
"CMakeFiles/ParaCL.dir/lexer.cc.o"

# External object files for target ParaCL
ParaCL_EXTERNAL_OBJECTS =

ParaCL: CMakeFiles/ParaCL.dir/src/main.cpp.o
ParaCL: CMakeFiles/ParaCL.dir/src/driver.cpp.o
ParaCL: CMakeFiles/ParaCL.dir/src/node.cpp.o
ParaCL: CMakeFiles/ParaCL.dir/src/symtab.cpp.o
ParaCL: CMakeFiles/ParaCL.dir/src/lexer.cpp.o
ParaCL: CMakeFiles/ParaCL.dir/parser.cc.o
ParaCL: CMakeFiles/ParaCL.dir/lexer.cc.o
ParaCL: CMakeFiles/ParaCL.dir/build.make
ParaCL: CMakeFiles/ParaCL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ParaCL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ParaCL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ParaCL.dir/build: ParaCL
.PHONY : CMakeFiles/ParaCL.dir/build

CMakeFiles/ParaCL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ParaCL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ParaCL.dir/clean

CMakeFiles/ParaCL.dir/depend: lexer.cc
CMakeFiles/ParaCL.dir/depend: parser.cc
CMakeFiles/ParaCL.dir/depend: parser.hh
	cd /home/andrey/Desktop/DREC/ilab/ParaCL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrey/Desktop/DREC/ilab/ParaCL /home/andrey/Desktop/DREC/ilab/ParaCL /home/andrey/Desktop/DREC/ilab/ParaCL/build /home/andrey/Desktop/DREC/ilab/ParaCL/build /home/andrey/Desktop/DREC/ilab/ParaCL/build/CMakeFiles/ParaCL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ParaCL.dir/depend

