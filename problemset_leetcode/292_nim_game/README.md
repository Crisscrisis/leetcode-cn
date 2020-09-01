## leetcode292 Nim游戏

### 思路
```
如果用dp算法，会超时或者空间过大溢出，使用脑筋急转弯方法即可：
只要保证我方抓完，给对方留下4的倍数的石子即可，那样的话，每次对方拿n个，我方就拿4-n个，这样总能让最后对方拿的时候，剩下4个，我方必胜。
反之，如果我方抓的时候，剩下的石子是4的倍数，则我方必输。
```

### code
```c++
class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 == 0) {
            return false;
        }
        return true;
    }
};
```