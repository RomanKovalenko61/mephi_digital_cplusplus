#include "../include/Unlimited.h"

namespace ticket {
    void Unlimited::operator()(const Owner &owner) {
        this->owner = owner;
    }

    void Unlimited::print() const {
        std::cout << "Unlimited Ticket ID: " << std::endl;
    }

    std::pair<TicketType, unsigned> Unlimited::getTypeAndId() const {
        return {TicketType::Unlimited, id};
    }
}
