#pragma once

#include <cstddef>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>


namespace Driver {
class Driver {
private:
  std::string res;
  std::size_t fileSize = 0;
  bool outstages = true;

public:
  Driver(std::string filePath) {
    std::ifstream fileSrc(filePath);

    std::string nameStage1 = filePath + "Stage1.txt";
    std::ofstream stage(nameStage1);

    try {

      while (std::getline(fileSrc, res)) {
        std::cout << res << "\n";
        if (outstages) {

          stage << res;
        }
        fileSize = res.size();
      }
      std::cout << res << "file size:" << fileSize << "byte";
    } catch (...) {
      fileSrc.close();
      std::cerr << "Faild to open \"" + filePath + "\"" << std::endl;
      exit(1);
    }
    fileSrc.close();
    stage.close();
  }
};
} // namespace Driver