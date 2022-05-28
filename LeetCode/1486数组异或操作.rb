# @param {Integer} n
# @param {Integer} start
# @return {Integer}
def xor_operation(n, start)
    ans = start
    (1...n).each do |i|
        ans ^= start + 2 * i
    end
    return ans
end