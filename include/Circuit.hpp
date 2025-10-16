/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Circuit
*/

#pragma once
#include <iostream>
#include <unordered_map>
#include <memory>
#include "IComponent.hpp"
#include "Factory.hpp"

namespace nts {

class Circuit {
    public:
        Circuit();
        ~Circuit();

        void addComponent(const std::string& name, const std::string& type);
        void addComponent(const std::string& name, std::shared_ptr<nts::IComponent> component);
        void linkComponents(const std::string& name, int pin, const std::string& otherName, int otherPin);

        std::shared_ptr<IComponent> getComponent(const std::string &name) const;
        void simulate(std::size_t tick);
        void display() const;
        bool isExiting = false;

    private:
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> _components;
        std::vector<std::string> _inpComponents; 
        std::vector<std::string> _outComponents;
        std::size_t _tickCount = 0; 
        Factory factory;
};
} 