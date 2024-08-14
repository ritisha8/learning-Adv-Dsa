#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;

    map<char,int>mp;   // we create a DS map with char as its key and int as its value to store ocurances of charecters
    for(int i=0;i<s.size();i++){ // here we run a loop to trvaerse a string
        mp[s[i]]++;   // here s[0] is a lets say. if we do mp[a] initially it will return 0; because it has no elemnts currently
        // if do mp[s[i]]++ , it will store the string charecter as it s key and 1 as it corresponding value (occurance);
    }


    int q;
    cin>>q;
    while(q--){
        char d;
        cin>>d;
        //fetch
        cout<<mp[d];  // here if we do m[d] , it will fetch the value at "d" key.
    }
   return 0;

}