//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef TREEITERATORHEAP_TPP
#define TREEITERATORHEAP_TPP

#include "Tree.hpp"
#include <memory>
#include <queue>

// heap iterator for the Tree class (work like BFS)
template<typename T, int K>
class Tree<T, K>::IteratorHeap {
public:
    // constructor that initialize the queue with the root node
    explicit IteratorHeap(Node<T>* root) {
        if (root) {
            node_queue.push(root);
        }
    }
    // operator that returns the value of the current node at the front of the queue
    T& operator*() {
        return node_queue.front()->value;
    }

    // operator that checks if two iterators are equals by comparing their queues
    bool operator==(const IteratorHeap& other) const {
        return node_queue == other.node_queue;
    }
    // operator that checks if two iterators are not equals
    bool operator!=(const IteratorHeap& other) const {
        return !(*this == other);
    }


    // operator that take the iterator to the next node in the heap order
    IteratorHeap& operator++() {
        if (!node_queue.empty()) {
            auto current = node_queue.front();// get the current node at the front of the queue
            node_queue.pop();// remove the current node from the queue
            // add all the children of the current node to the queue
            for (const auto& child : current->children) {
                node_queue.push(child);
            }
        }
        // return the updated iterator
        return *this;
    }

private:
    // queue of nodes for the heap traversal
    std::queue<Node<T>*> node_queue;
};

#endif // TREEITERATORHEAP_TPP