//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

// Tree class template definition
template<typename T, int K = 2>  // default K = 2 for binary tree
class Tree {
public:
    // iterator classes declaration
    class IteratorPreOrder;
    class IteratorPostOrder;
    class IteratorInOrder;
    class IteratorBFS;
    class IteratorDFS;
    class IteratorHeap;

    // Tree methods
    Tree(); // constructor
    ~Tree(); // destructor
    void add_root(const T& value);// add root to the tree
    void add_sub_node(const T& parent_value, const T& child_value);// add a sub node under a specified parent node
    void myHeap();// transform the tree into a min heap (only for binary trees)


    // iterator methods
        //the regular iterator of a tree (BFS)
    IteratorBFS begin();
    IteratorBFS end();

        //iterators for binary trees (k=2)
    IteratorPreOrder begin_pre_order();
    IteratorPreOrder end_pre_order();
    IteratorPostOrder begin_post_order();
    IteratorPostOrder end_post_order();
    IteratorInOrder begin_in_order();
    IteratorInOrder end_in_order();
    IteratorHeap begin_heap();
    IteratorHeap end_heap();

        //BFS and DFS iterators
    IteratorBFS begin_bfs_scan();
    IteratorBFS end_bfs_scan();
    IteratorDFS begin_dfs_scan();
    IteratorDFS end_dfs_scan();


        //iterators for not binary trees (k>2)
    IteratorDFS begin_pre_orderK();
    IteratorDFS end_pre_orderK();
    IteratorDFS begin_post_orderK();
    IteratorDFS end_post_orderK();
    IteratorDFS begin_in_orderK();
    IteratorDFS end_in_orderK();


    // friend output operator<<
    template<typename U, int L>
    friend std::ostream& operator<<(std::ostream& os, Tree<U, L>& tree);








private:
    Node<T>* root; // pointer to the root node of the tree

    // method to show the tree GUI using sfml
    void displayGui();
    // method to draw the tree in the GUI
    void drawTree(RenderWindow &screen,  Font &font, Node<T> *node, float x, float y, float spaceBetweenNodes);

    void delete_tree(Node<T>* node);//delete the entire tree
};



// include the template definitions
#include "Tree.tpp"

#endif // TREE_HPP
