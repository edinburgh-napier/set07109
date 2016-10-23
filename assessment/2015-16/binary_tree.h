#pragma once

#include <vector>
#include <iostream>
#include <string>

// Node of the tree
struct node
{
    // Data stored in this node of the tree
    int data;
    // The left branch of the tree
    node *left = nullptr;
    // The right branch of the tree
    node *right = nullptr;
};

class binary_tree
{
private:
    // Pointer to head of the tree
    node *tree = nullptr;
public:
    // Creates an empty binary tree
    binary_tree();
    // Creates a binary tree with an inital value to store
    binary_tree(int value);
    // Creates a binary tree from a collection of existing values
    binary_tree(const std::vector<int> &values);
    // Creates a binary tree by copying an existing tree
    binary_tree(const binary_tree &rhs);
    // Destroys (cleans up) the tree
    ~binary_tree();
    // Adds a value to the tree
    void insert(int value);
    // Removes a value from the tree
    void remove(int value);
    // Checks if a value is in the tree
    bool exists(int value) const;
    // Creates a string representing the tree in numerical order
    std::string inorder() const;
    // Creates a string representing the tree in pre-order
    std::string preorder() const;
    // Creates a string representing the tree in post-order
    std::string postorder() const;
    // Copy assignment operator
    binary_tree& operator=(const binary_tree &other);
    // Checks if two trees are equal
    bool operator==(const binary_tree &other) const;
    // Checks if two trees are not equal
    bool operator!=(const binary_tree &other) const;
    // Inserts a new value into the binary tree
    binary_tree& operator+(int value);
    // Removes a value from the binary tree
    binary_tree& operator-(int value);
    // Reads in values from an input stream into the tree
    friend std::istream& operator>>(std::istream &in, binary_tree &value);
    // Writes the values, in-order, to an output stream
    friend std::ostream& operator<<(std::ostream &out, const binary_tree &value);
};