#include "../include/Service.h"

namespace ticket {
    void Service::operator()(const Owner &owner) {
        this->owner = owner;
    }

    void Service::print() const {
        std::cout << "Service Ticket ID: " << std::endl;
    }

    std::pair<TicketType, unsigned> Service::getTypeAndId() const {
        return {TicketType::Service, id};
    }
}
