class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        
        vector <int>  o;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  minh;
    unordered_map <int,int> m;
    for(int i:arr)
        m[i]++;
    for(auto i=m.begin();i!=m.end();i++)
    {
        minh.push(make_pair(i->second,i->first));
        if(minh.size()>k)
            minh.pop();
        
    }
    while(minh.size()>0)
    {
        o.push_back(minh.top().second);
        minh.pop();
    }
    reverse(o.begin(),o.end());
    return o;
    

        
    }
};