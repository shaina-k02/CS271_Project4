all: test usecase

test: test_bst.o
	g++ -o test test_bst.o

usecase: usecase.o main.o
	g++ -o usecase main.o

bst.o: bst.cpp
	g++ -c bst.cpp

usecase.o: usecase.cpp bst.o
	g++ -c usecase.cpp

test_bst.o: test_bst.cpp bst.cpp
	g++ -c test_bst.cpp

main.o: main.cpp usecase.cpp
	g++ -c main.cpp

clean:
	rm -f all *.o
