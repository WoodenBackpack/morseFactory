#include "mors.h"

class factory {
public:
    factory();
    virtual ~factory();
    enum MorseType {
        beep,
        console,
        capsLock,
        disk
    };
    factory(const factory& other);
    factory& operator=(const factory& other);
    void setExternalInfo(const std::string& exInfo);
    void convert(const std::string& msg);
    void convert(const double& msg);
    void convert(const int& msg);
    void setOutput(const MorseType& type);
    mors* getMorse() const;
    MorseType getType() const;
    std::string getCurrentconfiguration() const;
    void setConfiguration(const std::string& s);
protected:
    MorseType currentType = MorseType::beep;
    std::string currentConfiguration = "";
    mors* m = nullptr;
};