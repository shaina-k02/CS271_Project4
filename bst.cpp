#include <iostream>
#include "bst.h"
using namespace std;


template<typename K, typename D>
bool BST<K,D>::empty(){

}

template<typename K, typename D>
void BST<K,D>::insert(D d, K k){
    if (key == NULL) {
        Node* newNode = new Node;
        newNode->d = d;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (d < k->d) {
        k->left = insert(k->left, d);
    } else {
        root->right = insert(k->right, d);
    }
    return k;
}

template<typename K, typename D>
D BST<K,D>::get(K k){

}

template<typename K, typename D>
void BST<K,D>::remove(K k){

}

template<typename K, typename D>
D BST<K,D>::max_data(){

}

template<typename K, typename D>
K BST<K,D>::max_key(){

}

template<typename K, typename D>
D BST<K,D>::min_data(){

}

template<typename K, typename D>
K BST<K,D>::min_key(){

}

template<typename K, typename D>
K BST<K,D>::successor(K k){

}

template<typename K, typename D>
string BST<K,D>::in_order(){

}

template<typename K, typename D>
void BST<K,D>::trim(K low, K high){

}



