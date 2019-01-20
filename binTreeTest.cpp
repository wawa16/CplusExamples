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

node* root;

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

void printinOrderpriv(node* Ptr){
    if(root!=NULL){
        if(Ptr->left != NULL){
            printinOrderpriv(Ptr->left);
        }
        cout << Ptr->key << " ";
        if(Ptr->right != NULL){
            printinOrderpriv(Ptr->right);
        }
    } else {
        cout << "No nodes in tree\n";
    }
}

void printinOrder(){
    printinOrderpriv(root);
}

void addLeaf(int key){
    addLeafPriv(key, root);
}


int main() {
    //node* root;
    root = NULL;
    int Treekeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80}
    
    cout << "tree in order\nBefore adding elements\n";
    printinOrder();
    
    for(int i = 0; i < 16; i++){
        addLeaf(Treekeys[i]);
    }
    cout << "tree in order\nAfter adding elements\n";
    printinOrder();

    
    return 0;
}


