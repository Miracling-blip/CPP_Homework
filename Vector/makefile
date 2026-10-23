v.exe:main.o Vector.o
	g++ -g main.o Vector.o -o v.exe

main.o:Vector.hpp main.cpp
	g++ -c -g main.cpp -o main.o

Vector.o:Vector.hpp Vector.cpp
	g++ -c -g Vector.cpp -o Vector.o

clean:
	rm *.o *.exe
