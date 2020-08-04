/* leetcode 4
 *
 *
 *
 */
#include <vector>
#include <algorithm>
class Solution {
public:
    // O(m+n)
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> mergeList;
    //     int p = 0;
    //     int q = 0;
    //     while (p < nums1.size() && q < nums2.size()) {
    //         if (nums1.at(p) < nums2.at(q)) {
    //             mergeList.push_back(nums1.at(p));
    //             p++;
    //         } else {
    //             mergeList.push_back(nums2.at(q));
    //             q++;
    //         }
    //     }
    //     if (p < nums1.size()) {
    //         while (p < nums1.size()) {
    //             mergeList.push_back(nums1.at(p));
    //             p++;
    //         }
    //     }
    //     if (q < nums2.size()) {
    //         while (q < nums2.size()) {
    //             mergeList.push_back(nums2.at(q));
    //             q++;
    //         }
    //     }
    //     int len = mergeList.size();
    //     if (len % 2 == 1) {
    //         return mergeList.at(len / 2);
    //     } else {
    //         return double((mergeList.at(len / 2) + mergeList.at(len / 2 - 1))) / 2;
    //     }
    // }

    // O(los(m+n))

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int c1, c2, l1Max, r1Min, l2Max, r2Min, lo = 0, hi = 2 * m;
        while (lo <= hi) {
            c1 = (lo + hi) / 2;
            c2 = m + n - c1;
            l1Max = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            r1Min = (c1 == 2 * m) ? INT_MAX : nums1[c1 / 2];
            l2Max = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            r2Min = (c2 == 2 * n) ? INT_MAX : nums2[c2 / 2];
            if (l1Max > r2Min) {
                hi = c1 - 1;
            } else if (l2Max > r1Min) {
                lo = c1 + 1;
            } else {
                break;
            }
        }
        return ((std::max(l1Max, l2Max) + std::min(r1Min, r2Min)) / 2.0);

    }

};


/**************************   run solution   **************************/
double _solution_run(vector<int>& nums1, vector<int>& nums2)
{
    Solution leetcode_4;
    double ans = leetcode_4.findMedianSortedArrays(nums1, nums2);
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