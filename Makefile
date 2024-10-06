out: clean compile execute

compile: main.cpp ProductData.cpp DataAnalysis.cpp
	g++ -g -Wall -std=c++14 main.cpp ProductData.cpp DataAnalysis.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe