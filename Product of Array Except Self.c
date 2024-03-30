/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *leftprd = (int *)malloc(numsSize * sizeof(int));
    int rightprd = 1;
    leftprd[0]=1;
    for(int i=1;i<numsSize;i++) {
        leftprd[i]=leftprd[i-1]*nums[i-1];
    }
    for(int i=numsSize-2;i>=0;i--) {
        rightprd =rightprd*nums[i+1];
        leftprd[i]=rightprd*leftprd[i];
        printf("%d ", leftprd[i]);
    }
    *returnSize = numsSize;
    return leftprd;
}
