class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> hashmap = new HashMap<>();
        for (char c: magazine.toCharArray()) {
            hashmap.put(c, hashmap.getOrDefault(c, 0) + 1);
        }

        for (char c: ransomNote.toCharArray()) {
            int cur = hashmap.getOrDefault(c, 0);
            if (cur == 0) {
                return false;
            }
            hashmap.put(c, cur - 1);
        }
        return true;
    }
}