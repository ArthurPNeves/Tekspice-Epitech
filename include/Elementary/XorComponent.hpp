/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** XorComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts{
class XorComponent : public AComponent {
    public:
        XorComponent();
        ~XorComponent() override = default;
        nts::Tristate compute(std::size_t pin) override;
};
}
