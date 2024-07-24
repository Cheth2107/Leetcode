import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        // Create an array of pairs to hold original numbers and their mapped values
        Integer[][] mappedNums = new Integer[nums.length][2];
        
        for (int i = 0; i < nums.length; i++) {
            mappedNums[i][0] = nums[i]; // original number
            mappedNums[i][1] = mapNumber(nums[i], mapping); // mapped value
        }
        
        // Sort based on mapped values using a custom comparator
        Arrays.sort(mappedNums, new Comparator<Integer[]>() {
            @Override
            public int compare(Integer[] a, Integer[] b) {
                return a[1].compareTo(b[1]); // Compare based on mapped value
            }
        });
        
        // Extract sorted original numbers
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            result[i] = mappedNums[i][0]; // Get original number from sorted pairs
        }
        
        return result;
    }

    private int mapNumber(int num, int[] mapping) {
        StringBuilder mappedValue = new StringBuilder();
        
        // Convert the number to string to process each digit
        String numStr = Integer.toString(num);
        for (char c : numStr.toCharArray()) {
            int digit = c - '0'; // Get the integer value of the character
            mappedValue.append(mapping[digit]); // Map the digit and append to result
        }
        
        return Integer.parseInt(mappedValue.toString()); // Convert back to integer
    }
}
