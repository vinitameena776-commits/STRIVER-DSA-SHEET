#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    int n= arr.size();
        int low=1 ,high=n-2;
        while(low<=high){
            int mid=low+(high - low)/2;
            if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] > arr[mid-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};
int main(){
vector<int>arr={0,1,0};
Solution sol;
int ans=sol.peakIndexInMountainArray(arr);
cout<<"The peak index is : "<<ans<<endl;
return 0;
}