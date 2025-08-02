#pragma once

#include "HavingCell.h"
#include "IReplenishable.h"

namespace ticket {
    class Timed : public HavingCell, public IReplenishable {
        unsigned expiredAt{};

    public:
        Timed(const unsigned id, const Owner &owner, const unsigned cellId)
            : HavingCell(id, owner, cellId) {
        }

        Timed &operator+=(unsigned amount) override {
            expiredAt += amount;
            return *this;
        }

        unsigned getRemains() override;

        void print() const override {
            std::cout << "Timed Ticket ID: " << std::endl;
        }
    };
}
