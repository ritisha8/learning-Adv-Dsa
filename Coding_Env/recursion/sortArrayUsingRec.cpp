//using ibh method
//in ibh method we have to see the hypothesis first and then accordinly we define base condition and then we do induction hat is define a code to run the hypotheisis
//in thisypoprtheisis would be that we are given a vector which ww have tp sort using recusrion and so we assume that 
// sort(v )isgoing to sort all the lelemnts of v in ascending order, and and now in order to perform recursion we need to make the input small so we ill remove the last llemnt of the vector and storre it in a variable and then then we call the sort fucntionaggain recusrsively
// nowin hypothesisi we are assuming that if it sorts the whiole vector inascecndinm order it will aslso sort the vector whne we have removed the last ellemntand now we just need to insert the last ellemnt into the vector

#include<bits/stdc++.h>
using namespace std;

//in this insert fucntion what are we going to do , wwe ar going to insert the last ellemnt at its correct position 
// so we will find here the correct position oflast ellemnt by 
void insert(int temp,vector <int>&v){  
   if(v.size()==0 || v[v.size()-1]<=temp){  // least valid input is 0 and not one becauese we are poppiung the last lelemnt of vector at each  step
   // i .e making input smaller, so if we take least possible input to be 1 , so now we have popped all llements and temp is smaller than all of them and niow it is amlller than 1stv ellemts as well 
   // it is possible right so we pop that as well and now we do have mepty vectior and nown we will push this temp in it , and it ca also happen tghatv we found the last ellemnt to be smaller than temp allready now we 
   //son simpty bwe will pushb temp after it, these two are the vbaseb conditions here
    v.push_back(temp);  
    return ; // after pushingn back the llemnt we simply we simply return to the calling function 
   }
  int val= v[v.size()-1];  // sif vector last ellemnt is not less than temp now we make input smaller byb storing ht last llemnt of vector in  a variable val
  // and now we will pop it 
  v.pop_back();
  insert(temp,v); //and then we run insert functyionn agaionn with same tyemp and smalller vector with last value removed
  // now hypotheticallly this function will insert the temp at its correct posiition now becauseb this is  magic function
  //and now we need to insett the lastb ellemnt back , the onme we popped from the vector 
  v.push_back(val);

}
void sort(vector <int>&v){
    if(v.size()==1) return ;  // defining base condition ,  
    // making input small
    int temp=v[v.size()-1];   // by removing last ellemtnof array and storing it in temp;
    v.pop_back();  
    sort(v);  //now we will sort v.size()-1 ellemnts in ascedning order
    insert(temp,v);   // and then we will insert the popped out elelmnt using this insert fucntion which is also recursive
}
int main(){
    vector<int>v={5,1,0,2};
    sort(v);
    for (int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
    }
    return 0;
    
}