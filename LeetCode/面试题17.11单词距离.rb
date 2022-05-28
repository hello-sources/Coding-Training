# @param {String[]} words
# @param {String} word1
# @param {String} word2
# @return {Integer}
def find_closest(words, word1, word2)
    hash_word = Hash.new
    ind1 = []
    ind2 = []
    temp = 100000
    (0...words.size).each do |x|
        hash_word[x] = words[x] 
    end
    hash_word.each_key do |x|
        if hash_word[x] == word1 then
            ind1 << x
        end
        if hash_word[x] == word2 then
            ind2 << x
        end
    end
    for i in ind1 do
        for j in ind2 do
            if (i - j).abs <= temp then
                temp = (i - j).abs
            end
        end
    end
    return temp
end