func maxProfit(prices []int) (ans int) {
	for i := 1; i < len(prices); i++ {
		ans += int(math.Max(float64(prices[i]-prices[i-1]), 0))
	}
	return
}

/*
	每天都可以买卖股票，如何获得最大收益，可以把股票营收按照天为单位
	即前一天买入，今天卖出，因为总的收益肯定是与当前每一天收入相关的
	每一天的收入相当于局部最优，那么局部最优加起来就是整体最优解
*/