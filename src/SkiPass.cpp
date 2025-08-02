#include "../include/SkiPass.h"
#include "../include/Unlimited.h"
#include "../include/Timed.h"
#include "../include/Limited.h"
#include "../include/Service.h"

#include <memory>

namespace ticket {
    std::unique_ptr<SkiPass> SkiPass::createTicket(TicketType type, unsigned id, const Owner &owner,
                                                   unsigned cellOrTurnstileId) {
        switch (type) {
            case TicketType::Unlimited:
                return std::make_unique<Unlimited>(id, owner, cellOrTurnstileId);
            case TicketType::Timed:
                return std::make_unique<Timed>(id, owner, cellOrTurnstileId);
            case TicketType::Limited:
                return std::make_unique<Limited>(id, owner, cellOrTurnstileId);
            case TicketType::Service:
                return std::make_unique<Service>(id, owner, cellOrTurnstileId);
            default:
                return nullptr;
        }
    }
}
