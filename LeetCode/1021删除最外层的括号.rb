# @param {String} s
# @return {String}
def remove_outer_parentheses(s)
    ans = ""
    cnt = 0
    (0...s.size).each do |i|
        if s[i] == ')' then
            cnt -= 1
        end
        if cnt != 0 then
            ans += s[i]
        end
        if s[i] == '(' then
            cnt += 1
        end
    end
    return ans
end