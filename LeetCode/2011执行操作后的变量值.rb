# @param {String[]} operations
# @return {Integer}
def final_value_after_operations(operations)
    ans = 0
    (0...operations.size).each do |x|
        if operations[x][1] == "+" then
            ans += 1
        elsif operations[x][1] == '-'
            ans -= 1
        end
    end
    return ans
end