#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    list<int> pageQueue;
    unordered_map<int, list<int>::iterator> pageMap;
    int cacheSize;

public:
    LRUCache(int size) {
        cacheSize = size;
    }

    void referPage(int pageNum) {
        if (pageMap.find(pageNum) == pageMap.end()) {
            if (pageQueue.size() == cacheSize) {
                int lastPage = pageQueue.back();
                pageQueue.pop_back();
                pageMap.erase(lastPage);
            }
        } else {
            pageQueue.erase(pageMap[pageNum]);
        }

        pageQueue.push_front(pageNum);
        pageMap[pageNum] = pageQueue.begin();
    }

    void displayCache() {
        for (auto page : pageQueue) {
            cout << page << " ";
        }
        cout << endl;
    }
};

int main() {
    LRUCache cache(3); // Cache size is 3

    cache.referPage(1); // Page 1 is referenced (added to cache)
    cache.displayCache(); // Cache: 1

    cache.referPage(2); // Page 2 is referenced (added to cache)
    cache.displayCache(); // Cache: 2 1

    cache.referPage(3); // Page 3 is referenced (added to cache)
    cache.displayCache(); // Cache: 3 2 1

    cache.referPage(4); // Page 4 is referenced (Page 1 is removed as it is least recently used)
    cache.displayCache(); // Cache: 4 3 2

    cache.referPage(2); // Page 2 is referenced (moved to the front of the cache)
    cache.displayCache(); // Cache: 2 4 3

    return 0;
}
