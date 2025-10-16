/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

namespace nts
{
    ClockComponent::ClockComponent() : AComponent(1), _state(nts::Undefined), setUsed(false) {}

    void ClockComponent::setState(nts::Tristate state)
    {
        _state = state;
        setUsed = true;
    }

    nts::Tristate ClockComponent::compute(std::size_t pin)
    {
        if (pin != 1)
            return nts::Undefined;
        return _pins[0];
    }

    void ClockComponent::simulate(std::size_t tick)
    {
        (void)tick;
        if (setUsed)
        {
            _pins[0] = _state;
            setUsed = false;
        }
        else
        {
            if (_state == nts::True)
                _state = nts::False;
            else if (_state == nts::False)
                _state = nts::True;

            _pins[0]=_state;
        }
    }
}