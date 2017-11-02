.PHONY: clean 
BIN=singleton test singleton1 Singleton question t ttt
all:$(BIN)

%.o:%.cpp
	g++ -c $< -o $@ -lpthread

clean :
	rm -f *.o $(BIN)
