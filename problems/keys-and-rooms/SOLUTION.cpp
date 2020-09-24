
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vi(rooms.size(), false);

        queue<int> que;
        que.push(0);
        vi[0] = true;
        while (!que.empty()) {
            auto q = que.front();
            que.pop();

            for (auto n : rooms[q]) {
                if (vi[n]) continue;
                que.push(n);
                vi[n] = true;
            }
        }

        return all_of(vi.begin(), vi.end(), [](bool b) { return b; });
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& rooms)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.canVisitAllRooms(rooms);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
