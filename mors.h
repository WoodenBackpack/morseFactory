#ifndef __MORS__
#define __MORS__

#include <string>
#include <vector>
#include <exception>

class mors {
public:
  mors() : dot('.'), dash('_'), space(' ') {}
  virtual ~mors(){}
  virtual void morseIt(const std::string& data) = 0;
  virtual void configure(std::vector<std::string> parameters) = 0;
  std::vector<std::string> getConfigurationData() const {
      return configuration;
  };
  void setConfigurationData(std::vector<std::string> cfg) {
      configuration = cfg;
  }

protected:
  const char dot;
  const char dash;
  const char space;
  std::vector<std::string> configuration;
  struct WrongConfigurationException : public std::exception {
    const char* what() const throw () {
        return "Wrong configration!";
    }
  };
  std::string convertToMorse(char menu) {
    switch (menu)
    {
    case 'a':
    case 'A':
        return "._";
    case 'b':
    case 'B':
        return "_...";
    case 'c':
    case 'C':
        return "_._.";
    case 'd':
    case 'D':
        return "_..";
    case 'e':
    case 'E':
        return ".";
    case 'f':
    case 'F':
        return ".._.";
    case 'g':
    case 'G':
        return "__.";
    case 'h':
    case 'H':
        return "....";
    case 'i':
    case 'I':
        return "..";
    case 'j':
    case 'J':
        return ".___";
    case 'k':
    case 'K':
        return "_._";
    case 'l':
    case 'L':
        return "._..";
    case 'm':
    case 'M':
        return "__";
    case 'n':
    case 'N':
        return "_.";
    case 'o':
    case 'O':
        return "___";
    case 'p':
    case 'P':
        return ".__.";
    case 'q':
    case 'Q':
        return "__._";
    case 'r':
    case 'R':
        return "._.";
    case 's':
    case 'S':
        return "...";
    case 't':
    case 'T':
        return "_";
    case 'u':
    case 'U':
        return ".._";
    case 'v':
    case 'V':
        return "..._";
    case 'w':
    case 'W':
        return ".__";
    case 'x':
    case 'X':
        return "_.._";
    case 'y':
    case 'Y':
        return "_.__";
    case 'z':
    case 'Z':
        return "__..";
    case '1':
        return ".____";
    case '2':
        return "..___";
    case '3':
        return "...__";
    case '4':
        return "...._";
    case '5':
        return ".....";
    case '6':
        return "_....";
    case '7':
        return "__...";
    case '8':
        return "___..";
    case '9':
        return "____.";
    case '0':
        return "_____";
    case '.':
        return "._._._";
    case ',':
        return "__..__";
    case '?':
        return "..__..";
    case '!':
        return "_._.__";
    default:
        return "";
    }
  }
};

#endif // __MORS__