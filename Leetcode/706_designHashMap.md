# [706. Design HashMap](https://leetcode.com/problems/design-hashmap/) 🌟

Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:

-   `MyHashMap()` initializes the object with an empty map.
-   `void put(int `key`, int `value`)` inserts a (`key`, `value`) pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
-   int get(int `key`) returns the `value` to which the specified `key` is mapped, or -1 if this map contains no mapping for the `key`.
-   void remove(`key`) removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.

### Array implementation

-   Simple implementation with array.

```cpp

class MyHashMap {
public:
    int arr[1000001];
    MyHashMap(){
        memset(arr, -1, sizeof(arr));
    }

    void put(int key, int val){
        arr[key] = val;
    }

    int get(int key){
        return arr[key];
    }

    void remove(int key){
        arr[key] = -1;
    }
};
```

### With the hashing function - 1

### Code

```cpp
class MyHashMap {
    vector<list<pair<int, int>>> mp;
    int sz;

public:
    MyHashMap()
    {
        sz = 119;
        mp.resize(sz);
    }

    // hash function
    int hash(int key)
    {
        return key % sz;
    }

    // returns iterator to the element with key == k
    list<pair<int, int>>::iterator search(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = mp[i].begin();
        while (it != mp[i].end()) {
            if (it->first == key) {
                return it;
            }
            it++;
        }
        return it;
    }

    // insert key, value pair
    void put(int key, int value)
    {
        int i = hash(key);
        remove(key);
        mp[i].push_back({ key, value });
    }

    // get value for key
    int get(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        if (it != mp[i].end()) {
            return it->second;
        }
        return -1;
    }

    // remove key, value pair
    void remove(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        if (it != mp[i].end()) {
            mp[i].erase(it);
        }
    }
};
```

### With the hashing function - 2

-   Read [this](<https://leetcode.com/problems/design-hashmap/discuss/1097755/JS-Python-Java-C%2B%2B-or-(Updated)-Hash-and-Array-Solutions-w-Explanation>)

```cpp

struct Node {
public:
    int key, val;
    Node* next;
    Node(int k, int v, Node* n)
    {
        key = k;
        val = v;
        next = n;
    }
};
class MyHashMap {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size];
    int hash(int key)
    {
        return (int)((long)key * mult % size);
    }
    void put(int key, int val)
    {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, val, data[h]);
        data[h] = node;
    }
    int get(int key)
    {
        int h = hash(key);
        Node* node = data[h];
        for (; node != NULL; node = node->next)
            if (node->key == key)
                return node->val;
        return -1;
    }
    void remove(int key)
    {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL)
            return;
        if (node->key == key)
            data[h] = node->next;
        else
            for (; node->next != NULL; node = node->next)
                if (node->next->key == key) {
                    node->next = node->next->next;
                    return;
                }
    }
};
```

### Must Read

-   [JS, Python, Java, C++ | (Updated) Hash & Array Solutions w/ Explanation](<https://leetcode.com/problems/design-hashmap/discuss/1097755/JS-Python-Java-C%2B%2B-or-(Updated)-Hash-and-Array-Solutions-w-Explanation>)
