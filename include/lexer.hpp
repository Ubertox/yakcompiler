#pragma once
#include <string>
#include <vector>

namespace Lexer
{

enum TOKENS
{
    EOFTK,
    BLOCKTK,
    KEYWORDTK,
    NUMLT,
    CASTTK,
};

class Lexer
{
  private:
    std::string srcBuf;

  public:
    Lexer(std::string srcBuffer)
    {
        srcBuf = srcBuffer;
    }

    std::vector<TOKENS> lexing();

    std::string getSrcBuf()
    {
        return srcBuf;
    }
};
} // namespace Lexer