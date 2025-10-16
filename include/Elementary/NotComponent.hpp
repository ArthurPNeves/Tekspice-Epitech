/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** NotComponent
*/

#pragma once
#include "AComponent.hpp"
namespace nts{
class NotComponent : public AComponent {
    public:
        NotComponent();
        ~NotComponent() override = default;
        nts::Tristate compute(std::size_t pin) override;
};
}
