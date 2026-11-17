#include <iostream>
#include <clocale>
#include "builders.h"

using namespace std;

class BadBuilder : public IPCBuilder {
private:
    Computer* pc;
public:
    BadBuilder() { pc = new Computer(); }
    void setProcessor() override { pc->cpu = new Processor("Офисный CPU", 65, 150, 100); }
    void setMotherboard() override { pc->mb = new Motherboard("Офисная плата", 50, 60); }
    void setRAM() override { pc->ram = new RAM("DDR4", 8, 80, 40); }
    void setGPU() override { pc->gpu = new GPU("Очень мощная видеокарта", 400, false, 1000, 1200); }
    void setPowerSupply() override { pc->psu = new PowerSupply("Слабый БП", 400, 80, 45); }
    void setStorage() override { pc->storage = new Storage("SSD", 512, 120, 50); }
    Computer* getResult() override { return pc; }
    ~BadBuilder() {}
};
int main() {
    setlocale(LC_ALL, "Russian");
    ComputerAssemblyDirector director;

    cout << "=== СБОРКА ОФИСНОГО ПК ===" << endl;
    OfficePCBuilder officeBuilder;
    Computer* officePC = director.buildComputer(&officeBuilder);
    if (officePC) {
        officePC->printSpecification();
        delete officePC;
    }

    cout << endl << "=== СБОРКА ИГРОВОГО ПК ===" << endl;
    GamingPCBuilder gamingBuilder;
    Computer* gamingPC = director.buildComputer(&gamingBuilder);
    if (gamingPC) {
        gamingPC->printSpecification();
        delete gamingPC;
    }

    cout << endl << "=== СБОРКА ДОМАШНЕГО МЕДИАСЕРВЕРА ===" << endl;
    ServerHomeBuilder serverBuilder;
    Computer* serverPC = director.buildComputer(&serverBuilder);
    if (serverPC) {
        serverPC->printSpecification();
        delete serverPC;
    }

    cout << endl << "=== ДЕМОНСТРАЦИЯ ПЕРЕХВАТА ОШИБКИ ===" << endl;
    
    BadBuilder badBuilder;
    Computer* brokenPC = director.buildComputer(&badBuilder);
    
    if (!brokenPC) {
        cout << "Сборка прервана из-за несовместимости компонентов." << endl;
    }

    return 0;
}