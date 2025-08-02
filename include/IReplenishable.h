#pragma once

#include "SkiPass.h"

namespace ticket {
    class IReplenishable {
    protected:
        IReplenishable() = default;

    public:
        virtual ~IReplenishable() = default;

        virtual SkiPass &operator+=(unsigned amount) = 0;

        virtual unsigned getRemains() = 0;
    };
}
