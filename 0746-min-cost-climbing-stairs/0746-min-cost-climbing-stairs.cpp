class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> t(cost.size() + 2);
		t[cost.size()] = 0;
		t[cost.size() + 1] = 0;

		for(int i = cost.size() - 1; i >= 0; i--)
		{
			t[i] = min(cost[i] + t[i + 1], cost[i] + t[i + 2]);
		}
		return min(t[0], t[1]);
    }
};