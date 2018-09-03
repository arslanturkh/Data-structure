
test.exe: program.o Set.o
	g++ program.o Set.o -o test.exe
	
program.o: program.cpp
	g++ -c -std=c++11 program.cpp
	
Set.o: Set.cpp Set.h
	g++ -c -std=c++11 Set.cpp
	

	
clean: 
	rm *.o test.exe
