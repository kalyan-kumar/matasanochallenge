all: hextob64 fixedxor

hextob64: hextob64.cpp util.cpp util.h
	g++ hextob64.cpp util.cpp -o hextob64

fixedxor: fixedxor.cpp util.cpp util.h
	g++ fixedxor.cpp util.cpp -o fixedxor

clean:
	rm hextob64 fixedxor