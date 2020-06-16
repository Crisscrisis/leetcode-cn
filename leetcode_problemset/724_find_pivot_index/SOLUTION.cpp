
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 2) {
            return -1;
        }
        int leftIdx = 0;
        int sum = 0;
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum * 2 + nums.at(i) == sum) {
                return i;
            }
            leftSum += nums.at(i);
        }
        return -1;
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& matrix)
{
    Solution leetcode724;
    return leetcode724.pivotIndex(matrix);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

