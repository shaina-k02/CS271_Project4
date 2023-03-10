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
        if (k < x->k.k){
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
    else if (k < y->k.k){
        y->left = newNode;
        //cout<<"inseting to the left"<<endl;
    }
    else{
        y->right = newNode;
        //cout<<"Inserting to the right"<<endl;
    }
}

template<typename D, typename K>
D BST<D,K>::get(K key){
    Node<D,K>*x = root;
    while (x != nullptr && x->k.k != key){
        if (key < x->k.k){
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
    return x->d.d;
}

template<typename D, typename K>
void BST<D,K>::remove(K k){
    Node<D, K>*x = root;
    if (root == NULL) {
        return;
    }
    while (x != nullptr && x->k.k != k){
        if (k < x->k.k) {
            x = x->left;
        }
        else if (k > x->k.k) {
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
    return x->d.d;
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
    return x->k.k;
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
       return x->d.d;
}

template<typename D, typename K>
K BST<D,K>::min_key(){
    Node<D,K>*x=root;
    if (x == nullptr) {
        Key<K> empty;
        return empty; // or some other value to indicate an empty tree
    }
    while (x->left != nullptr) {
        x = x->left;
    }
    return x->k.k;

}

template<typename D, typename K>
K BST<D,K>::successor(K k){
    Node<D,K>*x=root;
    while ((x->k.k!=k)&& (x!=nullptr)){
        if (k<x->k.k){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    if (x==nullptr){
        Key<K> empty;
        return empty;
    }
    if (x->right!=nullptr){
        x=x->right;
        while(x->left!=nullptr){
            x=x->left;
        }
        return x->k.k;
    }
    Node<D,K>*y=x->p;
    while (y!=nullptr && x==y->right){
        x=y;
        y=y->p;
    }
    return y->k.k;
}

template<typename D, typename K>
string BST<D,K>::in_order(){
    string res="";
    if (root == NULL) {
        return res;
    }
    res+=root->left.in_order();
    res+= std::to_string(root->d.d);
    res+=root->right.in_order();
    return res;
}

template<typename D, typename K>
void BST<D,K>::trim(K low, K high){

    // Trims the BST such that all nodes with values outside the range [low, high] are removed.
    /*TreeNode* trim(TreeNode* root, int low, int high) 
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
    */
    return;
}

template<typename D, typename K>
void BST<D,K>::transplant(Node<D, K>* x, Node<D, K>* y){
    if (x->p==nullptr){
        root=y;
    }
    else if(x==x->p->left){
        x->p->left=y;
    }
    else{
        x->p->right=y;
    }
    if (y!=nullptr){
        y->p=x->p;
    }
}

template<typename D, typename K>
string BST<D,K>::to_string() {
        string bststr;
        Node<D,K>*x=root;
        while (x!=nullptr){
            bststr+= std::to_string(x->k.k);
            if(x==root){
                if (root->left==nullptr){
                    x=root->right;
                }
                else{
                    x=root->left;
                }
                
            }
            else if(x==x->p->left){
                x=x->p->right;
            }
            else if(x==x->p->right){
                if (x->p->left!=nullptr){
                x=x->p->left->left;
                }
                else{
                    x=x->left;
                }
            }
            if (x!=nullptr)
            {
               bststr+=" ";
            }
            
        }
        return bststr;
    }
