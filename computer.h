#ifndef COMPUTER_H
#define COMPUTER_H

#include "components.h"

class Computer {
public:
    Processor* cpu;
    Motherboard* mb;
    RAM* ram;
    GPU* gpu;
    PowerSupply* psu;
    Storage* storage;

    Computer();
    void printSpecification();
    int getTotalPowerConsumption();
    int getTotalPrice();
    double calculatePerformanceCoefficient();
    ~Computer();
};

#endif