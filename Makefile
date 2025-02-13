# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cidi/vscodeWorkspace/ipu_wbserver/ipu_web_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cidi/vscodeWorkspace/ipu_wbserver/ipu_web_server

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cidi/vscodeWorkspace/ipu_wbserver/ipu_web_server/CMakeFiles /home/cidi/vscodeWorkspace/ipu_wbserver/ipu_web_server//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cidi/vscodeWorkspace/ipu_wbserver/ipu_web_server/CMakeFiles 0
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
# Target rules for targets named subway_app

# Build rule for target.
subway_app: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 subway_app
.PHONY : subway_app

# fast build rule for target.
subway_app/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/build
.PHONY : subway_app/fast

src/app/base_app.o: src/app/base_app.cc.o
.PHONY : src/app/base_app.o

# target to build an object file
src/app/base_app.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/base_app.cc.o
.PHONY : src/app/base_app.cc.o

src/app/base_app.i: src/app/base_app.cc.i
.PHONY : src/app/base_app.i

# target to preprocess a source file
src/app/base_app.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/base_app.cc.i
.PHONY : src/app/base_app.cc.i

src/app/base_app.s: src/app/base_app.cc.s
.PHONY : src/app/base_app.s

# target to generate assembly for a file
src/app/base_app.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/base_app.cc.s
.PHONY : src/app/base_app.cc.s

src/app/base_db.o: src/app/base_db.cc.o
.PHONY : src/app/base_db.o

# target to build an object file
src/app/base_db.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/base_db.cc.o
.PHONY : src/app/base_db.cc.o

src/app/base_db.i: src/app/base_db.cc.i
.PHONY : src/app/base_db.i

# target to preprocess a source file
src/app/base_db.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/base_db.cc.i
.PHONY : src/app/base_db.cc.i

src/app/base_db.s: src/app/base_db.cc.s
.PHONY : src/app/base_db.s

# target to generate assembly for a file
src/app/base_db.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/base_db.cc.s
.PHONY : src/app/base_db.cc.s

src/app/im_notify_app.o: src/app/im_notify_app.cc.o
.PHONY : src/app/im_notify_app.o

# target to build an object file
src/app/im_notify_app.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/im_notify_app.cc.o
.PHONY : src/app/im_notify_app.cc.o

src/app/im_notify_app.i: src/app/im_notify_app.cc.i
.PHONY : src/app/im_notify_app.i

# target to preprocess a source file
src/app/im_notify_app.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/im_notify_app.cc.i
.PHONY : src/app/im_notify_app.cc.i

src/app/im_notify_app.s: src/app/im_notify_app.cc.s
.PHONY : src/app/im_notify_app.s

# target to generate assembly for a file
src/app/im_notify_app.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/im_notify_app.cc.s
.PHONY : src/app/im_notify_app.cc.s

src/app/panoramic_app.o: src/app/panoramic_app.cc.o
.PHONY : src/app/panoramic_app.o

# target to build an object file
src/app/panoramic_app.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/panoramic_app.cc.o
.PHONY : src/app/panoramic_app.cc.o

src/app/panoramic_app.i: src/app/panoramic_app.cc.i
.PHONY : src/app/panoramic_app.i

# target to preprocess a source file
src/app/panoramic_app.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/panoramic_app.cc.i
.PHONY : src/app/panoramic_app.cc.i

src/app/panoramic_app.s: src/app/panoramic_app.cc.s
.PHONY : src/app/panoramic_app.s

# target to generate assembly for a file
src/app/panoramic_app.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/panoramic_app.cc.s
.PHONY : src/app/panoramic_app.cc.s

src/app/remote_control_app.o: src/app/remote_control_app.cc.o
.PHONY : src/app/remote_control_app.o

# target to build an object file
src/app/remote_control_app.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/remote_control_app.cc.o
.PHONY : src/app/remote_control_app.cc.o

src/app/remote_control_app.i: src/app/remote_control_app.cc.i
.PHONY : src/app/remote_control_app.i

