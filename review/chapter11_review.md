# chapter 11 复习整理

> 说明：当前线程没有可读取的更早聊天记录，所以“之前问过的问题”无法直接还原；本文件主要依据 `chapter 11/q` 的 10 道题面、对应 cpp，以及代码中的注释/提醒整理。

## 总体高频考点

- 模板函数：`template <typename T>`、函数参数用 `const vector<T>&` 或 `const basic_string<T>&`。
- 模板类：成员变量、构造函数、成员函数、非类型模板参数如 `template <typename T, size_t MAX_SIZE>`。
- STL 容器：`vector`、`basic_string`、`push_back`、`back()`、下标访问。
- 输入输出：`cin` 读数字数组，`getline` 读整行字符串，输出时控制空格。
- 泛型思维：内部变量类型尽量用 `T`，不要写死 `int`，否则模板失去意义。
- 边界情况：空字符串、重复元素、负数求最大值、输出末尾多空格、题目要求“二分”但写成线性查找。

## 第 1 题：SortedVector 二分查找

考点：模板类、向量成员、在有序数组中查找目标元素。

题目要求：
- 编写模板类 `SortedVector<T>`。
- 成员函数在已排序向量中进行二分查找。
- 找到返回下标，找不到返回 `-1`。

当前代码可能扣分的点：
- 函数名叫 `binarySearch`，但实现是从头到尾线性遍历，不是真正二分查找。
- 如果题目严格检查“二分”，应使用 `left/right/mid`。

复习提醒：
```cpp
int binarySearch(T target) {
    int l = 0, r = sv.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (sv[mid] == target) return mid;
        if (sv[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```

## 第 2 题：countCharacters 字符计数

考点：函数模板、`basic_string<CharType>`、自定义结构/类保存字符和次数、保持首次出现顺序。

你注释里的错点：
- 用 `basic_string<T>` 表示传进来的字符串类型，这样函数模板可以适配不同字符类型。
- `out` 的下标和原字符串 `in` 的下标不是一回事，不能混用。
- 用 `back()` 可以访问最后一个元素。
- `auto` 会根据返回值类型自动适配，适合模板函数返回类型较长的情况。

复习提醒：
- 输出顺序按字符首次出现顺序，而不是字典序。
- 每遇到一个新字符，再统计它在后面出现了几次。
- 题目给的小写字母可简化，但模板写法仍应使用 `basic_string<CharType>`。

## 第 3 题：UniqueArray 去重数组

考点：模板类、非类型模板参数、读入数组、保留顺序去重。

题目要求：
- 模板类包含固定大小数组成员。
- 去除重复元素并输出去重后的数组。

当前代码和复习提醒：
- 当前用 `vector<T>` 存储，功能上能完成，但题面说“固定大小数组成员”，如果老师严格要求，最好使用 `T arr[SIZE]` 或至少体现 `SIZE`。
- `removeDuplicates` 应保留第一次出现的顺序。
- 输出时注意不要在最后多一个空格；多数 OJ 宽松，但考试格式题最好控制。

## 第 4 题：computeProductVector 向量乘积

考点：函数模板、遍历向量、返回新向量。

题目要求：
- 函数模板 `vector<T> computeProductVector(const vector<T>& input)`。
- 返回一个新向量，新向量中的元素是原向量元素的乘积。
- 从样例看，返回向量只有一个元素：全部元素乘积。

当前代码可能扣分的点：
- 函数参数现在是按值传递 `vector<T> in`，会复制；更规范是 `const vector<T>& in`。
- `result` 写成 `int`，如果 `T` 不是 `int` 就不泛型；建议写 `T result = 1;`。

复习提醒：
- 如果输入可能为空，要考虑乘积初值是否应该为 `1`。

## 第 5 题：EncryptedString 字符串加密

考点：模板类、字符串成员、ASCII 运算、整行输入。

