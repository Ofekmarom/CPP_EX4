//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template<typename T>
struct Node {
    T value;        //value of the node
    std::vector<Node<T>*> children;   //vector of pointers to children nodes

    explicit Node(const T& value);// explicit constructor that takes a constant lvalue reference to T
    explicit Node(T&& value);// explicit constructor that takes an rvalue reference to T
    ~Node();//destructor
};

// Constructor with const reference
template<typename T>
Node<T>::Node(const T& value) : value(value), children() {}

// constructor with rvalue reference
template<typename T>
Node<T>::Node(T&& value) : value(std::move(value)), children() {}

// destructor to delete all the childrens
template<typename T>
Node<T>::~Node() {
    for (auto child : children) {
        delete child;
    }
}

#endif // NODE_HPP
