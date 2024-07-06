//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef TREE_ITERATOR_BFS_TPP
#define TREE_ITERATOR_BFS_TPP

#include "Tree.hpp"

// BFS iterator for the Tree class
template<typename T, int K>
class Tree<T, K>::IteratorBFS {
public:
    // constructor that initialize the queue with the root node
    explicit IteratorBFS(Node<T>* root) {
        // initialize the queue with the root node
        if (root)
            queue.push(root);
    }


    // operator that returns the current node at the front of the queue
    Node<T>* operator*() const {
        return queue.front();
    }
    // operator that checks if two iterators are equals by comparing their queues
    bool operator==(const IteratorBFS& other) const {
        return queue == other.queue;
    }
    // operator that checks if two iterators are not equals
    bool operator!=(const IteratorBFS& other) const {
        return !(*this == other);
    }

    // operator that take the iterator to the next node in BFS order
    IteratorBFS& operator++() {
        auto current = queue.front(); // get the current node at the front of the queue
        queue.pop(); // remove the current node from the queue
        // add all the children of the current node to the queue
        for (const auto& child : current->children) {
            if (child)
                queue.push(child);
        }
        // return the updated iterator
        return *this;
    }

private:
    // queue of nodes for the BFS traversal
    std::queue<Node<T>*> queue;
};

#endif // TREE_ITERATOR_BFS_TPP
