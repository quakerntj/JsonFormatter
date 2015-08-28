all: ftt uftt

clean:
	rm ftt uftt

ftt: main.cpp
	g++ -std=c++11 -g -o $@ $^
	
uftt: main2.cpp
	g++ -std=c++11 -g -o $@ $^
