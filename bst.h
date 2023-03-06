//BST declaration

#include<iostream>
using namespace std;


template<typename T>
class Key
{
    T k;
};

template<typename T>
class Data
{
    T data;
};

template<typename T>
class Node
{
    public:
    Node<T> *p; 
    Node<T> *left;
    Node<T> *right;
    Key<T> k;
    Data<T> d;

};

template<typename T>
class BST
{
    Node<T> *root;
};