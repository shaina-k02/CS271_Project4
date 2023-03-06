//BST declaration

#include<iostream>
using namespace std;


template<typename K>
class Key
{
    K k;
};

template<typename D>
class Data
{
    D data;
};

template<typename K, typename D>
class Node
{
    public:
    Node<K, D> *p; 
    Node<K, D> *left;
    Node<K, D> *right;
    Key<K> k;
    Data<D> d;

};

template<typename K, typename D>
class BST
{
    Node<K, D> *root;
};