#include <iostream>
#include "bst.h"
using namespace std;

//empty()
//pre-condition: Initialized an instance of class BST
//post-condition: returns true or false
template<typename D, typename K>
bool BST<D,K>::empty(){
    if (root == nullptr){
        return true;
    }
    return false;
}

//insert()
//pre-condition: none
//post-condition: bst with the new key-value added while maintaining BST property
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

//get()
//pre-condition: The presence of the key-data in question in the BST
//post-condition: Returns the data of the corresponding key in the BST
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

//remove()
//pre-condition: a non-empty BST
//post-condition: BST without the key-data in question while maintaining the BST property
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

//max_data()
//pre-condition:a non-empty BST
//post-condition: return the data associated with the max key
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

//max_key()
//pre-condition: a non-empty BST
//post-condition: Returns largest key in BST
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

//min_data()
//pre-condition: non-empty BST
//post-condition: return the data associated with the min key in the tree bst
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
//pre-condition: non-empty BST
//post-condition: Returns smallest key in BST
template<typename D, typename K>
K BST<D,K>::min_key(){
    Node<D,K>*x=root;
    if (x == nullptr) {
        K empty;
        return empty; // or some other value to indicate an empty tree
    }
    while (x->left != nullptr) {
        x = x->left;
    }
    return x->k.k;

}

//Successor()

//pre-condition: 
//1.	Node k must not be the largest node in the BST. In other words, k must have a node with a larger key value in the BST.
//2.	If node k has a right child, then the successor of k is the node with the minimum key value in the right subtree of k.
//3.	If node k does not have a right child, then the successor of k is the lowest ancestor of k whose left child is also an ancestor of k.

//post-condition:
//1.	If the node k has a right child, the successor node is the node with the minimum key value in the right subtree of k.
//2.	If the node k does not have a right child, the successor node is the lowest ancestor of k whose left child is also an ancestor of k.
//3.	If the node k is the largest node in the BST, then the successor function returns NULL.
//4.	If the successor function is called on a node k that is not present in the BST, then the successor function returns NULL.
//5.	The successor node y is guaranteed to have a key value greater than the key value of the given node k.
//6.	If there are multiple nodes with the same minimum key value in the right subtree of k, then the successor node is the one that is closest to the node k in terms of its position in the tree (i.e., it has the shortest path to k).

template<typename D, typename K>
K BST<D,K>::successor(K k){
    Node<D,K>*x=root;
      if (x==nullptr){
        K empty;
        return empty;
    }
    while ((x->k.k!=k)&& (x!=nullptr)){
        if (k<x->k.k){
            x=x->left;
        }
        else{
            x=x->right;
        }
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
        if (y->p!=nullptr){
            y=y->p;
        }
    }
    return y->k.k;
}

//in_order()
//pre-condition: 
//1.	The BST is not empty.
//2.	Each node in the BST must have a key value.
//3.	The key values in the BST must satisfy the binary search tree property, which is that the key value of each node must be greater than all key values in its left subtree, and less than all key values in its right subtree.

//post-condition:
//1.	The nodes of the BST are visited in ascending order of their key values.
//2.	All nodes of the BST are visited exactly once.
//3.	The in_order() function does not modify the BST.
//4.	The in_order() function returns the nodes of the BST in ascending order of their key values.
//5.	If the BST is empty, the in_order() function does not perform any traversal and returns an empty result.
//6.	The in_order() function can be used to perform operations on each node of the BST, such as printing the key values or updating the node data, while visiting the nodes in ascending order of their key values.

template<typename D, typename K>
string BST<D,K>::in_order(){
    string res="";
    if (root == NULL) {
        return res;
    }
    Node<D,K>* x=root;
    while (x->left!=nullptr){
        if(x->left!=nullptr){
            res+=std::to_string(x->left->k.k);
        }
        if(x->right!=nullptr){
            res+=std::to_string(x->right->k.k);
        }
        x=x->left;
    }
    res+= std::to_string(root->k.k);
    while (x->right!=nullptr){
        if(x->left!=nullptr){
            res+=std::to_string(x->left->k.k);
        }
        res+=std::to_string(x->right->k.k);

        x=x->right;
    }
    return res;
}

//trim()
//pre-condition: 
//1.	The BST is not empty.
//2.	The key values in the BST must satisfy the binary search tree property, which is that the key value of each node must be greater than all key values in its left subtree, and less than all key values in its right subtree.
//3.	The high value must be greater than or equal to the low value.
//4.	The BST may contain nodes with key values outside the range [low, high], inclusive

//post-condition:
template<typename D, typename K>
void BST<D,K>::trim(K low, K high){

    // Trims the BST such that all nodes with values outside the range [low, high] are removed.
    if (root == nullptr) {
        return;
    }
    Node<D,K>* x=root;
    while (x!=nullptr){
        if (x->k.k <low ||x->k.k > high ){
            remove(x->k.k);
        }
        x=x->left;

    }
    while (x!=nullptr){
        if (x->k.k <low ||x->k.k > high ){
            remove(x->k.k);
        }
        x=x->right;

    }
    
    return;
}
//pre-condition:
//post-condition:
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

//pre-condition:
//post-condition:
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
