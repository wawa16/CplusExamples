#include <iostream>
#include <vector> 
#include <algorithm>
#include <ctime>    
using namespace std;

struct Sorted {
    std::string name;
    std::vector<char> alphas;   //vector stores alphabets from names
    int word_size;
};



void printOutput(const vector<Sorted> &);      //prints sorted output
vector<Sorted> shortList(string[], int &size); //sorting function



int main()
{
    //string names[9] = {"a","b", "ab", "bab", "babel", "bebe", "bf", "c", "beb"}; //Input Array of names
   string names[5] = {"doll","dolla","boo", "dollarboy", "bay"}; //Input Array of names
   
    int size = sizeof(names)/sizeof(names[0]);
    Sorted names_data[size];
    int count = 0;
    for(int i=0; i<size; i++){
        count = 0;
        names_data[i].name = names[i];
        names_data[i].word_size = names[i].length();
        while(count < names[i].length()){
            if(std::find(names_data[i].alphas.begin(), names_data[i].alphas.end(), names[i][count]) == names_data[i].alphas.end()) {
                names_data[i].alphas.push_back(names[i][count]);
            } else {}
           count++;
       }
    }
    
    string arr[size];
        for (int m=0; m < size; m++) 
        arr[m] = names[m]; 
        
    char unique = 'a';
    // names_data[i+1].alphas[num] = unique;
    // names_data[i].alphas[num] = my_unique;
   for(int j=0; j<size-1; j++){ 
    for(int i=0; i<size-1; i++){
        count = 0; int flag = 0;
        if(names_data[i+1].word_size > names_data[i].word_size){
            while(count < names_data[i].name.length()){
            if(std::find(names_data[i+1].alphas.begin(), names_data[i+1].alphas.end(), names_data[i].name[count]) == names_data[i+1].alphas.end()) {
                //names_data[i].alphas.push_back(names[i][count]);
            } else {
               flag++;
            }
            if (flag == names_data[i].alphas.size()){
                  string z = names_data[i].name;
                  names_data[i].name = names_data[i+1].name;
                  names_data[i+1].name = z;
                  int zi = names_data[i].word_size;
                  names_data[i].word_size = names_data[i+1].word_size;
                  names_data[i+1].word_size = zi;
                  std::vector<char> zv = names_data[i].alphas;
                  names_data[i].alphas = names_data[i+1].alphas;
                  names_data[i+1].alphas = zv;
                // Sorted z[1] = names_data[i];
                // names_data[i] = names_data[i+1].name;
                // names_data[i+1] = z[1];  
            }
           count++;
            }
       } else {
           cout << "eq or less" << " " << endl; 
       }
     }   
   }
    int m; 
        for (m=0; m < size; m++){ 
        cout << names_data[m].name << " " << endl; 
        //cout << "name:" << names_data[m].alphas.size() << endl;
}
    return 0;
}


// void printOutput(const vector<Sorted> &output){
//     string arr[output.size()];
//     int size = output.size();
//     cout << "short-listed array of names:" << endl;
//     for(int i=0; i<output.size(); i++){
//         cout << output[i].name << " ";
//     }
// }






