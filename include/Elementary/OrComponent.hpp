/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** OrComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts{
class OrComponent : public AComponent {
    public:
        OrComponent();
        ~OrComponent() override = default;
        nts::Tristate compute(std::size_t pin) override;
};
}
