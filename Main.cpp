//ID : 208336701
//mail : ofekmarom9@gmail.com

#include "Tree.hpp"
#include "Complex.hpp"
#include <iostream>


using namespace std;

int main() {
    // create a tree of integers
    Tree<int, 2> tree; //  binary tree of int

    // add nodes to the tree
    tree.add_root(1);
    tree.add_sub_node(1, 2);
    tree.add_sub_node(1, 3);
    tree.add_sub_node(2, 4);
    tree.add_sub_node(2, 5);
    tree.add_sub_node(3, 6);

    // The tree should look like:
    /**
     *           1
     *      /       \
     *    2          3
     *   /  \       /
     *  4    5     6
     */

    // cout << tree;

    // Print the tree (same as BFS)
//    cout << "regular tree: ";
//    for (auto node : tree) {
//        cout << (*node).value << " ";
//    }
//    cout << endl;



    // Print the tree using BFS iterator
    cout << "BFS traversal: ";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        cout << (*it)->value << " ";
    }// should print: 1, 2, 3, 4, 5, 6
    cout << endl;

    // Print the tree using DFS iterator
    cout << "DFS traversal: ";
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        cout << (*it)->value << " ";
    }// should print: 1, 2, 4, 5, 3, 6
    cout << endl;


    // Print the tree using In-Order iterator
    cout << "In-Order traversal: " ;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        cout << (*it)->value << " ";
    }// should print:  4, 2, 5, 1, 6, 3
    cout << endl;

    // Print the tree using Pre-Order iterator
    cout << "Pre-Order traversal: ";
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        cout << (*it)->value << " ";
    }// should print:  1, 2, 4, 5, 3, 6
    cout << endl;

    // Print the tree using Post-Order iterator
    cout << "Post-Order traversal: ";
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        cout << (*it)->value << " ";
    }// should print:  4, 5, 2, 6, 3, 1
    cout << endl;




    cout << "finish first tree  (binary tree of int)"<< endl;
    cout << endl;
    cout << endl;






    Tree<double, 3> tree3; //  tree with K=3

    // Add nodes to the tree
    tree3.add_root(1.5);
    tree3.add_sub_node(1.5, 12.5);
    tree3.add_sub_node(1.5, 7.6);
    tree3.add_sub_node(1.5, 4.2);
    tree3.add_sub_node(7.6, 5.3);
    tree3.add_sub_node(7.6, 2.9);

    // The tree should look like:
    /**
     *             1.5
     *        /     |     \
     *    12.5     7.6      4.2
     *            /   \
     *          5.3   2.9
     */


  //  cout << tree3;



    // Print the tree using BFS iterator
    cout << "BFS traversal: ";
    for (auto it = tree3.begin_bfs_scan(); it != tree3.end_bfs_scan(); ++it) {
        cout << (*it)->value << " ";
    }// should print: 1.5, 12.5, 7.6, 4.2, 5.3, 2.9

    cout << endl;

    // Print the tree using DFS iterator
    cout << "DFS traversal: ";
    for (auto it = tree3.begin_dfs_scan(); it != tree3.end_dfs_scan(); ++it) {
        cout << (*it)->value << " ";
    }// should print:  1.5, 12.5, 7.6, 5.3, 2.9, 4.2
    cout << endl;


    // Print the tree using In-Order iterator(should be same as DFS because k>2)
    cout << "In-Order traversal(K>2 so should be like DFS): " ;
    for (auto it = tree3.begin_in_orderK(); it != tree3.end_in_orderK(); ++it) {
        cout << (*it)->value << " ";
    }// should print:  1.5, 12.5, 7.6, 5.3, 2.9, 4.2
    cout << endl;

    // Print the tree using Pre-Order iterator
    cout << "Pre-Order traversal(K>2 so should be like DFS): " ;
    for (auto it = tree3.begin_pre_orderK(); it != tree3.end_pre_orderK(); ++it) {
        cout << (*it)->value << " ";
    }// should print:  1.5, 12.5, 7.6, 5.3, 2.9, 4.2
    cout << endl;

    // Print the tree using Post-Order iterator
    cout << "Post-Order traversal(K>2 so should be like DFS): " ;
    for (auto it = tree3.begin_post_orderK(); it != tree3.end_post_orderK(); ++it) {
        cout << (*it)->value << " ";
    }// should print:  1.5, 12.5, 7.6, 5.3, 2.9, 4.2
    cout << endl;



    cout << "finish double tree with k=3"<< endl;
    cout << endl;
    cout << endl;






    //complex binary tree
    Tree<Complex , 2> complexTree;

    // Adding nodes to the tree
    complexTree.add_root(Complex(1, 2));
    complexTree.add_sub_node(Complex(1, 2), Complex(3, 4));
    complexTree.add_sub_node(Complex(1, 2), Complex(5, 6));
    complexTree.add_sub_node(Complex(5, 6), Complex(1, 1));
    complexTree.add_sub_node(Complex(5, 6), Complex(9, 10));


    // The tree should look like:
    /**
     *            1+2i
     *        /         \
     *    3+4i           5+6i
     *                 /       \
     *               1+1i      9+10i
     */

    // display the tree using the GUI
 //   cout << complexTree;


