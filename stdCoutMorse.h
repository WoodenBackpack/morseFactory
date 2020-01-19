#include "mors.h"

class StdCoutMorse : public mors {
public:
  StdCoutMorse(){}
  virtual ~StdCoutMorse(){}
  void morseIt(const std::string& data);
  void configure(std::vector<std::string> parameters);
  StdCoutMorse& operator=(const StdCoutMorse& other);
  StdCoutMorse(const StdCoutMorse& other);
};