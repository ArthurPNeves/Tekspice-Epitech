/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** InputComponent
*/

#pragma once
#include "AComponent.hpp"
#include <string>

namespace nts{

class InputComponent : public AComponent {
    private:
        nts::Tristate _state;
    public:
        InputComponent();
        void setState(nts::Tristate state);
        nts::Tristate compute(std::size_t pin) override;
        virtual void simulate(std::size_t tick) override;
};
}
