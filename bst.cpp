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

    Node* newNode = new Node;
    newNode->d = d;
    newNode->left = nullptr;
    newNode->right = nullptr;
    Node<typename K, typename D>*x=root;
    Node<typename K, typename D>*y=nullptr;
    while (x!=nullptr){
        y=x;
        if (k<x->k){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    newNode->p=y;
    if (y==nullptr){
        root=newNode;
    }
    else if (k<y->k){
        y->left=newNode;
    }
    else{
        y->right=newNode;
    }
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
if (root == NULL) {
        return root;
    }
    if (k < root->d) {
        root->left = remove(root->left, k);
    } else if (key > root->d) {
        root->right = remove(root->right, k);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->d = temp->data;
        root->right = remove(root->right, temp->d);
    }
    return root;
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
    Node<typename K, typename D>*x=root;
    if (x == nullptr) {
        return -1; // or some other value to indicate an empty tree
    }
    while (x->right != nullptr) {
        x = x->right;
    }
    return x->k;
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
    Node<typename K, typename D>*x=root;
    if (x == nullptr) {
        return -1; // or some other value to indicate an empty tree
    }
    while (x->left != nullptr) {
        x = x->left;
    }
    return x->k;

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
        x=x->right;
        while(x->left!=nullptr){
            x=x->left
        }
        return x->k;
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
    string res="";
    if (root == NULL) {
        return;
    }
    res+=root->left.in_order();
    res+= std::to_string(root->d);
    res+=root->right.in_order();
}

template<typename K, typename D>
void BST<K,D>::trim(K low, K high){

// Trims the BST such that all nodes with values outside the range [low, high] are removed.
 TreeNode* trim(TreeNode* root, int low, int high) {
    if (root == NULL) {
        return NULL;
    }
    
    // If the current node's value is outside the range, remove it and return the trimmed subtree.
    if (root->val < low) {
        return trim(root->right, low, high);
    } else if (root->val > high) {
        return trim(root->left, low, high);
    }
    
    // Recursively trim the left and right subtrees.
    root->left = trim(root->left, low, high);
    root->right = trim(root->right, low, high);
    
    return;
}

}



