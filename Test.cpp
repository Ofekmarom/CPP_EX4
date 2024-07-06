//ID : 208336701
//mail : ofekmarom9@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Complex.hpp"
#include <vector>
#include <string>

using namespace std;

// Test for Tree<int, 2>
TEST_CASE("Tree<int, 2>") {
    Tree<int, 2> tree;

    // Add nodes to the tree
    tree.add_root(1);
    tree.add_sub_node(1, 2);
    tree.add_sub_node(1, 3);
    tree.add_sub_node(2, 4);
    tree.add_sub_node(2, 5);
    tree.add_sub_node(3, 6);

    // Test BFS traversal
    SUBCASE("BFS traversal") {
        vector<int> expected = {1, 2, 3, 4, 5, 6};
        vector<int> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test DFS traversal
    SUBCASE("DFS traversal") {
        vector<int> expected = {1, 2, 4, 5, 3, 6};
        vector<int> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test inOrder traversal
    SUBCASE("inOrder traversal") {
        vector<int> expected = {4, 2, 5, 1, 6, 3};
        vector<int> result;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test PreOrder traversal
    SUBCASE("PreOrder traversal") {
        vector<int> expected = {1, 2, 4, 5, 3, 6};
        vector<int> result;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test PostOrder traversal
    SUBCASE("PostOrder traversal") {
        vector<int> expected = {4, 5, 2, 6, 3, 1};
        vector<int> result;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }
}

// Test for Tree<string, 2>
TEST_CASE("Tree<string, 2> ") {
    Tree<string, 2> tree;

    // Add nodes to the tree
    tree.add_root("root");
    tree.add_sub_node("root", "child1");
    tree.add_sub_node("root", "child2");
    tree.add_sub_node("child1", "grandchild1");
    tree.add_sub_node("child1", "grandchild2");

    // Test BFS traversal
    SUBCASE("BFS traversal") {
        vector<string> expected = {"root", "child1", "child2", "grandchild1", "grandchild2"};
        vector<string> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test DFS traversal
    SUBCASE("DFS traversal") {
        vector<string> expected = {"root", "child1", "grandchild1", "grandchild2", "child2"};
        vector<string> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test In-Order traversal
    SUBCASE("In-Order traversal") {
        vector<string> expected = {"grandchild1", "child1", "grandchild2", "root", "child2"};
        vector<string> result;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test Pre-Order traversal
    SUBCASE("Pre-Order traversal") {
        vector<string> expected = {"root", "child1", "grandchild1", "grandchild2", "child2"};
        vector<string> result;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test Post-Order traversal
    SUBCASE("Post-Order traversal") {
        vector<string> expected = {"grandchild1", "grandchild2", "child1", "child2", "root"};
        vector<string> result;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test heap traversal
    SUBCASE("heap traversal") {
        tree.myHeap();
        vector<string> expected = {"child1", "child2", "grandchild1", "grandchild2", "root"};
        vector<string> result;
        for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

// Test for Tree<Complex, 2>
TEST_CASE("Tree<Complex, 2> ") {
    Tree<Complex, 2> tree;

    // Add nodes to the tree
    tree.add_root(Complex(1, 2));
    tree.add_sub_node(Complex(1, 2), Complex(3, 4));
    tree.add_sub_node(Complex(1, 2), Complex(5, 6));
    tree.add_sub_node(Complex(5, 6), Complex(1, 1));
    tree.add_sub_node(Complex(5, 6), Complex(9, 10));

    // Test BFS traversal
    SUBCASE("BFS traversal") {
        vector<Complex> expected = {Complex(1, 2), Complex(3, 4), Complex(5, 6), Complex(1, 1), Complex(9, 10)};
        vector<Complex> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test DFS traversal
    SUBCASE("DFS traversal") {
        vector<Complex> expected = {Complex(1, 2), Complex(3, 4), Complex(5, 6), Complex(1, 1), Complex(9, 10)};
        vector<Complex> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test Pre-Order traversal
    SUBCASE("Pre-Order traversal") {
        vector<Complex> expected = {Complex(1, 2), Complex(3, 4), Complex(5, 6), Complex(1, 1), Complex(9, 10)};
        vector<Complex> result;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test Post-Order traversal
    SUBCASE("Post-Order traversal") {
        vector<Complex> expected = {Complex(3, 4), Complex(1, 1), Complex(9, 10), Complex(5, 6), Complex(1, 2)};
        vector<Complex> result;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test heap traversal of complex
    SUBCASE("Heap traversal") {
        tree.myHeap();
        vector<Complex> expected = {Complex(1, 1), Complex(1, 2), Complex(3, 4), Complex(5, 6),Complex(9, 10) };
        vector<Complex> result;
        for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

// Test for Tree<int, 3>
TEST_CASE("Tree<int, 3>") {
    Tree<int, 3> tree;

    // Add nodes to the tree
    tree.add_root(1);
    tree.add_sub_node(1, 2);
    tree.add_sub_node(1, 3);
    tree.add_sub_node(1, 4);
    tree.add_sub_node(2, 5);
    tree.add_sub_node(2, 6);
    tree.add_sub_node(3, 7);

    // Test BFS traversal
    SUBCASE("BFS traversal") {
        vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
        vector<int> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test DFS traversal
    SUBCASE("DFS traversal") {
        vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
        vector<int> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test In-Order traversal
    SUBCASE("In-Order traversal") {
        vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
        vector<int> result;
        for (auto it = tree.begin_in_orderK(); it != tree.end_in_orderK(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test Pre-Order traversal
    SUBCASE("Pre-Order traversal") {
        vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
        vector<int> result;
        for (auto it = tree.begin_pre_orderK(); it != tree.end_pre_orderK(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test Post-Order traversal
    SUBCASE("Post-Order traversal") {
        vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
        vector<int> result;
        for (auto it = tree.begin_post_orderK(); it != tree.end_post_orderK(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }
}

// Test for Tree<int, 4>
TEST_CASE("Tree<int, 4> ") {
    Tree<int, 4> tree;

    // Add nodes to the tree
    tree.add_root(1);
    tree.add_sub_node(1, 2);
    tree.add_sub_node(1, 3);
    tree.add_sub_node(1, 4);
    tree.add_sub_node(1, 5);
    tree.add_sub_node(2, 6);
    tree.add_sub_node(2, 7);
    tree.add_sub_node(3, 8);

    // Test BFS traversal
    SUBCASE("BFS traversal") {
        vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8};
        vector<int> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test DFS traversal
    SUBCASE("DFS traversal") {
        vector<int> expected = {1, 2, 6, 7, 3, 8, 4, 5};
        vector<int> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test In-Order traversal
    SUBCASE("In-Order traversal") {
        vector<int> expected = {1, 2, 6, 7, 3, 8, 4, 5};
        vector<int> result;
        for (auto it = tree.begin_in_orderK(); it != tree.end_in_orderK(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test Pre-Order traversal
    SUBCASE("Pre-Order traversal") {
        vector<int> expected = {1, 2, 6, 7, 3, 8, 4, 5};
        vector<int> result;
        for (auto it = tree.begin_pre_orderK(); it != tree.end_pre_orderK(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test Post-Order traversal
    SUBCASE("Post-Order traversal") {
        vector<int> expected = {1, 2, 6, 7, 3, 8, 4, 5};
        vector<int> result;
        for (auto it = tree.begin_post_orderK(); it != tree.end_post_orderK(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }
}

// Test for Tree<Complex, 3>
TEST_CASE("Tree<Complex, 3> ") {
    Tree<Complex, 3> tree;

    // Add nodes to the tree
    tree.add_root(Complex(1, 2));
    tree.add_sub_node(Complex(1, 2), Complex(3, 4));
    tree.add_sub_node(Complex(1, 2), Complex(5, 6));
    tree.add_sub_node(Complex(1, 2), Complex(7, 8));
    tree.add_sub_node(Complex(3, 4), Complex(9, 10));
    tree.add_sub_node(Complex(5, 6), Complex(11, 12));

    // Test BFS traversal
    SUBCASE("BFS traversal") {
        vector<Complex> expected = {Complex(1, 2), Complex(3, 4), Complex(5, 6), Complex(7, 8), Complex(9, 10), Complex(11, 12)};
        vector<Complex> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test DFS traversal
    SUBCASE("DFS traversal") {
        vector<Complex> expected = {Complex(1, 2), Complex(3, 4), Complex(9, 10), Complex(5, 6), Complex(11, 12), Complex(7, 8)};
        vector<Complex> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }
}

// Test for Tree<string, 3>
TEST_CASE("Tree<string, 3> basic operations") {
    Tree<string, 3> tree;

    // Add nodes to the tree
    tree.add_root("root");
    tree.add_sub_node("root", "child1");
    tree.add_sub_node("root", "child2");
    tree.add_sub_node("root", "child3");
    tree.add_sub_node("child1", "grandchild1");
    tree.add_sub_node("child2", "grandchild2");

    // Test BFS traversal
    SUBCASE("BFS traversal") {
        vector<string> expected = {"root", "child1", "child2", "child3", "grandchild1", "grandchild2"};
        vector<string> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }

    // Test DFS traversal
    SUBCASE("DFS traversal") {
        vector<string> expected = {"root", "child1", "grandchild1", "child2", "grandchild2", "child3"};
        vector<string> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back((*it)->value);
        }
        CHECK(result == expected);
    }
}

// Test for Tree<int, 2>
TEST_CASE("Tree<int, 2> edge cases and exceptions") {
    Tree<int, 2> tree;

    // Test adding subnode to empty tree(should throw exception)
    CHECK_THROWS(tree.add_sub_node(2, 4));

    tree.add_root(5);
    // Test adding nodes with non-existent parents(should throw exception)
    CHECK_THROWS(tree.add_sub_node(2, 4));

    //test try to add 3 kids to a binary tree(should throw exception)
    tree.add_sub_node(5,1);
    tree.add_sub_node(5,2);
    CHECK_THROWS(tree.add_sub_node(5, 4));




    // Test minheap for non-binary trees (should throw exception)
    Tree<int, 3> nonBinaryTree;
    nonBinaryTree.add_root(1);
    CHECK_THROWS(nonBinaryTree.myHeap());





    // Test with an empty tree
    Tree<int, 2> emptyTree;
    CHECK(emptyTree.begin_pre_order() == emptyTree.end_pre_order());
    CHECK(emptyTree.begin_post_order() == emptyTree.end_post_order());
    CHECK(emptyTree.begin_in_order() == emptyTree.end_in_order());
    CHECK(emptyTree.begin_bfs_scan() == emptyTree.end_bfs_scan());
    CHECK(emptyTree.begin_dfs_scan() == emptyTree.end_dfs_scan());
    CHECK(emptyTree.begin_heap() == emptyTree.end_heap());
}

