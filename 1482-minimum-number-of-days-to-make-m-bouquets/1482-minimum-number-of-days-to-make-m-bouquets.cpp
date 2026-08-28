
class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;

        for (int day : bloomDay) {
            if (day <= days) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;

                    if (bouquets >= m)
                        return true;
                }
            } else {
                flowers = 0;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long required = 1LL * m * k;

        if (required > bloomDay.size())
            return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

