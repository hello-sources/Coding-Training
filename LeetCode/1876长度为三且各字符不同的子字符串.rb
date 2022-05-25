# @param {String} s
# @return {Integer}
def count_good_substrings(s)
    cnt = 0
    (0...s.size - 2).each do |i|
        if s[i].ord != s[i + 1].ord && s[i + 1].ord != s[i + 2].ord && s[i].ord != s[i + 2].ord then
            cnt += 1 
        end
    end
    return cnt
end