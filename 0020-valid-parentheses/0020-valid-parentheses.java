class Solution {
    public boolean isValid(String s) {
        LinkedList<Character> stack = new LinkedList<>();
        for (int i = 0; i < s.length(); i++) {
           char cur = s.charAt(i);
            if (cur == '(' || cur == '[' || cur == '{'){
                stack.push(cur);
            } else {
                if (stack.isEmpty() || (cur == ')' && stack.pop() != '(') || (cur == ']' && stack.pop() != '[') || (cur == '}' && stack.pop() != '{')) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}