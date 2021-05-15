# Name of target executable.
BIN := prog.exe

# Project tree configuration.
SRC := src
COPY := copy

# Build configuration.
CC := g++
CPPFLAGS := -Iinclude
LDLIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
REDIST_FILES := SDL2.dll SDL2_image.dll
REDIST_FILES += libjpeg-8.dll libpng16-16.dll libtiff-5.dll libwebp-7.dll
REDIST_FILES += zlib1.dll libdeflate.dll liblzma-5.dll libzstd.dll

# Debug build configuration.
CXXFLAGS_DEBUG := -std=c++17 -g -O0 -Wall
LDFLAGS_DEBUG :=

# Release build configuration.
CXXFLAGS_RELEASE := -std=c++17 -DNDEBUG -O2 -fdata-sections -ffunction-sections -flto
LDFLAGS_RELEASE := -Wl,-O,--gc-sections,--strip-all -Wl,-subsystem,windows

# Statically link against the standard library
# I don't like it either, but for now, it's better than distributing the dlls
LDLIBS += -Wl,-Bstatic -lstdc++ -lgcc -lgcc_eh -lpthread -Wl,-Bdynamic

ifeq ($(filter MINGW32 MINGW64,$(MSYSTEM)),)
$(error Please build with either MinGW32 or MinGW64 MSYS2 subsystems)
endif

.PHONY: all debug release build clean
all: debug

debug: export BUILD_TYPE := debug
debug: export CXXFLAGS := $(CXXFLAGS_DEBUG)
debug: export LDFLAGS := $(LDFLAGS_DEBUG)

release: export BUILD_TYPE := release
release: export CXXFLAGS := $(CXXFLAGS_RELEASE)
release: export LDFLAGS := $(LDFLAGS_RELEASE)

debug release build: export SUBPATH = $(MSYSTEM_CARCH)/$(BUILD_TYPE)
debug release build:
	@echo "Building \"$(BUILD_TYPE)\" for $(MSYSTEM_CARCH)"
	@$(MAKE) build-target --no-print-directory

clean:
	rm -rf {bin,bld}

ifdef SUBPATH
SRC_DIRS := / $(shell (cd $(SRC); find * -type d 2> /dev/null))
SRC_FILES := $(shell (cd $(SRC); find * -type f 2> /dev/null))
OBJECTS := $(SRC_FILES:%.cpp=bld/$(SUBPATH)/obj/%.o)
BUILD_TARGET_DIRS := $(SRC_DIRS:%=bld/$(SUBPATH)/obj/%) $(SRC_DIRS:%=bld/$(SUBPATH)/dep/%)
OK := \033[0;32m[OK]\033[0m

ifeq ($(OBJECTS),)
$(error No source files to build)
endif

ifeq ($(BUILD_TYPE),)
$(error Must define $$(BUILD_TYPE) if performing a custom build)
endif

.PHONY: build-target
build-target: bin/$(SUBPATH)/$(BIN) bld/$(SUBPATH)/copy bld/$(SUBPATH)/redist

# Link target executable.
bin/$(SUBPATH)/$(BIN): $(OBJECTS) | bin/$(SUBPATH)
	@$(CC) $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) -o $@
	@echo -e "$(@F) $(OK)"

# Compile objects and generate dependency files.
bld/$(SUBPATH)/obj/%.o: $(SRC)/%.cpp | $(BUILD_TARGET_DIRS)
	@$(CC) -MD -MP -MF bld/$(SUBPATH)/dep/$*.d -c $< $(CXXFLAGS) $(CPPFLAGS) -o $@
	@echo -e "$*.o $(OK)"

# Copy assets and redists to bin directory if they exist.
bld/$(SUBPATH)/copy: $(shell find $(COPY) 2> /dev/null) | bin/$(SUBPATH)
	@if [[ "$(shell ls -A $(COPY))" ]]; then \
		rsync -rptgo $(COPY)/* $|/; \
		echo -e "Copy assets $(OK)"; \
	fi
	@touch $@

bld/$(SUBPATH)/redist: $(REDIST_FILES:%=$(MSYSTEM_PREFIX)/bin/%) | bin/$(SUBPATH)
	@if [[ "$^" ]]; then \
		rsync -ptgo $^ $|/; \
		echo -e "Copy redistributable files $(OK)"; \
	fi
	@touch $@

# Only call mkdir once for each directory.
bin/$(SUBPATH) $(BUILD_TARGET_DIRS):
	@mkdir -p $@

# Include dependency files if they exist.
-include $(SRC_FILES:%.cpp=bld/$(SUBPATH)/dep/%.d)
endif
