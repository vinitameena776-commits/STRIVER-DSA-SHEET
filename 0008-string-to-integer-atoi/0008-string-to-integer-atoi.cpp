class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;

        //spaces
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n) return 0;

        //+ve -ve
        int sign=1;
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+'){
            i++;
        }

        //convert digit
        int ans=0;
        while(i<n && isdigit(s[i])){
            int digit=s[i]-'0';
            if(ans > (INT_MAX-digit)/10){
                //pos=max, neg=min
                return (sign==1)?INT_MAX:INT_MIN;
            }
            ans=ans*10+digit;
            i++;
        }
        return sign*ans;
    }
};