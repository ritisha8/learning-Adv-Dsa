//problem statement: here what we need to do is swap the string number to make it the largest number in limited k values,like we are given limited swaps 
//and we need to make the largest number we can from that
// then we saw how we make do bakctarking =controlled recursion + pass by reference
// lets see why is there a need for bakctarcking here, this question can be done with greedy aproach as well
//assume we hve elements [1,2,3,4] we have k =2 , what is greedy aprroach is : when we want to achieve a long term goal with short term doings
// so here we can claerly see , that if we swap the maximum and first index , we will be done with 1 swap ,and left with kswaps , then we can 
//swap i+1 elemnt by finding the max among further i+2 and onwards, and then we will get the mximum number we can get in limited swaps

// but what if we have duplicate elements , 98368, the greedy aaproach will give us 98368->9

#include<bits/stdc++.h>
using namespace std;
void solve(string &s,int k,string &res,int start){
    //bc
    if(k==0 || start==s.length()-1){  // here we donotrweach the leaf node because  we have limitedk values ,so we keep the possibility of when k=0, and when start 
    //becomes s.length()-1
        return;  //then we simply return we dont store values here , because its not compulsr thta we get values here only we can get values anywhere inbetween 
    }
    char max=*max_element(s.begin()+start+1,s.end());  // we find out the maximum ellemnt in order to check further if the max elemnt is getting swapped or not
    for(int i=start+1;i<s.length();i++){ // we run a loop fromstart +1 because we dont want the string to havea choice of choose its own, because thta wouldnt be much helpful 
    //we will end up wasting our K's
        if(s[start]<s[i] && s[i]==max){  // then we will prune the choices which are notthe max elemnt and if theya are max elemnt but less than s[start] then prune it
            swap(s[start],s[i]);  // then we swap swap(s[start],s[i])
            if(s.compare(res)>0){  // now we chekc if teh string we have now is greater than the string we had before
            // if yes we storeit in res
                res=s;  // this checking we do order to ensure thta we get the largest elemnt
            }
              solve(s,k-1,res,start+1);  // case 1 wherewe we donot allready have largest string
              swap(s[start],s[i]);  //then we backtrack
        }
    }
    solve(s,k,res,start+1); // case 2  when we are already given the largest number
}
string largest(string s,int k){
    string res=s;
    solve(s,k,res,0);// result will store the final output
    return res;
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<largest(s,k);
    return 0;
}