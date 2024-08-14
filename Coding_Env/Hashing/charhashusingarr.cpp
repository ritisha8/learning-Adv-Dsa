
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;

  // charcter hashing using array  
    int hash[26]={0};   //we are doing hashing for only lower case charecters thats why we took an array of 26 numbers,
    // each no. representing a letter
    for(int i=0;i<s.size();i++){   //then we run aloop for traversing our string till less than s.size()
        hash[s[i]-'a']++;  // here we do s[i]-'a' because s[i] will return a char which will be typecasted to its ascii value that it 97
        // because hash is an int array then if we subract it from char 'a' which is also 97 , th result will be 0; and hence 0th location of hash will be incremented to 1
    }


    int q;
    cin>>q;
    while(q--){
        char d;
        cin>>d;
        //fetch
        cout<<hash[d-'a'];  // now here we do hash[d-'a'] because d is alrready declared as a charecter, so hash array willl take typecast it to its ascii lets say we take d input in d as its ascii is 101 and we dont have 101 ellemnts in our hash array
        // so we do d-'a' so that char a will be typecasted to its ascii 97 and now if we subtract their ascii we get 4 , and hash[4] will return all the occurances of d.
    }
   return 0;

}
