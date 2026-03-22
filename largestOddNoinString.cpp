#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            if((num[i] - '0') % 2 != 0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
int main(){
string s="35427";
Solution sol;
string ans =sol.largestOddNumber(s);
cout<<"The largest string is : "<<ans<<endl;
return 0;
}