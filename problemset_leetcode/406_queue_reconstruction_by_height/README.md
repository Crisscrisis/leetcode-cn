## leetcode406 根据身高重建队列

### 思路
```
首先按身高降序排列，相同身高的，按照k值升序排列。则从重新排好序的vector第一个开始，依次往后，每次都按照当前元素的k值，将其插入到从头开始数的位置上。
因为先排好了个子高的，后面个子低的再怎么排，都不会影响到个子高的排列。由于涉及随机的插入删除，则使用list最合适。
最终，使用容器初始化，直接返回vector即可。
```

### code
```c++
class Solution {
public:
    static bool cmpVec(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        } else {
            return a[0] > b[0];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty()) {
            return people;
        }
        sort(people.begin(), people.end(), cmpVec);
        int len = people.size();
        list<vector<int>> tmp;
        for (int i = 0; i < len; i++) {
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        return vector<vector<int>> (tmp.begin(), tmp.end());
    }
};
```