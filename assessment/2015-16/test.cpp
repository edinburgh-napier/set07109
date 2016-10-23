#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "binary_tree.h"

using namespace std;

int main(int argc, char **argv)
{
    // Test 1 - basic constructor
    binary_tree *tree = new binary_tree();
    string str = tree->inorder();
    if (str != string(""))
        cerr << "ERROR - test 1 failed (basic constructor)" << endl;
    else
        cout << "Test 1 passed (basic constructor)" << endl;
    delete tree;

    // Test 2 - single value constructor
    tree = new binary_tree(50);
    str = tree->inorder();
    if (str != string("50"))
        cerr << "ERROR - test 2 failed (single value constructor)" << endl;
    else
        cout << "Test 2 passed (single value constructor)" << endl;
    delete tree;

    // Test 3 - vector constructor
    tree = new binary_tree(vector<int>{10, 5, 12, 15, 8});
    str = tree->inorder();
    if (str != string("5 8 10 12 15"))
        cerr << "ERROR - test 3 failed (vector constructor)" << endl;
    else
        cout << "Test 3 passed (vector constructor)" << endl;

    // Test 4 - copy constructor part 1
    binary_tree *tree2 = new binary_tree(*tree);
    str = tree2->inorder();
    if (str != string("5 8 10 12 15"))
        cerr << "ERROR - test 4 failed (copy constructor part 1)" << endl;
    else
        cout << "Test 4 passed (copy constructor part 1)" << endl;

    // Test 5 - copy constructor part 2
    tree2->remove(10);
    if (tree->inorder() == tree2->inorder())
        cerr << "ERROR - test 5 failed (copy constructor part 2 - deep copy check)" << endl;
    else
        cout << "Test 5 passed (copy construcotr part 2 - deep copy check)" << endl;
    delete tree2;
    tree2 = nullptr;

    // Test 6 - insertion check
    tree->insert(15);
    tree->insert(25);
    tree->insert(4);
    tree->insert(5);
    str = tree->inorder();
    if (str != string("4 5 8 10 12 15 25"))
        cerr << "ERROR - test 6 failed (insertion check)" << endl;
    else
        cout << "Test 6 passed (insertion check)" << endl;
    
    // Test 7 - exists check
    if (tree->exists(4) && tree->exists(15) && !tree->exists(100) && !tree->exists(1))
        cout << "Test 7 passed (exists check)" << endl;
    else
        cerr << "ERROR - test 7 failed (exists check)" << endl;
    delete tree;

    // Test 8 - remove check part 1
    tree = new binary_tree(vector<int>{10, 5, 12, 3, 4, 7, 15, 11});
    tree->remove(8);
    str = tree->inorder();
    if (str != string("3 4 5 7 10 11 12 15"))
        cerr << "ERROR - test 8 failed (remove check part 1 - value not in tree)" << endl;
    else
        cout << "Test 8 passed (remove check part 1 - value not in tree)" << endl;

    // Test 9 - remove check part 2
    tree->remove(15);
    str = tree->inorder();
    if (str != string("3 4 5 7 10 11 12"))
        cerr << "ERROR - test 9 failed (remove check part 2 - leaf value)" << endl;
    else
        cout << "Test 9 passed (remove check part 2 - leaf value)" << endl;

    // Test 10 - remove check part 3
    tree->remove(12);
    str = tree->inorder();
    if (str != string("3 4 5 7 10 11"))
        cerr << "ERROR - test 10 failed (remove check part 3 - right branch null)" << endl;
    else
        cout << "Test 10 passed (remove check part 3 - right branch null)" << endl;

    // Test 11 - remove check part 4
    tree->remove(4);
    str = tree->inorder();
    if (str != string("3 5 7 10 11"))
        cerr << "ERROR - test 11 failed (remove check part 4 - left branch null)" << endl;
    else
        cout << "Test 11 passed (remove check part 4 - left branch null)" << endl;

    // Test 12 - remove check part 5
    tree->remove(10);
    str = tree->inorder();
    if (str != string("3 5 7 11"))
        cerr << "ERROR - test 12 failed (remove check part 5 - no branches null)" << endl;
    else
        cout << "Test 12 passed (remove check part 5 - no branches null)" << endl;
    delete tree;

    // Test 13 - preorder print
    tree = new binary_tree(vector<int>{11, 5, 3, 7});
    str = tree->preorder();
    if (str != string("11 5 3 7"))
        cerr << "ERROR - test 13 failed (pre-order print)" << endl;
    else
        cout << "Test 13 passed (pre-order print)" << endl;

    // Test 14 - postorder print
    str = tree->postorder();
    if (str != string("3 7 5 11"))
        cerr << "ERROR - test 14 failed (post-order print)" << endl;
    else
        cout << "Test 14 passed (post-order print)" << endl;

    // Test 15 - assignment operator
    binary_tree temp = *tree;
    temp.insert(12);
    str = temp.inorder();
    if (str != string("3 5 7 11 12") && temp.inorder() != tree->inorder())
        cerr << "ERROR - test 15 failed (assignment operator)" << endl;
    else
        cout << "Test 15 passed (assignment operator)" << endl;

    // Test 16 - comparison operator
    tree2 = new binary_tree(vector<int>{11, 5, 3, 7, 12});
    if (*tree2 != temp || *tree2 == *tree || *tree == temp)
        cerr << "ERROR - test 16 failed (comparison operator)" << endl;
    else
        cout << "Test 16 passed (comparison operator)" << endl;
    delete tree2;

    // Test 17 - add operator
    *tree = *tree + 10;
    *tree = *tree + 4;
    *tree = *tree + 11;
    str = tree->inorder();
    if (str != string("3 4 5 7 10 11"))
        cerr << "ERROR - test 17 failed (addition operator)" << endl;
    else
        cout << "Test 17 passed (addition operator)" << endl;

    // Test 18 - subtraction operator
    *tree = *tree - 10;
    *tree = *tree - 11;
    *tree = *tree - 15;
    str = tree->inorder();
    if (str != string("3 4 5 7"))
        cerr << "ERROR - test 18 failed (subtraction operator)" << endl;
    else
        cout << "Test 18 passed (subtraction operator)" << endl;

    // Test 19 - output operator
    stringstream stream;
    stream << *tree;
    if (stream.str() != string("3 4 5 7"))
        cerr << "ERROR - test 19 failed (output operator)" << endl;
    else
        cout << "Test 19 passed (output operator)" << endl;
    delete tree;

    // Test 20 - input operator
    stream << " 10" << " 11" << " 10" << " 2" << endl;
    tree = new binary_tree();
    stream >> *tree;
    if (tree->inorder() != string("2 3 4 5 7 10 11"))
        cerr << "ERROR - test 20 failed (input operator)" << endl;
    else
        cout << "Test 20 passed (input operator)" << endl;
    delete tree;

    return 0;
}