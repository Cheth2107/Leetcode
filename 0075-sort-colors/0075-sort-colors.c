void sortColors(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    int i = 0;
    
    while (i <= high) {
        if (nums[i] == 0) {
            int temp = nums[i];
            nums[i] = nums[low];
            nums[low] = temp;
            i++;
            low++;
        } else if (nums[i] == 1) {
            i++;
        } else {
            int temp = nums[i];
            nums[i] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}
