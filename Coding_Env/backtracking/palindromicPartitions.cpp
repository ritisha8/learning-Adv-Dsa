//Problem statement: here we need to print all posssible palindromic partitions of a string
//Inputs: we are given a string 
//Outputs: we need to return a 2d vector of strings , which contains allpssible combintions of string palindromes
//Approach: first we need to look for choices wht choices do we have at each step, lets say astring is "aba"
//first choice would be to take a , and then chcek whether it is palindrome or not, then we will check forfurther tring through recrsion , then if the sequence found  , it will besaved ina string vector , other wise the index wont reach the edn and we wikll not end up adding naything to vector<string> 
//now what we do is when the recusive call ends we bakctrak or rever the changes , thta is adding the sfirst eindex intovector ,and then we willmove to further itertion of for loop which will move  i to next index and nowwe will add s[i] to previous pal_string,we revertdthe vector <string> not the palinromic string
//so now we will ab in first partition, now this is not a palindrome sowe will not include it , and we wilmove to futher iteratiom of for
//so here we controlled the choices by putttting a function to check whther the first partof string isplaindrome ornot because if not, there is no point inmoving forwsrd with this combination, the the whole vcetor should be of palindromic strings
//why we use bakctraking here: no of schoces will be very large depending in the sie of string andvariable at eahc level
//we have to find dfferent combinations here,
//lets see the solution
/*
                               []
                                |
                  +------------+----------------+
                  |                             |
                 ["a"]                         ["aba"]
                  |                              |
         +--------+--------+              (Partition found: ["aba"])
         |                 |
      ["a", "b"]       ["a", "ba"] (Pruned, "ba" is not a palindrome)
         |
   +-----+-----+
   |           |
["a", "b", "a"] ["a", "b", "ab"] (Pruned, "ab" is not a palindrome)
   |
(Partition found: ["a", "b", "a"])


*/
            

#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>ans;
bool isPal(string pal){
    int i=0;
    int j=pal.size()-1;
    while(i<=j){
        if(pal[i]!=pal[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(string s,vector<string>&temp,int index){
    if(index==s.size()){
        ans.push_back(temp); //whenever we index reaches at evctor sizemeans it ha straversed allth string and madeall the combinations now we will add it to ans
        return;
    } 
    string pal_string="";
    for(int i=index;i<s.length();i++){  // choices loop
        pal_string=pal_string+s[i];
        if(isPal(pal_string)){
            temp.push_back(pal_string);  // we didi for the ith string , we  hcekcd if te string is palindrome , then we pushed it into vector ,now we will check  for the further string left that
            solve(s,temp,i+1);  // we diid index+1 here for solving next part ofthe string after ith
            temp.pop_back();
        }
    }
}
vector<vector<string>> PalPartitions(string s){
    vector<string>temp;
    //here what we need to pass in bT func , s string , ans vector, index which will move
    solve(s,temp,0);
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<vector<string>>v=PalPartitions(s);
    for(int i=0;i<v.size();i++){
       for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
       }
    }

    return 0;

}