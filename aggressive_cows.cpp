#include<bits/stdc++.h>
using namespace std;
 class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int start=1,end=stalls[n-1]-stalls[0];
        int ans;
        while(start <= end){
            int mid=(start+end)/2;
            int count=1;
            int pos=stalls[0];
            
            for(int i=1;i<n;i++){
                if(stalls[i] >= pos+mid){
                    count++;
                    pos=stalls[i];
                }
            }
            
            if(count < k){
                end=mid-1;
            }else{
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }
};
int main(){
vector<int>stalls= {1, 2, 4, 8, 9};
Solution sol;
int result=sol.aggressiveCows(stalls, 3);
cout<<"The distance between two cows should be :"<<result<<endl;
return 0;
}