.PHONY: clean 
BIN=singleton test singleton1 Singleton question
all:$(BIN)

%.o:%.cpp
	g++ -c $< -o $@ -lpthread

clean :
	rm -f *.o $(BIN)
