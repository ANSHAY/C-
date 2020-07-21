class Solution {
public:
    vector<int> data;
    Solution(vector<int>& nums) {
        data = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> foo=data;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
        return foo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
