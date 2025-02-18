// Given an array of integers nums and an integer k, an element nums[i] is considered good if it is strictly greater than the elements at indices i - k and i + k (if those indices exist). If neither of these indices exists, nums[i] is still considered good.
// Return the sum of all the good elements in the array.

// Example 1:
// Input: nums = [1,3,2,1,5,4], k = 2
// Output: 12
// Explanation:
// The good numbers are nums[1] = 3, nums[4] = 5, and nums[5] = 4 because they are strictly greater than the numbers at indices i - k and i + k.

// Example 2:
// Input: nums = [2,1], k = 1
// Output: 2
// Explanation:
// The only good number is nums[0] = 2 because it is strictly greater than nums[1].


// Constraints:
// 2 <= nums.length <= 100
// 1 <= nums[i] <= 1000
// 1 <= k <= floor(nums.length / 2)


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool inBounds(int index, const vector<int>& array) {
        return (index >= 0) && (index < array.size());
    }   
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        if (nums.size() < 2 || nums.size() > 100 || k < 1 || k > floor(nums.size() / 2)) {
            return 0;  // Invalid input, return 0
        }

        vector<int> good_numbers;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 1 || nums[i] > 1000) continue; // Ignore invalid values

            bool leftInBounds = inBounds(i - k, nums);
            bool rightInBounds = inBounds(i + k, nums);

            // If both indices are out of bounds, it's automatically good
            if (!leftInBounds && !rightInBounds) {
                good_numbers.push_back(nums[i]);
            }
            // If one of them is out of bounds, check the existing one
            else if ((!leftInBounds && nums[i] > nums[i + k]) || 
                     (!rightInBounds && nums[i] > nums[i - k])) {
                good_numbers.push_back(nums[i]);
            }
            // If both are in bounds, compare with both
            else if (leftInBounds && rightInBounds && 
                     nums[i] > nums[i - k] && nums[i] > nums[i + k]) {
                good_numbers.push_back(nums[i]);
            }
        }

        // Compute the sum of good numbers
        for (int num : good_numbers) {
            sum += num;
        }

        return sum;
        
    }
};