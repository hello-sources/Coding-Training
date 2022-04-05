class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        ans = 0
        hour1 = int(current[0:2])
        minutes1 = int(current[3:5])
        time1 = hour1 * 60 + minutes1
        
        hour2 = int(correct[0:2])
        minutes2 = int(correct[3:5])
        time2 = hour2 * 60 + minutes2
        
        cha = time2 - time1
        ans += cha // 60
        cha %= 60
        ans += cha // 15
        cha %= 15
        ans += cha // 5
        cha %= 5
        ans += cha 
        return ans