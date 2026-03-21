#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        //reverse whole string
        reverse(s.begin(),s.end());
        //now reverse each word seprately
        int i=0;
        int l=0,r=0;
        int n=s.length();
        while(i<n){
           while(i<n && s[i]!=' '){ // i ko agr character dikha tho r  ko dega and i++ and r++
           s[r++]=s[i++];
            }
            if(l<r){
                reverse(s.begin()+l , s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        s=s.substr(0,r-1);
        return s;
    }
};
int main(){
string s="I am a good girl";
Solution sol;
string ans=sol.reverseWords(s);
cout<<"The reversed string is : "<<ans<<endl;
return 0;
}