class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        const int bloom_start=-1, bloom_end=people.size();
        vector<pair<int, int>> q;//index + event: start, visitor,end of bloom
        //
        for(int i=0; i<flowers.size(); ++i) {
            q.emplace_back(flowers[i][0], bloom_start);
            q.emplace_back(flowers[i][1], bloom_end);
        }
        for(int i=0; i<people.size(); ++i) {
            q.emplace_back(people[i], i);
        }
        sort(q.begin(), q.end());
        //
        vector<int> result(people.size());
        int curr=0;//current blossoming flowers
        for(int i=0; i<q.size(); ++i) {
            auto [index, event]=q[i];
            if (event==bloom_start) {
                //start of new interval
                curr++;
            }
            else if (event==bloom_end) {
                //end of interval
                curr--;
            }
            else {
                //visitor
                result[event]=curr;
            }
        }
        return result;
 
    }
};