// Print the tree using BFS iterator
    cout << "BFS traversal: ";
    for (auto it = complexTree.begin_bfs_scan(); it != complexTree.end_bfs_scan(); ++it) {
        cout << (*it)->value << ", ";
    }// should print:  1 + 2i, 3 + 4i, 5 + 6i, 1 + 1i, 9 + 10i
    cout << endl;

    // Print the tree using DFS iterator
    cout << "DFS traversal: ";
    for (auto it = complexTree.begin_dfs_scan(); it != complexTree.end_dfs_scan(); ++it) {
        cout << (*it)->value << ", ";
    }// should print:  1 + 2i, 3 + 4i, 5 + 6i, 1 + 1i, 9 + 10i
    cout << endl;


    // Print the tree using inOrder iterator
    cout << "in Order traversal: ";
    for (auto it = complexTree.begin_in_order(); it != complexTree.end_in_order(); ++it) {
        cout << (*it)->value << ", ";
    }// should print:   3 + 4i, 1 + 2i, 1 + 1i, 5 + 6i, 9 + 10i
    cout << endl;


    // Print the tree using preOrder iterator
    cout << "pre Order traversal: ";
    for (auto it = complexTree.begin_pre_order(); it != complexTree.end_pre_order(); ++it) {
        cout << (*it)->value << ", ";
    }// should print:  1 + 2i, 3 + 4i, 5 + 6i, 1 + 1i, 9 + 10i
    cout << endl;

    // Print the tree using postOrder iterator
    cout << "post Order traversal: ";
    for (auto it = complexTree.begin_post_order(); it != complexTree.end_post_order(); ++it) {
        cout << (*it)->value << ", ";
    }// should print: 3 + 4i, 1 + 1i, 9 + 10i, 5 + 6i, 1 + 2i,
    cout << endl;










    cout << "now we convert the tree to min heap" << endl;
    complexTree.myHeap();

    //we change the tree to min heap so
    // now the tree should look like:
    /**
     *            1+1i
     *        /         \
     *     1+2i           3+4i
     *                 /       \
     *              5+6i      9+10i
     */
    //cout <<complexTree;



    // Print the tree using heap iterator
    cout << "after myHeap Heap traversal: ";
    for (auto it = complexTree.begin_heap(); it != complexTree.end_heap(); ++it) {
        cout << *it << ", ";
    }// should print:   1 + 1i, 1 + 2i, 3 + 4i, 5 + 6i, 9 + 10i
    cout << endl;



    cout << "finish complex binary tree" << endl;






    return 0;
}










