all: test usecase

test: test_bst.o
	g++ -o test test_bst.o

usecase: usecase.o main.o bst.o
	g++ -o usecase main.o bst.o usecase.o

bst.o: bst.cpp bst.h
	g++ -c bst.cpp

usecase.o: usecase.cpp bst.h
	g++ -c usecase.cpp

test_bst.o: test_bst.cpp bst.h
	g++ -c test_bst.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o
