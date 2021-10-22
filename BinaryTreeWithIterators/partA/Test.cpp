#include "doctest.h"
#include "BinaryTree.hpp"


TEST_CASE("test to board"){

    ariel::BinaryTree<int> tree_int;

    CHECK_NOTHROW(ariel::BinaryTree<int> tree_int);
    CHECK_NOTHROW(tree_int.add_root(1));
    CHECK_NOTHROW(tree_int.add_root(-1));
    CHECK_NOTHROW(tree_int.add_root(0));
    CHECK_NOTHROW(tree_int.add_left(0, 3));
    CHECK_NOTHROW(tree_int.add_left(3, 5));
    CHECK_THROWS(tree_int.add_left(12, 4));
    CHECK_NOTHROW(tree_int.add_right(0, 2));
    CHECK_NOTHROW(tree_int.add_right(2, 4));
    CHECK_THROWS(tree_int.add_right(10, 4));
    CHECK_THROWS(tree_int.add_right(1, 4));
    //

    ariel::BinaryTree<std::string> tree_str;

    CHECK_NOTHROW(ariel::BinaryTree<int> tree_str);
    CHECK_NOTHROW(tree_str.add_root("shlomo"));
    CHECK_NOTHROW(tree_str.add_root(""));
    CHECK_NOTHROW(tree_str.add_root("test"));
    CHECK_NOTHROW(tree_str.add_left("test", "tree"));
    CHECK_NOTHROW(tree_str.add_left("tree", "blue"));
    CHECK_THROWS(tree_str.add_left("binary", "black"));
    CHECK_NOTHROW(tree_str.add_right("test", "black"));
    CHECK_NOTHROW(tree_str.add_right("test", "blue"));
    CHECK_THROWS(tree_str.add_right("shlomo","311"));



}