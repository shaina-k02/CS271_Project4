

#include <iostream>
#include "usecase.cpp"
using namespace std;

int main(){
    BST<string,int>* bst = create_bst();
    string s= convert(bst);
    return 0;
}