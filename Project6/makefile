m.exe:main.o BigInt.o BigInt.h
	g++ -g main.o BigInt.o -o m.exe

main.o:BigInt.h main.C
	g++ -g -c main.C -o main.o

BigInt.o:BigInt.C BigInt.h
	g++ -g -c BigInt.C -o BigInt.o

clean:
	rm *.o *.exe
