# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ES_18_RicercaBinaria.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ES_18_RicercaBinaria.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ES_18_RicercaBinaria.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ES_18_RicercaBinaria.dir/flags.make

CMakeFiles/ES_18_RicercaBinaria.dir/main.c.obj: CMakeFiles/ES_18_RicercaBinaria.dir/flags.make
CMakeFiles/ES_18_RicercaBinaria.dir/main.c.obj: C:/Users/davide.ristorto/Desktop/EserciziC_UNI/Programmazione1/ES_18_RicercaBinaria/main.c
CMakeFiles/ES_18_RicercaBinaria.dir/main.c.obj: CMakeFiles/ES_18_RicercaBinaria.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ES_18_RicercaBinaria.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ES_18_RicercaBinaria.dir/main.c.obj -MF CMakeFiles\ES_18_RicercaBinaria.dir\main.c.obj.d -o CMakeFiles\ES_18_RicercaBinaria.dir\main.c.obj -c C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\main.c

CMakeFiles/ES_18_RicercaBinaria.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ES_18_RicercaBinaria.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\main.c > CMakeFiles\ES_18_RicercaBinaria.dir\main.c.i

CMakeFiles/ES_18_RicercaBinaria.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ES_18_RicercaBinaria.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\main.c -o CMakeFiles\ES_18_RicercaBinaria.dir\main.c.s

# Object files for target ES_18_RicercaBinaria
ES_18_RicercaBinaria_OBJECTS = \
"CMakeFiles/ES_18_RicercaBinaria.dir/main.c.obj"

# External object files for target ES_18_RicercaBinaria
ES_18_RicercaBinaria_EXTERNAL_OBJECTS =

ES_18_RicercaBinaria.exe: CMakeFiles/ES_18_RicercaBinaria.dir/main.c.obj
ES_18_RicercaBinaria.exe: CMakeFiles/ES_18_RicercaBinaria.dir/build.make
ES_18_RicercaBinaria.exe: CMakeFiles/ES_18_RicercaBinaria.dir/linkLibs.rsp
ES_18_RicercaBinaria.exe: CMakeFiles/ES_18_RicercaBinaria.dir/objects1.rsp
ES_18_RicercaBinaria.exe: CMakeFiles/ES_18_RicercaBinaria.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ES_18_RicercaBinaria.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ES_18_RicercaBinaria.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ES_18_RicercaBinaria.dir/build: ES_18_RicercaBinaria.exe
.PHONY : CMakeFiles/ES_18_RicercaBinaria.dir/build

CMakeFiles/ES_18_RicercaBinaria.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ES_18_RicercaBinaria.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ES_18_RicercaBinaria.dir/clean

CMakeFiles/ES_18_RicercaBinaria.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\cmake-build-debug C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\cmake-build-debug C:\Users\davide.ristorto\Desktop\EserciziC_UNI\Programmazione1\ES_18_RicercaBinaria\cmake-build-debug\CMakeFiles\ES_18_RicercaBinaria.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ES_18_RicercaBinaria.dir/depend

