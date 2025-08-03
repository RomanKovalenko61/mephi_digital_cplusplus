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
            if (is_open) {
                std::cout << "Cell with ID " << cellId << " already is opened" << std::endl;
            } else {
                std::cout << "Cell with ID " << cellId << " was open" << std::endl;
                is_open = true;
            }
        }

        void close() {
            if (!is_open) {
                std::cout << "Cell with ID " << cellId << " already is closed" << std::endl;
            } else {
                std::cout << "Cell with ID " << cellId << " was close" << std::endl;
                is_open = false;
            }
        }

        bool isOpen() const {
            return is_open;
        }
    };
}
