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
CMAKE_SOURCE_DIR = C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\Solution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\build-Solution-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/linearSystem1Solution.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linearSystem1Solution.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linearSystem1Solution.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linearSystem1Solution.dir/flags.make

CMakeFiles/linearSystem1Solution.dir/main.cpp.obj: CMakeFiles/linearSystem1Solution.dir/flags.make
CMakeFiles/linearSystem1Solution.dir/main.cpp.obj: CMakeFiles/linearSystem1Solution.dir/includes_CXX.rsp
CMakeFiles/linearSystem1Solution.dir/main.cpp.obj: C:/Users/aless/Desktop/PCS2023_Exercises-main/Esercitazione_3_c++_avanzato/Exercise_1/Solution/main.cpp
CMakeFiles/linearSystem1Solution.dir/main.cpp.obj: CMakeFiles/linearSystem1Solution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linearSystem1Solution.dir/main.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linearSystem1Solution.dir/main.cpp.obj -MF CMakeFiles\linearSystem1Solution.dir\main.cpp.obj.d -o CMakeFiles\linearSystem1Solution.dir\main.cpp.obj -c C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\Solution\main.cpp

CMakeFiles/linearSystem1Solution.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linearSystem1Solution.dir/main.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\Solution\main.cpp > CMakeFiles\linearSystem1Solution.dir\main.cpp.i

CMakeFiles/linearSystem1Solution.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linearSystem1Solution.dir/main.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\Solution\main.cpp -o CMakeFiles\linearSystem1Solution.dir\main.cpp.s

# Object files for target linearSystem1Solution
linearSystem1Solution_OBJECTS = \
"CMakeFiles/linearSystem1Solution.dir/main.cpp.obj"

# External object files for target linearSystem1Solution
linearSystem1Solution_EXTERNAL_OBJECTS =

linearSystem1Solution.exe: CMakeFiles/linearSystem1Solution.dir/main.cpp.obj
linearSystem1Solution.exe: CMakeFiles/linearSystem1Solution.dir/build.make
linearSystem1Solution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest.a
linearSystem1Solution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest_main.a
linearSystem1Solution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock.a
linearSystem1Solution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock_main.a
linearSystem1Solution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock.a
linearSystem1Solution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest.a
linearSystem1Solution.exe: CMakeFiles/linearSystem1Solution.dir/linklibs.rsp
linearSystem1Solution.exe: CMakeFiles/linearSystem1Solution.dir/objects1.rsp
linearSystem1Solution.exe: CMakeFiles/linearSystem1Solution.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linearSystem1Solution.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\linearSystem1Solution.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linearSystem1Solution.dir/build: linearSystem1Solution.exe
.PHONY : CMakeFiles/linearSystem1Solution.dir/build

CMakeFiles/linearSystem1Solution.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\linearSystem1Solution.dir\cmake_clean.cmake
.PHONY : CMakeFiles/linearSystem1Solution.dir/clean

CMakeFiles/linearSystem1Solution.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\Solution C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\Solution C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\build-Solution-Desktop-Debug C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\build-Solution-Desktop-Debug C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_3_c++_avanzato\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles\linearSystem1Solution.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linearSystem1Solution.dir/depend

