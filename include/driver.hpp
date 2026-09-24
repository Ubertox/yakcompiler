#pragma once


#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>
#include <string>


namespace Driver {
class Driver {
private:
  std::string res = "";
  std::string tmp;
  std::stringstream buffer;
  std::size_t fileSize = 0;
  bool printStage1 = false;

public:
  Driver(std::string filePath) {
    std::ifstream fileSrc(filePath);

    std::string nameStage1 = filePath + "Stage1.txt";
    std::ofstream stage(nameStage1);

    if (!fileSrc.is_open()) {
      fileSrc.close();
      std::cerr << "Failed to open \"" + filePath + "\"" << std::endl;
      exit(1);
    }

      while (std::getline(fileSrc,  tmp)) {
        if (printStage1)std::cout << tmp << "\n";
        buffer << tmp;
        stage << tmp;
      }

    res = buffer.str();

    fileSrc.close();
    stage.close();
  }

  std::string getStage1() { return res; }
  void setPrintStage1(bool print) { printStage1 = print; }
};
} // namespace Driver