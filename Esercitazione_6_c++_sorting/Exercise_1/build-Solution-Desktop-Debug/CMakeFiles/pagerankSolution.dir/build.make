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
CMAKE_SOURCE_DIR = C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\build-Solution-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/pagerankSolution.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pagerankSolution.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pagerankSolution.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pagerankSolution.dir/flags.make

CMakeFiles/pagerankSolution.dir/main.cpp.obj: CMakeFiles/pagerankSolution.dir/flags.make
CMakeFiles/pagerankSolution.dir/main.cpp.obj: CMakeFiles/pagerankSolution.dir/includes_CXX.rsp
CMakeFiles/pagerankSolution.dir/main.cpp.obj: C:/Users/aless/Desktop/PCS2023_Exercises-main/Esercitazione_6_c++_sorting/Exercise_1/Solution/main.cpp
CMakeFiles/pagerankSolution.dir/main.cpp.obj: CMakeFiles/pagerankSolution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pagerankSolution.dir/main.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pagerankSolution.dir/main.cpp.obj -MF CMakeFiles\pagerankSolution.dir\main.cpp.obj.d -o CMakeFiles\pagerankSolution.dir\main.cpp.obj -c C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution\main.cpp

CMakeFiles/pagerankSolution.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pagerankSolution.dir/main.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution\main.cpp > CMakeFiles\pagerankSolution.dir\main.cpp.i

CMakeFiles/pagerankSolution.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pagerankSolution.dir/main.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution\main.cpp -o CMakeFiles\pagerankSolution.dir\main.cpp.s

CMakeFiles/pagerankSolution.dir/src/web.cpp.obj: CMakeFiles/pagerankSolution.dir/flags.make
CMakeFiles/pagerankSolution.dir/src/web.cpp.obj: CMakeFiles/pagerankSolution.dir/includes_CXX.rsp
CMakeFiles/pagerankSolution.dir/src/web.cpp.obj: C:/Users/aless/Desktop/PCS2023_Exercises-main/Esercitazione_6_c++_sorting/Exercise_1/Solution/src/web.cpp
CMakeFiles/pagerankSolution.dir/src/web.cpp.obj: CMakeFiles/pagerankSolution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pagerankSolution.dir/src/web.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pagerankSolution.dir/src/web.cpp.obj -MF CMakeFiles\pagerankSolution.dir\src\web.cpp.obj.d -o CMakeFiles\pagerankSolution.dir\src\web.cpp.obj -c C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution\src\web.cpp

CMakeFiles/pagerankSolution.dir/src/web.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pagerankSolution.dir/src/web.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution\src\web.cpp > CMakeFiles\pagerankSolution.dir\src\web.cpp.i

CMakeFiles/pagerankSolution.dir/src/web.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pagerankSolution.dir/src/web.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution\src\web.cpp -o CMakeFiles\pagerankSolution.dir\src\web.cpp.s

# Object files for target pagerankSolution
pagerankSolution_OBJECTS = \
"CMakeFiles/pagerankSolution.dir/main.cpp.obj" \
"CMakeFiles/pagerankSolution.dir/src/web.cpp.obj"

# External object files for target pagerankSolution
pagerankSolution_EXTERNAL_OBJECTS =

pagerankSolution.exe: CMakeFiles/pagerankSolution.dir/main.cpp.obj
pagerankSolution.exe: CMakeFiles/pagerankSolution.dir/src/web.cpp.obj
pagerankSolution.exe: CMakeFiles/pagerankSolution.dir/build.make
pagerankSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest.a
pagerankSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest_main.a
pagerankSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock.a
pagerankSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock_main.a
pagerankSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock.a
pagerankSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest.a
pagerankSolution.exe: CMakeFiles/pagerankSolution.dir/linklibs.rsp
pagerankSolution.exe: CMakeFiles/pagerankSolution.dir/objects1.rsp
pagerankSolution.exe: CMakeFiles/pagerankSolution.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable pagerankSolution.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pagerankSolution.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pagerankSolution.dir/build: pagerankSolution.exe
.PHONY : CMakeFiles/pagerankSolution.dir/build

CMakeFiles/pagerankSolution.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pagerankSolution.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pagerankSolution.dir/clean

CMakeFiles/pagerankSolution.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\Solution C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\build-Solution-Desktop-Debug C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\build-Solution-Desktop-Debug C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_6_c++_sorting\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles\pagerankSolution.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pagerankSolution.dir/depend

