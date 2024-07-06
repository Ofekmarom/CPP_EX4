//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef TREE_ITERATOR_POSTORDER_TPP
#define TREE_ITERATOR_POSTORDER_TPP

#include "Tree.hpp"
#include <stack>

// postOrder iterator for the Tree class
template<typename T, int K>
class Tree<T, K>::IteratorPostOrder {
public:
//constructor initializes the stack for postOrder traversal from the root node
    explicit IteratorPostOrder(Node<T>* root) {
        traverse_post_order(root);
    }

    // operator that returns the current node at the top of the stack
    Node<T>* operator*() const {
        return stack.top();
    }

    // operator that checks if two iterators are equals by comparing their stacks
    bool operator==(const IteratorPostOrder& other) const {
        return stack == other.stack;
    }
    // operator that checks if two iterators are not equals
    bool operator!=(const IteratorPostOrder& other) const {
        return !(*this == other);
    }

    // operator to move to the next node in postOrder traversal
    IteratorPostOrder& operator++() {
        if (!stack.empty()) {
            stack.pop();
        }
        // return the updated iterator
        return *this;
    }

private:
    // stack of nodes for the postOrder traversal
    std::stack<Node<T>*> stack;

// function to init the stack for postOrder traversal
    void traverse_post_order(Node<T>* node) {
        // return if node is null
        if (!node) return;

        // push the root node to a temp stack
        std::stack<Node<T>*> tempStack;
        tempStack.push(node);

        while (!tempStack.empty()) {
            auto current = tempStack.top();
            tempStack.pop();// remove the top node from the temp stack

            // push current node to the main stack
            stack.push(current);

//push the current node children in reverse order for postOrder traversal
            for (size_t i = 0; i < current->children.size(); i++) {
                tempStack.push(current->children[i]);
            }
        }
    }
};

#endif // TREE_ITERATOR_POSTORDER_TPP
