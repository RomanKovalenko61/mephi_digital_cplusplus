#pragma once

#include <chrono>
#include "HavingCell.h"
#include "IReplenishable.h"

namespace ticket {
    class Timed : public HavingCell, public IReplenishable {
        std::chrono::system_clock::time_point expiredAt{};

    public:
        Timed(const unsigned id, const Owner &owner, const unsigned cellId)
            : HavingCell(id, owner, cellId),
              expiredAt(std::chrono::system_clock::now()) {
        }

        Timed &operator+=(const unsigned days) override {
            expiredAt = std::chrono::system_clock::now();
            expiredAt += std::chrono::days(days);
            return *this;
        }

        float replenish(unsigned amount) override;

        unsigned getRemains() override;

        void print() const override;

        std::string getExpiredAtStr() const;

        std::pair<TicketType, unsigned> getTypeAndId() const override;

        bool canGoThrough(unsigned turnstileId) const override;

        void goThrough(unsigned turnstileId) override;
    };
}
