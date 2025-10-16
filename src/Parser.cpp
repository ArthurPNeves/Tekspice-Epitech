/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Error.hpp"

namespace nts
{

    Parser::Parser()
    {
        this->_line = std::stringstream(std::ios_base::in);
    }

    Parser::~Parser()
    {
    }

    void Parser::openFile(const std::string &filepath)
    {
        if (filepath.find(".nts") == std::string::npos || filepath.find(".nts") != filepath.length() - 4)
            throw notANtsFile();
        this->_stream = std::ifstream(filepath);
        if (this->_stream.eof())
            throw Error("Empty file.");
    }

    void Parser::NextLine(void)
    {
        std::string tempLine("");
        while (tempLine == "")
        {
            if (this->_stream.fail() || this->_stream.bad() || this->_stream.eof())
                throw getParseState() == State::links ? Error("EOF") : Error("Failed.");
            getline(_stream, tempLine);
            if (tempLine.find('#') != std::string::npos)
                tempLine = tempLine.substr(0, tempLine.find('#'));
            while (tempLine[0] <= 32 && tempLine != "")
            {
                tempLine = tempLine.length() > 1 ? tempLine.substr(1) : "";
            }
            
            _line = std::stringstream(tempLine);
            this->_argNumber = 0;
        }

        if (tempLine == ".chipsets:")
        {
            this->_parseState = chipsets;            
        }
        if (tempLine == ".links:")
        {
            this->_parseState = links;
        }
    }

    std::string Parser::parseLine()
    {
        std::string nextArgument;
        _line >> nextArgument;
        if (nextArgument == "" && this->_argNumber > 0)
            throw Error("Missing an argument");
        this->_argNumber++;
        return nextArgument;
    }

    bool Parser::isNewSection()
    {
        std::string sectionChecker;
        std::string holder(this->_line.str());
        this->_line >> sectionChecker;
        if (!sectionChecker.compare(".chipsets:") || !sectionChecker.compare(".links:"))
        {
            this->_parseState = !sectionChecker.compare(".chipsets:") ? chipsets : links;
            this->_line = std::stringstream(holder);
            return true;
        }
        this->_line = std::stringstream(holder);
        return false;
    }

    void Parser::buildCircuit(Circuit &circuit)
    {
        bool isThereAComponent = false;
        this->NextLine();
        if (!this->isNewSection() || this->parseLine() != ".chipsets:")
            throw Error("No Chipsets.");
        this->NextLine();

        while (!this->isNewSection())
        {
            isThereAComponent = true;
            std::string componentType = this->parseLine();
            std::string componentName = this->parseLine();
            circuit.addComponent(componentName, componentType);
            this->NextLine();
        }
        if (this->parseLine() == ".chipsets:")
        {
            throw Error("Multiple .chipsets definition.");
        }
        if (!isThereAComponent)
        {
            throw Error("No components in file.");
        }

        this->NextLine();
        while (!this->isNewSection())
        {
            std::string component = this->parseLine();
            std::string toLink = this->parseLine();
            if (component.find(':') != std::string::npos && toLink.find(':') != std::string::npos &&
                component.find(':') != 0 && component.find(':') != component.length() - 1 &&
                toLink.find(':') != 0 && toLink.find(':') != toLink.length() - 1)
            {
                circuit.linkComponents(
                    component.substr(0, component.find(':')),
                    static_cast<size_t>(std::atoi(component.substr(component.find(':') + 1).c_str())),
                    toLink.substr(0, toLink.find(':')),
                    static_cast<size_t>(std::atoi(toLink.substr(toLink.find(':') + 1).c_str())));
            }
            else
                throw Error("Wrong linking syntax.");
            this->NextLine();
        }
    }



}
