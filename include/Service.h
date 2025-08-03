#pragma once

#include "IChangeable.h"
#include "SkiPass.h"

namespace ticket {
    class Service : public SkiPass, public IChangeable {
        unsigned turnstileId{};

    public:
        Service(unsigned id, const Owner &owner, unsigned turnstileId)
            : SkiPass(id, owner), turnstileId(turnstileId) {
        }

        void operator()(const Owner &owner) override;

        void print() const override;

        std::pair<TicketType, unsigned> getTypeAndId() const override;

        bool canGoThrough(unsigned turnstileId) const override;

        void goThrough(unsigned turnstileId) override;
    };
}
