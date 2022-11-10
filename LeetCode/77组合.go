var ans [][]int

func combine(n int, k int) [][]int {
	ans = [][]int{}
	backtracking(n, 1, k, []int{})
	return ans
}

func backtracking(n int, left int, k int, temp []int) {
	if len(temp) == k {
		path := make([]int, k)
		copy(path, temp)
		ans = append(ans, path)
		return
	}
	for i := left; i <= n-(k-len(temp)-1); i++ {
		temp = append(temp, i)
		backtracking(n, i+1, k, temp)
		temp = temp[:len(temp)-1]
	}
	return
}

/*
	go在所有传参中都是值传递，而不是引用传递，都是一个副本，一个拷贝
	所做的修改不会影响到原参数
	拷贝的是引用类型（指针、map、slice、chan）是可以修改原参数
	拷贝的是非引用类型（int、string、struct）无法修改原参数

	一个有趣的现象是，go在声明了切片长度之后，在函数中对形参进行添加操作会引发扩容
	扩容的底层就是新建一个匿名切片，然后指向匿名切片的地址
	那么实参是不会遭到修改的
*/