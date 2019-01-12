/* This program accesses array of random integers via pointer increment */

#include <iostream>
#include <stdlib.h>		/* srand, rand */
#include <time.h>		/* time */
using namespace std;   
int *pointerArray (int[]); //function returns a pointer
int main ()
{
  int arr[10];
  cout << "Hello World\n";
  srand (time (NULL));
  int *ptrr = pointerArray (arr);
  cout << ptrr << endl;
  for (int i = 0; i < 10; i++) //Pointer increment to access array members
   {
    cout << "Pointer values: " << *(ptrr + i) << endl;
   }
  return 0;
}  
int * pointerArray (int arr[])
{
  static int *ptr = &arr[0];
  for (int i = 0; i < 10; i++)
    {
      arr[i] = rand () % 10;
     // cout << "Random no: " << arr[i] << endl;
    }
  return ptr; //returning pointer to only first element of array
  }

