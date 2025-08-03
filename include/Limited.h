#pragma once

#include "HavingCell.h"
#include "IReplenishable.h"


namespace ticket {
    class Limited : public HavingCell, public IReplenishable {
        unsigned count{};

    public:
        Limited(unsigned id, const Owner &owner, unsigned cellId)
            : HavingCell(id, owner, cellId) {
        }

        Limited &operator+=(unsigned amount) override {
            count += amount;
            return *this;
        }

        float replenish(unsigned amount) override;

        unsigned getRemains() override;

        void print() const override;

        std::pair<TicketType, unsigned> getTypeAndId() const override;

        bool canGoThrough(unsigned turnstileId) const override;

        void goThrough(unsigned turnstileId) override;
    };
}
