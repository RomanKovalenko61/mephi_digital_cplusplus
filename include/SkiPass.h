#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace ticket {
    enum class TicketType { Unlimited, Timed, Limited, Service };

    struct Owner {
        std::string fio;
        int age;
        char gender;

        void print_info(std::ostream &os) const {
            os << fio << " " << age << " " << gender << std::endl;
        }
    };

    class SkiPass {
    protected:
        unsigned id;
        Owner owner;

        SkiPass(unsigned id, Owner owner) : id(id), owner(std::move(owner)) {
        }

    public:
        SkiPass() = delete;

        virtual ~SkiPass() = default;

        unsigned getId() const {
            return id;
        }

        const Owner &getOwner() const {
            return owner;
        }

        virtual void print() const = 0;

        static std::unique_ptr<SkiPass> createTicket(TicketType type, unsigned id, const Owner &owner,
                                                     unsigned cellOrTurnstileId = 0);
    };
}
