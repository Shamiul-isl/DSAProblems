/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let seen = new Map();
    
    for (let i = 0; i < nums.length; i++) {
        let complement = target - nums[i];
        if (seen.has(complement)) {
            return [seen.get(complement), i];
        }
        
        seen.set(nums[i], i);
        
        // if (seen.has(nums[i])) {
        //     seen.get(nums[i]).push(i);
        // } else
        //     seen.set(nums[i], [i]);
    }
    
};