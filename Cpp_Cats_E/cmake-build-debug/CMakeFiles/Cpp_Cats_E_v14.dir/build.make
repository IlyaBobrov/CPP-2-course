# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x86)\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Program Files (x86)\Cpp_Cats_E_v14"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Program Files (x86)\Cpp_Cats_E_v14\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Cpp_Cats_E_v14.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cpp_Cats_E_v14.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cpp_Cats_E_v14.dir/flags.make

CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.obj: CMakeFiles/Cpp_Cats_E_v14.dir/flags.make
CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Program Files (x86)\Cpp_Cats_E_v14\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.obj"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cpp_Cats_E_v14.dir\main.cpp.obj -c "D:\Program Files (x86)\Cpp_Cats_E_v14\main.cpp"

CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.i"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Program Files (x86)\Cpp_Cats_E_v14\main.cpp" > CMakeFiles\Cpp_Cats_E_v14.dir\main.cpp.i

CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.s"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Program Files (x86)\Cpp_Cats_E_v14\main.cpp" -o CMakeFiles\Cpp_Cats_E_v14.dir\main.cpp.s

CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.obj: CMakeFiles/Cpp_Cats_E_v14.dir/flags.make
CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.obj: ../Num.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Program Files (x86)\Cpp_Cats_E_v14\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.obj"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cpp_Cats_E_v14.dir\Num.cpp.obj -c "D:\Program Files (x86)\Cpp_Cats_E_v14\Num.cpp"

CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.i"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Program Files (x86)\Cpp_Cats_E_v14\Num.cpp" > CMakeFiles\Cpp_Cats_E_v14.dir\Num.cpp.i

CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.s"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Program Files (x86)\Cpp_Cats_E_v14\Num.cpp" -o CMakeFiles\Cpp_Cats_E_v14.dir\Num.cpp.s

# Object files for target Cpp_Cats_E_v14
Cpp_Cats_E_v14_OBJECTS = \
"CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.obj" \
"CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.obj"

# External object files for target Cpp_Cats_E_v14
Cpp_Cats_E_v14_EXTERNAL_OBJECTS =

Cpp_Cats_E_v14.exe: CMakeFiles/Cpp_Cats_E_v14.dir/main.cpp.obj
Cpp_Cats_E_v14.exe: CMakeFiles/Cpp_Cats_E_v14.dir/Num.cpp.obj
Cpp_Cats_E_v14.exe: CMakeFiles/Cpp_Cats_E_v14.dir/build.make
Cpp_Cats_E_v14.exe: CMakeFiles/Cpp_Cats_E_v14.dir/linklibs.rsp
Cpp_Cats_E_v14.exe: CMakeFiles/Cpp_Cats_E_v14.dir/objects1.rsp
Cpp_Cats_E_v14.exe: CMakeFiles/Cpp_Cats_E_v14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Program Files (x86)\Cpp_Cats_E_v14\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Cpp_Cats_E_v14.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cpp_Cats_E_v14.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cpp_Cats_E_v14.dir/build: Cpp_Cats_E_v14.exe

.PHONY : CMakeFiles/Cpp_Cats_E_v14.dir/build

CMakeFiles/Cpp_Cats_E_v14.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cpp_Cats_E_v14.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cpp_Cats_E_v14.dir/clean

CMakeFiles/Cpp_Cats_E_v14.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Program Files (x86)\Cpp_Cats_E_v14" "D:\Program Files (x86)\Cpp_Cats_E_v14" "D:\Program Files (x86)\Cpp_Cats_E_v14\cmake-build-debug" "D:\Program Files (x86)\Cpp_Cats_E_v14\cmake-build-debug" "D:\Program Files (x86)\Cpp_Cats_E_v14\cmake-build-debug\CMakeFiles\Cpp_Cats_E_v14.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Cpp_Cats_E_v14.dir/depend

