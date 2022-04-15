#include <iostream>
#include <vector>

// Application includes
#include "myalgo.h"


int main(int argc, char const *argv[])
{
    /* code */
    printf ("Starting application...\n");
    // std::vector<double> v_nums = {31.5, 41.2, 59, 26, 41.1, 58};
    // insertion_sort(v_nums);
    // for (auto& i : v_nums)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // Test division by zero
    // unsigned long long x = 0.0;
    // unsigned long long lv_size_extents = 2304061 / x;
    // printf ("Size: %llu\n", lv_size_extents);

    // Test limits
    // long long int x = 2199023255552;
    // long double x = 2199023255552.0;
    // std::cout << x << std::endl;
    // printf ("Size: %Lf\n", x);

    std::vector<int> v_nums = {3, 9, 26, 38, 49, 57};
    merge_sort(v_nums);
    auto ans = binary_search(v_nums, 3);
    // for (auto& i : v_nums)
        std::cout << ans << " ";
    std::cout << std::endl;

    printf ("*** Ending application ***\n");
    return 0;
}
