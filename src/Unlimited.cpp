#include "../include/Unlimited.h"

namespace ticket {
    void Unlimited::operator()(const Owner &owner) {
        this->owner = owner;
    }

    void Unlimited::print() const {
        std::cout << "Unlimited Ticket with ID: " << id << std::endl;
    }

    std::pair<TicketType, unsigned> Unlimited::getTypeAndId() const {
        return {TicketType::Unlimited, id};
    }

    bool Unlimited::canGoThrough(unsigned turnstileId) const {
        return true;
    }

    void Unlimited::goThrough(unsigned turnstileId) {
        std::cout << "Unlimited Ticket go through turnstile with ID: " << turnstileId << std::endl;
    }
}
