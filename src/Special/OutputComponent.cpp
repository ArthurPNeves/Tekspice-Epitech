/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

namespace nts {
OutputComponent::OutputComponent() : AComponent(1){}

nts::Tristate OutputComponent::compute(std::size_t pin)
{
    if (pin != 1) 
        return nts::Undefined;
    return getLink(1);
}
}