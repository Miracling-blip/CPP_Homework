B.exe:BankUI.o BankAccount.o main.o
	g++ BankUI.o BankAccount.o main.o -o B.exe

main.o:BankUI.h BankUI.C main.C
	g++ -c main.C -o main.o

BankUI.o:BankAccount.h BankAccount.C BankUI.h BankUI.C
	g++ -c BankUI.C -o BankUI.o

BankAccount.o:BankAccount.h BankAccount.C
	g++ -c BankAccount.C -o BankAccount.o

clean:
	rm -rf *.exe *.o
