// Given an integer x, return true if x is a palindrome, and false otherwise.

 
// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:
// -231 <= x <= 231 - 1

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x>= pow(-2,31) && x<= (pow(2,31)-1)){
            string num = to_string(x);
            vector<char> num_vector(num.begin(), num.end()); 

            vector<char> rev_num_vector = num_vector; 
            reverse(rev_num_vector.begin(), rev_num_vector.end()); 

            return num_vector == rev_num_vector; 

        }
        return false;
        
    }
    
};