#pragma once

#include "HavingCell.h"
#include "IChangeable.h"

namespace ticket {
    class Unlimited : public HavingCell, public IChangeable {
    public:
        Unlimited(const unsigned id, const Owner &owner, const unsigned cellId)
            : HavingCell(id, owner, cellId) {
        }

        void operator()(const Owner &owner) override;

        void print() const override;
    };
}
