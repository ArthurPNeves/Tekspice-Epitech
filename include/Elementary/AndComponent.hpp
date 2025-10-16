/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** AndComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts{

class AndComponent : public AComponent {
    public:
        AndComponent();
        nts::Tristate compute(std::size_t pin) override;
};
}
