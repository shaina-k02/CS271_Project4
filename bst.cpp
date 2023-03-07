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

}

template<typename K, typename D>
K BST<K,D>::max_key(){
if (root == NULL) {
        return -1; // or some other value to indicate an empty tree
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

template<typename K, typename D>
D BST<K,D>::min_data(){

}

template<typename K, typename D>
K BST<K,D>::min_key(){
     if (root == NULL) {
        return -1; // or some other value to indicate an empty tree
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;

}

template<typename K, typename D>
K BST<K,D>::successor(K k){

}

template<typename K, typename D>
string BST<K,D>::in_order(){
    if (root == NULL) {
        return;
    }
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

template<typename K, typename D>
void BST<K,D>::trim(K low, K high){

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
    
    return root;
}

}



