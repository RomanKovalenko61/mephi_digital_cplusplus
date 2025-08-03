#pragma once

#include <map>
#include "IRepo.h"

namespace ticket {
    class MapRepoImpl : public IRepo {
        std::map<Key, Value> storage;

    public:
        void add(const Key &key, Value &&value) override;

        std::shared_ptr<SkiPass> find(const Key &key) const override;

        bool remove(const Key &key) override;

        bool contains(const Key &key) const override;

        void clear() override;

        size_t size() const override;

        std::map<Key, Value> copyStorage() const;

        friend std::ostream &operator<<(std::ostream &os, const MapRepoImpl &repo);
    };
}
