solution 1:
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct numbers {
     int idx;
     int val;
 };
int compare(const void *a, const void *b) {
    return ((struct numbers *)a)->val - ((struct numbers *)b)->val;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int i=0, j=0;
    int *res=(int *)malloc(*returnSize * sizeof(int));
    struct numbers *lookup = (struct numbers*)malloc(numsSize * sizeof(struct numbers));
    int end =0;
    for(i=0;i<numsSize;i++) {
        for(j=0;j<end;j++) {
            if((nums[i]+lookup[j].val)==target) {
                res[0]=i;
                res[1]=lookup[j].idx;
                free(lookup);
                return res;
            } 
            
        }
        lookup[end].val=nums[i];
        lookup[end].idx=i;
        end+=1;
    }
    res[0]=-1;
    res[1]=-1;
    free(lookup);
    return res;
}



solution 2:
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct numbers {
     int idx;
     int val;
 };
int compare(const void *a, const void *b) {
    return ((struct numbers *)a)->val - ((struct numbers *)b)->val;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int i=0;
    int *res=(int *)malloc(*returnSize * sizeof(int));
    struct numbers *num = (struct numbers*)malloc(numsSize * sizeof(struct numbers));
    for(i=0;i<numsSize;i++) {
        num[i].idx=i;
        num[i].val=nums[i];
    }
    qsort(num, numsSize, sizeof(struct numbers), compare);
    int l =0;
    int r=numsSize-1;
    while(l<r) {
        int total = num[l].val+num[r].val;
        if(total==target) {
            res[0]=num[l].idx;
            res[1]=num[r].idx;
            free(num);
            return res;
        } else if (total<target)
            l++;
        else
            r--;
    }
    res[0]=-1;
    res[1]=-1;
    free(num);
    return res;
}
