void sortColors(int* nums, int numsSize) {
    int i=0, tmp = 0;
    int l=0, m =0, r=numsSize-1;
    while(m<=r) {
        if(nums[m]==0) {
            tmp = nums[l];
            nums[l]=nums[m];
            nums[m]=tmp;
            l+=1;
            m+=1;
        } else if(nums[m]==2) {
            tmp = nums[r];
            nums[r]=nums[m];
            nums[m]=tmp;
            r-=1;
        } else {
            m+=1;
        }
    }
}
