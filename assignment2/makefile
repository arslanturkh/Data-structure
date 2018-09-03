test.exe: program.o Player.o SimpleList.o 
	g++ program.o  SimpleList.o  Player.o -o test.exe
	
program.o: program.cpp
	g++ -c -std=c++11 program.cpp
	
SimpleList.o: SimpleList.cpp SimpleList.h
	g++ -c -std=c++11 SimpleList.cpp

Player.o: Player.cpp Player.h
	g++ -c -std=c++11 Player.cpp

	
clean: 
	rm *.o test.exe
