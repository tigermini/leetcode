#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *retarr;
    int arrsize;

    arrsize = sizeof(int) * 2;
    retarr = (int *)malloc(arrsize);
    if (retarr == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(retarr, 0, sizeof(arrsize));

    for (i = 0; i < numsSize -1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if ((nums[i] + nums[j] == target) && (i != j)) {
                *returnSize = 2;
                retarr[0] = i;
                retarr[1] = j;
                return retarr;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

static void test(int *nums, int size, int target)
{
    int *tmparr;
    int return_size;

    tmparr = twoSum(nums, size, target, &return_size);

    if (tmparr != NULL) {
        printf("tmparr[0] is %d, tmparr[1] is %d\n", tmparr[0], tmparr[1]);
    } else {
        printf("tmparr is NULL\n");
    }
}

int main(int argc, char *argv[])
{
    int nums1[4] = {2, 7, 11, 15};
    int target1 = 9;
    int nums2[3] = {3, 2, 4};
    int target2 = 6;
    int nums3[2] = {3, 3};
    int target3 = 6;

    test(nums1, sizeof(nums1) / sizeof(int), target1);
    test(nums2, sizeof(nums2) / sizeof(int), target2);
    test(nums3, sizeof(nums3) / sizeof(int), target3);

    return 0;
}