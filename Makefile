.PHONY: debug release clean install uninstall default

CXX = g++
CXX_FLAGS = -std=c++20

debug: main.cpp Calculator.cpp
	$(CXX) $(CXX_FLAGS) -g -O0 main.cpp Calculator.cpp -o my_calculator_debug
	gdb ./my_calculator_debug

release: main.cpp Calculator.cpp
	$(CXX) $(CXX_FLAGS) -g -O3 -s main.cpp Calculator.cpp -o my_calculator_release