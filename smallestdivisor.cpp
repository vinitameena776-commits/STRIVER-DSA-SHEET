#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int sumByD(vector<int>&arr,int mid){
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        sum=sum+ceil((double)(arr[i]) / (double)(mid));
    }
    return sum;
}

int smallestDivisor(vector<int>&arr,int limit){
    int low=1,high=*max(arr.begin(),arr.end());;
    while(low <= high){
        int mid=(low+high) /2;
        if(sumByD(arr,mid) <= limit){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
};
int main(){
vector<int>arr={1,2,3,4,5};
Solution sol;
int result=sol.smallestDivisor(arr,8);
cout<<" The mminimum possible answer is :"<<result<<endl;
return 0;
}