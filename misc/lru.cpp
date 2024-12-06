#include<iostream>
#include<deque>
#include<unordered_map>

using namespace std;

class LRU {
    private:
        int capacity;
        // {key --> (key's position in deque as iterator, value)}
        unordered_map<int, pair<deque<int>::iterator, int>> cache;
        deque<int> dq; // order of key usage
    public:
        LRU(int capacity) : capacity(capacity) {}
        int get(int key);
        void put(int key, int value);
};

int LRU::get(int key)
{
    // check if key is present in cache map
    if (cache.find(key) != cache.end()) {
        // get the iterator for 'key'
        deque<int>::iterator it = cache[key].first;

        // update queue with 'key' as recently used; meaning keep in front
        dq.erase(it);
        dq.push_front(key);
        cache[key].first = dq.begin();

        return cache[key].second;
    }

    return -1; // key not found in cache
}

/*
 * For deque O(1), better to use the following:
 * 1) int lru_key = dq.back();
 * 2) dq.pop_back();
 * */
void LRU::put(int key, int value)
{
    // check if 'key' already present, update its its value with 'value'
    if (cache.find(key) != cache.end()) {
        cache[key].second = value;
        // get it and delete it from queue
        deque<int>::iterator it = cache[key].first;
        dq.erase(it); // O(n)
        dq.push_front(key); // update value
        cache[key].first = dq.begin(); // update new it
    } else if (cache.size() == capacity) {
        // cache is full so delete the least recenty used entry from map & queue
        int lru_key = dq.back();
        deque<int>::iterator it = cache[lru_key].first;
        dq.erase(it);
        cache.erase(lru_key);

        // add to queue front & update cache
        dq.push_front(key);
        //cache[key] = {dq.begin(), value};
        cache[key].first = dq.begin();
        cache[key].second = value;
    } else {
        // key not present
        dq.push_front(key);
        deque<int>::iterator it = dq.begin();

        cache[key] = {it, value};
    }
}

int main(int argc, char *argv[]) 
{
    class LRU LRUCache(3);
    LRUCache.put(1, 10);
    LRUCache.put(2, 20);
    LRUCache.put(3, 30);

    // [1,2,3]
    cout << "Key:2 ==> Value:" << LRUCache.get(2) << endl; // [1,3,2]
    LRUCache.put(4, 40); // evict [3,2,4]
    cout << "Key:1 ==> Value:" << LRUCache.get(1) << endl;
    cout << "Key:2 ==> Value:" << LRUCache.get(2) << endl;
    cout << "Key:3 ==> Value:" << LRUCache.get(3) << endl;
    cout << "Key:4 ==> Value:" << LRUCache.get(4) << endl;

    return 0;
}
