class Solution {
public:
    string reverseWords(string s) {
        //j->reads characcter 
        //i-> writes cleaned string
        int i=0,j=0;
        int n=s.size();

        while(j<n){
            //ignore all spaces before a word 
            while(j<n && s[j]==' ') j++;

            //copies char of a word
            while(j<n && s[j]!=' ') s[i++]=s[j++];

            //removes extra space b/w words
            while(j<n && s[j]==' ')j++;

            //ensures only ONE space between words
            if(j<n) s[i++]=' ';
        }
        
        //removes garbage leftover characters
        s.resize(i);
        
        //words are reversed
        reverse(s.begin(),s.end());

        int start=0;
        for(int end=0;end<=s.size();end++){
            if(end==s.size() || s[end]==' '){
                reverse(s.begin()+start , s.begin()+end);
                start=end+1;
            }
        }
        return s;
    }
};