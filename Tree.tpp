//ID : 208336701
//mail : ofekmarom9@gmail.com

#ifndef TREE_TPP
#define TREE_TPP

#include "TreeIteratorBFS.tpp"
#include "TreeIteratorDFS.tpp"
#include "TreeIteratorInOrder.tpp"
#include "TreeIteratorPostOrder.tpp"
#include "TreeIteratorPreOrder.tpp"
#include "TreeIteratorHeap.tpp"


using namespace std;
using namespace sf;


// constructor
template<typename T, int K>
Tree<T, K>::Tree() : root(nullptr) {}

// destructor
template<typename T, int K>
Tree<T, K>::~Tree() {
    delete_tree(root);
}

// delete the entire tree
template<typename T, int K>
void Tree<T, K>::delete_tree(Node<T>* node) {
    if (!node) return;  // check if node is null before proceeding

    for (auto child : node->children) {
        delete_tree(child);  // delete child nodes
    }

    node->children.clear();  // clear the children vector
    delete node;  // delete the current node
}

// add root to the tree
template<typename T, int K>
void Tree<T, K>::add_root(const T& value) {
    delete_tree(root);// delete the existing tree, if there is
    root = new Node<T>(value);// create a new node with the value and set it as the root of the tree.
}

// add a sub node under a specified parent node
template<typename T, int K>
void Tree<T, K>::add_sub_node(const T& parent_value, const T& child_value) {
    // if the tree is empty, return
    if (!root) {
        throw runtime_error("cant add this node to the tree , the tree is empty");
    }

    // create a queue for BFS of the tree
    queue<Node<T>*> q;
    // Start the traversal from the root node
    q.push(root);

    // continue the traversal until there are no more nodes
    while (!q.empty()) {
        // get the front node from the queue
        auto node = q.front();
        // remove the front node from the queue
        q.pop();

        // check if the current node value equals to the the parent value
        if (node->value == parent_value) {
            // if the current node number of children is less than K (the maximum allowed), add the new child node
            if (node->children.size() < K) {
                // create a new node with the child value and add it to the current node children
                node->children.push_back(new Node<T>(child_value));
                return;
            }
            if (node->children.size() == K) {
                throw runtime_error("cant add the node to the tree, there is maximum subnodes to this parent already");
            }
        }

        // if the current node is not the parent node or already has maximum children
        // add its children to the queue to continue the search
        for (const auto& child : node->children) {
            q.push(child);
        }
    }
    throw runtime_error("cant add this node to the tree , there is no node in the tree with this parent value");
}



// transform the tree into a min heap (only for binary trees)
template<typename T, int K>
void Tree<T, K>::myHeap() {
    //if not binary tree
    if (K != 2) {
        throw runtime_error("Heap from tree is only supported for binary trees");
    }

    // collect all values in BFS order
    vector<T> values; // vector to store all node values
    queue<Node<T>*> node_queue;// queue for BFS traversal
    // Start BFS traversal from the root node if it exists
    if (root) {
        node_queue.push(root);
    }

    // BFS traversal to collect values
    while (!node_queue.empty()) {
        auto node = node_queue.front();
        node_queue.pop();
        values.push_back(node->value);  // add the current node value

        // add all children of the current node to the queue
        for (const auto& child : node->children) {
            node_queue.push(child);
        }
    }

    // Build and sort the min heap from the values
    make_heap(values.begin(), values.end(), less<T>());
    sort_heap(values.begin(), values.end(),less<T>());


    // reassign values to the tree to as min heap
    queue<Node<T>*> node_queue_assign;// queue for assigning values back to nodes
    // start from the root
    if (root) {
        node_queue_assign.push(root);
    }

    // iterator for the sorted values
    auto it = values.begin();
    while (!node_queue_assign.empty()) {
        auto node = node_queue_assign.front();
        node_queue_assign.pop();
        // assign the next sorted value to the current node
        node->value = *it++;
        // add all children of the current node to the queue
        for (const auto& child : node->children) {
            node_queue_assign.push(child);
        }
    }
}






// Iterator methods implementation
//the begin returns an iterator to the first element in the tree (root)
//the end returns an iterator to one past the last element in the tree (nullptr)


