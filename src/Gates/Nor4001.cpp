/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** C4001
*/

#include "Nor4001.hpp"
#include "Error.hpp"
namespace nts {

Nor4001::Nor4001(std::size_t nbPin) : AComponent(nbPin) {
    if (nbPin != 14) 
        throw InvalidPinNb();
}

Nor4001::~Nor4001()
{
}

void Nor4001::simulate(std::size_t tick) {
    (void)tick;
}

Tristate Nor4001::compute(std::size_t pin) {
    
    if (pin < 1 || pin > 14)
        throw InvalidPin();

    if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
        return computeNOR(pin);

    return Tristate::Undefined;
}

Tristate Nor4001::computeNOR(std::size_t pin) {
    std::size_t pinA, pinB;

    switch (pin) {
    case 3:
        pinA = 1; 
        pinB = 2;
        break;
    case 4:
        pinA = 5;
        pinB = 6;
        break;
    case 10:
        pinA = 8;
        pinB = 9;
        break;
    case 11:
        pinA = 12;
        pinB = 13;
        break;
    default:
        throw InvalidPin();
    }



    Tristate A = _links[pinA].first->compute(_links[pinA].second);
    Tristate B = _links[pinB].first->compute(_links[pinB].second);
    
    if  (A == Tristate::True || B == Tristate::True)
        return Tristate::False;
    else if(A == Tristate::Undefined || B == Tristate::Undefined)
        return Tristate::Undefined;
    else
        return Tristate::True;
}

}