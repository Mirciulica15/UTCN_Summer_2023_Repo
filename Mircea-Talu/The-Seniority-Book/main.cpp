#include <iostream>
#include <vector>
#include <algorithm>

void generatePermutations(std::vector<int>& nums, int start, int n) {
    if (start == n) {
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start; i <= n; i++) {
        std::swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1, n);
        std::swap(nums[start], nums[i]);
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    generatePermutations(nums, 0, n - 1);

    return 0;
}
