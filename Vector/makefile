v.exe:main.o Vector.hpp
	g++ -g main.o -o v.exe

main.o:Vector.hpp main.cpp
	g++ -c -g main.cpp -o main.o

clean:
	rm *.o *.exe
