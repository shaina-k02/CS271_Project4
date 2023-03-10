//BST declaration

#include<iostream>
using namespace std;


template<typename K>
class Key
{
    K k;

    Key(){
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
    }

    Data(D data){
        d=data;
    }
};

template<typename D, typename K>
class Node
{
    public:
    Node<D, K> *p; 
    Node<D, K> *left;
    Node<D, K> *right;
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
        k= Key<K>(key);
        d= Data<D>(data);
    }

};

template<typename D, typename K>
class BST
{
    Node<D, K> *root;


    public:
    BST(){
        root=nullptr;
    }
    ~BST(){
       Node<D,K>*x=root;
       Node<D,K>*r=x->right;
       Node<D,K>*l=x->left;
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
    void transplant(Node<K, D>* x, Node<K, D>* y);//used for remove
    string to_string();
};