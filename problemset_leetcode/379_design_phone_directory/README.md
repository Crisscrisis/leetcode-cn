## leetcode379 电话目录管理系统

### 思路
```
使用一个vector<bool>来维护即可。
```

### code
```c++
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        direct.resize(maxNumbers, true);
        size = maxNumbers;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for (int i = 0; i < size; i++) {
            if (direct[i] == true) {
                direct[i] = false;
                return i;
            }
        }
        return -1;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if (number > size - 1 || number < 0) {
            return false;
        }
        return direct[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < size) {
            direct[number] = true;
        }
    }
private:
    vector<bool> direct;
    int size;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
```