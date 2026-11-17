#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <string>
using namespace std;

class Processor {
public:
    string name;
    int powerConsumption;
    int performanceScore;
    int price;
    Processor(string n, int power, int perf, int p);
    ~Processor();
};

class Motherboard {
public:
    string name;
    int performanceScore;
    int price;
    Motherboard(string n, int perf, int p);
    ~Motherboard();
};

class RAM {
public:
    string name;
    int sizeGB;
    int performanceScore;
    int price;
    RAM(string n, int size, int perf, int p);
    ~RAM();
};

class GPU {
public:
    string name;
    int powerConsumption;
    bool isIntegrated;
    int performanceScore;
    int price;
    GPU(string n, int power, bool integrated, int perf, int p);
    ~GPU();
};

class PowerSupply {
public:
    string name;
    int wattage;
    int performanceScore; 
    int price;
    PowerSupply(string n, int w, int perf, int p);
    ~PowerSupply();
};

class Storage {
public:
    string name;
    int capacityGB;
    int performanceScore;
    int price;
    Storage(string n, int capacity, int perf, int p);
    ~Storage();
};

#endif