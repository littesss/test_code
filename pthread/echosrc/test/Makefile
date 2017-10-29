.PHONY: clean all
cc=gcc
CFLAGS=-wall -g

BIN= main test

all:$(BIN)
%.o:%.cpp
	$(cc) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)
