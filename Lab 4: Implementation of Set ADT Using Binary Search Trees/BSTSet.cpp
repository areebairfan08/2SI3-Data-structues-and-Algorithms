#include "BSTSet.h"
#include <iostream>
#include <vector>
#include "ArrayStack.cpp"

using namespace std;


BSTSet::BSTSet()
//TIME: O(1)
//SPACE: O(1) --> only creating one node and do not need to allocate any more memory
{
    // The constructor initializes an empty BST by setting the root node of the tree to NULL
    this->root = NULL;
}

BSTSet::BSTSet(const std::vector<int>& input)
//TIME: O(nlogn) 
    // --> This is because the for loop iterates n times,
    // and each call to the add function has a time complexity of O(log n) in the average case
//SPACE: O(n) --> size of input vector
{
    
    this->root = NULL; // Initialize the root node to be NULL

    for (int i = 0; i < input.size(); i++) { //loop through the input vector 
        this->add(input[i]); //the add function will take care of any repeated numbers
    }
}

void BSTSet::deleteRec(TNode* node)
//TIME: O(n) --> where n is the total number of nodes in the subtree rooted at the target node
//SPACE: O(n) --> at most there's n recursive calls
{
	if(node){ //first ensure the node is not NULL
        deleteRec(node->left); //call the recursive function to delete all  nodes of the  left subtree
        deleteRec(node->right); //same with right
		delete node; //and delete the current node
	}
}


BSTSet::~BSTSet() //deconstructor
//TIME:O(n)
// SPACE: O(1)
//frees the memory allocated for the BSTSet object
{
    deleteRec(root);
}


bool BSTSet::isIn(int v)
//TIME:  O(logn) --> if the tree is balanced, the height is approximately log(n),
                    // where n is the number of elements in the set
                    // because at each level of the tree, the number of nodes is roughly doubled
//SPACE: O(1) --> constant amount of memory to store the current node pointer and the value v
/*
* bool isIn(int v): returns true if integer v is an element of this BSTSet.
It returns false otherwise
*/
{
    TNode* current = root;

    while (current != NULL) { //loop until NULL
        
        if (current->element < v) { // if the current element is less than v, traverse right
            current = current->right;
        }
        else if (current->element > v) { // if the current element is less than v, traverse left
            current = current->left;
        }
        else {  // If the current node's value is equal to v, return true
            
            return true;
        }
    }
    return false; //if not found, return false
}

void BSTSet::add(int v)
//TIME:  O(logn) --> if the tree is balanced, the height is approximately log(n),
                    // where n is the number of elements in the set
                    // because at each level of the tree, the number of nodes is roughly doubled
//SPACE: O(1)   
/*
* void add(int v): adds v to this BSTSet if v was not already an element of
this BSTSet. It does nothing otherwise.
*/
{
    if (isIn(v)) { //if v is already in the set, we dont want to duplicate so do nothing
        return;
    }
    else {
        TNode* newNode = new TNode(v, NULL, NULL); //create new node with value v and no children
        TNode* previous = NULL; //previous node
        TNode* current = this->root; //current node set to root


     
        for (previous = NULL, current = root; current != NULL; ) { //loop until NULL
            previous = current; //Keep track of the previous node in case we need to insert the new node there
            if (v < current->element) { //If v is less than the current node's value
                current = current->left; // move to the left child
            }
            else if (v > current->element) { //If v is greater than the current node's value
                current = current->right; //move to the right child
            }
        }

        if (previous == NULL) { //if the whole tree is empty
            this->root = newNode; //set the new node as the root
        }
        else if (current == NULL) { //otherwise set the node as a child of the previous node
            if (v < previous->element) {
                previous->left = newNode;
            }
            else {
                previous->right = newNode;
            }

        }
    }

}

TNode* recur_remove(int v, TNode* node) { // The function recur_remove recursively removes the node with value v from the binary search tree rooted at node.
//TIME: O(n) --> every node has one child worst case
//SPACE: O(n) --> if tree is skewed
    if (node == NULL) { // If the node is null, the element is not present in the BST
        return node;
    }

    else if (v > node->element) { // If the element is greater than the current node, recurse right
        node->right = recur_remove(v, node->right);
    }

    else if (v < node->element) { // If the element is less than the current node, recurse left
        node->left = recur_remove(v, node->left);
    }

    else {

        //case 1: no children, if both sides of the left and right are NULL we can simply delete the node
        if (node->left == NULL && node->right == NULL) {  // If the current node is the one to be removed
            delete node; //delete the node
            node = NULL;
            return node;
        }

        //in the case where the left has one child, the node to be deleted can be replaced by the child
        else if (node->right == NULL) { 
            TNode* temporary = node;
            node = node->left;
            delete temporary;
            return node;
        }

        //in the case where the right has one child, the node to be deleted can be replaced by the child
        else if (node->left == NULL) {
            TNode* temporary = node;
            node = node->right;
            delete temporary;
            return node;
        }

        else { //case where there is 2 children
            TNode* temp = node->right;
            while (temp->left != NULL) { //while theres a left child, 
                temp = temp->left; //keep going left
            }
            node->element = temp->element; //the last elemement of left is assigned to the node (to be removed)
            node->right = recur_remove(temp->element, node->right); //the right subtree of the node being removed is updated with a recursive call
            // removing the node from the right subtree and updating the right subtree after removal
        }
    }

    return node;
}

bool BSTSet::remove(int v)
//TIME O(logn) --> assuming tree is balanced
//SPACE O(1)
{

    if (!(isIn(v))) { //if v is found within the tree
        return false; //return false
    }

    root = recur_remove(v, root); //if found, run the recursive function above
    return true;
}

