# @param {Integer[]} encoded
# @param {Integer} first
# @return {Integer[]}
def decode(encoded, first)
    n = encoded.size
    ans = Array.new(n)
    ans[0] = first
    for i in (1...n + 1)
        ans[i] = encoded[i - 1] ^ ans[i - 1]
    end
    return ans
end