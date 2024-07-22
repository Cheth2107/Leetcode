import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        // Create an array of indices from 0 to n-1
        Integer[] indices = new Integer[heights.length];
        for (int i = 0; i < heights.length; i++) {
            indices[i] = i;
        }
        
        // Sort the indices array based on the heights array in descending order
        Arrays.sort(indices, Comparator.comparingInt((Integer i) -> heights[i]).reversed());
        
        // Create a new array to store the sorted names
        String[] sortedNames = new String[names.length];
        
        // Populate the sorted names array based on the sorted indices
        for (int i = 0; i < heights.length; i++) {
            sortedNames[i] = names[indices[i]];
        }
        
        return sortedNames;
    }
}
