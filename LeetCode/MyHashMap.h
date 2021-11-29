#pragma once

// Design a HashMap without using any built - in hash table libraries.
// Implement the MyHashMap class :
// 	MyHashMap() initializes the object with an empty map.
// 	void put(int key, int value) inserts a(key, value) pair into the HashMap.If the key already exists in the map, update the corresponding value.
// 	int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// 	void remove(key) removes the keyand its corresponding value if the map contains the mapping for the key.
// Constraints:
//	0 <= key, value <= 10^6
//	At most 10^4 calls will be made to put, get, and remove.

#include<vector>
#include<forward_list>
#include<iterator>
#include<algorithm>
#include<utility>

class MyHashMap {
private:
    std::vector<std::forward_list<std::pair<int, int>>> m_buckets;
    size_t BUCKETS_QTY = 10'007; // five-digit prime or use 1009 smallest four-digit prime
public:
    MyHashMap() {
        m_buckets.resize(BUCKETS_QTY);
    }

    void put(int key, int value) {
        auto& bucket = m_buckets[key % BUCKETS_QTY];
        auto iter = std::find_if(bucket.begin(), bucket.end(), [key](auto el) { return el.first == key; });
        if(iter != bucket.end()) {
            iter->second = value;
        } else {
            bucket.push_front({ key, value });
        }
    }

    int get(int key) {
        auto bucket = m_buckets[key % BUCKETS_QTY];
        auto iter = std::find_if(bucket.begin(), bucket.end(), [key](auto el) { return el.first == key; });
        if (iter != bucket.end()) {
            return iter->second;
        }
        else {
            return -1;
        }

    }

    void remove(int key) {
        auto& bucket = m_buckets[key % BUCKETS_QTY];
        bucket.remove_if([key](auto el) { return el.first == key; });
    }
};