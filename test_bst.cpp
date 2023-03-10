
#include <iostream>
#include "bst.cpp"
using namespace std;


/*
//Is empty tests

TEST(BSTEmptyTest, EmptyTree) {
    BST<int, std::string> tree;
    ASSERT_TRUE(tree.empty());
}

TEST(BSTEmptyTest, NonEmptyTree) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    ASSERT_FALSE(tree.empty());
}
//Insert Test
TEST(BSTInsertTest, InsertIntoEmptyTree) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    ASSERT_EQ(tree.get("five"), 5);
}

TEST(BSTInsertTest, InsertLeft) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(3, "three");
    ASSERT_EQ(tree.get("three"), 3);
}

TEST(BSTInsertTest, InsertRight) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(7, "seven");
    ASSERT_EQ(tree.get("seven"), 7);
}

TEST(BSTInsertTest, InsertDuplicateKey) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    ASSERT_THROW(tree.insert(3, "five"), std::invalid_argument);
}

//Remove test
TEST(BSTRemoveTest, RemoveFromEmptyTree) {
    BST<int, std::string> tree;
    ASSERT_NO_THROW(tree.remove("five"));
}

TEST(BSTRemoveTest, RemoveNonexistentKey) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(10, "ten");
    ASSERT_NO_THROW(tree.remove("twenty"));
}

TEST(BSTRemoveTest, RemoveKeyWithNoChildren) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.remove("five");
    ASSERT_THROW(tree.get("five"), std::invalid_argument);
}

TEST(BSTRemoveTest, RemoveKeyWithOneChild) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(3, "three");
    tree.remove("three");
    ASSERT_THROW(tree.get("three"), std::invalid_argument);
}

TEST(BSTRemoveTest, RemoveKeyWithTwoChildren) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(3, "three");
    tree.insert(7, "seven");
    tree.remove("five");
    ASSERT_THROW(tree.get("five"), std::invalid_argument);
}

//Get test
TEST(BSTGetTest, EmptyTree) {
    BST<int, std::string> tree;
    ASSERT_THROW(tree.get("foo"), std::out_of_range);
}

TEST(BSTGetTest, NonEmptyTreeWithMissingKey) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(3, "three");
    tree.insert(7, "seven");
    ASSERT_THROW(tree.get("foo"), std::out_of_range);
}

TEST(BSTGetTest, NonEmptyTreeWithExistingKey) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(3, "three");
    tree.insert(7, "seven");
    ASSERT_EQ(tree.get(3), "three");
    ASSERT_EQ(tree.get(5), "five");
    ASSERT_EQ(tree.get(7), "seven");
}


//max key test
TEST(BSTMaxKeyTest, MaxKeyInEmptyTree) {
    BST<int, std::string> tree;
    ASSERT_EQ(tree.max_key(), "");
}

TEST(BSTMaxKeyTest, MaxKeyInTreeWithOneNode) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    ASSERT_EQ(tree.max_key(), "five");
}

TEST(BSTMaxKeyTest, MaxKeyInTreeWithMultipleNodes) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(3, "three");
    tree.insert(7, "seven");
    ASSERT_EQ(tree.max_key(), "seven");
}

//Min key test
TEST(BSTMinKeyTest, MinKeyInEmptyTree) {
    BST<int, std::string> tree;
    ASSERT_EQ(tree.min_key(), "");
}

TEST(BSTMinKeyTest, MinKeyInTreeWithOneNode) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    ASSERT_EQ(tree.min_key(), "five");
}

TEST(BSTMinKeyTest, MinKeyInTreeWithMultipleNodes) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(3, "three");
    tree.insert(7, "seven");
    ASSERT_EQ(tree.min_key(), "three");
}


//in_order test
TEST(BSTInOrderTest, InOrderOfEmptyTree) {
    BST<int, std::string> tree;
    ASSERT_EQ(tree.in_order(), "");
}

TEST(BSTInOrderTest, InOrderOfTreeWithOneNode) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    ASSERT_EQ(tree.in_order(), "five");
}

TEST(BSTInOrderTest, InOrderOfTreeWithMultipleNodes) {
    BST<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(3, "three");
    tree.insert(7, "seven");
    ASSERT_EQ(tree.in_order(), "threesevenfive");
}

//to_string test
#include <sstream>
#include <cassert>

void test_to_string() {
    // Create a new BST and insert some nodes
    BST<int, string> bst;
    bst.insert(5, "five");
    bst.insert(3, "three");
    bst.insert(7, "seven");
    bst.insert(1, "one");
    bst.insert(4, "four");

    // Call the to_string method and compare with expected output
    stringstream expected;
    expected << "5 (five) 3 (three) 1 (one) 4 (four) 7 (seven) ";

    assert(bst.to_string() == expected.str());
}
*/

