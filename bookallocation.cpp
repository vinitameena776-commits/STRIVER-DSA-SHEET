#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int countStudents(vector<int>&arr , int mid){
    int n=arr.size();
    int student =1;
    long long pages=0;
    for(int i=0;i<n;i++){
        if(pages + arr[i] <= mid){
            pages+=arr[i];
        }else{
            student++;
            pages=arr[i]; // ab wo page 2nd wale ko milega 
        }
    }
    return student;
}

int findPages(vector<int>&arr,int k){
    int n=arr.size();
    if(k > n) return -1;
    int low= *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid=(low+high)/2;
        int students=countStudents(arr,mid);
        if(students > k){
            low=mid+1;
        }else{
           high=mid-1;
        }
    }
    return low;
}
};
int main(){
    vector<int> arr = {12,34,67,90};
    Solution obj;
    int ans = obj.findPages(arr, 2);
    cout << "The answer is: " << ans << "\n";
return 0;
}