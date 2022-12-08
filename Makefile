output: main.o

main.o:
	g++ Functions.cpp Functions.h Subject.cpp Subject.h project.cpp -o main.o

clean:
	rm *.o
