class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int q = queries.length;
        int[] prefixXOR = new int[n];
        int[] answer = new int[q];
        
        // Build the prefix XOR array
        prefixXOR[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        }
        
        // Process each query
        for (int i = 0; i < q; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            if (left > 0) {
                answer[i] = prefixXOR[right] ^ prefixXOR[left - 1];
            } else {
                answer[i] = prefixXOR[right];
            }
        }
        
        return answer;
    }
}