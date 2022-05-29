# @param {Integer[]} nums
# @return {Integer}
def reduction_operations(nums)
    arr = nums.sort {|x, y| x <=> y}
    ans, temp = 0, 0
    (1...nums.size).each do |i|
        if arr[i] != arr[i - 1] then
            temp += 1
        end
        ans += temp
    end
    return ans
end