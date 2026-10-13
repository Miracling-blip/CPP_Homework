v.exe:Vector.o main.o
	g++ main.o Vector.o -o v.exe

main.o:main.cpp Vector.hpp
	g++ -c main.cpp -o main.o

Vector.o:Vector.cpp Vector.hpp
	g++ -c Vector.cpp -o Vector.o

clean:
	rm *.o *.exe
