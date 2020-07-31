class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> v;
        stack <int> s;
        int carry=0;int r;
        for(int  i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                r=digits[i]+carry+1;
            }
            else
                 r=digits[i]+carry;
            if(r>9)
            {
                r=r%10;
                carry=1;
            }
            else
                carry=0;
           s.push(r);
             //v.push_back(r);
        }
        if(carry==1)
            s.push(1);
        while(!s.empty())
        {
            
            v.push_back(s.top());
            s.pop();
           
        }
        return v;
    }
};