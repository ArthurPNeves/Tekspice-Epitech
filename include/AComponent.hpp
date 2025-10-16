/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** AComponent
*/

#pragma once
#include "IComponent.hpp"
#include <unordered_map>
#include <memory>
#include <vector>
#include <iostream>

namespace nts{

class AComponent : public nts::IComponent {
    protected:
        std::unordered_map<std::size_t, std::pair< std::shared_ptr<IComponent>, std::size_t>> _links;
        std::vector<nts::Tristate> _pins;

    public:
        AComponent(std::size_t pinCount);
        virtual ~AComponent();

        void setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin) const;
        virtual void simulate(std::size_t tick) override;
        virtual nts::Tristate compute(std::size_t pin) override = 0;
};
}