# target to preprocess a source file
src/app/remote_control_app.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/remote_control_app.cc.i
.PHONY : src/app/remote_control_app.cc.i

src/app/remote_control_app.s: src/app/remote_control_app.cc.s
.PHONY : src/app/remote_control_app.s

# target to generate assembly for a file
src/app/remote_control_app.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/remote_control_app.cc.s
.PHONY : src/app/remote_control_app.cc.s

src/app/remote_control_db.o: src/app/remote_control_db.cc.o
.PHONY : src/app/remote_control_db.o

# target to build an object file
src/app/remote_control_db.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/remote_control_db.cc.o
.PHONY : src/app/remote_control_db.cc.o

src/app/remote_control_db.i: src/app/remote_control_db.cc.i
.PHONY : src/app/remote_control_db.i

# target to preprocess a source file
src/app/remote_control_db.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/remote_control_db.cc.i
.PHONY : src/app/remote_control_db.cc.i

src/app/remote_control_db.s: src/app/remote_control_db.cc.s
.PHONY : src/app/remote_control_db.s

# target to generate assembly for a file
src/app/remote_control_db.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/remote_control_db.cc.s
.PHONY : src/app/remote_control_db.cc.s

src/app/subway_app.o: src/app/subway_app.cc.o
.PHONY : src/app/subway_app.o

# target to build an object file
src/app/subway_app.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/subway_app.cc.o
.PHONY : src/app/subway_app.cc.o

src/app/subway_app.i: src/app/subway_app.cc.i
.PHONY : src/app/subway_app.i

# target to preprocess a source file
src/app/subway_app.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/subway_app.cc.i
.PHONY : src/app/subway_app.cc.i

src/app/subway_app.s: src/app/subway_app.cc.s
.PHONY : src/app/subway_app.s

# target to generate assembly for a file
src/app/subway_app.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/subway_app.cc.s
.PHONY : src/app/subway_app.cc.s

src/app/svm_app.o: src/app/svm_app.cc.o
.PHONY : src/app/svm_app.o

# target to build an object file
src/app/svm_app.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/svm_app.cc.o
.PHONY : src/app/svm_app.cc.o

src/app/svm_app.i: src/app/svm_app.cc.i
.PHONY : src/app/svm_app.i

# target to preprocess a source file
src/app/svm_app.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/svm_app.cc.i
.PHONY : src/app/svm_app.cc.i

src/app/svm_app.s: src/app/svm_app.cc.s
.PHONY : src/app/svm_app.s

# target to generate assembly for a file
src/app/svm_app.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/svm_app.cc.s
.PHONY : src/app/svm_app.cc.s

src/app/svm_db.o: src/app/svm_db.cc.o
.PHONY : src/app/svm_db.o

# target to build an object file
src/app/svm_db.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/svm_db.cc.o
.PHONY : src/app/svm_db.cc.o

src/app/svm_db.i: src/app/svm_db.cc.i
.PHONY : src/app/svm_db.i

# target to preprocess a source file
src/app/svm_db.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/svm_db.cc.i
.PHONY : src/app/svm_db.cc.i

src/app/svm_db.s: src/app/svm_db.cc.s
.PHONY : src/app/svm_db.s

# target to generate assembly for a file
src/app/svm_db.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/app/svm_db.cc.s
.PHONY : src/app/svm_db.cc.s

src/buffer_parser.o: src/buffer_parser.cc.o
.PHONY : src/buffer_parser.o

# target to build an object file
src/buffer_parser.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/buffer_parser.cc.o
.PHONY : src/buffer_parser.cc.o

src/buffer_parser.i: src/buffer_parser.cc.i
.PHONY : src/buffer_parser.i

# target to preprocess a source file
src/buffer_parser.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/buffer_parser.cc.i
.PHONY : src/buffer_parser.cc.i

src/buffer_parser.s: src/buffer_parser.cc.s
.PHONY : src/buffer_parser.s

# target to generate assembly for a file
src/buffer_parser.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/buffer_parser.cc.s
.PHONY : src/buffer_parser.cc.s

