class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        set<int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            if(s.find(nums[i])==s.end()) {
                s.insert(nums[i]);
                  it = s.find(nums[i]);
                it++;
                if (it != s.end()) s.erase(it);
            }

        }
        return s.size();
    }
};
