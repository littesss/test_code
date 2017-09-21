objs = main.o print.o

CXXFLAGS = -g 

test: $(objs)
	g++ -o test  objs

objs: 
	g++ -c main.cpp print.h

clean:
	rm -rf  $(objs) 
