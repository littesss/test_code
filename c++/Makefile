CFLAGS = -g
CXX = g++
SRC = $(wildcard *.cpp)
TARGET = $(patsubst %.cpp, %, $(SRC))

#.PHONY:all clean

all: $(TARGET)

%:%.cpp
	$(CXX) $(CFLAGS) $^ -o $@

.PHONY:clean
clean:
	$(RM) $(TARGET)
