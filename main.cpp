#include <iostream>

#include "include/Limited.h"
#include "include/SkiPass.h"
#include "include/Unlimited.h"
#include "include/Timed.h"
#include "include/InMemoryRepo.h"
#include "include/Service.h"

unsigned ID = 1;

unsigned generateId() {
    return ID++;
}

using namespace ticket;

int main() {
    std::cout << "Step 0 : create owners, tickets" << std::endl;
    Owner owner{"Ivanov Ivan Ivanovich", 30, 'M'};
    Owner owner2{"Petrov Petr Petrovich", 25, 'M'};
    Owner owner3{"Sidorov Sidor Sidorovich", 28, 'M'};
    Owner owner4{"Ivanova Alexandra Petrovna", 21, 'F'};
    Owner owner5{"Smehova Tatyana Vladimirivna", 25, 'F'};
    Owner owner6{"Sidorova Elena Sergeevna", 22, 'F'};
    Owner owner7{"NewOwnerov Man Manovich", 35, 'M'};

    auto unlim_ticket = SkiPass::createTicket(TicketType::Unlimited, generateId(), owner, 1);
    auto timed_ticket = SkiPass::createTicket(TicketType::Timed, generateId(), owner2, 2);
    auto limited_ticket = SkiPass::createTicket(TicketType::Limited, generateId(), owner3, 3);
    auto service_ticket = SkiPass::createTicket(TicketType::Service, generateId(), owner4, 4);
    auto unlim_ticket2 = SkiPass::createTicket(TicketType::Unlimited, generateId(), owner5, 5);
    auto timed_ticket2 = SkiPass::createTicket(TicketType::Timed, generateId(), owner6, 6);

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Step 1 : fill repo (unordered) and get each element (Sorted type after sorted ID)" << std::endl;
    MapRepoImpl repo;
    repo.add(unlim_ticket->getTypeAndId(), std::move(unlim_ticket));
    repo.add(timed_ticket->getTypeAndId(), std::move(timed_ticket));
    repo.add(limited_ticket->getTypeAndId(), std::move(limited_ticket));
    repo.add(service_ticket->getTypeAndId(), std::move(service_ticket));
    repo.add(unlim_ticket2->getTypeAndId(), std::move(unlim_ticket2));
    repo.add(timed_ticket2->getTypeAndId(), std::move(timed_ticket2));

    std::cout << "Repo size: " << repo.size() << std::endl;
    std::cout << repo;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Step 2 : test method print()" << std::endl;

    for (auto &[key, value]: repo.copyStorage()) {
        value->print();
    }

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Step 3 : test method for classes" << std::endl;

    for (auto &[key, value]: repo.copyStorage()) {
        auto unlim = dynamic_cast<Unlimited *>(value.get());
        auto timed = dynamic_cast<Timed *>(value.get());
        auto limited = dynamic_cast<Limited *>(value.get());
        auto service = dynamic_cast<Service *>(value.get());
        value->print();
        if (unlim) {
            unlim->getOwner().print_info(std::cout);
            std::cout << "Changed owner ... " << std::endl;
            unlim->operator()(owner7);
            unlim->getOwner().print_info(std::cout);
            std::cout << std::boolalpha << "Cell is open? " << unlim->isOpen() << std::endl;
            std::cout << "Opening cell with ID : " << unlim->getCellId() << std::endl;
            unlim->open();
            std::cout << "Can go through turnstile 1? " << unlim->canGoThrough(1) << std::endl;
            unlim->goThrough(1);
        }
        if (timed) {
            timed->getOwner().print_info(std::cout);
            std::cout << std::boolalpha << "Cell is open? " << timed->isOpen() << std::endl;
            std::cout << "Opening cell with ID : " << timed->getCellId() << std::endl;
            timed->open();
            std::cout << "Can go through turnstile 1? " << timed->canGoThrough(1) << std::endl;
            timed->goThrough(1);
            std::cout << "Replenish ticket with 1000 rubles" << std::endl;
            float change = timed->replenish(1000);
            std::cout << "Change: " << change << " rubles" << std::endl;
            std::cout << "Remains: " << timed->getRemains() << " hours" << std::endl;
            std::cout << "Can go through turnstile 1? " << timed->canGoThrough(1) << std::endl;
            timed->goThrough(1);
        }
        if (limited) {
            limited->getOwner().print_info(std::cout);
            std::cout << std::boolalpha << "Cell is open? " << limited->isOpen() << std::endl;
            std::cout << "Opening cell with ID : " << limited->getCellId() << std::endl;
            limited->open();
            std::cout << "Can go through turnstile 1? " << limited->canGoThrough(1) << std::endl;
            limited->goThrough(1);
            std::cout << "Replenish ticket with 1000 rubles" << std::endl;
            float change = limited->replenish(1000);
            std::cout << "Change: " << change << " rubles" << std::endl;
            std::cout << "Remains: " << limited->getRemains() << " counts" << std::endl;
            std::cout << "Can go through turnstile 1? " << limited->canGoThrough(1) << std::endl;
            limited->goThrough(1);
            std::cout << "Remains: " << limited->getRemains() << " counts" << std::endl;
        }
        if (service) {
            service->getOwner().print_info(std::cout);
            std::cout << "Changed owner ... " << std::endl;
            service->operator()(owner7);
            service->getOwner().print_info(std::cout);
            std::cout << "Can go through turnstile 1? " << service->canGoThrough(1) << std::endl;
            service->goThrough(1);
            std::cout << "Can go through turnstile 4? " << service->canGoThrough(4) << std::endl;
            service->goThrough(4);
        }
        std::cout << "----- ****** ----------" << std::endl;
    }

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Step 4 : clean storage" << std::endl;

    repo.clear();
    std::cout << "Repo size after clear: " << repo.size() << std::endl;
    std::cout << repo;

    return 0;
}
