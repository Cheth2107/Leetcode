/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]*/

//code
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for(int i=0; i<nums.length; i++){
            for(int j=1;j<nums.length; j++){
                int comp=target-nums[i];
                
                if(nums[j]==comp){
                    return new int[]{i,j};
                }
            }
        }
        throw new IllegalArgumentException("no match found");
    }
}
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        int[] nums = {2, 7, 11, 15};
        int target = 9;

        try {
            int[] result = solution.twoSum(nums, target);
            System.out.println("Indices: " + result[0] + ", " + result[1]);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}

//modified solution funciton with O(n^2)
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer>num_map=new HashMap<>();

        for(int i=0; i<nums.length; i++){
          int comp = target - nums[i];
          if (num_map.containsKey(comp)){
              return new int[] {num_map.get(comp),i};
          }
          num_map.put(nums[i],i);

        }
        throw new IllegalArgumentException("no match found");
    }
}

https://leetcode.com/problems/two-sum/submissions/1103123089
