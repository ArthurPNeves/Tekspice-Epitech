/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Component4017.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class Component4017 : public AComponent {
private:
    std::size_t _currentState;
    std::vector<int> _inPins;
    std::vector<int> _outPins;
    bool _isUpdated;

public:
    Component4017();
    ~Component4017() override;

    nts::Tristate compute(std::size_t pin) override;
    void simulate(std::size_t tick) override;
    void reset(void);
    void updatePins(void);

};

}
