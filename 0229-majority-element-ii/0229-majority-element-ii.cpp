class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0 ,cnt2=0;
        int ele1=0,ele2=0;

        for(int x:nums){
            if(x==ele1){
                cnt1++;
            }
            else if(x==ele2){
                cnt2++;
            }
            else if(cnt1==0){
                ele1=x;
                cnt1=1;
            }
            else if(cnt2==0){
                ele2=x;
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        int c1=0 ,c2=0;
        for(int x:nums){
            if(x==ele1)c1++;
            else if(x==ele2)c2++;
        }

        vector<int>ans;
        if(c1 >n/3) ans.push_back(ele1);
        if(c2 > n/3) ans.push_back(ele2);

         return ans;
    }
};