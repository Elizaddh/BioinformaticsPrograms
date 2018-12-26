/*Improved reversal sort that reverses decreasing strand to decrease breakpoint by one 
in presence of decreasing strand and flips the increasing strand in absence of decreasing strand
@author : Eliza Dhungel
*/ 

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

//function to check the presence of breakpoints
bool hasBreakpoints(vector <int> b){
    bool temp = 0;
    int val = 0;
    for (int i = 1; i <= b.size()-1; i++){
        if (b[i] == b[i-1]+1){
            val++;
        }
        if (val == b.size()-1)
            temp = false;
        else temp = true;
    }
//    cout << "Has breakpoint is " << temp ;
    return temp;
}

//function that returns the last index of increasing strip
vector<int>increasingstrip(vector<int>c){ 
   vector<int>incindex;
  // cout << "incrasing indes are as follows ";
   for(int i= 1; i <= c.size()-1; i++){
   if (c[i]==c[i-1]+1 && c[i+1]!= c[i]+1){
           incindex.push_back(i);
       //    cout << i << " ";
           }      
   } 
   return incindex ; 
}  

//function that returns the last index of decreasing strip and singletons index
vector<int> decreasingstrip(vector<int>d){ 
    vector<int>decindex;
    //cout << "Decreaing is working" << "\n";
    for (int i =1; i<= d.size()-1;i++ ){
        if(d[i]== d[i-1]-1 && d[i+1]!= d[i] - 1 ){
        decindex.push_back(i);
        }        
    }
    for (int i = 1; i<d.size()-1; i++){
        if(d[i]!= d[i+1]+1 && d[i]!= d[i+1]-1 && d[i]!= d[i-1]-1 && d[i]!= d[i-1]+1){
        decindex.push_back(i);
        }
    }
    return decindex;
}

//function that picks reversal indexes
void reversalindexes(vector<int>ince, vector<int>dece, vector<int>e , int &indexi, int &indexj){
   // cout << "The reveresal indeces is working" << "\n";
    vector<int>decarr;
    if(dece.size()!=0){
    for(vector<int>::iterator it = dece.begin(); it!= dece.end(); ++it){
        decarr.push_back(e[*it]);
    }
    
    vector<int>::iterator iti = find(e.begin(),e.end(), *(min_element(decarr.begin(), decarr.end())));
    vector<int>::iterator itj = find(e.begin(),e.end(), *(min_element(decarr.begin(), decarr.end()))-1 );
    //cout<< *(min_element(decarr.begin(), decarr.end()));
    indexi = distance(e.begin(),iti);
    indexj = distance(e.begin(), itj)+1;
   // cout <<"The minimum index minus one  is " << indexj << "\n";
   // cout << "The minimum index is " << indexi << "\n" ;

  //  cout << "The size of vector is " << e.size();
    //position of minimum index of decreasing strip
    //return indexj; //if possible
    }
    
     else if (ince[0]!= ince.size()-1 ||  ince.size() != 0 ){
         indexi = ince[0] + 1 ;
         indexj= ince[1] + 1;
     }
}


int main(){
    vector <int> a;
    int myinpt;
    while(cin >> myinpt){ // allows numeric input. input is signalled to terminate by non-numeric/character input.  cant handle negative input/does not have checkpoints to see if input values are continuous.
        a.push_back(myinpt);
    }
    a.insert(a.begin(),0);
    a.push_back(a.size());
   // bool result1 = hasBreakpoints(a);
    
    vector<int>instripindex;
    instripindex = increasingstrip(a);
    //cout <<"The function is good", instripindex.size();
    //cout << " the increasing indexes are ";
   // for (int i = 0; i< instripindex.size(); i++){
  //  cout <<instripindex[i] << " " ; 
   // }
    
    cout << '\n';
    vector<int>destripindex;
    destripindex = decreasingstrip(a);
    //cout << "The decreasing indexes are ";
    //for(int i = 0; i< destripindex.size();++i){
   // cout << destripindex[i] << " ";
   // }
    
    int ofdestripi;
    int ofinstripj;
    // Perform breakpoint reversal sort
    while(hasBreakpoints(a)!= false){
    instripindex = increasingstrip(a);
    destripindex= decreasingstrip(a);
    reversalindexes(instripindex, destripindex, a, ofdestripi, ofinstripj);
    //cout << "Before reversal " << a.size() << "\n" ;
    if(destripindex.size()!=0){
    if(ofdestripi  > ofinstripj){
        if(ofinstripj==a.size()-1)
            reverse(a.begin() + ofinstripj, a.begin()+ofdestripi);
        else
            reverse(a.begin() + ofinstripj , a.begin()+ofdestripi+1);
    }
    else{
        reverse(a.begin()+ofdestripi, a.begin()+ofinstripj+1);
    }
         }
    else if(instripindex.size()!=1 && instripindex[0]!=instripindex.size() - 1){
    reverse(a.begin()+ofdestripi, a.begin()+ofinstripj);
    }
        for(vector <int>:: iterator it  = a.begin(); it!=a.end();it++){
        cout <<*it << " " ;
        }
        cout << "\n\n";
        if (hasBreakpoints(a)==false)
        break;
    }
}

