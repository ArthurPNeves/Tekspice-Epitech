/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** AndComponent
*/

#include "AndComponent.hpp"

namespace nts{

AndComponent::AndComponent() : AComponent(3) {}

nts::Tristate AndComponent::compute(std::size_t pin)
{   
    
    if (pin != 3)
        return nts::Undefined;
    nts::Tristate a = getLink(1);
    nts::Tristate b = getLink(2);

    if (a == nts::False || b == nts::False)
        return nts::False;
    if (a == nts::Undefined || b == nts::Undefined)
        return nts::Undefined;
    return nts::True;
}
}