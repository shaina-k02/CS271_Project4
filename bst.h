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

    bool empty();
    void insert(D d, K k);
    D get(K k);
    void remove(K k);
    D max_data();
    K max_key();
    D min_data();
    K min_key();
    K successor(K k);
    string in_order();
    void trim(low,high);

};

template<typename K, typename D>
class BST
{
    Node<K, D> *root;
};