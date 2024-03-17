int lengthOfLIS(int* nums, int numsSize) {
    int *stack = (int *)malloc(numsSize*sizeof(int));
    int top=-1, i=0;
    for(i=0;i<numsSize;i++) {
        if(top==-1)
            stack[++top]=nums[i];
        else {
            if(nums[i]>stack[top])
                stack[++top]=nums[i];
            else {
                //find smallest element stack that is greater than or equal to nums[i]
                for(int n=0;n<=top;n++) {
                    if(stack[n]>=nums[i]) {
                        stack[n]=nums[i];
                        break;
                    }
                }
            }
        }
    }
    return top+1;
}
