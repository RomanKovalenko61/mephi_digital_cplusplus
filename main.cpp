#include <iostream>

#include "include/Limited.h"
#include "include/SkiPass.h"
#include "include/Unlimited.h"
#include "include/Timed.h"
#include "include/InMemoryRepo.h"

int main() {
    ticket::Owner owner{"fio owner", 30, 'm'};
    auto unlim_ticket = ticket::SkiPass::createTicket(ticket::TicketType::Unlimited, 1, owner, 100);

    unlim_ticket->print();

    auto *unlim = dynamic_cast<ticket::Unlimited *>(unlim_ticket.get());
    if (unlim != nullptr) {
        unlim->getOwner().print_info(std::cout);
        (*unlim)({"new owner", 25, 'f'});
        unlim->getOwner().print_info(std::cout);
    }

    auto timed_ticker = ticket::SkiPass::createTicket(ticket::TicketType::Timed, 2, owner, 200);

    timed_ticker->print();
    auto *timed = dynamic_cast<ticket::Timed *>(timed_ticker.get());
    if (timed != nullptr) {
        std::cout << timed->getExpiredAtStr() << std::endl;
        auto change = timed->replenish(150);
        std::cout << "Change: " << change << std::endl;
        std::cout << "Hours left: " << timed->getRemains() << std::endl;
        std::cout << timed->getExpiredAtStr() << std::endl;
    }

    auto limited_ticket = ticket::SkiPass::createTicket(ticket::TicketType::Limited, 3, owner, 300);

    limited_ticket->print();
    auto *limited = dynamic_cast<ticket::Limited *>(limited_ticket.get());
    if (limited != nullptr) {
        std::cout << "Trips left: " << limited->getRemains() << std::endl;
        auto change = limited->replenish(250);
        std::cout << "Change: " << change << std::endl;
        std::cout << "Trips left: " << limited->getRemains() << std::endl;
    }

    ticket::MapRepoImpl repo;
    repo.add(timed->getTypeAndId(), std::move(timed_ticker));
    repo.add(unlim->getTypeAndId(), std::move(unlim_ticket));

    for (auto &[key, value]: repo.copyStorage()) {
        std::cout << "Key: " << static_cast<int>(key.first) << ", ID: " << key.second << std::endl;
        value->print();
    }

    return 0;
}
