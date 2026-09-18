#include "main.hpp"

using namespace Compiler;


int main(int argc, char *argv[])
{
    CliInterface cli(argc,argv);
    YCompiler ycp(cli.getSourceCli());
}

