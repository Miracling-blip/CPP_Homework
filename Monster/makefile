m.exe:main.o Trainer.o Team.o Monster.o
	g++ -g main.o Trainer.o Team.o Monster.o -o m.exe

main.o:main.C Trainer.h Monster.h Team.h
	g++ -g -c main.C -o main.o

Trainer.o:Trainer.C Trainer.h Monster.h Team.h
	g++ -g -c Trainer.C -o Trainer.o

Monster.o:Monster.C Monster.h
	g++ -g -c Monster.C -o Monster.o

Team.o:Monster.h Team.h Team.C
	g++ -g -c Team.C -o Team.o

clean:
	rm -r *.o *.exe
