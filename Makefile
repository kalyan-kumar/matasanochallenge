all: hextob64

hextob64: hextob64.cpp util.cpp util.h
	g++ hextob64.cpp util.cpp -o hextob64

clean:
	rm hextob64