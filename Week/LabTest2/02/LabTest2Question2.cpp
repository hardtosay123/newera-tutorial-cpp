#include <iostream>
#include "binarySearchTree.h"

using namespace std;

bSearchTreeType<int> binaryTree;

int main()
{
    binaryTree.insert(60);
    binaryTree.insert(50);
    binaryTree.insert(35);
    binaryTree.insert(32);
    binaryTree.insert(40);
    binaryTree.insert(48);
    binaryTree.insert(45);
    binaryTree.insert(53);
    binaryTree.insert(57);
    binaryTree.insert(70);
    binaryTree.insert(80);
    binaryTree.insert(75);
    binaryTree.insert(77);
    binaryTree.printKNode(50);
}