题目要求：
- 模板类包含字符串成员。
- 每个字符 ASCII 值加 3。
- `getline` 读入整行，输出加密后字符串。

当前代码可能扣分的点：
- 类模板写了 `template <typename T>`，但成员固定为 `string con`，泛型程度不高；如果要真正泛型，可写 `basic_string<T> con`。

复习提醒：
- 题目是简单 ASCII 加 3，不要求循环回到 `a`，所以 `z` 会变成 `}`。
- 读整行时用 `getline(cin, line)`，可以保留空格。

## 第 6 题：VectorSum 向量求和

考点：模板类、向量成员、成员函数求和。

当前代码可能扣分的点：
- `T out;` 定义后没有使用。
- `result` 写成 `int`，模板类里更应该写 `T result = 0;`。
- `computeSum()` 返回 `T`，内部累加变量也应是 `T`。

复习提醒：
```cpp
T computeSum() {
    T result = 0;
    for (const T& x : con) result += x;
    return result;
}
```

## 第 7 题：reverseString 字符串反转

考点：函数模板、`basic_string<CharType>`、反向遍历、整行输入。

你注释里的提醒：
- 函数模板形式是 `basic_string<CharType> reverseString(const basic_string<CharType>& str)`。

当前代码可能扣分的点：
- 参数按值传递，会复制；建议改为 `const basic_string<T>& in`。
- `for (int i = in.size() - 1; i >= 0; i--)` 对空字符串不够稳，`size()` 是无符号类型。

复习提醒：
- 更稳写法：
```cpp
for (int i = static_cast<int>(in.size()) - 1; i >= 0; --i)
    out.push_back(in[i]);
```

## 第 8 题：ArrayMax 固定数组最大值

考点：模板类、非类型模板参数、读入数组、寻找最大值。

题目要求：
- 类模板包含固定大小数组成员。
- `findMax()` 返回数组最大值。

当前代码和复习提醒：
- 代码用 `vector<T>` 存储，功能上能完成；但题面强调固定大小数组时，建议写 `T data[MAX_SIZE]; size_t size;`。
- 最大值初始化应使用第一个元素，不能初始化为 `0`，否则全负数会错。
- 当前 `T max = con[0]` 这点是对的，但前提是输入数量 `n > 0`。

## 第 9 题：squareVector 向量平方

考点：函数模板、`const vector<T>&`、返回新向量、逐元素处理。

你注释里的提醒：
- 题目给出的函数模板形式是 `vector<T> squareVector(const vector<T>& input)`。

复习提醒：
- 不修改原向量，创建新向量返回。
- 每个元素独立平方：`out.push_back(in[i] * in[i]);`
- 注意输出空格：第一个元素前不输出空格，后续元素前输出一个空格。

## 第 10 题：FilteredVector 过滤向量

考点：模板类、向量成员、条件筛选、返回新向量。

题目要求：
- 类模板包含向量成员。
- 成员函数 `filterGreaterEqual(k)` 返回所有 `>= k` 的元素。

当前代码可能扣分的点：
- `filterGreaterEqual(int n)` 中阈值写成 `int`，若模板类型不是 `int` 就不够泛型；更规范是 `filterGreaterEqual(T n)` 或 `const T& n`。
- 成员变量 `int fil;` 没有使用，可删。

复习提醒：
- 保留原顺序，不需要排序。
- 如果没有元素满足条件，输出空行。

## 考前速记

- 函数模板参数优先用引用：`const vector<T>& input`，避免复制。
- 字符串模板用 `basic_string<T>`，不要只会 `string`。
- 模板内部临时变量尽量用 `T`：求和、乘积、最大值都不要随手写 `int`。
- 非类型模板参数建议写成 `size_t MAX_SIZE`，和 `const size_t MAX_SIZE = 1000` 对齐。
- 输出数组/向量时控制空格：`if (i > 0) cout << " ";`
- 题目写“二分查找”就要真的写二分，不能只写线性查找。
