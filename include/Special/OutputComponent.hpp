/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** OutputComponent
*/

#pragma once
#include "AComponent.hpp"
#include <string>

namespace nts{

class OutputComponent : public AComponent {

    public: 
        OutputComponent();
        nts::Tristate compute(std::size_t pin) override;
};
}