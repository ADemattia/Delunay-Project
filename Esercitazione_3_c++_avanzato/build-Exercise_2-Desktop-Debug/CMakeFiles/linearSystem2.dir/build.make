# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = C:\Qt\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = C:\Qt\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\build-Exercise_2-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/linearSystem2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linearSystem2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linearSystem2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linearSystem2.dir/flags.make

CMakeFiles/linearSystem2.dir/main.cpp.obj: CMakeFiles/linearSystem2.dir/flags.make
CMakeFiles/linearSystem2.dir/main.cpp.obj: CMakeFiles/linearSystem2.dir/includes_CXX.rsp
CMakeFiles/linearSystem2.dir/main.cpp.obj: C:/Users/aless/Desktop/PCS2023_Exercises-main/Esercitazione_3_c++_avanzato/Exercise_2/main.cpp
CMakeFiles/linearSystem2.dir/main.cpp.obj: CMakeFiles/linearSystem2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\build-Exercise_2-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linearSystem2.dir/main.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linearSystem2.dir/main.cpp.obj -MF CMakeFiles\linearSystem2.dir\main.cpp.obj.d -o CMakeFiles\linearSystem2.dir\main.cpp.obj -c C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_2\main.cpp

CMakeFiles/linearSystem2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linearSystem2.dir/main.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_2\main.cpp > CMakeFiles\linearSystem2.dir\main.cpp.i

CMakeFiles/linearSystem2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linearSystem2.dir/main.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_2\main.cpp -o CMakeFiles\linearSystem2.dir\main.cpp.s

# Object files for target linearSystem2
linearSystem2_OBJECTS = \
"CMakeFiles/linearSystem2.dir/main.cpp.obj"

# External object files for target linearSystem2
linearSystem2_EXTERNAL_OBJECTS =

linearSystem2.exe: CMakeFiles/linearSystem2.dir/main.cpp.obj
linearSystem2.exe: CMakeFiles/linearSystem2.dir/build.make
linearSystem2.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest.a
linearSystem2.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest_main.a
linearSystem2.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock.a
linearSystem2.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock_main.a
linearSystem2.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock.a
linearSystem2.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest.a
linearSystem2.exe: CMakeFiles/linearSystem2.dir/linklibs.rsp
linearSystem2.exe: CMakeFiles/linearSystem2.dir/objects1.rsp
linearSystem2.exe: CMakeFiles/linearSystem2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\build-Exercise_2-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linearSystem2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\linearSystem2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linearSystem2.dir/build: linearSystem2.exe
.PHONY : CMakeFiles/linearSystem2.dir/build

CMakeFiles/linearSystem2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\linearSystem2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/linearSystem2.dir/clean

CMakeFiles/linearSystem2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_2 C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_2 C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\build-Exercise_2-Desktop-Debug C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\build-Exercise_2-Desktop-Debug C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\build-Exercise_2-Desktop-Debug\CMakeFiles\linearSystem2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linearSystem2.dir/depend

