int subarraysDivByK(int* nums, int numsSize, int k) {
    // Hash map to store the frequency of prefix sum remainders
    int* remainderCount = (int*)calloc(k, sizeof(int));
    remainderCount[0] = 1; // To handle the case where the subarray itself is divisible by k
    
    int prefixSum = 0;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        
        // Calculate remainder of the current prefix sum
        int remainder = prefixSum % k;
        
        // Handle negative remainders to ensure they fall within the range [0, k-1]
        if (remainder < 0) {
            remainder += k;
        }
        
        // If this remainder has been seen before, it means there are subarrays
        // which sum to a value divisible by k
        count += remainderCount[remainder];
        
        // Increment the count of this remainder in the hash map
        remainderCount[remainder]++;
    }
    
    // Free allocated memory for the hash map
    free(remainderCount);
    
    return count;
}