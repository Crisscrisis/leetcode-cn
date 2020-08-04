/* leetcode 15
 *
 *
 *
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) {
            return ans;
        }
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if (nums.at(i) > 0) {
                return ans;
            }
            if (i > 0 && nums.at(i) == nums.at(i-1)) {
                continue;
            }
            int lo = i + 1;
            int hi = nums.size() - 1;
            while(lo < hi) {
                int sum = nums.at(i) + nums.at(lo) + nums.at(hi);
                if(sum == 0) {
                    vector<int> sample = {nums.at(i), nums.at(lo), nums.at(hi)};
                    ans.push_back(sample);
                    while(lo < hi && nums.at(lo) == nums.at(lo+1)) {
                        lo++;
                    }
                    while(lo < hi && nums.at(hi) == nums.at(hi-1)) {
                        hi--;
                    }
                    lo++;
                    hi--;
                } else if(sum > 0) {
                    hi--;
                } else if(sum < 0){
                    lo++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(vector<int>& nums)
{
    Solution leetcode_15;
    vector<vector<int>> ans = leetcode_15.threeSum(nums);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{

}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif