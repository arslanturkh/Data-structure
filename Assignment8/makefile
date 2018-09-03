
test.exe: Program.o Job.o PQueue.o
	g++ Program.o Job.o PQueue.o -o test.exe
	
Program.o: Program.cpp
	g++ -c -std=c++11 Program.cpp
	
Job.o: Job.cpp Job.h
	g++ -c -std=c++11 Job.cpp
	
PQueue.o: PQueue.cpp PQueue.h
	g++ -c -std=c++11 PQueue.cpp
	
clean: 
	rm *.o test.exe
