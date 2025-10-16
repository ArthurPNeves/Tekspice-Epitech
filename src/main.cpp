/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** main
*/

#include "IComponent.hpp"
#include "AndComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "NotComponent.hpp"
#include "miniShell.hpp"

#include <iostream>
#include <memory>
#include "Parser.hpp"
#include "Error.hpp"

int main(int ac, char **av)
{
    nts::miniShell shell;
    nts::Parser parser;
    nts::Circuit circuit;

    if (ac != 2) {
        std::cout << "Invalid number of argument." << std::endl;
        return 84;
    }
    try {
        parser.openFile(av[1]);
        parser.buildCircuit(circuit);
    } 
    catch (const std::exception &except) {
        if (except.what() != std::string("EOF")) {
            std::cerr << except.what() << std::endl;
            return 84;
        }
    };
    try {
        shell.run(circuit);
    } catch (const std::exception &exception) {
        if (exception.what() == std::string("EOF")) return 0;
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}