void BSTSet::recur_Union(TNode* node)
//TIME: O(n^2) --> since were going through both left and right
//SPACE: O(n) --> if tree is skewed
{

    if (node == NULL) {
        return;
    }
        this->add(node->element); //add the element
        recur_Union(node->right); //traverse through right subtree
        recur_Union(node->left);  //traverse through left subtree
    }

void BSTSet::Union(const BSTSet& s)
//TIME: O(n^2) --> since were going through both left and right
//SPACE: O(n) --> if three is skewed
{
    TNode* root = s.root; //root of the input set is the starting point for the recursive call
    this->recur_Union(root);
}

void BSTSet::recur_intersection(TNode* target, BSTSet& input, BSTSet& this_tree)
//TIME: O(n^2) --> since were going through both left and right
//SPACE: O(n) --> if tree is skewed
{
    if (target == NULL || input.root == NULL) { //if both sets are empty, the resulting set will be empty
        return;
    }

    // Check if the current node's element is in the input tree
    if (input.isIn(target->element)) { //condition to check if the target node is in the input tree
        this_tree.add(target->element); //if it is, add it to the output tree
    }

    // Recursively traverse the left and right subtrees
    recur_intersection(target->right, input, this_tree);
    recur_intersection(target->left, input, this_tree);
}

void BSTSet::intersection(const BSTSet& s)
//TIME: O(n^2) --> since were going through both left and right
//SPACE: O(n) --> if tree is skewed
{
    // Create new empty BSTSets for the input tree and the copy of this tree
    BSTSet* input = new BSTSet();
    BSTSet* copy = new BSTSet();
     
    if (s.root == NULL && this->root == NULL) { //if both sets are empty, return empty set
        return;
    }
    else {

        input->root = s.root;
        this->recur_intersection(this->root, *input, *copy); //run the recusrive function and add the elements to 'copy'
        this->root = copy->root; //modify BSTSet to copy

    }

}

void BSTSet::recur_difference(TNode* node)
//TIME: O(n^2) --> since were going through both left and right
//SPACE: O(n) --> if tree is skewed
{


    if (node == NULL) {
        return;
    }

    if (this->isIn(node->element)) {//checking if target is found
        this->remove(node->element); //if its found, remove
    }
    // Recursively traverse the right and left subtrees
    recur_difference(node->right);
    recur_difference(node->left);
}


void BSTSet::difference(const BSTSet& s)
//TIME: O(n^2) --> since were going through both left and right
//SPACE: O(n) --> if tree is skewed
{
    if (s.root == NULL) { //if the set is empty, return empty set
        return;
    }
    this->recur_difference(s.root); //else run the recursive function
}

int BSTSet::recur_size(TNode* node) {
//TIME: O(n) --> each node is visited once

    if (node == NULL) {
        return 0;
    }

    else {
        return(recur_size(node->left) + recur_size(node->right) + 1);
        // Recursively traverse the right and left subtrees + 1 for the current node
    }
}

int BSTSet::size()

//TIME: O(n) --> each node is visited once
//SPACE: O(n) --> tree is skewed and has height of n (worst case)
{
    int element_no = 0;

    if (this->root == NULL) { // If the tree is not empty, call the recursive size function
        return 0;
    }

    element_no = this->recur_size(this->root); //call the recursive function and assign it to element_no

    return element_no; // Return the size of the tree
}

int BSTSet::recur_height(TNode*& node) {
//TIME: O(n) --> visits each node once
//SPACE: O(n) --> tree is skewed and has height of n (worst case)

    int rightHeight;
    int leftHeight;

    if (node == NULL) {
        return NULL;
    }

    else {

         rightHeight = recur_height(node->right); //recursive call on right subtree
         leftHeight = recur_height(node->left); //recursive call on left subtree

        //we want the max + 1 for current node
        if (leftHeight > rightHeight) {
            return(leftHeight + 1); //if left is bigger
        }
        else {
            return(rightHeight + 1); // if right is bigger
        }
    }
}

int BSTSet::height()
//TIME: O(n) --> visits each node once
//SPACE: O(n) --> tree is skewed and has height of n (worst case)
{
    TNode* temp = root;

    return(recur_height(temp) - 1);
    // Call the recursive height function and subtract 1 to account for the extra 1 added when the recursive function ends
}


void BSTSet::printNonRec() {
//TIME: O(n) --> each node is visited once   
//SPACE: O(n) --> tree is skewed and has height of n (worst case)
    //stack to hold all the codes
    ArrayStack<TNode*> stack;

    TNode* current = root; //current node starts at the root
   
    // Loop through the BST until the stack is empty or the current node is null
    while ((current != NULL) || (stack.isEmpty() == false)) 
    {
        if (current != NULL) { // If the current node is not null
            stack.push(current); //push it onto the stack
            current = current->left; //move to the left child

        }
        // If the current node is null, pop the top element of the stack, print its value,
    // set the current node to its right child, and repeat the loop
        if (current == NULL) // If the current node is null
        {
            TNode* temp = stack.top(); //holds top of the stack
            stack.pop(); //pop the top element of the stack
            current = temp; //set the current node to top of the stack
            cout << current->element << ","; //print its value
            current = current->right;

        }

    }

}

void BSTSet::printBSTSet()
{
    if (root == NULL)
        std::cout << "";
    else {
        printBSTSet(root);
    }
}

void BSTSet::printBSTSet(TNode* t)
{
    if (t != NULL) {
        printBSTSet(t->left);
        std::cout << t->element << ",";
        printBSTSet(t->right);
    }
}
