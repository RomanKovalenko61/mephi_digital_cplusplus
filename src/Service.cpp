#include "../include/Service.h"

namespace ticket {
    void Service::operator()(const Owner &owner) {
        this->owner = owner;
    }

    void Service::print() const {
        std::cout << "Service Ticket with ID: " << id << std::endl;
    }

    std::pair<TicketType, unsigned> Service::getTypeAndId() const {
        return {TicketType::Service, id};
    }

    bool Service::canGoThrough(unsigned turnstileId) const {
        return this->turnstileId == turnstileId;
    }

    void Service::goThrough(unsigned turnstileId) {
        if (canGoThrough(turnstileId)) {
            std::cout << "Service Ticket go through turnstile with ID: " << turnstileId << std::endl;
        }
    }
}
