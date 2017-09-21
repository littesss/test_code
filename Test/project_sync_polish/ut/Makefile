.PHONY: all
.PHONY: clean
.PHONY: lib

bins = $(shell files=""; for file in `ls *.cpp *.c 2>/dev/null`; do obj=`echo $$file |sed -r 's/(.*)\.cpp/\1/g'`; files="$$files $$obj"; done ; echo $$files)

CXXFLAGS = -g -I ../lib ../lib/*.o

all: lib $(bins)

lib:
	cd ../lib;  $(MAKE)

clean:
	rm -rf $(bins)


