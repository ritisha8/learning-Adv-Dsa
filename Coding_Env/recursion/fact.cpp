//designing hypothesis
// ifwe want to write fact (n), weknow fact(5) is going to return 5*4*3*2*1
// same way fact(4) is going to give 4*3*2*1 nowwe just need 5 to be multiplied to fact of 4
//byusing induction base consditionand hyposthesis rule(IBH)
#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==1) return 1;   // base condition
    return n*fact(n-1);   //induction step + defining hyposthesis
}
int main(){
    int n;
    cin>>n;
    cout<<"fact of "<<n<<":"<<fact(n);
    return 0;
}
