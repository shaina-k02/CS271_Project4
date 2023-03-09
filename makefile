all: test usecase

test: test_bst_example.o
	g++ -o test test_bst_example.o

usecase: usecase.o main.o
	g++ -o usecase main.o

bst.o: bst.cpp
	g++ -c bst.cpp

usecase.o: usecase.cpp bst.o
	g++ -c usecase.cpp

test_bst_example.o: test_bst_example.cpp bst.cpp
	g++ -c test_bst_example.cpp

main.o: main.cpp usecase.cpp
	g++ -c main.cpp

clean:
	rm -f all *.o
