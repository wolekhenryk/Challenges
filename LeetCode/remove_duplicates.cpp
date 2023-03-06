class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        auto newEnd = unique(nums.begin(), nums.end());
        nums.erase(newEnd, nums.end());

        int k = 0;
        for (const auto& e : nums) k++;
        return k;
    }
};