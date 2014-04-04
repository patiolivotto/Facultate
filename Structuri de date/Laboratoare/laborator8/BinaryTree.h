/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * Modificari: Adrian Bogatu
  * Echipa SD, 2013
  *
  * License: LGPL
  */

#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include<iostream>

using namespace std;

template <typename T>
class BinaryTree
{
private:
    BinaryTree<T> *leftNode;
    BinaryTree<T> *rightNode;

    T *pData;

public:
    BinaryTree() {
		};
    ~BinaryTree();

    // Inspect if the current node has data.
    bool hasData(){
		};

    // Set data for current node.
    void setData(T data){
		};

    // Set left subtree.
    void setLeftSubtree(BinaryTree<T> *node);

    // Get the left subtree.
    BinaryTree<T> *getLeftSubtree();

    // Set right subtree.
    void setRightSubtree(BinaryTree<T> *node);

    // Get the right subtree.
    BinaryTree<T> *getRightSubtree();

    // Insert data recursively randomly where it is possible.
    void insert(T data);

    // Insert data into left subtree.
    void insertLeft(T data);

    // Insert data into right subtree.
    void insertRight(T data);

    // Display the binary tree to output.
    void displayTree(int indentLevel);
};

// Debugging purposes for ExpressionNode
ostream& operator<<(ostream &out, ExpressionNode& node)
{
    out << node.value;
    return out;
}

#endif // __BINARY_TREE_H
