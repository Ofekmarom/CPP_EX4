//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef TREE_ITERATOR_IN_ORDER_TPP
#define TREE_ITERATOR_IN_ORDER_TPP

#include "Tree.hpp"
#include <stack>

// inOrder iterator for the Tree class
template<typename T, int K>
class Tree<T, K>::IteratorInOrder {
public:

//constructor that initializes the stack with the most left path of the tree starting from the root
    explicit IteratorInOrder(Node<T>* root) : current(root) {
// traverse to the most left node and push each node in the path to the stack
        while (current) {
            stack.push(current);
            if (!current->children.empty())
                current = current->children[0];
            else
                break;
        }
        // set currrent to nullptr to handle the end case and avoid problems
        current = nullptr;
    }


    // operator that returns the current node at the top of the stack
    Node<T>* operator*() const {
        return stack.top();
    }

    // operator that checks if two iterators are equals by comparing their stacks
    bool operator==(const IteratorInOrder& other) const {
        return stack == other.stack;
    }
    // operator that checks if two iterators are not equals
    bool operator!=(const IteratorInOrder& other) const {
        return !(*this == other);
    }

    // operator to move to the next node in inOrder traversal
    IteratorInOrder& operator++() {
        auto node = stack.top(); // get the current node
        stack.pop(); // remove the current node from the stack
//if the node has a right child, traverse to the most left node of the right subtree
        if (!node->children.empty() && node->children.size() > 1) {
            node = node->children[1];
            while (node) {
                // push each node onto the stack for inOrder traversal
                stack.push(node);
                if (!node->children.empty())
                    // move to the left child
                    node = node->children[0];
                else
                    // no more children, end traversal
                    break;
            }
        }
        // return the updated iterator
        return *this;
    }

private:
    // stack of nodes for the inOrder traversal
    std::stack<Node<T>*> stack;
    // pointer to the current node being processed
    Node<T>* current;
};

#endif // TREE_ITERATOR_IN_ORDER_TPP
