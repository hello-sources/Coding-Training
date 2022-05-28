# @param {Integer[]} nums
# @return {Integer}
def subset_xor_sum(nums)
    ans = 0
    temp = 1 << nums.size
    (0...temp).each do |i|
        sum = 0
        (0...nums.size).each do |j|
            if  i & (1 << j) != 0 then
                sum ^= nums[j]
            end
        end
        ans += sum
    end
    return ans
end