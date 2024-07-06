//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef TREE_ITERATOR_PRE_ORDER_TPP
#define TREE_ITERATOR_PRE_ORDER_TPP

#include "Tree.hpp"
#include <stack>

// preOrder iterator for the Tree class
template<typename T, int K>
class Tree<T, K>::IteratorPreOrder {
public:
    // constructor that initializes the preOrder traversal from the root node
    explicit IteratorPreOrder(Node<T>* root) {
        // push the root node to the stack if it exists
        if (root)
            stack.push(root);
    }


    // operator that returns the current node at the top of the stack
    Node<T>* operator*() const {
        return stack.top();
    }
    // operator that checks if two iterators are equals by comparing their stacks
    bool operator==(const IteratorPreOrder& other) const {
        return stack == other.stack;
    }
    // operator that checks if two iterators are not equals
    bool operator!=(const IteratorPreOrder& other) const {
        return !(*this == other);
    }

    // operator to move to the next node in preOrder traversal
    IteratorPreOrder& operator++() {
        auto current = stack.top();// get the current node
        stack.pop();// remove the current node from the stack
//push the node children to the stack in reverse order for the preOrder traversal
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it)
                stack.push(*it);// push every child node to the stack
        }
        // return the updated iterator
        return *this;
    }

private:
    // stack of nodes for the preOrder traversal
    std::stack<Node<T>*> stack;
};

#endif // TREE_ITERATOR_PRE_ORDER_TPP
