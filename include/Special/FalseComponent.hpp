/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** FalseComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts{

class FalseComponent : public AComponent {
    private:
        nts::Tristate _state;
    public:
        FalseComponent();
        nts::Tristate compute(std::size_t pin) override;
};
}