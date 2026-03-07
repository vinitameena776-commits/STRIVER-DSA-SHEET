#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int floorsqrt(int n){
    int low=1,high=n;
    int ans=n;
    while(low<=high){
        long long mid=(low+high)/2;
        long long val=mid*mid;
        if(val<=n){
            low=mid+1;
            ans=mid;
        }else{
            high=mid-1;
        } 
    }
    return ans;
}
};
int main(){
Solution s;
cout<<"The sqrt is :"<<s.floorsqrt(36)<<endl;
return 0;
}