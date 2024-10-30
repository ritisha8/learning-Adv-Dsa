//here wHAT we need to do is we are given an old phone number style mapping in question and with each dgit , we have equial chances thta any chrecter can come from the string it is mappedto , like in old phones keypad
// we saw 2 mapped to abc , 3  to def, and so on, so here we need to find different combnations of mapping of the string we will be given '
// if we are given "23" then first we will look for choices of 2 what do we have , we can either take a , or b , or c, right?, and now we move the index to index +1 like in previous question when work of one call is done we make a recursive call for frther same operatiions on the string with index +1
// a like thta we do here, and here , we donot actually have any control, we want all the combinations we can get for the digits string we are given,


#include<bits/stdc++.h>
using namespace std;
void solve(int idx,string s,unordered_map<char,string>mp,vector<string>&ans,string &temp){
//base case
if(idx==s.size()){
    ans.push_back(temp);
    return;
}
char ch=s[idx];  // lets say 0 is passed as first index so s[0] , will be stored in ch
for(int i=0;i<mp[ch].size();i++){  // then we will put this ch in map and  see the mapped tring , and this for loop will run till the mappes string's size
    temp=temp+mp[ch][i];
    solve(idx+1,s,mp,ans,temp);
    temp.pop_back();
}
}

vector<string> combinations(string s){
vector<string>ans;
if(s.size()==0) return ans;

//what we want are choices in for loop what choices we hav here only strig right? we need to map the string to those letters like in keypad and store them so that we can furthwer use them while aking choices
unordered_map<char,string>mp;

mp['2']="abc";
mp['3']="def";
mp['4']="ghi";
mp['5']="jkl";
mp['6']="mno";
mp['7']="pqrs";
mp['8']="tuv";
mp['9']="wxyz";

// to store the string at each point this is the string thta will be passed by reference and hence will be vaktraked and rverted and used for further calls , this same string
string temp; 

//function to solve this question and fetch us combinations
solve(0,s,mp,ans,temp);
return ans;
}
int main(){
    string s;
    cin>>s;
    vector<string>v=combinations(s);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}