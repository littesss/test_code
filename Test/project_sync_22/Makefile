.PHONY: clean
.PHONY: all
.PHONY: lasync
.PHONY: libs
.PHONY: uts

CXXFLAGS = -g -I lib  lib/*.o

all: lasync

lasync: libs uts main.cpp
	$(CXX)  $(CXXFLAGS) main.cpp -o $@

uts:
	cd ut; $(MAKE)

libs:
	cd lib; $(MAKE)


clean: 
	rm -rf  lasync
	cd  ut; $(MAKE) clean
	cd  lib; $(MAKE) clean


