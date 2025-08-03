#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace ticket {
    enum class TicketType { Unlimited, Timed, Limited, Service };

    inline std::string to_string(TicketType type) {
        switch (type) {
            case TicketType::Unlimited: return "Unlimited";
            case TicketType::Timed: return "Timed";
            case TicketType::Limited: return "Limited";
            case TicketType::Service: return "Service";
            default: return "Unknown";
        }
    }

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

        virtual std::pair<TicketType, unsigned> getTypeAndId() const = 0;

        static std::shared_ptr<SkiPass> createTicket(TicketType type, unsigned id, const Owner &owner,
                                                     unsigned cellOrTurnstileId = 0);
    };
}
