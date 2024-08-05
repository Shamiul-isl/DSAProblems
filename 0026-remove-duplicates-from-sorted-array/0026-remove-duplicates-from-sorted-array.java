class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 1) {
          return 1;
        }

        int i = 0;
        boolean changed = false;

        for (int j = i + 1; j < nums.length; j++) {
            // You dont need changed because if we increment i and change value when i and j are 1 element apart, we essentially set j to itself
          // if (!changed) {
          //   if (nums[i] != nums[j]) 
          //     i++;
          //   else
          //     changed = true;
          // } else {
          //   if (nums[i] != nums[j]) {
          //     i++;
          //     nums[i] = nums[j];
          //   }
          // }
            if (nums[i] != nums[j]) {
              i++;
              nums[i] = nums[j];
            }
        }

        return i+1;
    }
}