#include<bits/stdc++.h>
using namespace std;
 class Stack{
    vector<int>v;
    public:
    void push(int val){
        v.push_back(val);
    }

    void pop(){

        v.pop_back();
    }

    int top(){
        return v[v.size()-1]; // can also use v.back()
    }

    bool empty(){
        return v.empty();
    }
 };

int main(){
Stack s;
s.push(10);
s.push(20);
s.push(30);

while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
}
cout<<endl;//30 20 10
return 0;
}