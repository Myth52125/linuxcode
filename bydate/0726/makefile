test:test.o CliSock.o SerSock.o
	g++ -o test test.o CliSock.o SerSock.o
test.o:test.cpp
	g++ -c -std=c++11 test.cpp
CliSock.o:CliSock.cpp CliSock.h
	g++ -c -std=c++11 CliSock.cpp CliSock.h
SerSock.o:SerSock.h SerSock.cpp
	g++ -c -std=c++11 SerSock.cpp SerSock.h
clean:
	rm test test.o CliSock.o SerSock.o
