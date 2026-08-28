class Solution {
public:
    int SumByDiv(vector<int>& nums, int div) {
        int sum = 0;

        for (int num : nums) {
            sum += (num + div - 1) / div;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        if (nums.size() > threshold) {
            return -1;
        }

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (SumByDiv(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};