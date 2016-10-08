all: main

main: EuropeanOption.o main.o
	g++ -o main EuropeanOption.o main.o

%.o: %.cpp
	g++ -Wall -O2 -std=c++11 -I. -c -o $@ $<

clean:
	rm -f *.o
	rm main
