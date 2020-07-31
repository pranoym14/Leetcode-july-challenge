class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<size;i++)
        {
            int left=i+1;
            int right=size-1;
            int target=-nums[i];
            while(left<right)
            {
                int sum=nums[left]+nums[right];
                if(sum<target)
                    {left++;}
                else if(sum>target)
                    {right--;}
                else
                {
                    vector <int> temp(3,0);
                    temp[0]=nums[i];
                    temp[1]=nums[left];
                    temp[2]=nums[right];
                    result.push_back(temp);
                    while(left<right && nums[left]==temp[1])
                        {left++;}
                    while(left<right && nums[right]==temp[2])
                        {right--;}
                    
                }
                // cout<<left<<right<<i<<endl;
                while(i+1<size && nums[i]==nums[i+1])
                   { i++;}
                
            }
           
        }
        return result;
    }
};