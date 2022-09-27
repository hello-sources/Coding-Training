/**
 * Java新的东西
 * https://blog.csdn.net/m0_51051154/article/details/120392110
 * map.entrySet()将map里的每一个键值对取出来封装成一个Entry对象并存放到一个Set里面
 * Collections.sort(List list, Comparator<? super T> c) 集合类的排序方法，通过自定义的比较器进行排序。这里的list存放的对象是entry对象。定义比较器对entry对象中的value属性进行比较。
 */
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        Map<Integer, String> map = new HashMap<Integer, String>();
        String[] ans = new String[heights.length];
        for (int i = 0; i < heights.length; i++) {
            map.put(heights[i], names[i]);
        }
        List<Map.Entry<Integer, String>> entrys = new ArrayList<>(map.entrySet());
        Collections.sort(entrys, new MyCmp());
        int i = 0;
        for (Map.Entry<Integer, String> entry : entrys) {
            ans[i++] = entry.getValue();
        }
        return ans;
    }

    class MyCmp implements Comparator<Map.Entry>{
        public int compare(Map.Entry m1, Map.Entry m2) {
            return ((Integer)m2.getKey()).compareTo((Integer)m1.getKey());
        }
    }
}