class Solution {
public:
    // int addDigits(int num) {
    //   int x=num;
    //     while(x>9)
    //     {
    //         int y=x,d,r=0;
    //         while(y)
    //         {
    //             d=y%10;
    //             r+=d;
    //             y/=10;
    //         }
    //         x=r;
    //     }
    //     return x;
    // }  //brute force
    int addDigits(int num) {
        if(num==0)
            return 0;
        if(num%9==0)
            return 9;
        else
            
        return num%9;
        
    }
};