/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct Node {
    int val;
    int cnt;
 };
 int compare(const void *a, const void *b) {
    return (((struct Node *)b)->cnt-((struct Node *)a)->cnt);
 }
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int i=0, end = -1, j=0;
    struct Node *dict = (struct Node *)malloc(numsSize * sizeof(struct Node));
    for(i=0;i<numsSize;i++) {
        bool found=false;
        for (j=0;j<=end;j++) {
            if(end>=0 && nums[i]==dict[j].val) {
                dict[j].cnt+=1;
                found=true;
            }
        }
        if(found==false) {
                end++;
                dict[end].val = nums[i];
                dict[end].cnt = 1;
        }
    }

    *returnSize = k;
    qsort(dict, end+1, sizeof(dict[0]), compare);
    int *res = (int *)malloc(k *sizeof(int));
    int idx=0;
    for(i=0;i<k && i<=end;i++) {
        res[idx++]= dict[i].val;
    }
    free(dict);
    return res;
}
