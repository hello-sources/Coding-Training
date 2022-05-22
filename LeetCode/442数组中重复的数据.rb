# @param {Integer[]} nums
# @return {Integer[]}
def find_duplicates(nums)
    temp = Array.new(100005, 0)
    (0...nums.size).each do |x|
        temp[nums[x]] += 1
    end
    ans = []
    (0...temp.size).each do |x|
        if temp[x] == 2 then
            ans.push(x)
        end
    end
    return ans
end