void test_empty(){
    BST<int, int> bst;
    if (!bst.empty()){
        cout<<"identified empty as not empty"<<endl;
    }
    bst.insert(7,2);
    bst.insert(3,4);
    if (bst.empty()){
        cout<<"identified not empty as empty"<<endl;
    }

    return;
}

void test_insert(){
    BST<int, int> bst;
        bst.insert(2, 1);
        string bst_str = bst.to_string();
        if(bst_str != "1") {
            cout << "Incorrect result of inserting (2, 1). Expected 1 but got : " << bst_str << endl;
        }
        bst.insert(3,5);
        bst_str = bst.to_string();
        if(bst_str != "1 5") {
            cout << "Incorrect result of inserting (3, 5). Expected 1 5 but got : " << bst_str << endl;
        }
        bst.insert(4,2);
        bst.insert(7,8);
        bst_str = bst.to_string();
        if(bst_str != "1 5 2 8") {
            cout << "Incorrect result of inserting multiple nodes. Expected 1 5 2 8 but got : " << bst_str << endl;
        }
}

void test_get(){
    BST<int, int> bst;
        int val = bst.get(0);
        if(val!=1) {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert(2 ,1);
        val = bst.get(1);
        if(val != 2) {
            cout << "Incorrect get result. Expected 2 but got : " << val << endl;
        }
}

void test_remove(){
  
    BST<int, int> bst;
    bst.insert(5,7);
    bst.insert(2,3);
    bst.insert(3,5);
    bst.remove(3);
    string bst_str = bst.to_string();
    if(bst_str != "7 5") {
        cout << "Incorrect result of removing (3). Expected 7 5 but got : " << bst_str << endl;
    }
    bst.remove(7);
    bst_str=bst.to_string();
    if(bst_str != "5") {
        cout << "Incorrect result of removing (7). Expected 5 but got : " << bst_str << endl;
    }
}

void test_max_data(){
    BST<int, int> bst;
    bst.insert(5,7);
    bst.insert(2,3);
    bst.insert(3,5);
    int max=bst.max_data();
    if (max!=5){
        cout<< "Incorrect result of max data. Expected 5 but got : "<<std::to_string(max)<<endl;
    }
}

void test_max_key(){
    BST<int, int> bst;
    bst.insert(5,7);
    bst.insert(2,3);
    bst.insert(3,5);
    int max=bst.max_key();
    if (max!=7){
        cout<< "Incorrect result of max key. Expected 7 but got : "<<std::to_string(max)<<endl;
    }
}

void test_min_data(){
    BST<int, int> bst;
    bst.insert(5,7);
    bst.insert(2,3);
    bst.insert(3,5);
    int min=bst.min_data();
    if (min!=2){
        cout<< "Incorrect result of min data. Expected 2 but got : "<<std::to_string(min)<<endl;
    }
}

void test_min_key(){
    BST<int, int> bst;
    bst.insert(5,7);
    bst.insert(2,3);
    bst.insert(3,5);
    int min=bst.min_key();
    if (min!=3){
        cout<< "Incorrect result of min key. Expected 3 but got : "<<std::to_string(min)<<endl;
    }
}

void test_successor(){
    BST<int, int> bst;
    bst.insert(5,7);
    bst.insert(2,3);
    bst.insert(3,5);
    int suc= bst.successor(5);
    if (suc!=7){
        cout<< "Incorrect result of successor. Expected 7 but got : "<<std::to_string(suc)<<endl;
    }
    suc= bst.successor(7);
    if (suc!=5){
        cout<< "Incorrect result of successor. Expected 5 but got : "<<std::to_string(suc)<<endl;
    }
}

int main() {
    //test_to_string();
    test_empty(); cout<<"tested empty"<<endl;
    test_insert(); cout<<"tested insert"<<endl;
    test_get(); cout<<"tested get"<<endl;
    test_remove(); cout<<"tested remove"<<endl;
    test_max_data(); cout<<"tested max data"<<endl;
    test_max_key(); cout<<"tested max key"<<endl;
    test_min_data(); cout<<"tested min data"<<endl;
    test_min_key(); cout<<"tested min key"<<endl;
    test_successor(); cout<<"tested successor"<<endl;
    return 0;

}
