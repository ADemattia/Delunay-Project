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
CMAKE_SOURCE_DIR = C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\build-Solution-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/carSolution.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/carSolution.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/carSolution.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/carSolution.dir/flags.make

CMakeFiles/carSolution.dir/main.cpp.obj: CMakeFiles/carSolution.dir/flags.make
CMakeFiles/carSolution.dir/main.cpp.obj: CMakeFiles/carSolution.dir/includes_CXX.rsp
CMakeFiles/carSolution.dir/main.cpp.obj: C:/Users/aless/Desktop/PCS2023_Exercises-main/Esercitazione_5_c++_OOP/Exercise_1/Solution/main.cpp
CMakeFiles/carSolution.dir/main.cpp.obj: CMakeFiles/carSolution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/carSolution.dir/main.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/carSolution.dir/main.cpp.obj -MF CMakeFiles\carSolution.dir\main.cpp.obj.d -o CMakeFiles\carSolution.dir\main.cpp.obj -c C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution\main.cpp

CMakeFiles/carSolution.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/carSolution.dir/main.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution\main.cpp > CMakeFiles\carSolution.dir\main.cpp.i

CMakeFiles/carSolution.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/carSolution.dir/main.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution\main.cpp -o CMakeFiles\carSolution.dir\main.cpp.s

CMakeFiles/carSolution.dir/src/car.cpp.obj: CMakeFiles/carSolution.dir/flags.make
CMakeFiles/carSolution.dir/src/car.cpp.obj: CMakeFiles/carSolution.dir/includes_CXX.rsp
CMakeFiles/carSolution.dir/src/car.cpp.obj: C:/Users/aless/Desktop/PCS2023_Exercises-main/Esercitazione_5_c++_OOP/Exercise_1/Solution/src/car.cpp
CMakeFiles/carSolution.dir/src/car.cpp.obj: CMakeFiles/carSolution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/carSolution.dir/src/car.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/carSolution.dir/src/car.cpp.obj -MF CMakeFiles\carSolution.dir\src\car.cpp.obj.d -o CMakeFiles\carSolution.dir\src\car.cpp.obj -c C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution\src\car.cpp

CMakeFiles/carSolution.dir/src/car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/carSolution.dir/src/car.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution\src\car.cpp > CMakeFiles\carSolution.dir\src\car.cpp.i

CMakeFiles/carSolution.dir/src/car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/carSolution.dir/src/car.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution\src\car.cpp -o CMakeFiles\carSolution.dir\src\car.cpp.s

# Object files for target carSolution
carSolution_OBJECTS = \
"CMakeFiles/carSolution.dir/main.cpp.obj" \
"CMakeFiles/carSolution.dir/src/car.cpp.obj"

# External object files for target carSolution
carSolution_EXTERNAL_OBJECTS =

carSolution.exe: CMakeFiles/carSolution.dir/main.cpp.obj
carSolution.exe: CMakeFiles/carSolution.dir/src/car.cpp.obj
carSolution.exe: CMakeFiles/carSolution.dir/build.make
carSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest.a
carSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest_main.a
carSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock.a
carSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock_main.a
carSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgmock.a
carSolution.exe: C:/Users/aless/Desktop/PCS2023_Exercises-main/Externals/Main_Install/googletest/lib/libgtest.a
carSolution.exe: CMakeFiles/carSolution.dir/linklibs.rsp
carSolution.exe: CMakeFiles/carSolution.dir/objects1.rsp
carSolution.exe: CMakeFiles/carSolution.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable carSolution.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\carSolution.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/carSolution.dir/build: carSolution.exe
.PHONY : CMakeFiles/carSolution.dir/build

CMakeFiles/carSolution.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\carSolution.dir\cmake_clean.cmake
.PHONY : CMakeFiles/carSolution.dir/clean

CMakeFiles/carSolution.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\Solution C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\build-Solution-Desktop-Debug C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\build-Solution-Desktop-Debug C:\Users\aless\Desktop\PCS2023_Exercises-main\Esercitazione_5_c++_OOP\Exercise_1\build-Solution-Desktop-Debug\CMakeFiles\carSolution.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/carSolution.dir/depend

