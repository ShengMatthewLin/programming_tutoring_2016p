all: main

main: Config.o EuropeanOption.o main.o SecurityFactory.o
	g++ -o main Config.o EuropeanOption.o main.o SecurityFactory.o

%.o: %.cpp
	g++ -Wall -O2 -std=c++11 -I. -c -o $@ $<

clean:
	rm -f *.o
	rm main
