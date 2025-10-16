/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** TrueComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts{

class TrueComponent : public AComponent {
    private:
        nts::Tristate _state;
    public:
        TrueComponent();
        nts::Tristate compute(std::size_t pin) override;
};
}
