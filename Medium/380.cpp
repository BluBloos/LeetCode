// Going to start by doing the dumbest thing - the thing that I know will
// be absolutely slow and not O(1).
#include <vector>
#include <random>

class RandomizedSet {
private:
    std::vector<int> set;
    std::random_device rd;
    std::mt19937 gen; // standard mersenne_twister_engine
    std::uniform_int_distribution<int> dist;

    void UpdateDistribution(int totalElements) {
        dist = std::uniform_int_distribution<int>(0, totalElements - 1); // construct a new distribution.
    }

public:
    RandomizedSet() : dist(0,1), gen(rd()) {
        // nothing really needs to happen here. lol.
        // dist = std::uniform_int_distribution<int>(0, 9);
    }
    
    bool insert(int val) {
        // Check if the value is in the set.
        bool inSet = false;
        for (unsigned int i = 0; i < set.size(); i++) {
            if (set[i] == val) {
                inSet = true;
                break;
            }
        }
        if (!inSet) set.push_back(val);
        UpdateDistribution(set.size());
        return !inSet;
    }
    
    bool remove(int val) {
        bool removed = false;
        for (unsigned int i = 0; i < set.size(); i++) {
            if (set[i] == val) {
                // remove from the list.
                set.erase(set.begin() + i);
                removed = true;
                break;
            }
        }
        UpdateDistribution(set.size());
        return removed;
    }
    
    int getRandom() {
        if (set.size() == 1) {
            return set[0];
        } else {
            int index = dist(gen);
            return set[index];
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.

bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.

bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.

int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists 
when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
*/