#include <iostream>
#include "bst.h"
using namespace std;


template<typename D, typename K>
bool BST<D,K>::empty(){
    if (root == nullptr){
        return true;
    }
    return false;
}

template<typename D, typename K>
void BST<D,K>::insert(D d, K k){

    Node<D,K>* newNode = new Node<D,K>;
    newNode->d = d;
    newNode->k = k;
    newNode->left = nullptr;
    newNode->right = nullptr;
    Node<D,K>*x = root;
    Node<D,K>*y = nullptr;
    while (x != nullptr){
        y = x;
        if (k < x->k){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    newNode->p = y;
    if (y == nullptr){
        root = newNode;
    }
    else if (k < y->k){
        y->left = newNode;
    }
    else{
        y->right = newNode;
    }
}

template<typename D, typename K>
D BST<D,K>::get(K key){
    Node<D,K>*x = root;
    while (x != nullptr && x->k != key){
        if (key < x->k){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    if (x == nullptr){
        D empty;
        return empty;
    }
    return x->d;
}

template<typename D, typename K>
void BST<D,K>::remove(K k){
    Node<D, K>*x = root;
    if (root == NULL) {
        return;
    }
    while (x != nullptr && x->k != k){
        if (k < x->k) {
            x = x->left;
        }
        else if (k > x->k) {
            x = x->right;
        }
    }
    if (x == nullptr){
        return;
    }
    if (x->left == nullptr) {
        transplant(x, x->right);
    }
    else if(x->right == nullptr){
        transplant(x, x->left);
    }
    else{
        Node<D, K>*y = x->right;
        while (y->left != nullptr){
            y = y->left;
        }
        if (y->p != x){
            transplant(y, y->right);
            y->right = x->right;
            y->right->p = y;
        }
        transplant(x, y);
        y->left = x->left;
        y->left->p = y;
    }
}

template<typename D, typename K>
D BST<D,K>::max_data(){
    Node<D,K>*x = root;
    if (x == nullptr){
        D empty;
        return empty;
    }
    while (x->right != nullptr){
        x = x->right;
    }
    return x->d;
}

template<typename D, typename K>
K BST<D,K>::max_key(){
    Node<D,K>*x = root;
    if (x == nullptr) {
        K empty;
        return empty;// or some other value to indicate an empty tree
    }
    while (x->right != nullptr) {
        x = x->right;
    }
    return x->k;
}

template<typename D, typename K>
D BST<D,K>::min_data(){
    Node<D,K>*x = root;
    if (x == nullptr){
        D empty;
        return empty;
    }
    while (x->left != nullptr){
        x = x->left;
    }
   