template<typename T, int K>
typename Tree<T, K>::IteratorBFS Tree<T, K>::begin() {
    return IteratorBFS(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorBFS Tree<T, K>::end() {
    return IteratorBFS(nullptr);
}


template<typename T, int K>
typename Tree<T, K>::IteratorPreOrder Tree<T, K>::begin_pre_order() {
    return IteratorPreOrder(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorPreOrder Tree<T, K>::end_pre_order() {
    return IteratorPreOrder(nullptr);
}

template<typename T, int K>
typename Tree<T, K>::IteratorPostOrder Tree<T, K>::begin_post_order() {
    return IteratorPostOrder(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorPostOrder Tree<T, K>::end_post_order() {
    return IteratorPostOrder(nullptr);
}

template<typename T, int K>
typename Tree<T, K>::IteratorInOrder Tree<T, K>::begin_in_order() {
    return IteratorInOrder(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorInOrder Tree<T, K>::end_in_order() {
    return IteratorInOrder(nullptr);
}

template<typename T, int K>
typename Tree<T, K>::IteratorBFS Tree<T, K>::begin_bfs_scan() {
    return IteratorBFS(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorBFS Tree<T, K>::end_bfs_scan() {
    return IteratorBFS(nullptr);
}

template<typename T, int K>
typename Tree<T, K>::IteratorDFS Tree<T, K>::begin_dfs_scan() {
    return IteratorDFS(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorDFS Tree<T, K>::end_dfs_scan() {
    return IteratorDFS(nullptr);
}

template<typename T, int K>
typename Tree<T, K>::IteratorHeap Tree<T, K>::begin_heap() {
    return IteratorHeap(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorHeap Tree<T, K>::end_heap() {
    return IteratorHeap(nullptr);
}


template<typename T, int K>
typename Tree<T, K>::IteratorDFS Tree<T, K>::begin_pre_orderK() {
    return IteratorDFS(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorDFS Tree<T, K>::end_pre_orderK() {
    return IteratorDFS(nullptr);
}

template<typename T, int K>
typename Tree<T, K>::IteratorDFS Tree<T, K>::begin_post_orderK() {
    return IteratorDFS(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorDFS Tree<T, K>::end_post_orderK() {
    return IteratorDFS(nullptr);
}

template<typename T, int K>
typename Tree<T, K>::IteratorDFS Tree<T, K>::begin_in_orderK() {
    return IteratorDFS(root);
}

template<typename T, int K>
typename Tree<T, K>::IteratorDFS Tree<T, K>::end_in_orderK() {
    return IteratorDFS(nullptr);
}








//output operator<<
template<typename T, int K>
ostream& operator<<(ostream& os, Tree<T, K>& tree) {
    tree.displayGui();
    return os;
}












// method to show the tree GUI using sfml
template<typename T, int K>
void Tree<T, K>::displayGui() {
    //set the screen and the font of the GUI
    RenderWindow screen(VideoMode(800, 600), "tree GUI");
    Font font;
    if (!font.loadFromFile("./myfont.otf")) {
        cerr << "error in font loading" << endl;
        return;
    }

    // set the screen with a white color (clear)
    screen.clear(Color::White);
    // draw the tree in the screen starting from the root node at the position (350, 20) with a space of 600/k between nodes in the same level
    float spaceOfNodes = 600 / K;
    drawTree(screen, font, root, 350, 20, spaceOfNodes);
    // display the screen after the drawing of the tree
    screen.display();

    // loop to keep the GUI screen open until the user press the close button of the screen or escape in the keyboard
    while (screen.isOpen()) {
        Event event;
        // update the event based on what the user did
        while (screen.pollEvent(event)) {
            // check if the user pressed the close button of the screen
            if (event.type == Event::Closed) {
                // clear the screen and close it
                screen.clear(Color::White);
                screen.close();
            }
            // check if the user pressed the escape key in the keyboard
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    // clear the screen and close it
                    screen.clear(Color::White);
                    screen.close();
                }
            }
        }
    }
}





// method to draw the tree in the GUI
//get screen,font,node to start from,starting x,starting y,spacing between the nodes
template<typename T, int K>
void Tree<T, K>::drawTree(RenderWindow& screen, Font& font, Node<T>* node, float x, float y, float spaceBetweenNodes) {
    // if the node is null, return and dont draw
    if (!node) {
        return;
    }

    // draw the circle representing the node
    CircleShape circle(35); // set the circle with it radius
    circle.setPosition(x, y); // set the position of the node
    circle.setFillColor(Color::Blue);// set blue as the color of the node
    screen.draw(circle);// draw the node on the screen

    // take the value of the node and represent it as string
    T value = node->value;
    ostringstream oss;
    oss << value; // convert the value to a string
    string valueAsString = oss.str(); // save the string representation of the value of the node

    // draw the value of the node inside the node circle
    Text valueToDraw(valueAsString, font, 25);// create a Text object with the node value, font, and font size 25
    valueToDraw.setFillColor(Color::Black); // color of the value of the node
    FloatRect textBounds = valueToDraw.getLocalBounds();// get the bounds of the Text object for centering the string in the node
    valueToDraw.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);//set the text to the center of its bounds
    valueToDraw.setPosition(x + circle.getRadius(), y + circle.getRadius());// position the value in the center of the circle
    screen.draw(valueToDraw);//draw the value of the node on the screen

    // draw lines that represents the edges of the node to its children
    size_t childrens = node->children.size();  // the number of children of the node
    if (childrens > 0) {  // if the node has children
        for (size_t i = 0; i < childrens; i++) {  //  loop for each child
            float xOfChild = (x - spaceBetweenNodes / 2) + (i * spaceBetweenNodes);  // calculate the x position of the child node
            float yOfChild = y + 100;  // calculate the y position of the child node
            Vertex edge[] = {  // create an edge from the parent node to the child node
                    Vertex(Vector2f(x + circle.getRadius(), y + circle.getRadius() * 2)),  // the starting point of the edge
                    Vertex(Vector2f(xOfChild + circle.getRadius(), yOfChild))  // the ending point of the edge
            };
            edge[0].color = Color::Black;  // set the color of the starting point of the edge
            edge[1].color = Color::Black;  // set the color of the ending point of the edge
            screen.draw(edge, 2, Lines);  // draw the edge on the screen
            drawTree(screen, font, node->children[i], xOfChild, yOfChild, spaceBetweenNodes / 2);  // draw the child node and its subtree
        }
    }
}








#endif // TREE_TPP
