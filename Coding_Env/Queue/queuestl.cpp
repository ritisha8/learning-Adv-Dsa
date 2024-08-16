#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    cout<<"f:"<<q.front()<<" "<<"r:"<<q.back()<<endl;
    cout<<"size:"<<q.size()<<endl;
    cout<<"q.empty:"<<q.empty()<<endl;
    while(q.empty()==false){
     cout<<"f:"<<q.front()<<" "<<"b:"<<q.back()<<endl;
     q.pop();
    }
    return 0;
}