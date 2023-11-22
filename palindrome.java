/*Given an integer x, return true if x is a 
palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.*/

basic program-

class Solution {
    public boolean isPalindrome(int x) {
        int temp, r, sum = 0;
        temp = x;
        while (x > 0) {
            r = x % 10;
            sum = (sum * 10) + r;
            x = x / 10;
        }
        return temp == sum;
    }
}

modified program-

class Solution {
    public boolean isPalindrome(int x) {
        int temp, r, sum = 0;
        temp = x;
        while (x > 0) {
            r = x % 10;
            sum = (sum * 10) + r;
            x = x / 10;
        }
        return temp == sum;
    }
}
https://leetcode.com/problems/palindrome-number/submissions/1103845144

public class Main {
    public static void main(String[] args) {
        int param_1 = 121;
        boolean ret = new Solution().isPalindrome(param_1);
        System.out.println("Is it a palindrome? " + ret);
    }
}
https://leetcode.com/problems/palindrome-number/submissions/1103846671

Could you solve it without converting the integer to a string?

class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            // Negative numbers are not palindromes
            return false;
        }

        int original = x;
        int reversed = 0;

        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
}
https://leetcode.com/problems/palindrome-number/submissions/1103847890
