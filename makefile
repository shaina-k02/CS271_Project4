
main.cpp: main.o  bst.cpp usecase.cpp
	g++ main.cpp

bst.cpp: bst.o
	g++ bst.cpp

test_bst.cpp: test_bst.o bst.o
	g++ test_bst.cpp

usecase.cpp: usecase.o bst.o
	g++ usecase.cpp

test_bst_example.cpp: test_bst_example.o best.o
	g++ test_bst_example.cpp
