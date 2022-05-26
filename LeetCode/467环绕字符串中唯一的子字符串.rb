# @param {String} p
# @return {Integer}
def find_substring_in_wrapround_string(p)
    temp = 0
    arr = Array.new(26, 0)
    (0...p.size).each do |x|
        if x > 0 && (p[x].ord - p[x - 1].ord + 26) % 26 == 1 then
            temp += 1
        else 
            temp = 1
        end
        arr[p[x].ord - 97] = [arr[p[x].ord - 97], temp].max
    end
    return arr.sum
end