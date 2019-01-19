#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

void printOutput(const vector<string> &);      //prints sorted output
vector<string> shortList(string[], int &size); //sorting function

int main()
{
    string names[7] = {"alison", "bob", "kate", "son", "carl", "ansen", "mike"}; //Input Array of names
    int size = sizeof(names)/sizeof(names[0]);
    
    printOutput(shortList(names,size));
    
    return 0;
}

vector<string> shortList(string names[], int &size){
     std::vector<char> alphabets;   //vector stores alphabets from names
     std::vector<string> output;   //vector contains final sorted output
     
       for(int i=0; i<size; i++){
       int count = 0;
       int state = 0;
       while(count < names[i].length()){
           if(std::find(alphabets.begin(), alphabets.end(), names[i][count]) == alphabets.end()) {
              alphabets.push_back(names[i][count]);
              state++;
            }
           count++;
       }
       if(state != 0){
           output.push_back(names[i]);
       }
    }
    return output;
}
