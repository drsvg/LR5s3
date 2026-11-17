#ifndef BUILDERS_H
#define BUILDERS_H

#include "computer.h"

class IPCBuilder {
public:
    virtual ~IPCBuilder() {}
    
    virtual void setProcessor() = 0;
    virtual void setMotherboard() = 0;
    virtual void setRAM() = 0;
    virtual void setGPU() = 0;
    virtual void setPowerSupply() = 0;
    virtual void setStorage() = 0;
    
    virtual Computer* getResult() = 0;
};

class OfficePCBuilder : public IPCBuilder {
private:
    Computer* pc;
public:
    OfficePCBuilder();
    void setProcessor() override;
    void setMotherboard() override;
    void setRAM() override;
    void setGPU() override;
    void setPowerSupply() override;
    void setStorage() override;
    Computer* getResult() override;
    ~OfficePCBuilder();
};

class GamingPCBuilder : public IPCBuilder {
private:
    Computer* pc;
public:
    GamingPCBuilder();
    void setProcessor() override;
    void setMotherboard() override;
    void setRAM() override;
    void setGPU() override;
    void setPowerSupply() override;
    void setStorage() override;
    Computer* getResult() override;
    ~GamingPCBuilder();
};

class ServerHomeBuilder : public IPCBuilder {
private:
    Computer* pc;
public:
    ServerHomeBuilder();
    void setProcessor() override;
    void setMotherboard() override;
    void setRAM() override;
    void setGPU() override;
    void setPowerSupply() override;
    void setStorage() override;
    Computer* getResult() override;
    ~ServerHomeBuilder();
};

class ComputerAssemblyDirector {
public:
    Computer* buildComputer(IPCBuilder* builder);
    ~ComputerAssemblyDirector();
};

#endif