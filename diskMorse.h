#include "mors.h"

class DiskMorse : public mors {
public:
  DiskMorse();
  DiskMorse(const DiskMorse& other); 
  ~DiskMorse(){}
  void morseIt(const std::string& data);
  void configure(std::vector<std::string> parameters);
  DiskMorse& operator=(const DiskMorse& other);
  
  std::string getFile() const;
  void setFile(const std::string& fileName);
protected:
  std::string currentFileName;
};