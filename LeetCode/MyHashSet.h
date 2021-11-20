#pragma once

// Design a HashSet without using any built - in hash table libraries.
// Implement MyHashSet class :
//     void add(key) Inserts the value key into the HashSet.
//     bool contains(key) Returns whether the value key exists in the HashSet or not.
//     void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
// 
// MyHashSet object will be instantiatedand called as such :
// MyHashSet * obj = new MyHashSet();
// obj->add(key);
// obj->remove(key);
// bool param_3 = obj->contains(key);
// 0 <= key <= 1'000'000


#include<vector>
#include<forward_list>
#include<iterator>
#include<algorithm>

class MyHashSet {
private:
    std::vector<std::forward_list<int>> m_buckets;

public:
    MyHashSet() {
        m_buckets.resize(1000); // since 0 <= key <= 1'000'000 let's create 1000 buckets
    }

    void add(int key) {
        size_t i = key % 1000; // hash index
        if (std::find(m_buckets[i].begin(), m_buckets[i].end(), key) == m_buckets[i].end()) {
            m_buckets[i].push_front(key);
        }
    }

    void remove(int key) {
        size_t i = key % 1000; // hash index
        m_buckets[i].remove(key);
    }

    bool contains(int key) {
        size_t i = key % 1000; // hash index
        return std::find(m_buckets[i].begin(), m_buckets[i].end(), key) != m_buckets[i].end();
    }
};


 
