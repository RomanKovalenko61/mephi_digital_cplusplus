#pragma once

#include "SkiPass.h"

namespace ticket {
    class HavingCell : public SkiPass {
    protected:
        unsigned cellId;
        bool is_open;

        explicit HavingCell(unsigned id, const Owner &owner, unsigned cellId) : SkiPass(id, owner), cellId(cellId),
            is_open(false) {
        }

    public:
        HavingCell() = delete;

        ~HavingCell() override = default;

        unsigned getCellId() const {
            return cellId;
        }

        void open() {
            is_open = true;
        }

        void close() {
            is_open = false;
        }

        bool isOpen() const {
            return is_open;
        }
    };
}
