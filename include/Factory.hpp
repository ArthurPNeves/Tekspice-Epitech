/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Factory
*/

#pragma once
#include "IComponent.hpp"
#include <memory>
#include <string>
#include <vector>

namespace nts {
class Factory {
public:
    static std::shared_ptr<nts::IComponent> createComponent(const std::string &type);
};
}
