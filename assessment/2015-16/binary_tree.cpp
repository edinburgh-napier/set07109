#include "binary_tree.h"

// Creates an empty binary tree
binary_tree::binary_tree()
{
}

// Creates a binary tree with an initial value to store
binary_tree::binary_tree(int value)
{
}

// Creates a binary tree from a collection of existing values
binary_tree::binary_tree(const std::vector<int> &values)
{

}

// Creates a binary tree by copying an existing tree
binary_tree::binary_tree(const binary_tree &rhs)
{

}

// Destroys (cleans up) the tree
binary_tree::~binary_tree()
{
    
}


// Adds a value to the tree
void binary_tree::insert(int value)
{
}

// Removes a value from the tree
void binary_tree::remove(int value)
{

}

// Checks if a value is in the tree
bool binary_tree::exists(int value) const
{
    return true;
}

// Prints the tree to standard out in numerical order
std::string binary_tree::inorder() const
{
    return std::string("");
}

// Prints the tree in pre-order
std::string binary_tree::preorder() const
{
    return std::string("");
}

// Prints the tree in post-order
std::string binary_tree::postorder() const
{
    return std::string("");
}

// Copy assignment operator
binary_tree& binary_tree::operator=(const binary_tree &other)
{
    return binary_tree();
}

// Checks if two trees are equal
bool binary_tree::operator==(const binary_tree &other) const
{
    return true;
}

// Checks if two trees are not equal
bool binary_tree::operator!=(const binary_tree &other) const
{
    return true;
}

// Inserts a new value into the binary tree
binary_tree& binary_tree::operator+(int value)
{
    return binary_tree();
}

// Removes a value from the binary tree
binary_tree& binary_tree::operator-(int value)
{
    return binary_tree();
}

// Reads in values from an input stream into the tree
std::istream& operator>>(std::istream &in, binary_tree &value)
{
    return in;
}

// Writes the values, in-order, to an output stream
std::ostream& operator<<(std::ostream &out, const binary_tree &value)
{
    return out;
}