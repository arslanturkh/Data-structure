
ass3.exe: testerAss3.o SimpleListL.o
	g++ testerAss3.o SimpleListL.o -o ass3.exe
	
testerAss3.o: testerAss3.cpp
	g++ -c -std=c++11 testerAss3.cpp
	
SimpleListL.o: SimpleListL.cpp SimpleListL.h
	g++ -c -std=c++11 SimpleListL.cpp
	
clean: 
	rm *.o ass3.exe
