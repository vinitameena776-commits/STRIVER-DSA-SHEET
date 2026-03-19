#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        for (int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(count > 0) ans.push_back(s[i]);
                count++;
            }
            else{
                count--;
                if(count > 0) ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
int main(){
string s = "((()))";
Solution sol;
string ans=sol.removeOuterParentheses(s);
cout << ans;
return 0;
}