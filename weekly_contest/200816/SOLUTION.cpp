/* weekly contest
 * 2020/08/16
 * leetcode 1550, 1551, 1552
 *
 */
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    // leetcode 1550
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        int flag = 0;
        for (int num : arr) {
            if (num % 2 == 1) {
                flag++;
            } else {
                flag = 0;
            }
            if (flag == 3) {
                return true;
            }
        }
        return false;
    }

    // leetcode 1551
    int minOperations(int n) {
        if (n == 1) {
            return 0;
        }
        // target == n
        int operation = 0;
        for(int i = 0; i < n /2; i++) {
            operation += n - (2 * i + 1);
        }
        return operation;
    }

    // leetcode 1552
    bool isMatched(vector<int>& position, int m, int dis) {
        int cnt = 0;
        int pre = position[0];
        int len = position.size();
        for(int i = 1; i < len; i++) {
            if (position[i] - pre >= dis && position[len - 1] - position[i] >= dis) { // current position to left, right borad >= distance
                pre = position[i];
                cnt++;
            }
            if (cnt == m - 2) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int len = position.size();
        int minDis = INT_MAX;
        for(int i = 1; i < len; i++) {
            if (minDis > position[i] - position[i-1]) {
                minDis = position[i] - position[i-1];
            }
        }
        int maxDis = (position[len - 1] - position[0]) / (m - 1);
        int l,r;
        l = minDis;
        r = maxDis;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(isMatched(position, m, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l-1;
    }

    // leetcode 1552
    unordered_map<int, int> ans;
    int dfs(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (ans.count(n)) { // find ans[n]
            return ans[n];
        }
        int tmp = min(dfs(n/3) + n % 3 + 1, dfs(n/2) + n % 2 + 1);
        ans[n] = tmp;
        return tmp;
    }
    int minDays(int n) {
        return dfs(n);
    }
};


/**************************   run solution   **************************/
#if 0 //leetcode 1552
int _solution_run(vector<int>& position, int m)
{
    Solution weekly_contest;
    int ans = weekly_contest.maxDistance(position, m);
    return ans;
}
#else
// leetcode 1553
int _solution_run(int n)
{
    Solution weekly_contest;
    int ans = weekly_contest.minDays(n);
    return ans;
}
#endif
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