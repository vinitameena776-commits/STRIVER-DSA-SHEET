class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,char>mp;
        unordered_map<char,char>mpp;

        for(int i=0;i<s.length();i++){
            if(mp.count(s[i])){
                if(mp[s[i]]!=t[i]) return false;
            }
            else mp[s[i]]=t[i];

            if(mpp.count(t[i])){
                if(mpp[t[i]]!=s[i])return false;
            }
            else mpp[t[i]]=s[i];
        }
        return true;
    }
};