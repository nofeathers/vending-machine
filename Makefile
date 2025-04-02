#Makefile
all: vending-machine

vending-machine: main.o widget.o
	g++ -o vending-machine main.o widget.o

main.o: widget.h main.cpp
	g++ -o vending-machine main.o main.cpp

widget.o: widget.h widget.cpp
	g++ -c -o sum.o sum.cpp

clean:
	rm -f vending-machine
	rm -f *.o
