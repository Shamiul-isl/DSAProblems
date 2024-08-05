class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> seen = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            seen.put(arr[i], seen.getOrDefault(arr[i], 0) + 1);
        }
        
        int count = 0;
        for (String s: arr) {
            if (seen.get(s) == 1) {
                count++;
                if (count == k) {
                    return s;
                }
            }
        }
        
        return "";
    }
}