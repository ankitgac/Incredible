#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    returnSize = (int*)malloc(sizeof(int)*2);
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i+1; j < numsSize; j++)
        {
            if((nums[i]+nums[j]) == target)
            {
                returnSize[0] = nums[i];
                returnSize[1] = nums[j];
            }
        }
    }
    return returnSize;
}
void func(int* test)
{
	printf("%d",test[0]);
	printf("%d",test[1]);
	printf("%d",test[2]);
	printf("%d",test[3]);
}
int main(void)
{
        int nums[]={2,7,11,15};
	int size;
	int *arr = twoSum(nums,4,9,&size);
	printf("%d",arr[0]);
	printf("%d",arr[1]);
	return 0;
}
