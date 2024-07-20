class Solution {
    void reverse(int []arr,int l,int h){
        int left=l;
        int right=h;
        while(left<right){
            int temp=arr[right];
            arr[right]=arr[left];
            arr[left]=temp;
            left++;
            right--;
        }
    }
    public void rotate(int[] nums, int k) {
        k%=nums.length;
        reverse(nums,0,nums.length-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.length-1);
    }
}