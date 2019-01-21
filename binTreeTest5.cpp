#include <iostream>
#include<stdio.h> 
#define COUNT 10 
using namespace std;

struct node {
  int key;
  node* left;
  node* right;
};

node* root;
node* makeNode(int key_);                //initializes Node with key value
void leftChildSort(node* ptr);           //finds and Prints the left most child in tree, then root, then right
void ascendingSort(int key, node* ptr);  //function places nodes according to key values

void leftChildSort(node* ptr){
    if(ptr!=NULL){
        if(ptr->left != NULL){
            leftChildSort(ptr->left);
        }
        //arr[] = ptr->key;
        cout << ptr->key << " ";
        if(ptr->right != NULL){
            leftChildSort(ptr->right);
        }
    } else {
        cout << "No nodes in tree\n";
    }
}


void ascendingSort(int key, node* ptr){
    if(root == NULL){
        root = makeNode(key);
    }
    else if(key < ptr->key)
    {
        if(ptr->left != NULL){
            ascendingSort(key, ptr->left);
        } else {
            ptr->left = makeNode(key);
        }
    }
    else if(key > ptr->key)
    {
        if(ptr->right != NULL){
            ascendingSort(key, ptr->right);
        } else {
            ptr->right = makeNode(key);
        }
    }
    else {
        cout << "Key " << key << " exits already in BTree\n";
    }
}

node* makeNode(int key_){
    node* n = new node;
    n->key = key_;
    n->left = NULL; n->right = NULL;
    return n;
}


int main() {
    //Sample Tree with random key values
    // root = makeNode(1);
    // root->left = makeNode(2);
    // root->right = makeNode(3);
    // root->left->left = makeNode(5);
    // root->left->right = makeNode(4);
    // root->left->right->left = makeNode(6);
    // root->left->right->right = makeNode(8);
    // root->right->left = makeNode(7);
    // root->right->right = makeNode(8);
    
    // leftChildSort(root);             
    
///Following is for Testing User-Input Tree. When a node has key value < root value, it places the node to its left, 
///then print keys by traversing with leftChildSort func
///Comment the code above and Uncomment code below to use it

    int size;
    cout << "Enter No. of nodes (including root node): " << endl;
    cin >> size;
    cout << "Enter " << size << " node values (first being the root node, press enter after each entry):" << endl;
    int tree_input[size];  //array to hold node keys input by user
    for(int i=0; i<size; i++){
        cin >> tree_input[i];
    }
    for(int i=0; i<size; i++){
        ascendingSort(tree_input[i], root);
    }
    leftChildSort(root);
    return 0;
}
