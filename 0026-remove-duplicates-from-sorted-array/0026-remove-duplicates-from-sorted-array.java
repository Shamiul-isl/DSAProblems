class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 1) {
          return 1;
        }

        int i = 0;
        boolean changed = false;

        for (int j = i + 1; j < nums.length; j++) {
          if (!changed) {
            if (nums[i] != nums[j]) 
              i++;
            else
              changed = true;
          } else {
            if (nums[i] != nums[j]) {
              i++;
              nums[i] = nums[j];
            }
          }
        }

        return i+1;
    }
}