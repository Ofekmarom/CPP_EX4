//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef TREE_ITERATOR_DFS_TPP
#define TREE_ITERATOR_DFS_TPP

#include "Tree.hpp"

//  DFS iterator for the Tree class
template<typename T, int K>
class Tree<T, K>::IteratorDFS {
public:
    // constructor that initialize the stack with the root node
    explicit IteratorDFS(Node<T>* root) {
        // initialize the stack with the root node
        if (root)
            stack.push(root);
    }

    // operator that returns the current node at the top of the stack
    Node<T>* operator*() const {
        return stack.top();
    }
    // operator that checks if two iterators are equals by comparing their stacks
    bool operator==(const IteratorDFS& other) const {
        return stack == other.stack;
    }
    // operator that checks if two iterators are not equals
    bool operator!=(const IteratorDFS& other) const {
        return !(*this == other);
    }

    // operator that take the iterator to the next node in DFS order
    IteratorDFS& operator++() {
        auto current = stack.top();// get the current node at the top of the stack
        stack.pop();// remove the current node from the stack
        // add all the children of the current node to the stack in reverse order
//we add in reverse order so the left child will be on top of the stack and will be processed next
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it)
                stack.push(*it);
        }
        // return the updated iterator
        return *this;
    }

private:
    // stack of nodes for the DFS traversal
    std::stack<Node<T>*> stack;
};

#endif // TREE_ITERATOR_DFS_TPP
