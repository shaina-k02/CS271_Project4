
#include <iostream>
#include "bst.h"
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
    return;
}

int main() {
    //test_to_string();
    test_empty();
    return 0;
}
