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

void _merge(std::vector<int>& v_nums, long unsigned int p, long unsigned int q, long unsigned int r)
{
    if (r <= p)
        return;
    std::vector<int> v_left, v_right;
    for (long unsigned int i = 0; i < q - p; ++i)
        v_left.push_back(v_nums.at(p + i));
    for (long unsigned int i = 0; i < r - q; ++i)
        v_right.push_back(v_nums.at(q + i));
    unsigned int i = 0, j = 0, k = p;
    while (i < v_left.size() && j < v_right.size())
    {
        if (v_left.at(i) < v_right.at(j))
        {
            v_nums.at(k) = v_left.at(i);
            ++i;
        } else {
            v_nums.at(k) = v_right.at(j);
            ++j;
        }
        ++k;
    }
    while (i < v_left.size())
    {
        v_nums.at(k) = v_left.at(i);
        ++k;
        ++i;
    }
    while (j < v_right.size())
    {
        v_nums.at(k) = v_right.at(j);
        ++j;
        ++k;
    }
    return;
}

#endif  // __MYALGO_H__