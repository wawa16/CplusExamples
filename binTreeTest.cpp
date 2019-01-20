#include <iostream>
#include <cstdlib>
#include <vector> 
#include <algorithm>

using namespace std;


struct node {
  int key;
  node* left;
  node* right;
};

node* createLeaf(int key_){
    node* n = new node;
    n->key = key_;
    n->left = NULL; n->right = NULL;
    return n;
}

void addLeafPriv(int key, node* Ptr){
    if(root == NULL){
        root = createLeaf(key);
    }
    else if(key < Ptr->key)
    {
        if(Ptr->left != NULL){
            addLeafPriv(key, Ptr->left);
        } else {
            Ptr->left = createLeaf(key);
        }
    }
    else if(key > Ptr->key)
    {
        if(Ptr->right != NULL){
            addLeafPriv(key, Ptr->right);
        } else {
            Ptr->right = createLeaf(key);
        }
    }
    else {
        cout << "Key " << key << " exits already in BTree\n";
    }
}

void addLeaf(int key){
    addLeafPriv(key, root);
}


int main() {
    node* root;
    root = NULL;
    
    return 0;
}
