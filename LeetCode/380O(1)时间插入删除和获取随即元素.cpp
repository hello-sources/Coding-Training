class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (u_map.count(val)) return false;
        u_map[val] = vec.size();
        vec.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!u_map.count(val)) return false;
        int ind = u_map[val];
        int last = vec.back();
        vec[ind] = last;
        u_map[last] = ind;
        vec.pop_back();
        u_map.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }

private:
    vector<int> vec;
    unordered_map<int, int> u_map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */