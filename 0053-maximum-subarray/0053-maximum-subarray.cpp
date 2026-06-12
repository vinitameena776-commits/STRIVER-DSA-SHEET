class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum=0;
        long long maxi=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums.size()<=0) return nums[i];
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
    
        }
        return maxi;
    }
};