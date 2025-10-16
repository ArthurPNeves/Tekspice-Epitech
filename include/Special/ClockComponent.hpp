/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** ClockComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts{

class ClockComponent : public AComponent {
    private:
        nts::Tristate _state;
        bool setUsed;
    public: 
        ClockComponent();
        void setState(nts::Tristate state);
        nts::Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
};
}