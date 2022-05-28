# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer}
def count_k_difference(nums, k)
    ans = 0
    (0...nums.size - 1).each do |x|
        (x...nums.size).each do |y|
            if (nums[x] - nums[y]).abs == k then
                ans += 1
            end
        end
    end
    return ans
end