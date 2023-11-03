// @author: gezhipeng @ 20231103
// @file: 4.h
// @brief: 查找两个排序数组的中位数，要求时间复杂度是O(log(m+n))

#include <iostream>
#include <vector>
int find(const std::vector<int>& nums1, int i, const std::vector<int> & nums2, int j, int k);
double FindMedian(const std::vector<int> &nums1, const std::vector<int>& nums2) {
    size_t sz = nums1.size() + nums2.size();
    if (sz % 2 == 0) {
        int left = find(nums1, 0, nums2, 0, sz / 2);
        int right = find(nums1, 0, nums2, 0, sz / 2 + 1);
        return (left + right) / 2.0;
    } else {
        return find(nums1, 0, nums2, 0, sz / 2 + 1);
    }
}

/*
* i, j 表示查找的起始位置
* k 表示找第k大的数字，从1开始
*/

int find(const std::vector<int>& nums1, int i, const std::vector<int> & nums2, int j, int k) {
    if (nums1.size() - i > nums2.size() - j) {
        return find(nums2, j, nums1, i, k);
    } 
    if (nums1.size() - i == 0) {
        return nums2[j + k - 1];
    }
    // 终止条件
    if (k == 1) {
        return std::min(nums1[i], nums2[j]);
    }
    // 折半查找
    int idx1 = std::min((int)nums1.size(), i + k / 2);
    int idx2 = j + k - k / 2;
    if (nums1[idx1 - 1] < nums2[idx2 - 1]) {
         return find(nums1, idx1, nums2, j, k - (idx1 - i));
    } else {
        return find(nums1, i, nums2, idx2, k - (idx2 - j));
    }
}