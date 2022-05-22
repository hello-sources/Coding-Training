# @param {Integer[]} nums
# @return {Integer}
def repeated_n_times(nums)
    nums.find{ |num| nums.count(num) == nums.size / 2}
end