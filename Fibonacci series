#include <iostream> 
#include <cstring>
using namespace std; 

void fibunacci(int&);

int main(){
    int upper_limit;
    cout << "Enter upper limit of Fibonacci sequence: " << endl;
    cin >> upper_limit;
    fibunacci(upper_limit);
}

void fibunacci(int &limit){
    int i = 0;
    int temp[limit];
    do {
        temp[0] = 0;
        temp[1] = 1;
        temp[i+2] = temp[i] + temp[i+1];
        cout << temp[i] << endl;
        i++;
    }
    while(temp[i] <= limit);
}
