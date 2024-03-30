/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    int l=0;
    int r = numbersSize-1;
    while(l<r) {
        if(numbers[l]+numbers[r]==target) {
            result[0]=l+1;
            result[1]=r+1;
            return result;
        }
        else if(numbers[l]+numbers[r]<target) {
            l+=1;
        } else
            r-=1; 
    }
    return result;
}
