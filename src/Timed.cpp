#include "../include/Timed.h"

#include "../include/Settings.h"

namespace ticket {
    unsigned Timed::getRemains() {
        auto now = std::chrono::system_clock::now();
        if (expiredAt <= now) return 0;
        auto diff = std::chrono::duration_cast<std::chrono::hours>(expiredAt - now).count();
        return static_cast<unsigned>(diff);
    }

    float Timed::replenish(unsigned amount) {
        auto price = static_cast<unsigned>(Settings::price_day);
        unsigned days = amount / price;
        this->operator+=(days);
        float change = static_cast<float>(amount) - days * price;
        return change;
    }

    std::string Timed::getExpiredAtStr() const {
        std::time_t tt = std::chrono::system_clock::to_time_t(expiredAt);
        std::tm tm = *std::localtime(&tt);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
        return oss.str();
    }

    void Timed::print() const {
        std::cout << "Timed Ticket ID: " << std::endl;
    }

    std::pair<TicketType, unsigned> Timed::getTypeAndId() const {
        return {TicketType::Timed, id};
    }
}
