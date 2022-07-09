#include <vector>
#include <random>
class RandomizedSet {
private:
    std::random_device rd;
    std::mt19937 gen; // standard mersenne_twister_engine
    std::uniform_int_distribution<uint64_t> dist;
    std::unordered_map<int, bool> _set;
    void UpdateDistribution(uint64_t totalElements) {
        dist = std::uniform_int_distribution<uint64_t>(0, totalElements - 1); // construct a new distribution.
    }
public:
    RandomizedSet() : dist(0,1), gen(rd()) {}
    bool insert(int val) {
        bool r = !(_set.count(val) > 0);
        _set.emplace(val, true);
        UpdateDistribution(_set.bucket_count());
        return r;
    }
    bool remove(int val) {
        bool r = _set.count(val) > 0;
        _set.erase(val);
        UpdateDistribution(_set.bucket_count());
        return r;
    }
    int getRandom() {
        int index = dist(gen);
        // iterate first the index to a valid bucket.
        while (_set.bucket_size(index) == 0) {
            index = (index + 1) % _set.bucket_count();
        }
        auto iter = _set.begin(index);
        return std::get<0>(*iter);
    }
};