/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

namespace nts {
FalseComponent::FalseComponent() : AComponent(1), _state(nts::False) {}

nts::Tristate FalseComponent::compute(std::size_t pin)
{
    if (pin != 1) 
        return nts::Undefined;
    return _state;
}
}