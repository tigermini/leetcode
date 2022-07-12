#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *tmparr;
    int i, j, k;
    double retmid = -1;
    int arrsize;

    arrsize = nums1Size + nums2Size;
    tmparr = (int *)malloc(arrsize * sizeof(int));
    if (tmparr == NULL) {
        return -1;
    }

    i = j = k = 0;
    while (1) {
        if ((i < nums1Size) && (j < nums2Size)) {
            if (nums1[i] <= nums2[j]) {
                tmparr[k] = nums1[i];
                i++;
            } else {
                tmparr[k] = nums2[j];
                j++;
            }
            k++;
        } else if ((i < nums1Size) && (j >= nums2Size)) {
            tmparr[k] = nums1[i];
            i++;
            k++;
        } else if ((i >= nums1Size) && (j < nums2Size)) {
            tmparr[k] = nums2[j];
            j++;
            k++;
        } else {
            break;
        }
    }

    if (arrsize % 2 == 0) {
        retmid = (double)(tmparr[arrsize / 2] + tmparr[arrsize / 2 - 1]) / 2;
    } else {
        retmid = (double)tmparr[arrsize / 2];
    }

    free(tmparr);

    return retmid;
}

static void test(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double ret;

    ret = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("%f\n", ret);
}

int main(int argc, char *argv[])
{
    int nums1[2] = {1, 3};
    int nums2[1] = {2};
    int nums3[2] = {1, 2};
    int nums4[2] = {3, 4};

    test(nums1, 2, nums2, 1);
    test(nums3, 2, nums4, 2);

    return 0;
}
