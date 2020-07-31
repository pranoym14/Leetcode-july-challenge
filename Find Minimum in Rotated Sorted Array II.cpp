class Solution {
public:
    int findMin(vector<int>& nums) {
        priority_queue <int,vector<int>, greater<int>> g;
        for(int i:nums)
            g.push(i);
        return g.top();
    }
};