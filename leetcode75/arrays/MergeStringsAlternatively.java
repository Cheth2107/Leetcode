/*You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d*/

//code
class Solution {
    public String mergeAlternately(String word1, String word2) {
        int len1,len2,min;
        len1 = word1.length();
        len2 = word2.length();
        min = Math.min(len1,len2);
        String longerString = " ";
        if(min == len1){
            longerString = word2;
        }
        else{
            longerString = word1;
        }
        char[] chars1 = word1.toCharArray();
        char[] chars2 = word2.toCharArray();
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<min;i++){
            sb.append(chars1[i]);
            sb.append(chars2[i]);
        }
        sb.append(longerString.substring(min));
        return sb.toString();
    }
}
https://leetcode.com/problems/merge-strings-alternately/submissions/1104548406?envType=study-plan-v2&envId=leetcode-75

//modified code
class Solution {
    public String mergeAlternately(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int min = Math.min(len1, len2);

        char[] chars1 = word1.toCharArray();
        char[] chars2 = word2.toCharArray();

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < min; i++) {
            sb.append(chars1[i]);
            sb.append(chars2[i]);
        }

        // Append the remaining characters from the longer string
        if (len1 > min) {
            sb.append(word1, min, len1);
        } else if (len2 > min) {
            sb.append(word2, min, len2);
        }

        return sb.toString();
    }
}
https://leetcode.com/problems/merge-strings-alternately/submissions/1104549669?envType=study-plan-v2&envId=leetcode-75
