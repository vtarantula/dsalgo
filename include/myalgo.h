#ifndef __MYALGO_H__
#define __MYALGO_H__

#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& v_nums, const bool is_decreasing=false)
{
    for (long unsigned int i = 1; i < v_nums.size(); ++i)
    {
        if (v_nums.empty() || v_nums.size() == 1)
            return;
        T key = v_nums.at(i);
        int j = i - 1;
        bool is_valid = (is_decreasing) ? (v_nums.at(j) < key) : (v_nums.at(j) > key);
        // Order of j and is_valid is important in the while condition
        while (j >= 0 && is_valid)
        {
            v_nums.at(j + 1) = v_nums.at(j);
            --j;
            if (j > -1)
                is_valid = (is_decreasing) ? (v_nums.at(j) < key) : (v_nums.at(j) > key);
        }
        v_nums.at(j + 1) = key;
    }
    return;
}

template <typename T>
void _merge(std::vector<T>& v_nums, long unsigned int p, long unsigned int q, long unsigned int r)
{
    if (r < p)
        return;

    auto n1 = q - p + 1, n2 = r - q;
    std::vector<int> v_left, v_right;
    v_left.reserve(n1), v_right.reserve(n2);

    for (long unsigned int i = 0; i < n1; ++i)
        v_left.push_back(v_nums.at(p + i));
    for (long unsigned int i = 0; i < n2; ++i)
        v_right.push_back(v_nums.at(q + i + 1));
    
    unsigned int i = 0, j = 0;
    while (i < v_left.size() && j < v_right.size())
    {
        if (v_left.at(i) < v_right.at(j))
        {
            v_nums.at(p + i + j) = v_left.at(i);
            ++i;
        } else {
            v_nums.at(p + i + j) = v_right.at(j);
            ++j;
        }
    }
    while (i < v_left.size())
    {
        v_nums.at(p + i + j) = v_left.at(i);
        ++i;
    }
    while (j < v_right.size())
    {
        v_nums.at(p + i + j) = v_right.at(j);
        ++j;
    }
    return;
}

template <typename T>
void _merge_sort(std::vector<T>& v_nums, long unsigned int p, long unsigned int r)
{
    if (p >= r)
        return;
    
    long unsigned int q = (p + r) / 2;
    _merge_sort(v_nums, p, q);
    _merge_sort(v_nums, q + 1, r);
    _merge(v_nums, p, q, r);
    return;
}

template <typename T>
void merge_sort(std::vector<T>& v_nums)
{
    if (v_nums.empty() || v_nums.size() == 1)
        return;
    _merge_sort(v_nums, 0, v_nums.size() - 1);
    return;
}

template <typename T>
int binary_search(std::vector<T>& v_nums, int target)
{
    int i_ans = -1;
    if (v_nums.empty())
        return i_ans;
    long unsigned int left = 0, mid  = v_nums.size() / 2, right = v_nums.size() - 1;
    while (mid >= 0 && mid < v_nums.size())
    {
        if (v_nums.at(mid) == target)
        {
            i_ans = mid;
            break;
        } 
        if (mid == 0)
            return i_ans;
        if (v_nums.at(mid) > target)
        {
            right = mid;
        } else {
            left = mid;
        }
        mid = (left + right + 1) / 2;
    }
    return i_ans;
}

#endif  // __MYALGO_H__