## leetcode860 柠檬水找零

### 思路
```
设置一个数组，存储当前拥有现金的数量（为节省空间，20元现金数量不需要存储，因为不会用于找零）。
根据当前收到的现金，会有不同的现金处理逻辑，注意，若遇上20元，有10+5和5+5+5的找零方案，优先选择10+5方案。
```

### code
```c++
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
```