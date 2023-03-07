#include <iostream>
#include "bst.h"
using namespace std;


template<typename K, typename D>
bool BST<K,D>::empty(){
    if (root==nullptr){
        return true;
    }
    return false;
}

template<typename K, typename D>
void BST<K,D>::insert(D d, K k){

}

template<typename K, typename D>
D BST<K,D>::get(K key){
    Node<typename K, typename D>*x=root;
    while ((x->k!=key)&& (x!=nullptr)){
        if (key<x->k){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    if (x==nullptr){
        return;
    }
    return x->d;
}

template<typename K, typename D>
void BST<K,D>::remove(K k){

}

template<typename K, typename D>
D BST<K,D>::max_data(){
    Node<typename K, typename D>*x=root;
    if (x==nullptr){
        return;
    }
    while (x->right != nullptr){
        x=x->right;
    }
    return x->d;
}

template<typename K, typename D>
K BST<K,D>::max_key(){

}

template<typename K, typename D>
D BST<K,D>::min_data(){
    Node<typename K, typename D>*x=root;
    if (x==nullptr){
        return;
    }
    while (x->left != nullptr){
        x=x->left;
    }
    return x->d;
}

template<typename K, typename D>
K BST<K,D>::min_key(){

}

template<typename K, typename D>
K BST<K,D>::successor(K k){
    Node<typename K, typename D>*x=root;
    while ((x->k!=key)&& (x!=nullptr)){
        if (key<x->k){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    if (x==nullptr){
        return;
    }
    if (x->right!=nullptr){
        //see if theres a way to do the minkey thing here, probs not though
    }
    Node<typename K, typename D>*y=x->p;
    while (y!=nullptr && x==y->right){
        x=y;
        y=y.p;
    }
    return y->k;
}

template<typename K, typename D>
string BST<K,D>::in_order(){

}

template<typename K, typename D>
void BST<K,D>::trim(K low, K high){
    // working on this still 
}



