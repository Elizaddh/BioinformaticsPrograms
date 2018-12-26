// Simple Reversal Sort 
//Does not check if it is identitiy permutation
//Author: Eliza Dhungel
#include <iostream> 
#include <vector>  
#include <algorithm> 

using namespace std; 
int temp;

int main(){
        vector <int> a;
            while(cin >>temp){
                    a.push_back(temp);
                        }
                a.insert(a.begin(),0);
               // a.push_back(99999);

                for (int i =1; i <= a.size(); i++){
                   vector<int>::iterator it = find(a.begin(),a.end(),i);
                   int mindex;
                   mindex = distance(a.begin(),it);
                   if(mindex != i){
                       //cout<< "Seq is reversed", "\n";
                        reverse(a.begin()+i,a.begin()+mindex+1);
                   cout << "\n";
                        for (vector<int>::iterator it2 = a.begin() ; it2!=a.end(); it2++){
                                                  cout << *it2;
                        }

                       }
                
                }
}
