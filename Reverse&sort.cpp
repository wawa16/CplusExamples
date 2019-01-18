
//This program sorts number of five digits in reverse order also it prints digits in Descending order
//Program demonstrates use of abstract class with pure Virtual funtion

#include <iostream>

using namespace std;
class Sort {                               //abstract base class
    public:
     virtual void sortFunc(int num) = 0;   //pure virtual func
};

class ReverseAndDescend : public Sort {
    public:
    void sortFunc(int num){
        int arr[5];
        cout << "Reverse order of " << num << " is: ";
        for (int i=0 ; i<5; i++)
        {
            int digit = num%10;
            arr[i] = digit;
            num /= 10;
            cout << arr[i] << " ";
        } 
        
        int size = sizeof(arr)/sizeof(arr[1]);
        for(int j = 0; j<size-1; j++){
            for(int m = 0; m<size-1; m++){
                if(arr[m] > arr[m+1]){
                 int temp = arr[m];
                 arr[m] = arr[m+1];
                 arr[m+1] = temp;
                }
            }
        }
        cout << "& Descending order: ";
        for(int p = size-1; p>=0; p--){
        cout << arr[p] << " ";
        }
    }
};


int main()
{
    int number;
    cout << "Enter 5 digit number: " << endl;
    cin >> number;
    ReverseAndDescend dec;
    dec.sortFunc(number);
}
