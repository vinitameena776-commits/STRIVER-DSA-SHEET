#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
      int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(arr[mid]-mid-1 >= k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
          return low+k;
    }
};
int main(){
vector<int>arr={2,3,7,11,12};
Solution sol;
int ans=sol.findKthPositive(arr,5);
cout<<"Kth missing positive integer is : "<<ans<<endl;
return 0;
}