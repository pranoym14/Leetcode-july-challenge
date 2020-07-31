class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res;
        int i=0,j=0,carry=0;
        while(i<a.length() && j<b.length())
        {
            int sum=a[i]+b[j]-'0'-'0'+carry;
            if(sum==0)
            {
                carry=0;
                res+='0';
            }
            else if(sum==1)
            {
                carry=0;res+='1';
            }
            else if(sum==2)
            {
                carry=1;res+='0';
            }
            else if(sum==3)
            {
                carry=1;res+='1';
            }
            i++;j++;
        }
        while(i<a.length())
        {
            int sum=a[i]-'0'+carry;
            if(sum==0)
            {
                carry=0;
                res+='0';
            }
            else if(sum==1)
            {
                carry=0;res+='1';
            }
            else if(sum==2)
            {
                carry=1;res+='0';
            }
            else if(sum==3)
            {
                carry=1;res+='1';
            }
            i++;
        }
        while(j<b.length())
        {
            int sum=b[j]-'0'+carry;
            if(sum==0)
            {
                carry=0;
                res+='0';
            }
            else if(sum==1)
            {
                carry=0;res+='1';
            }
            else if(sum==2)
            {
                carry=1;res+='0';
            }
            else if(sum==3)
            {
                carry=1;res+='1';
            }
            j++;
        }
        if(carry==1)
            res+=to_string(carry);
        reverse(res.begin(),res.end());
        return res;
        
    }
};