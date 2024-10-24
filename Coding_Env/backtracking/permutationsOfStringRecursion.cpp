// the aprioach is thta there are choices and decisions so recusrsion is posssible , so we are implemntting it with recursion first , there are larger as well as varuable choices thta makes it a question of bakctrsking but thta oesnot denythta it is recursion, so lets try and solve it with recrysion first 
#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op, vector<string>&v){
    if(ip.size()==0){ 
        v.push_back(op);  // base condition ,according to tree when we make a tree of it at last when ip is empty we the ans in op string, so we are addign it in vector
    }
    unordered_set<char>st;
    // for loop for choice because of larger andvariable choices we need a for loop here, like normal recrsion problem here the no. of chocies arenot contant , they are variable
    for(int i=0;i<ip.size();i++){  // so we run a loop  ip size,beause thtas how manyplaceholders we need to fill andthta is exactl tghe number of choices thta we have to flll theplceholders 
      if(st.find(ip[i])==st.end()){  // if he charecter has not been used before it will not be found inset and hence will be equal to st.end()
        st.insert(ip[i]);  // so we make it as used
        string newip=ip.substr(0,i)+ ip.substr(i+1);  // from the tree we observe that fromip s[i] is delted and in output it is added
        string newop=op+ip[i];  
        solve(newip,newop,v);
      }
    }
}
vector<string> permute(string s){
    vector<string>v;
    solve(s," ",v);
    return v;
}
int main(){
    string s;
    cin>>s;
    vector<string>v=permute(s);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}