src/config.o: src/config.cc.o
.PHONY : src/config.o

# target to build an object file
src/config.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/config.cc.o
.PHONY : src/config.cc.o

src/config.i: src/config.cc.i
.PHONY : src/config.i

# target to preprocess a source file
src/config.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/config.cc.i
.PHONY : src/config.cc.i

src/config.s: src/config.cc.s
.PHONY : src/config.s

# target to generate assembly for a file
src/config.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/config.cc.s
.PHONY : src/config.cc.s

src/hv_web_server.o: src/hv_web_server.cc.o
.PHONY : src/hv_web_server.o

# target to build an object file
src/hv_web_server.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/hv_web_server.cc.o
.PHONY : src/hv_web_server.cc.o

src/hv_web_server.i: src/hv_web_server.cc.i
.PHONY : src/hv_web_server.i

# target to preprocess a source file
src/hv_web_server.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/hv_web_server.cc.i
.PHONY : src/hv_web_server.cc.i

src/hv_web_server.s: src/hv_web_server.cc.s
.PHONY : src/hv_web_server.s

# target to generate assembly for a file
src/hv_web_server.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/hv_web_server.cc.s
.PHONY : src/hv_web_server.cc.s

src/main.o: src/main.cc.o
.PHONY : src/main.o

# target to build an object file
src/main.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/main.cc.o
.PHONY : src/main.cc.o

src/main.i: src/main.cc.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/main.cc.i
.PHONY : src/main.cc.i

src/main.s: src/main.cc.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/main.cc.s
.PHONY : src/main.cc.s

src/request_handler.o: src/request_handler.cc.o
.PHONY : src/request_handler.o

# target to build an object file
src/request_handler.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/request_handler.cc.o
.PHONY : src/request_handler.cc.o

src/request_handler.i: src/request_handler.cc.i
.PHONY : src/request_handler.i

# target to preprocess a source file
src/request_handler.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/request_handler.cc.i
.PHONY : src/request_handler.cc.i

src/request_handler.s: src/request_handler.cc.s
.PHONY : src/request_handler.s

# target to generate assembly for a file
src/request_handler.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/request_handler.cc.s
.PHONY : src/request_handler.cc.s

src/utils/disk.o: src/utils/disk.cc.o
.PHONY : src/utils/disk.o

# target to build an object file
src/utils/disk.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/disk.cc.o
.PHONY : src/utils/disk.cc.o

src/utils/disk.i: src/utils/disk.cc.i
.PHONY : src/utils/disk.i

# target to preprocess a source file
src/utils/disk.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/disk.cc.i
.PHONY : src/utils/disk.cc.i

src/utils/disk.s: src/utils/disk.cc.s
.PHONY : src/utils/disk.s

# target to generate assembly for a file
src/utils/disk.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/disk.cc.s
.PHONY : src/utils/disk.cc.s

src/utils/log.o: src/utils/log.cc.o
.PHONY : src/utils/log.o

# target to build an object file
src/utils/log.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/log.cc.o
.PHONY : src/utils/log.cc.o

src/utils/log.i: src/utils/log.cc.i
.PHONY : src/utils/log.i

# target to preprocess a source file
src/utils/log.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/log.cc.i
.PHONY : src/utils/log.cc.i

src/utils/log.s: src/utils/log.cc.s
.PHONY : src/utils/log.s

# target to generate assembly for a file
src/utils/log.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/log.cc.s
.PHONY : src/utils/log.cc.s

src/utils/utils.o: src/utils/utils.cc.o
.PHONY : src/utils/utils.o

# target to build an object file
src/utils/utils.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/utils.cc.o
.PHONY : src/utils/utils.cc.o

src/utils/utils.i: src/utils/utils.cc.i
.PHONY : src/utils/utils.i

# target to preprocess a source file
src/utils/utils.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/utils.cc.i
.PHONY : src/utils/utils.cc.i

src/utils/utils.s: src/utils/utils.cc.s
.PHONY : src/utils/utils.s

