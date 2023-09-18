class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        for(int i = 0; i<mat.size(); i++)
        {
            pair<int, int>p = {0, 0};
            for(int j = 0; j<mat[0].size(); j++)
            {
                if(mat[i][j] == 1)
                {
                    p.first++;
                }
                   p.second = i;
            }
            pq.push(p);
        }
        while(pq.size() && k>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
        
    }
};