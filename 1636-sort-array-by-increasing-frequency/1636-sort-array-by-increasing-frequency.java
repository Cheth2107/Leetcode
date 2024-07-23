import java.util.*;

class Solution {
    public int[] frequencySort(int[] nums) {
        // Step 1: Count the frequency of each number
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Step 2: Create a list from the map entries and sort it
        List<Map.Entry<Integer, Integer>> entryList = new ArrayList<>(frequencyMap.entrySet());
        
        // Sorting based on frequency (ascending) and value (descending)
        Collections.sort(entryList, (a, b) -> {
            if (a.getValue().equals(b.getValue())) {
                return b.getKey().compareTo(a.getKey()); // Sort by value descending
            }
            return a.getValue().compareTo(b.getValue()); // Sort by frequency ascending
        });

        // Step 3: Build the result array
        List<Integer> sortedList = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : entryList) {
            int freq = entry.getValue();
            int num = entry.getKey();
            for (int i = 0; i < freq; i++) {
                sortedList.add(num);
            }
        }

        // Convert List<Integer> to int[]
        return sortedList.stream().mapToInt(i -> i).toArray();
    }
}
