/**
 * Map.Entry中map.entrySet将Map中的每一个键值对取出来封装成一个Entry对象，并且封装成一个set
 * 通过Collections进行排序，Collections是对集合操作的工具类，主要用来实现自定义排序
 * 
 * 那么HashMap与TreeMap有什么区别呢？
 * HashMap基于数组存储键值对，线程不安全。
 * TreeMap基于红黑树存储键值对，直接存入元素的时候就进行排序。
 */
class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        List<List<Integer>> ans = new ArrayList<>();
        Map<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < items1.length; i++) {
            map.put(items1[i][0], items1[i][1]);
        }
        for (int i = 0; i < items2.length; i++) {
            Integer orDefault = map.getOrDefault(items2[i][0], 0);
            map.put(items2[i][0], orDefault + items2[i][1]);
        }
        List<Map.Entry<Integer, Integer>> entry = new ArrayList<>(map.entrySet());
        Collections.sort(entry, new MyCmp());
        map.forEach((key,value)->{
            ans.add(Arrays.asList(key, value));
        });
        return ans;
    }

    class MyCmp implements Comparator<Map.Entry> {
        public int compare(Map.Entry m1, Map.Entry m2) {
            return ((Integer)m1.getKey()).compareTo((Integer)m2.getKey());
        }
    }
}