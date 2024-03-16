int maximumStrongPairXor(int* nums, int numsSize) {
    int maxXor=0;
    int i, j;
    for(i=0;i<numsSize;i++) {
        for(j=0;j<numsSize;j++) {
            int smallest = (nums[i]<nums[j])?nums[i]:nums[j];
            if(abs(nums[i]-nums[j])<=smallest) {
                if ((nums[i]^nums[j])>maxXor)
                    maxXor = nums[i]^nums[j];
            }
        }
    }
    return maxXor;
}
