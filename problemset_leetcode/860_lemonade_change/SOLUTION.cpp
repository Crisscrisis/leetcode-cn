/* leetcode 860
 *
 *
 *
 */
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coins(2);
        if(bills.empty()) {
            return true;
        }
        int len = bills.size();
        for (int i = 0; i < len; i++) {
            if(bills[i] == 5) {
                coins[0]++;
            } else if(bills[i] == 10) {
                if(coins[0] >= 1) {
                    coins[0]--;
                    coins[1]++;
                } else {
                    return false;
                }
            } else { //bills[i] == 20
                if(coins[1] >= 1 && coins[0] >= 1) {
                    coins[1]--;
                    coins[0]--;
                } else if (coins[1] < 1 && coins[0] >= 3) {
                    coins[0] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};


/**************************   run solution   **************************/
bool _solution_run(vector<int>& bills)
{
    Solution leetcode860;
    bool ans = leetcode860.lemonadeChange(bills);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{

	return leetcode_2.addTwoNumbers(l1, l2);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif