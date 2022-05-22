# @param {Integer[]} nums
# @return {Integer[]}
def running_sum(nums)
    temp = 0
    (0...nums.length).each do |i|
        temp += nums[i]
        nums[i] = temp
    end
    return nums
end