#include "builders.h"
#include <iostream>

using namespace std;

OfficePCBuilder::OfficePCBuilder() { pc = new Computer(); }
void OfficePCBuilder::setProcessor() { pc->cpu = new Processor("Бюджетный Intel Core i3", 65, 150, 100); }
void OfficePCBuilder::setMotherboard() { pc->mb = new Motherboard("Бюджетная плата H610", 50, 60); }
void OfficePCBuilder::setRAM() { pc->ram = new RAM("DDR4", 8, 80, 40); }
void OfficePCBuilder::setGPU() { pc->gpu = new GPU("Встроенное видеядро Intel UHD", 0, true, 30, 0); }
void OfficePCBuilder::setPowerSupply() { pc->psu = new PowerSupply("Тихий БП", 400, 80, 45); }
void OfficePCBuilder::setStorage() { pc->storage = new Storage("Быстрый SSD", 512, 120, 50); }
Computer* OfficePCBuilder::getResult() { return pc; }
OfficePCBuilder::~OfficePCBuilder() {}

GamingPCBuilder::GamingPCBuilder() { pc = new Computer(); }
void GamingPCBuilder::setProcessor() { pc->cpu = new Processor("Мощный Intel Core i7", 125, 450, 350); }
void GamingPCBuilder::setMotherboard() { pc->mb = new Motherboard("Игровая плата Z790", 150, 200); }
void GamingPCBuilder::setRAM() { pc->ram = new RAM("DDR5", 32, 250, 150); }
void GamingPCBuilder::setGPU() { pc->gpu = new GPU("Мощная дискретная NVIDIA RTX 4070", 250, false, 800, 800); }
void GamingPCBuilder::setPowerSupply() { pc->psu = new PowerSupply("Мощный БП", 850, 200, 150); }
void GamingPCBuilder::setStorage() { pc->storage = new Storage("NVMe SSD", 2000, 350, 180); }
Computer* GamingPCBuilder::getResult() { return pc; }
GamingPCBuilder::~GamingPCBuilder() {}

ServerHomeBuilder::ServerHomeBuilder() { pc = new Computer(); }
void ServerHomeBuilder::setProcessor() { pc->cpu = new Processor("Энергоэффективный AMD Ryzen", 95, 380, 300); }
void ServerHomeBuilder::setMotherboard() { pc->mb = new Motherboard("Серверная плата B650", 120, 180); }
void ServerHomeBuilder::setRAM() { pc->ram = new RAM("ECC RAM", 64, 300, 250); }
void ServerHomeBuilder::setGPU() { pc->gpu = new GPU("Встроенное видео", 0, true, 20, 0); }
void ServerHomeBuilder::setPowerSupply() { pc->psu = new PowerSupply("Надежный БП", 600, 250, 120); }
void ServerHomeBuilder::setStorage() { pc->storage = new Storage("Надежный RAID-массив", 4000, 400, 300); }
Computer* ServerHomeBuilder::getResult() { return pc; }
ServerHomeBuilder::~ServerHomeBuilder() {}

Computer* ComputerAssemblyDirector::buildComputer(IPCBuilder* builder) {
    builder->setProcessor();
    builder->setMotherboard();
    builder->setRAM();
    builder->setGPU();
    builder->setPowerSupply();
    builder->setStorage();
    
    Computer* pc = builder->getResult();
    
    int totalPower = pc->getTotalPowerConsumption();
    if (pc->psu != nullptr && totalPower > pc->psu->wattage) {
        cout << "ОШИБКА СБОРКИ! Суммарное энергопотребление (" << totalPower 
             << " Вт) превышает мощность БП (" << pc->psu->wattage << " Вт)." << endl;
        delete pc;
        return nullptr;
    }
    
    return pc;
}

ComputerAssemblyDirector::~ComputerAssemblyDirector() {}