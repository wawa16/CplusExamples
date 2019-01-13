#include <iostream>
using namespace std;

void printSorted(int[], int*);

int main()
{
    int arr[] = {2, 1, 3, 5, 9, 8, 4, 6, 0, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    printSorted(arr, &size);
    return 0;
}

void printSorted(int arr[], int *size){
   int i,j;
   for(j=0; j<*size-1; j++){
        for(i=0; i<*size-1; i++){
         if(arr[i] > arr[i+1]){
            int z = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = z;
         }
    }
    //cout << "seq: " << arr[j] << endl;
   }
      int m; 
        for (m=0; m < *size; m++) 
        cout << arr[m] << " "; 
}
