.PHONY: all clean
cxx=g++
CFLAGS= -g

BIN=fork fork1

all:$(BIN)
%.o:%.cpp
	$(cxx)  $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN) *.o
