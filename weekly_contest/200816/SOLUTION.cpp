/* weekly contest
 * 2020/08/16
 *
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

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int len = position.size();
        vector<int> distance(len);
        distance[0] = 0;
        for(int i = 1; i < len; i++) {
            distance[i] = position[i] - position[i-1];
        }
        sort(distance.begin(), distance.end());
        int maxDis = (position[len - 1] - position[0]) / (m - 1);
        int pre, resNum;
        int j = len - 1;
        for (int dis = maxDis; dis > 0; dis = distance[j--]) {
            pre = position[0];
            resNum = m - 2;
            for (int i = 1; i < len - 1; i ++) {
                if (position[i] - pre >= dis) {
                    pre = position[i];
                    resNum--;
                }
                if (resNum == 0 && position[len - 1] - pre >= dis) {
                    return min(dis, position[len - 1] - pre);
                }
            }
        }
        return 1;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& position, int m)
{
    Solution weekly_contest;
    int ans = weekly_contest.maxDistance(position, m);
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