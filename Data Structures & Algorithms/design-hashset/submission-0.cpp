class MyHashSet {
private:
    size_t capacity = 16384; // p = 14
    size_t mask = this->capacity - 1;

    vector<int> table = vector<int>(this->capacity, -1);

    enum State : uint8_t { EMPTY, OCCUPIED, DELETED };
    vector<State> state = vector<State>(capacity, EMPTY);

    static inline uint32_t hash(int key) {
        // Knuth's Multiplicative Hashing
        return (static_cast<uint32_t>(key) * 2654435769u) >> (32 - 14);
    }
public:
    MyHashSet() {}

    void add(int key) {
        uint32_t idx = hash(key);
    
        // will only be used if a DELETED slot is found
        // and the key is guaranteed not to be later in the chain
        int firstDeleted = -1;
        while (state[idx] != EMPTY) {
            if (state[idx] == OCCUPIED && table[idx] == key)
                return;
            if (state[idx] == DELETED && firstDeleted == -1)
                firstDeleted = idx;
            idx = (idx + 1) & mask;
        }
        int insertAt = (firstDeleted != -1) ? firstDeleted : idx;
        table[insertAt] = key;
        state[insertAt] = OCCUPIED;
    }

    void remove(int key) {
        uint32_t idx = hash(key);
        while (state[idx] != EMPTY) {
            if (state[idx] == OCCUPIED && table[idx] == key) {
                state[idx] = DELETED;
                return;
            }
            idx = (idx + 1) & mask;
        }
    }

    bool contains(int key) {
        uint32_t idx = hash(key);
        while (state[idx] != EMPTY) {
            if (state[idx] == OCCUPIED && table[idx] == key)
                return true;
            idx = (idx + 1) & mask;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */