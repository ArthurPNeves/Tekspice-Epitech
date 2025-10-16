CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -Wextra -Iinclude -Iinclude/Gates -Iinclude/Special -Iinclude/Advanced -Iinclude/Elementary

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = \
    $(SRC_DIR)/Advanced/Adder4008.cpp \
    $(SRC_DIR)/Advanced/Counter4040.cpp \
    $(SRC_DIR)/Advanced/FlipFlop4013.cpp \
    $(SRC_DIR)/Advanced/Johnson4017.cpp \
    $(SRC_DIR)/Elementary/AndComponent.cpp \
    $(SRC_DIR)/Elementary/NotComponent.cpp \
    $(SRC_DIR)/Elementary/OrComponent.cpp \
    $(SRC_DIR)/Elementary/XorComponent.cpp \
    $(SRC_DIR)/Gates/And4081.cpp \
    $(SRC_DIR)/Gates/FlipFlop.cpp \
    $(SRC_DIR)/Gates/Inverter4069.cpp \
    $(SRC_DIR)/Gates/Nand4011.cpp \
    $(SRC_DIR)/Gates/Nor4001.cpp \
    $(SRC_DIR)/Gates/Or4071.cpp \
    $(SRC_DIR)/Gates/Xor4030.cpp \
    $(SRC_DIR)/Special/ClockComponent.cpp \
    $(SRC_DIR)/Special/FalseComponent.cpp \
    $(SRC_DIR)/Special/InputComponent.cpp \
    $(SRC_DIR)/Special/OutputComponent.cpp \
    $(SRC_DIR)/Special/TrueComponent.cpp \
    $(SRC_DIR)/AComponent.cpp \
    $(SRC_DIR)/Circuit.cpp \
    $(SRC_DIR)/Factory.cpp \
    $(SRC_DIR)/main.cpp \
    $(SRC_DIR)/miniShell.cpp \
    $(SRC_DIR)/Parser.cpp

OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

TARGET = nanotekspice

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Create subdirectories in obj/ dynamically
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

re: clean all

debug: CXXFLAGS += -g
debug: clean all

run: all
	@$(TARGET)

.PHONY: all clean debug run re