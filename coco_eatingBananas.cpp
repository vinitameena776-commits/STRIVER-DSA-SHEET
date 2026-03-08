#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
bool canEatAll(vector<int>&piles,int mid,int h){
    int actualHours=0;
    for(int &x:piles){
        actualHours+=x/mid;
        if(x%mid!=0){
            actualHours++;
        }
    }
    return actualHours<=h;
}
int mineatingSpeed(vector<int>&piles,int h){
    int n=piles.size();
    int low=1,high=*max_element(begin(piles),end(piles));
    while(low<high){
        int mid=(low+high)/2;
        if(canEatAll(piles,mid,h)){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    return low;
}
};
int main(){
vector<int>piles={3,6,7,11};
Solution sol;
int result=sol.mineatingSpeed(piles,8);
cout<<"The number of bananas koko should eat per hour is:"<<result<<endl;
return 0;
}