//BST declaration

#include<iostream>
using namespace std;


template<typename K>
class Key
{
    K k;

    Key(){
        k=0;
    }

    Key(K key){
        k=key;
    }
};

template<typename D>
class Data
{
    D d;

    Data(){
        d=0;
    }

    Data(D data){
        d=Data;
    }
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

    Node(){
        p=nullptr;
        left=nullptr;
        right=nullptr;
    }

    Node(K key, D data){
        p=nullptr;
        left=nullptr;
        right=nullptr;
        k= Key(key);
        d= Data(data);
    }

};

template<typename K, typename D>
class BST
{
    Node<K, D> *root;

    BST(){
        root=nullptr
    }

    

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
    void trim(K low, K high);
};