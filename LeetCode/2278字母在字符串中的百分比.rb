# @param {String} s
# @param {Character} letter
# @return {Integer}
def percentage_letter(s, letter)
    cnt = 0
    len = s.size
    # for i in (0...len)
    #     if s[i] == letter
    #         cnt += 1
    #     end
    # end
    s.each_char do |x|
        if x == letter then
            cnt += 1
        end
    end
    return cnt * 100 / len
end