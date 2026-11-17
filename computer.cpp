#include "computer.h"
#include <iostream>

using namespace std;

Processor::Processor(string n, int power, int perf, int p) 
    : name(n), powerConsumption(power), performanceScore(perf), price(p) {}
Processor::~Processor() {}

Motherboard::Motherboard(string n, int perf, int p) 
    : name(n), performanceScore(perf), price(p) {}
Motherboard::~Motherboard() {}

RAM::RAM(string n, int size, int perf, int p) 
    : name(n), sizeGB(size), performanceScore(perf), price(p) {}
RAM::~RAM() {}

GPU::GPU(string n, int power, bool integrated, int perf, int p) 
    : name(n), powerConsumption(power), isIntegrated(integrated), performanceScore(perf), price(p) {}
GPU::~GPU() {}

PowerSupply::PowerSupply(string n, int w, int perf, int p) 
    : name(n), wattage(w), performanceScore(perf), price(p) {}
PowerSupply::~PowerSupply() {}

Storage::Storage(string n, int capacity, int perf, int p) 
    : name(n), capacityGB(capacity), performanceScore(perf), price(p) {}
Storage::~Storage() {}

Computer::Computer() : cpu(nullptr), mb(nullptr), ram(nullptr), gpu(nullptr), psu(nullptr), storage(nullptr) {}

void Computer::printSpecification() {
    cout << "--- Спецификация ПК ---" << endl;
    if (cpu) cout << "Процессор: " << cpu->name << " (Потребление: " << cpu->powerConsumption 
                  << " Вт, Производительность: " << cpu->performanceScore 
                  << ", Цена: " << cpu->price << ")" << endl;
    if (gpu) cout << "Видеокарта: " << gpu->name << " (Потребление: " << gpu->powerConsumption 
                  << " Вт, Производительность: " << gpu->performanceScore 
                  << ", Цена: " << gpu->price << ")" << endl;
    if (mb) cout << "Материнская плата: " << mb->name << " (Производительность: " << mb->performanceScore 
                 << ", Цена: " << mb->price << ")" << endl;
    if (ram) cout << "Оперативная память: " << ram->name << " (" << ram->sizeGB << " ГБ, Производительность: " 
                  << ram->performanceScore << ", Цена: " << ram->price << ")" << endl;
    if (psu) cout << "Блок питания: " << psu->name << " (" << psu->wattage << " Вт, Надежность: " 
                  << psu->performanceScore << ", Цена: " << psu->price << ")" << endl;
    if (storage) cout << "Накопитель: " << storage->name << " (" << storage->capacityGB << " ГБ, Производительность: " 
                      << storage->performanceScore << ", Цена: " << storage->price << ")" << endl;
    
    cout << "Итоговая стоимость: " << getTotalPrice() << " у.е." << endl;
    cout << "Коэффициент производительности (баллы / цена): " << calculatePerformanceCoefficient() << endl;
    cout << "-----------------------" << endl;
}

int Computer::getTotalPowerConsumption() {
    int total = 0;
    if (cpu) total += cpu->powerConsumption;
    if (gpu) total += gpu->powerConsumption;
    return total;
}

int Computer::getTotalPrice() {
    int total = 0;
    if (cpu) total += cpu->price;
    if (mb) total += mb->price;
    if (ram) total += ram->price;
    if (gpu) total += gpu->price;
    if (psu) total += psu->price;
    if (storage) total += storage->price;
    return total;
}

double Computer::calculatePerformanceCoefficient() {
    int totalPerformance = 0;
    if (cpu) totalPerformance += cpu->performanceScore;
    if (mb) totalPerformance += mb->performanceScore;
    if (ram) totalPerformance += ram->performanceScore;
    if (gpu) totalPerformance += gpu->performanceScore;
    if (psu) totalPerformance += psu->performanceScore;
    if (storage) totalPerformance += storage->performanceScore;
    
    int totalPrice = getTotalPrice();
    if (totalPrice == 0) return 0.0;
    
    return static_cast<double>(totalPerformance) / totalPrice;
}

Computer::~Computer() {
    delete cpu;
    delete mb;
    delete ram;
    delete gpu;
    delete psu;
    delete storage;
}