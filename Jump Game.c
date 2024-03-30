bool canJump(int* nums, int numsSize) {
    int maxjump = 0;
    for(int i=0;i<numsSize;i++) {
        if (maxjump>=numsSize-1)
            return true;
        if(i>maxjump)
            return false;
        
        maxjump = (maxjump>nums[i]+i)? maxjump: nums[i]+i;
    }
    return false;
}
