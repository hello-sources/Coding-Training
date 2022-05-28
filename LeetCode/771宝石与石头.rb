# @param {String} jewels
# @param {String} stones
# @return {Integer}
def num_jewels_in_stones(jewels, stones)
    jewels.split('').map { |e| stones.count(e) }.sum
end