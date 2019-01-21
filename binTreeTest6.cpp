#include <iostream>
#include <cstdlib>
#include <sstream> 
using namespace std;


struct node {
  int key;
  node* left;
  node* right;
  node(int key_ = 0){
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
    if(root->left == NULL){
       root->left = new node();
    } else {
        addLeftChild(root->left);
    }
      node *ptr = root->left;
      return ptr; 
}

node* addRightChild(node* root){
    if(root->right == NULL){
       root->right = new node();
    } else {
       addRightChild(root->right);
    }
      node *ptr = root->right;
      return ptr; 
}

void buildTree(string input[], int &size){

    int key_;
   
    node* arr_[size];
    
     for(int i=0; i<size; i++){
         if(root == NULL){
             int key_ = input[i][0] - '0';
             root = new node(key_);
             arr_[i] = root;
             cout << arr_[i]->key;
         } else {
             int count = 0;
             node *ptr = root;
             while(count < input[i].length()){
                if (input[i][count] == 'L') {
                      if(arr_[i]->left == NULL){
                        arr_[i] = addLeftChild(root);                 //temp pointer
                      } else {
                        arr_[i] = addLeftChild(arr_[i]);
                      }
                } else if (input[i][count] == 'R') {
                    
                    if(arr_[i]->right == NULL){
                        arr_[i] = addRightChild(root);                 //temp pointer
                      } else {
                        arr_[i] = addRightChild(arr_[i]);
                      }                 
                  //cout << input[i][count] << " ";
                }
                else {
                  key_ = input[i][count] - '0';
                }
                count++;
             }
             arr_[i] = new node(key_);       //finally place the key at pointer location
             cout << arr_[i]->key << " ";
         }
     
         
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
    int size;
    cout << "Enter total number of elements (nodes&children including root node):" << endl;
    cin >> size;
    cout << "Enter Root value first then Enter Children of Tree in proper sequence\n(e.g. LLR2 is left->left->right=2 with respect to root):" << endl;
    string tree_input[size];
    for(int i=0; i<size; i++){
        cin >> tree_input[i];
    }
    
    buildTree(tree_input, size);
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
