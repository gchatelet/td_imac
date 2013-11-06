##############################################################
#               CMake Project Wrapper Makefile               #
############################################################## 

SHELL   := /bin/bash
RM      := rm -rf
OPTIONS := -DCMAKE_BUILD_TYPE=Release
CMAKE   := cmake $(OPTIONS)

all: ./build/Makefile
	@ $(MAKE) --silent -C build

./build/Makefile: ./build
	@ (cd build >/dev/null 2>&1 && $(CMAKE) ..)

./build:
	@ mkdir ./build

distclean:
	@- (cd build >/dev/null 2>&1 && $(CMAKE) .. >/dev/null 2>&1)
	@- $(MAKE) --silent -C build clean || true
	@- $(RM) ./build


ifeq ($(findstring distclean,$(MAKECMDGOALS)),)

    $(MAKECMDGOALS): ./build/Makefile
	@ $(MAKE) -C build $(MAKECMDGOALS)

endif
