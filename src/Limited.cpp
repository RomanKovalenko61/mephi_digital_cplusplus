#include "../include/Limited.h"
#include "../include/Settings.h"

namespace ticket {
    unsigned Limited::getRemains() {
        return count;
    }

    void Limited::print() const {
        std::cout << "Limited Ticket with ID: " << id << std::endl;
    }

    float Limited::replenish(unsigned amount) {
        auto price = static_cast<unsigned>(Settings::price_trip);
        unsigned transfer = amount / price;
        this->operator+=(transfer);
        return static_cast<float>(amount - transfer * price);
    }

    std::pair<TicketType, unsigned> Limited::getTypeAndId() const {
        return {TicketType::Limited, id};
    }

    bool Limited::canGoThrough(unsigned turnstileId) const {
        return count > 0;
    }

    void Limited::goThrough(unsigned turnstileId) {
        if (canGoThrough(turnstileId)) {
            count--;
            std::cout << "Timed Ticket go through turnstile with ID: " << turnstileId << std::endl;
        }
    }
}
