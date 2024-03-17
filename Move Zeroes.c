void moveZeroes(int* nums, int numsSize) {
    int i=0, idx=0;
    for(i=0;i<numsSize;i++) {
        if(nums[i]!=0) {
            nums[idx]=nums[i];
            idx+=1;
        }
    }
    while(idx<numsSize) {
        nums[idx++]=0;
    }
    
}
