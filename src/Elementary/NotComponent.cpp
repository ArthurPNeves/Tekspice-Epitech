/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** NotComponent
*/

#include "NotComponent.hpp"
namespace nts {
NotComponent::NotComponent() : AComponent(2) {}

nts::Tristate NotComponent::compute(std::size_t pin)
{
    if (pin != 2)
        return nts::Undefined;

    nts::Tristate a = getLink(1);
    
    if (a == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;

    if (a == nts::Tristate::True)
        return nts::Tristate::False;
    else
        return nts::Tristate::True;
}
}