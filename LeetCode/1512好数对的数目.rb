# @param {Integer[]} nums
# @return {Integer}
def num_identical_pairs(nums)
    ans = 0
    (0...nums.size - 1).each do |i|
        (i + 1...nums.size).each do |j|
            if nums[i] == nums[j]
                ans += 1
            end
        end
    end
    return ans
end