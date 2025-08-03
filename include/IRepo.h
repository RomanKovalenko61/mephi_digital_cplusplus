#pragma once
#include <string>
#include <utility>

#include "SkiPass.h"

namespace ticket {
    class IRepo {
    public:
        using Key = std::pair<TicketType, unsigned>;
        using Value = std::shared_ptr<SkiPass>;

        virtual ~IRepo() = default;

        virtual void add(const Key &key, Value &&value) = 0;

        virtual std::shared_ptr<SkiPass> find(const Key &key) const = 0;

        virtual bool remove(const Key &key) = 0;

        virtual bool contains(const Key &key) const = 0;

        virtual void clear() = 0;

        virtual size_t size() const = 0;
    };
}
