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

        unsigned getRemains() override;

        void print() const override;
    };
}
