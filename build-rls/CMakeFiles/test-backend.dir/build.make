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
CMAKE_SOURCE_DIR = /home/brunoaquino/repos/braq-server/portal-backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brunoaquino/repos/braq-server/portal-backend/build-rls

# Include any dependencies generated for this target.
include CMakeFiles/test-backend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test-backend.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test-backend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test-backend.dir/flags.make

CMakeFiles/test-backend.dir/tests/test_backend.cpp.o: CMakeFiles/test-backend.dir/flags.make
CMakeFiles/test-backend.dir/tests/test_backend.cpp.o: ../tests/test_backend.cpp
CMakeFiles/test-backend.dir/tests/test_backend.cpp.o: CMakeFiles/test-backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/brunoaquino/repos/braq-server/portal-backend/build-rls/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test-backend.dir/tests/test_backend.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test-backend.dir/tests/test_backend.cpp.o -MF CMakeFiles/test-backend.dir/tests/test_backend.cpp.o.d -o CMakeFiles/test-backend.dir/tests/test_backend.cpp.o -c /home/brunoaquino/repos/braq-server/portal-backend/tests/test_backend.cpp

CMakeFiles/test-backend.dir/tests/test_backend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-backend.dir/tests/test_backend.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/brunoaquino/repos/braq-server/portal-backend/tests/test_backend.cpp > CMakeFiles/test-backend.dir/tests/test_backend.cpp.i

CMakeFiles/test-backend.dir/tests/test_backend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-backend.dir/tests/test_backend.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/brunoaquino/repos/braq-server/portal-backend/tests/test_backend.cpp -o CMakeFiles/test-backend.dir/tests/test_backend.cpp.s

CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o: CMakeFiles/test-backend.dir/flags.make
CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o: ../src/bkend-sql.cpp
CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o: CMakeFiles/test-backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/brunoaquino/repos/braq-server/portal-backend/build-rls/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o -MF CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o.d -o CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o -c /home/brunoaquino/repos/braq-server/portal-backend/src/bkend-sql.cpp

CMakeFiles/test-backend.dir/src/bkend-sql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-backend.dir/src/bkend-sql.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/brunoaquino/repos/braq-server/portal-backend/src/bkend-sql.cpp > CMakeFiles/test-backend.dir/src/bkend-sql.cpp.i

CMakeFiles/test-backend.dir/src/bkend-sql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-backend.dir/src/bkend-sql.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/brunoaquino/repos/braq-server/portal-backend/src/bkend-sql.cpp -o CMakeFiles/test-backend.dir/src/bkend-sql.cpp.s

# Object files for target test-backend
test__backend_OBJECTS = \
"CMakeFiles/test-backend.dir/tests/test_backend.cpp.o" \
"CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o"

# External object files for target test-backend
test__backend_EXTERNAL_OBJECTS =

test-backend: CMakeFiles/test-backend.dir/tests/test_backend.cpp.o
test-backend: CMakeFiles/test-backend.dir/src/bkend-sql.cpp.o
test-backend: CMakeFiles/test-backend.dir/build.make
test-backend: /opt/vcpkg/installed/x64-linux/lib/libpq.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/libfmt.a
test-backend: ../external/lib/libboost_date_time.a
test-backend: ../external/lib/libboost_system.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/manual-link/libgtest_main.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/libpgport.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/libpgcommon.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/libssl.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/libcrypto.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/libboost_system.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/libboost_date_time.a
test-backend: /opt/vcpkg/installed/x64-linux/lib/libgtest.a
test-backend: CMakeFiles/test-backend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/brunoaquino/repos/braq-server/portal-backend/build-rls/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test-backend"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-backend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test-backend.dir/build: test-backend
.PHONY : CMakeFiles/test-backend.dir/build

CMakeFiles/test-backend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test-backend.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test-backend.dir/clean

CMakeFiles/test-backend.dir/depend:
	cd /home/brunoaquino/repos/braq-server/portal-backend/build-rls && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brunoaquino/repos/braq-server/portal-backend /home/brunoaquino/repos/braq-server/portal-backend /home/brunoaquino/repos/braq-server/portal-backend/build-rls /home/brunoaquino/repos/braq-server/portal-backend/build-rls /home/brunoaquino/repos/braq-server/portal-backend/build-rls/CMakeFiles/test-backend.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test-backend.dir/depend
