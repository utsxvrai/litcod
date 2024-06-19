class Solution {
private:
    int numberOfBouque(vector<int> &bloomDay, int &maxDay, int &k, int &n) {
       int ans = 0;
       int cnt = 0;
       for(int i=0; i < n; i++) {
            if(bloomDay[i] <= maxDay) {
                cnt += 1;
            } else {
                cnt = 0;
            }
            
            // if we found a continous subarray of size k with bloomDay[i] <= assumed_max_day>
            if(cnt == k) ans += 1, cnt = 0;
       }

       return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
     int n = bloomDay.size();
     if((n/k) < m) return -1; // can't divide n into m partitions of size k.

    // our answer will lie in this range
     int left = *min_element(begin(bloomDay), end(bloomDay));
     int right = *max_element(begin(bloomDay), end(bloomDay));
     
     int ans = -1;
     
     while(left < right) {
        int mid = left + (right - left ) /2;
        // number of banque we can make if we are mid as our anser
        int num = numberOfBouque(bloomDay, mid, k, n);
        // if we can make >= m banqute then we'll try to reduce the days and if can make >=m banquate using less number of day
        if( num >= m) ans = mid, right = mid;
        else left = mid + 1; // else we have increase our assumed number of days
     }

     return right; 
    }
};