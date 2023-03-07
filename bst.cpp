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
    Node<typename K, typename D>*x=root;
    if (root == NULL) {
        return root;
    }
    while (x->k!=k && x!=nullptr){
        if (k < x->k) {
            x=x->left;
        }
        else if (key > x->k) {
            x=x->right;
        }
    }
    if (x->left == nullptr) {
        transplant(x, x->right);
    }
    else if(x->right==nullptr){
        transplant(x, x->left);
    }
    else{
        Node<typename K, typename D>*y=x->right;
        while(y->left!=nullptr){
            y=y->left
        }
        if (y->p!=x){
            transplant(y,y->right);
            y->right=x->right;
            y->right->p=y;
        }
        transplant(x,y);
        y->left=x->left;
        y->left->p=y
    }
    return;
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
    TreeNode* trim(TreeNode* root, int low, int high) 
    if (root == NULL) {
        return;
    }
    
    if (root->val < low) {
        // The current node's value is outside the range, so we remove it and trim its right subtree.
        TreeNode* right = root->right;
        delete root;
        root = right;
        trim(root, low, high);
    } else if (root->val > high) {
        // The current node's value is outside the range, so we remove it and trim its left subtree.
        TreeNode* left = root->left;
        delete root;
        root = left;
        trim(root, low, high);
    } else {
        // The current node's value is within the range, so we recursively trim its left and right subtrees.
        trim(root->left, low, high);
        trim(root->right, low, high);
    }
    
    // Recursively trim the left and right subtrees.
    root->left = trim(root->left, low, high);
    root->right = trim(root->right, low, high);
    
    return;
}

template<typename K, typename D>
void BST<K,D>::transplant(Node<K, D>* x, Node<K, D>* y){
    if (x->p==nullptr){
        root=y;
    }
    else if(x=x->p->left){
        x->p->left=y;
    }
    else{
        x->p->right=y;
    }
    if (y!=nullptr){
        y->p=x->p;
    }
}




