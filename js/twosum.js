nums = [3,2,4];
target = 6;

function twoSum(nums, target) {
	for (var i=0; i<nums.length; ++i)
		for (var k=i+1; k<nums.length; ++k)
			if (nums[i]+nums[k]==target)
				return [i, k];
	return null; // In case there is no solution
}

console.log(twoSum(nums, target));

/*


	*/
