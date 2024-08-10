class Solution {
    public int longestPalindrome(String s) {
        int biggestOdd = 0;
        boolean seenOdd = false;
        int length = 0;
        // ToDo: Write Your Code Here.
        Map<Character, Integer> hashmap = new HashMap<>();
        for (char c: s.toCharArray()) {
            int cur = hashmap.getOrDefault(c, 0) + 1;
            hashmap.put(c, cur);
            // if (cur % 2 != 0) {
            //     biggestOdd = Math.max(cur, biggestOdd);
            // }
        }

        for (char key: hashmap.keySet()) {
            int cur = hashmap.get(key);
            if (cur % 2 != 0) {
                if (!seenOdd) {
                    length += cur;
                    seenOdd = true;
                } else {
                    length += (cur - 1);
                }
            } else {
                length += cur;
            }
        }
        return length;
    }
}