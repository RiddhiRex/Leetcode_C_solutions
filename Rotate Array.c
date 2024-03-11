void reverse(int *nums, int start, int end) {
    while(start<end) {
        int tmp = nums[start];
        nums[start]=nums[end];
        nums[end]=tmp;
        start++;
        end--;
    }
    return;
}
void rotate(int* nums, int numsSize, int k) {
    k=k%numsSize;
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}
