#include<bits/stdc++.h>
using namespace std;
//leetcode vesion -see on leetcode (LC-74)
//GFG VERSION
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int target) {
        int m=mat.size() ,n=mat[0].size();
        int r=0 ,c=n-1;
        while(r < m && c >=0 ){
            if(target==mat[r][c]){
                return true;
            }
            else if(target < mat[r][c]) c--;
            else r++;
        }
        return false;
    }
};
int main(){
vector<vector<int>>mat = {{3, 30, 38},{20, 52, 54},{35, 60, 69}};
Solution sol;
bool ans = sol.matSearch(mat, 35);

 cout << ans << endl;

return 0;
}