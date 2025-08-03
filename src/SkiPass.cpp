#include "../include/SkiPass.h"
#include "../include/Unlimited.h"
#include "../include/Timed.h"
#include "../include/Limited.h"
#include "../include/Service.h"

#include <memory>

namespace ticket {
    std::shared_ptr<SkiPass> SkiPass::createTicket(TicketType type, unsigned id, const Owner &owner,
                                                   unsigned cellOrTurnstileId) {
        switch (type) {
            case TicketType::Unlimited:
                return std::make_shared<Unlimited>(id, owner, cellOrTurnstileId);
            case TicketType::Timed:
                return std::make_shared<Timed>(id, owner, cellOrTurnstileId);
            case TicketType::Limited:
                return std::make_shared<Limited>(id, owner, cellOrTurnstileId);
            case TicketType::Service:
                return std::make_shared<Service>(id, owner, cellOrTurnstileId);
            default:
                return nullptr;
        }
    }
}