# target to generate assembly for a file
src/utils/utils.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/utils.cc.s
.PHONY : src/utils/utils.cc.s

src/utils/vpsystem.o: src/utils/vpsystem.cc.o
.PHONY : src/utils/vpsystem.o

# target to build an object file
src/utils/vpsystem.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/vpsystem.cc.o
.PHONY : src/utils/vpsystem.cc.o

src/utils/vpsystem.i: src/utils/vpsystem.cc.i
.PHONY : src/utils/vpsystem.i

# target to preprocess a source file
src/utils/vpsystem.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/vpsystem.cc.i
.PHONY : src/utils/vpsystem.cc.i

src/utils/vpsystem.s: src/utils/vpsystem.cc.s
.PHONY : src/utils/vpsystem.s

# target to generate assembly for a file
src/utils/vpsystem.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/utils/vpsystem.cc.s
.PHONY : src/utils/vpsystem.cc.s

src/web_server.o: src/web_server.cc.o
.PHONY : src/web_server.o

# target to build an object file
src/web_server.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/web_server.cc.o
.PHONY : src/web_server.cc.o

src/web_server.i: src/web_server.cc.i
.PHONY : src/web_server.i

# target to preprocess a source file
src/web_server.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/web_server.cc.i
.PHONY : src/web_server.cc.i

src/web_server.s: src/web_server.cc.s
.PHONY : src/web_server.s

# target to generate assembly for a file
src/web_server.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/subway_app.dir/build.make CMakeFiles/subway_app.dir/src/web_server.cc.s
.PHONY : src/web_server.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... subway_app"
	@echo "... src/app/base_app.o"
	@echo "... src/app/base_app.i"
	@echo "... src/app/base_app.s"
	@echo "... src/app/base_db.o"
	@echo "... src/app/base_db.i"
	@echo "... src/app/base_db.s"
	@echo "... src/app/im_notify_app.o"
	@echo "... src/app/im_notify_app.i"
	@echo "... src/app/im_notify_app.s"
	@echo "... src/app/panoramic_app.o"
	@echo "... src/app/panoramic_app.i"
	@echo "... src/app/panoramic_app.s"
	@echo "... src/app/remote_control_app.o"
	@echo "... src/app/remote_control_app.i"
	@echo "... src/app/remote_control_app.s"
	@echo "... src/app/remote_control_db.o"
	@echo "... src/app/remote_control_db.i"
	@echo "... src/app/remote_control_db.s"
	@echo "... src/app/subway_app.o"
	@echo "... src/app/subway_app.i"
	@echo "... src/app/subway_app.s"
	@echo "... src/app/svm_app.o"
	@echo "... src/app/svm_app.i"
	@echo "... src/app/svm_app.s"
	@echo "... src/app/svm_db.o"
	@echo "... src/app/svm_db.i"
	@echo "... src/app/svm_db.s"
	@echo "... src/buffer_parser.o"
	@echo "... src/buffer_parser.i"
	@echo "... src/buffer_parser.s"
	@echo "... src/config.o"
	@echo "... src/config.i"
	@echo "... src/config.s"
	@echo "... src/hv_web_server.o"
	@echo "... src/hv_web_server.i"
	@echo "... src/hv_web_server.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/request_handler.o"
	@echo "... src/request_handler.i"
	@echo "... src/request_handler.s"
	@echo "... src/utils/disk.o"
	@echo "... src/utils/disk.i"
	@echo "... src/utils/disk.s"
	@echo "... src/utils/log.o"
	@echo "... src/utils/log.i"
	@echo "... src/utils/log.s"
	@echo "... src/utils/utils.o"
	@echo "... src/utils/utils.i"
	@echo "... src/utils/utils.s"
	@echo "... src/utils/vpsystem.o"
	@echo "... src/utils/vpsystem.i"
	@echo "... src/utils/vpsystem.s"
	@echo "... src/web_server.o"
	@echo "... src/web_server.i"
	@echo "... src/web_server.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

