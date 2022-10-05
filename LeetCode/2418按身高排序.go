func sortPeople(names []string, heights []int) []string {
    infos := make(map[int]string, 0)
    ans := make([]string, 0)
    for i := 0; i < len(names); i++ {
        infos[heights[i]] = names[i]
    }
    sort.Sort(sort.Reverse(sort.IntSlice(heights)))
    for _, v := range heights {
        ans = append(ans, infos[v])
    }
    return ans
}

func sortPeople(names []string, heights []int) []string {
    pos := []int{}
    for i:=range names {
        pos = append(pos, i)
    } 
    sort.Slice(pos, func(i, j int)bool {
        return heights[pos[i]] > heights[pos[j]]
    })
    ans := []string{}
    for _, i := range pos  {
        ans = append(ans, names[i])
    }
    return ans
}