
test.exe: program.o stack.o queue.o
	g++ program.o stack.o queue.o -o test.exe
	
program.o: program.cpp
	g++ -c -std=c++11 program.cpp
	
stack.o: stack.cpp stack.h
	g++ -c -std=c++11 stack.cpp
	
queue.o: queue.cpp queue.h
	g++ -c -std=c++11 queue.cpp
	
clean: 
	rm *.o test.exe
