class Solution {
public:
    long long tothrs(vector<int>& piles, int hourly) {
        long long totalhrs = 0;

        for (long long pile : piles) {
            totalhrs += (pile + hourly - 1) / hourly;
        }

        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long total_hrs = tothrs(piles, mid);

            if (total_hrs <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};