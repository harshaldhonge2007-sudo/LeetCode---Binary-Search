class Solution {
public:
int CountPart(vector<int> &nums, int maxsum) {
    int partitions = 1;
    int subarraysum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (subarraysum + nums[i] <= maxsum) {
            subarraysum += nums[i];
        } else {
            partitions++;
            subarraysum = nums[i];
        }
    }

    return partitions;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (CountPart(nums, mid) > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}
};