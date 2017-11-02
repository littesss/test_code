.PHONY: clean all
cc=gcc
CFLAGS=-wall -g

BIN=ser cli

all:$(BIN)
%.o:%.cpp %.h
	$(cc) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)
