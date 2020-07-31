class Solution {
public:
//     vector<int> prisonAfterNDays(vector<int>& cells, int N) {
//         int k=N;
//         while(k--)
//         {
//             vector <int> temp(8,0);
//             for(int i=1;i<7;i++)
//             {
//                 if(cells[i-1]^cells[i+1])
//                     temp[i]=0;
//                 else
//                     temp[i]=1;
//             }
//             cells=temp;
//         }
//         return cells;
        
//     }  TLE
    vector<int> prisonAfterNDays(vector<int>& cells, int N)
    {
          int k=14;
        if(N==0)
            return cells;
        vector <vector <int> > r ;
        // r.push_back(cells);
        while(k--)
        {
            vector <int> temp(8,0);
            for(int i=1;i<7;i++)
            {
                if(cells[i-1]^cells[i+1])
                    temp[i]=0;
                else
                    temp[i]=1;
            }
            r.push_back(temp);
            cells=temp;
        }
        
        return r[(N-1)%14];
    }
};