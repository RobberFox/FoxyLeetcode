#include <stdlib.h>
#include <stdio.h>
#define dprint(expr) printf(#expr " = %d\n", expr)

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main()
{
	int array[] = { 2, 7, 11, 15 };
	int arraySize = sizeof(array)/sizeof(array[0]);
	int ansSize = 2;
	int targ = 9;

	int* ans = twoSum(array, arraySize, targ, &ansSize);
	if (ans != NULL) {
		printf("%d, %d", ans[0], ans[1]);
	}
	else {
		printf("No answer found.");
	}
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i, k;

	*returnSize = 2; // Wouldn't be really required, outside of leetcode.
	int* pAns = (int *)malloc(*returnSize * sizeof(int));
	if (pAns == NULL) {
		printf("Allocation Failed");
	}

	for (i = 0; i < numsSize; ++i) {
		for (k = i+1; k < numsSize; ++k) {
			if (nums[i] + nums[k] == target) {
				pAns[0] = i;
				pAns[1] = k;

				return pAns;
			}
		}
	}

	return NULL;
}
