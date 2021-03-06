### leetcode problemset 使用说明

该文件夹下均为Lucas的leetcode problemset，同原作者的目录隔离开。

#### 使用test.txt的方法：

test.txt自动将传入的字符转化为string类型，所以如果题目中的输入时string类型，则不能加""，否则""也会被算进去。每个输入占一行，输出结果占最后一行。

例1.输入为如下形式：

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

    }
};
```

则完整的1个输入用例为2行，第一行为输入，第二行为结果

```
[1, 2, 3]
[1, 2, 4]
```

例2.输入为如下形式：

```c++
class Solution {
public:
    string addBinary(string a, string b) {

    }
};
```

则完整的1个输入用例为3行，第一行为输入a，第二行为输入b，第三行为结果（不能加""）

```
11
1
100
```

例3.输入为空字符

```c++
""
```

则直接空一行即可

```c++

```

#### 测试ListNode类型的用例方法：
需要在Test.cpp和SOLUTION.cpp中打开定义#define USE_SOLUTION_CUSTOM
自己设计 _solution_custom，其中每个链表的值，在test.txt中可以用[]括起来，然后在测试用例中，每次按照string的方式读取一行，
然后用StringToListNode将其转换为ListNode链表

例：
```c++
ListNode* _solution_custom(TestCases &tc)
{
	string a = tc.get<string>();
	ListNode *l1 = StringToListNode(a);
    string b = tc.get<string>();
	ListNode *l2 = StringToListNode(b);
    Solution leetcode_21;
	return leetcode_21.mergeTwoLists(l1, l2);
}
```