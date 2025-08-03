#include <iostream>

#include "include/Limited.h"
#include "include/SkiPass.h"
#include "include/Unlimited.h"
#include "include/Timed.h"
#include "include/InMemoryRepo.h"
#include "include/Service.h"

int main() {
    ticket::Owner owner{"fio owner", 30, 'm'};
    auto unlim_ticket = ticket::SkiPass::createTicket(ticket::TicketType::Unlimited, 1, owner, 100);

    unlim_ticket->print();

    auto *unlim = dynamic_cast<ticket::Unlimited *>(unlim_ticket.get());
    if (unlim != nullptr) {
        unlim->getOwner().print_info(std::cout);
        (*unlim)({"new owner", 25, 'f'});
        unlim->getOwner().print_info(std::cout);
        std::cout << "Cell ID: " << unlim->getCellId() << std::endl;
        unlim->goThrough(1);
    }

    std::cout << " ----------------------------------------" << std::endl;

    auto timed_ticker = ticket::SkiPass::createTicket(ticket::TicketType::Timed, 2, owner, 200);

    timed_ticker->print();
    auto *timed = dynamic_cast<ticket::Timed *>(timed_ticker.get());
    if (timed != nullptr) {
        std::cout << timed->getExpiredAtStr() << std::endl;
        auto change = timed->replenish(150);
        std::cout << "Change: " << change << std::endl;
        std::cout << "Hours left: " << timed->getRemains() << std::endl;
        std::cout << timed->getExpiredAtStr() << std::endl;
        std::cout << "Cell ID: " << timed->getCellId() << std::endl;
        timed->goThrough(1);
        std::cout << std::boolalpha << timed->canGoThrough(2) << std::endl;
    }

    std::cout << " ----------------------------------------" << std::endl;

    auto limited_ticket = ticket::SkiPass::createTicket(ticket::TicketType::Limited, 3, owner, 300);

    limited_ticket->print();
    auto *limited = dynamic_cast<ticket::Limited *>(limited_ticket.get());
    if (limited != nullptr) {
        std::cout << "Trips left: " << limited->getRemains() << std::endl;
        auto change = limited->replenish(250);
        std::cout << "Change: " << change << std::endl;
        std::cout << "Trips left: " << limited->getRemains() << std::endl;
        limited->goThrough(1);
        std::cout << "Trips left: " << limited->getRemains() << std::endl;
        std::cout << "Cell ID: " << limited->getCellId() << std::endl;
    }

    std::cout << " ----------------------------------------" << std::endl;

    auto service_ticket = ticket::SkiPass::createTicket(ticket::TicketType::Service, 4, owner, 2);
    service_ticket->print();
    auto *serviced = dynamic_cast<ticket::Service *>(service_ticket.get());
    if (serviced != nullptr) {
        std::cout << "Service Ticket ID: " << serviced->getId() << std::endl;
        serviced->getOwner().print_info(std::cout);
        serviced->goThrough(2);
        serviced->goThrough(3);
    }

    std::cout << " ----------------------------------------" << std::endl;

    ticket::MapRepoImpl repo;
    repo.add(timed->getTypeAndId(), std::move(timed_ticker));
    repo.add(unlim->getTypeAndId(), std::move(unlim_ticket));
    repo.add(service_ticket->getTypeAndId(), std::move(service_ticket));
    repo.add(limited->getTypeAndId(), std::move(limited_ticket));

    std::cout << "Repo size: " << repo.size() << std::endl;
    std::cout << repo;

    return 0;
}
