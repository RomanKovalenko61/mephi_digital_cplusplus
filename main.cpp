#include <iostream>

#include "include/SkiPass.h"
#include "include/Unlimited.h"

int main() {
    ticket::Owner owner{"fio owner", 30, 'm'};
    auto ticket = ticket::SkiPass::createTicket(ticket::TicketType::Unlimited, 1, owner, 100);

    ticket->print();

    auto *unlim = dynamic_cast<ticket::Unlimited *>(ticket.get());
    if (unlim != nullptr) {
        unlim->getOwner().print_info(std::cout);
        (*unlim)({"new owner", 25, 'f'});
        unlim->getOwner().print_info(std::cout);
    }

    return 0;
}
