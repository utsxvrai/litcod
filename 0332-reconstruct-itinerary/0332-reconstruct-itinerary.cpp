class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        stack<string> st;
        st.push("JFK");
        // using PQ to get airports in lexicographical order
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for (int i = 0; i < tickets.size(); i++)
        {
            adj[tickets[i][0]].push(tickets[i][1]);
        }

        vector<string> ans;
        while (!st.empty())
        {
            string node = st.top();
            if (adj[node].size() == 0)
            {
                ans.push_back(node);
                st.pop();
            }
            else
            {
                st.push(adj[node].top());
                adj[node].pop();
            }
        }
        // As we added the last vertex in path first, we need to reverse the ans vector
        reverse(ans.begin(), ans.end());
        return ans;
    }
};