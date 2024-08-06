class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] squares = new int[n];
        // TODO: Write your code here
        int start = 0, end = n - 1, toReplace = n - 1;
        while (start <= end) {
          int cur = Math.max(Math.abs(nums[start]), Math.abs(nums[end]));
          squares[toReplace] = (cur * cur);
            toReplace--;
          if (cur == Math.abs(nums[start]))
            start++;
          else if (cur == Math.abs(nums[end]))
            end--;
        }
        return squares;
    }
}