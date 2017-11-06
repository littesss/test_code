.PHONY: clean all
cc=gcc
CFLAGS=-g

BIN=ser cli gethostname

all:$(BIN)
%.o:%.c %.h
	$(cc) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)
