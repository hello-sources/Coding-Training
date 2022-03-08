class Solution {
    public List<String> cellsInRange(String s) {
        List<String> list = new ArrayList();
        for (char ch = s.charAt(0); ch <= s.charAt(3); ch++) {
            for (int i = s.charAt(1) - '0'; i <= s.charAt(4) - '0'; i++) {
                list.add(String.valueOf(ch) + String.valueOf(i));
            }
        }
        return list;
    }
}