// @author: gezhipeng @ 20231102
// @file: 3.cc
// @brief: 3

#include <iostream>
#include <vector>
#include <string>

int GetLengthOfLongestSubString(const std::string& str) {
    std::vector<int> pos(128, -1);  // 记录最后一次出现的字符位置
    int res = 0;
    // j, i分别为左右边界
    for (int i = 0, j = 0; i < str.length(); ++i) {
        j = std::max(j, pos[str[i]] + 1);  // 取上一次出现该字符的位置
        res = std::max(res, i - j + 1);    // 更新结果
        pos[str[i]] = i;                   // 更新该字符的位置
    }
    return res;
}