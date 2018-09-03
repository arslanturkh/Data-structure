
test.exe: program.o 
	g++ program.o -o test.exe
	
program.o: program.cpp
	g++ -c -std=c++11 program.cpp
	
clean: 
	rm *.o test.exe
