#include <iostream> 
#include <cstring>
using namespace std; 

void printStruct(struct Piano *piano, int& pianos);

typedef struct Piano{
    string piano_type;
    string mechanism;
    string owner;
    int age;
};

int main(){
    int pianos;
    cout << "Enter no. of pianos: " << endl;
    cin >> pianos;
    Piano piano[pianos];
    for(int i=0; i<pianos; i++){
        cout << "Please enter the details for piano #" << (i+1) << endl;
        cout << "Piano Type: " << endl;
        cin >> piano[i].piano_type;
        cout << "Piano mechanism: " << endl;
        cin >> piano[i].mechanism;
        cout << "Piano Age: " << endl;
        cin >> piano[i].age;
    }
    
    for(int i=0; i<pianos; i++){
        printStruct(&piano[i], i);
    }
    
}
    void printStruct(struct Piano *piano, int &pianos){
        cout << "Details of piano # " << (pianos+1) << endl;
        cout << piano->piano_type << endl;
        cout << piano->mechanism << endl;
        cout << piano->age << endl;
    }
