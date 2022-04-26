class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> u_map;
        for (auto &word : cpdomains) {
            int ind = word.find(' ');
            int num = stoi(word.substr(0, ind));
            string name = word.substr(ind + 1);
            while (ind > 0) {
                u_map[name] += num;
                ind = name.find('.');
                name = name.substr(ind + 1);
            }  
        }
        for (auto &x : u_map) {
            ans.push_back(to_string(x.second) + ' ' + x.first);
        }
        return ans;
    }
};