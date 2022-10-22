/*
	1、需要用哈希表存储两个键值对，表示对应篮子编号以及所能承受的果子数目，如果超过两个键值对，就移除第一个
	2、注意Go语言中没有三目运算符，且对应max、min函数只是针对float类型的，如果用的话得强转
	3、如果不符合规则的话，需要一直移动left指针，直到从map中删除left对应的内容
*/
func totalFruit(fruits []int) (ans int) {
    cnt := map[int]int{}
    left := 0
    for right, val := range fruits {
        cnt[val]++
        if len(cnt) > 2 {
            y := fruits[left]
            cnt[y]--
            if cnt[y] == 0 {
                delete(cnt, y)
            }
            left++
        }
        ans = int(math.Max(float64(ans), float64(right - left + 1)))
    }
    return ans
}