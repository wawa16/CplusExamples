#include <iostream>
#include <cstdlib>
#include <sstream> 
using namespace std;


struct node {
  int key;
  node* left;
  node* right;
  node(int key_){
      this->key = key_;
      left = NULL; right = NULL;
  }
};

node* root;

// node* createLeaf(int key_){
//     node* n = new node;
//     n->key = key_;
//     n->left = NULL; n->right = NULL;
//     return n;
// }

// void addLeafPriv(int key, node* Ptr){
//     if(root == NULL){
//         root = createLeaf(key);
//     }
//     else if(key < Ptr->key)
//     {
//         if(Ptr->left != NULL){
//             addLeafPriv(key, Ptr->left);
//         } else {
//             Ptr->left = createLeaf(key);
//         }
//     }
//     else if(key > Ptr->key)
//     {
//         if(Ptr->right != NULL){
//             addLeafPriv(key, Ptr->right);
//         } else {
//             Ptr->right = createLeaf(key);
//         }
//     }
//     else {
//         cout << "Key " << key << " exits already in BTree\n";
//     }
// }

// void printinOrderpriv(node* Ptr){
//     if(root!=NULL){
//         if(Ptr->left != NULL){
//             printinOrderpriv(Ptr->left);
//         }
//         cout << Ptr->key << " ";
//         if(Ptr->right != NULL){
//             printinOrderpriv(Ptr->right);
//         }
//     } else {
//         cout << "No nodes in tree\n";
//     }
// }

void printinOrderpriv(node* Ptr){
    if(Ptr!=NULL){
        if(Ptr->left != NULL){
            printinOrderpriv(Ptr->left);
        }
        //arr[] = Ptr->key;
        cout << Ptr->key << " ";
        if(Ptr->right != NULL){
            printinOrderpriv(Ptr->right);
        }
    } else {
        cout << "No nodes in tree\n";
    }
}

void printinOrder(node* root){
    printinOrderpriv(root);
}

node* addLeftChild(node* root){
      node *ptr = root->left;
      return ptr; 
}

node* addRightChild(node* root){
      node *ptr = root->right;
      return ptr; 
}

void buildTree(string input[], node* root, int &size){

    int key_;
    int arr_[size];
    
     for(int i=0; i<size; i++){
         int count = 0;
         node *ptr = root;
         while(count < input[i].length()){
            if (input[i][count] == 'L') {
            
                   ptr = addLeftChild(ptr);                 //temp pointer
       
            } else if (input[i][count] == 'R') {
              
                   ptr = addRightChild(ptr);              //temp pointer
                
               //cout << input[i][count] << " ";
            }
            else {
               key_ = input[i][count] - '0';
            }
            count++;
         }
         ptr = new node(key_);       //finally place the key at pointer location
         cout << ptr->key << " ";
         
     }

    //printinOrder(ptr);

    
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(5);
    // root->left->right = new node(4);
    // root->left->right->left = new node(6);
    // root->left->right->right = new node(8);
    // root->right->left = new node(7);
    // root->right->right = new node(8);
}



// void addLeaf(int key){
//     addLeafPriv(key, root);
// }


int main() {
    //node* root;
    int root_input, size;
    node* root;
    cout << "Enter Root of Tree:" << endl;
    cin >> root_input;
    root = new node(root_input);
    cout << "Enter total number of elements (nodes&children):" << endl;
    cin >> size;
    cout << "Root is saved. Enter Children of Tree (e.g. LLR2 is left->left->right=2 with respect to root):" << endl;
    string tree_input[size];
    for(int i=0; i<size; i++){
        cin >> tree_input[i];
    }
    
    buildTree(tree_input, root, size);
    //printinOrder(root);
    // int Treekeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    
    // cout << "tree in order\nBefore adding elements\n";
    //printinOrder(root);
    
    // for(int i = 0; i < 16; i++){
    //     addLeaf(Treekeys[i]);
    // }
    // cout << "tree in order\nAfter adding elements\n" << " Root: " << root->key << endl;
    // printinOrder();

    
    return 0;
}






