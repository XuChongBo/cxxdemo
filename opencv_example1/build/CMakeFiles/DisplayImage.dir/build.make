# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xcbfreedom/projects/opencv_example1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xcbfreedom/projects/opencv_example1/build

# Include any dependencies generated for this target.
include CMakeFiles/DisplayImage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DisplayImage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DisplayImage.dir/flags.make

CMakeFiles/DisplayImage.dir/main.cxx.o: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/main.cxx.o: ../main.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/xcbfreedom/projects/opencv_example1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DisplayImage.dir/main.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/main.cxx.o -c /Users/xcbfreedom/projects/opencv_example1/main.cxx

CMakeFiles/DisplayImage.dir/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/main.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/xcbfreedom/projects/opencv_example1/main.cxx > CMakeFiles/DisplayImage.dir/main.cxx.i

CMakeFiles/DisplayImage.dir/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/main.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/xcbfreedom/projects/opencv_example1/main.cxx -o CMakeFiles/DisplayImage.dir/main.cxx.s

CMakeFiles/DisplayImage.dir/main.cxx.o.requires:
.PHONY : CMakeFiles/DisplayImage.dir/main.cxx.o.requires

CMakeFiles/DisplayImage.dir/main.cxx.o.provides: CMakeFiles/DisplayImage.dir/main.cxx.o.requires
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/main.cxx.o.provides.build
.PHONY : CMakeFiles/DisplayImage.dir/main.cxx.o.provides

CMakeFiles/DisplayImage.dir/main.cxx.o.provides.build: CMakeFiles/DisplayImage.dir/main.cxx.o

# Object files for target DisplayImage
DisplayImage_OBJECTS = \
"CMakeFiles/DisplayImage.dir/main.cxx.o"

# External object files for target DisplayImage
DisplayImage_EXTERNAL_OBJECTS =

DisplayImage: CMakeFiles/DisplayImage.dir/main.cxx.o
DisplayImage: CMakeFiles/DisplayImage.dir/build.make
DisplayImage: /usr/local/lib/libopencv_calib3d.dylib
DisplayImage: /usr/local/lib/libopencv_contrib.dylib
DisplayImage: /usr/local/lib/libopencv_core.dylib
DisplayImage: /usr/local/lib/libopencv_features2d.dylib
DisplayImage: /usr/local/lib/libopencv_flann.dylib
DisplayImage: /usr/local/lib/libopencv_gpu.dylib
DisplayImage: /usr/local/lib/libopencv_highgui.dylib
DisplayImage: /usr/local/lib/libopencv_imgproc.dylib
DisplayImage: /usr/local/lib/libopencv_legacy.dylib
DisplayImage: /usr/local/lib/libopencv_ml.dylib
DisplayImage: /usr/local/lib/libopencv_nonfree.dylib
DisplayImage: /usr/local/lib/libopencv_objdetect.dylib
DisplayImage: /usr/local/lib/libopencv_photo.dylib
DisplayImage: /usr/local/lib/libopencv_stitching.dylib
DisplayImage: /usr/local/lib/libopencv_ts.dylib
DisplayImage: /usr/local/lib/libopencv_video.dylib
DisplayImage: /usr/local/lib/libopencv_videostab.dylib
DisplayImage: CMakeFiles/DisplayImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable DisplayImage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DisplayImage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DisplayImage.dir/build: DisplayImage
.PHONY : CMakeFiles/DisplayImage.dir/build

CMakeFiles/DisplayImage.dir/requires: CMakeFiles/DisplayImage.dir/main.cxx.o.requires
.PHONY : CMakeFiles/DisplayImage.dir/requires

CMakeFiles/DisplayImage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DisplayImage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DisplayImage.dir/clean

CMakeFiles/DisplayImage.dir/depend:
	cd /Users/xcbfreedom/projects/opencv_example1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xcbfreedom/projects/opencv_example1 /Users/xcbfreedom/projects/opencv_example1 /Users/xcbfreedom/projects/opencv_example1/build /Users/xcbfreedom/projects/opencv_example1/build /Users/xcbfreedom/projects/opencv_example1/build/CMakeFiles/DisplayImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DisplayImage.dir/depend

