func mostWordsFound(sentences []string) int {
    ans, cnt := 0, 0
    for i := 0; i < len(sentences); i++ {
        cnt = 1
        for j := 0; j < len(sentences[i]); j++ {
            if sentences[i][j] == ' ' {
                cnt++
            }
        }
        ans = int(math.Max(float64(cnt), float64(ans)))
    }
    return ans
}