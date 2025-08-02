#pragma once

#include "SkiPass.h"

namespace ticket {
    class IChangeable {
    protected:
        IChangeable() = default;

    public:
        virtual ~IChangeable() = default;

        virtual void operator()(const Owner &owner) = 0;
    };
}
