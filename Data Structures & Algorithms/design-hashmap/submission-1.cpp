class MyHashMap {
    private:
    // p = 14 (there are at most 10^4 calls, which can all be put(), then capacity >= 10^4)
    // but we have to store both the key and value, so its capacity >= 10^5
    // then, p = 15
    size_t capacity = 32768;
    size_t mask = this->capacity - 1;

    vector<pair<int, int>> table = vector<pair<int, int>>(this->capacity, { -1, -1 });

    enum State : uint8_t { EMPTY, OCCUPIED, DELETED };
    vector<State> states = vector<State>(this->capacity, EMPTY);

    static inline uint32_t hash(int key) {
        // Knuth's Multiplicative Hashing
        return (static_cast<uint32_t>(key) * 2654435769u) >> (32 - 15);
    }
public:
    MyHashMap() {}

    void put(int key, int value) {
        uint32_t idx = hash(key);

        int firstDeleted = -1;
        while (this->states[idx] != EMPTY) {
            if (this->states[idx] == OCCUPIED
            && this->table[idx].first == key)
                break; // update the value at this idx
            
            if (this->states[idx] == DELETED
            && firstDeleted == -1)
                firstDeleted = idx;
            
            idx = (idx + 1) & mask;
        }

        idx = (firstDeleted != -1) ? firstDeleted : idx;
        this->table[idx] = { key, value };
        this->states[idx] = OCCUPIED;
    }

    int get(int key) {
        uint32_t idx = hash(key);

        while (this->states[idx] != EMPTY) {
            if (this->states[idx] == OCCUPIED
            && this->table[idx].first == key)
                return this->table[idx].second;

            idx = (idx + 1) & mask;
        }
        return -1;
    }

    void remove(int key) {
        uint32_t idx = hash(key);

        while (states[idx] != EMPTY) {
            if (states[idx] == OCCUPIED
            && this->table[idx].first == key) {
                states[idx] = DELETED;
                return;
            }
            idx = (idx + 1) & mask;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */