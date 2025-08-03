#include <map>
#include "../include/InMemoryRepo.h"

namespace ticket {
    void MapRepoImpl::add(const Key &key, Value &&value) {
        storage[key] = std::move(value);
    }

    std::shared_ptr<SkiPass> MapRepoImpl::find(const Key &key) const {
        auto it = storage.find(key);
        if (it != storage.end()) {
            return it->second;
        }
        return nullptr;
    }

    bool MapRepoImpl::remove(const Key &key) {
        return storage.erase(key);
    }

    bool MapRepoImpl::contains(const Key &key) const {
        return storage.find(key) != storage.end();
    }

    void MapRepoImpl::clear() {
        storage.clear();
    }

    size_t MapRepoImpl::size() const {
        return storage.size();
    }

    std::map<IRepo::Key, IRepo::Value> MapRepoImpl::copyStorage() const {
        return storage;
    };
}
