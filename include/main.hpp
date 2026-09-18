#pragma once
#include "driver.hpp"
#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Error.hpp>
#include <CLI/Formatter.hpp>
#include <iostream>
#include <string>



namespace Compiler
{

class YCompiler
{

    const std::string sourceBuf;

  public:
    YCompiler(std::string inpFile)
    {
        // sourceBuf = Driver(inpFile);
        std::cout << "Compiling started!" << std::endl;
        Driver::Driver d(inpFile);
    }
};



class CliInterface
{
  private:
    int argc;
    char **argv;
    CLI::App app{"ycp"};

    std::string sourceCli;
    std::string outCli;

  public:
    CliInterface(int _argc, char **_argv)
    {
        argc = _argc;
        argv = _argv;

        app.add_option("source", sourceCli)->required()->check(CLI::ExistingFile);
        app.add_option("-o", outCli)->required();

        try
        {
            app.parse(argc, argv);
        }
        catch (CLI::ParseError &e)
        {
            std::exit(app.exit(e));
        }
        std::cout << "Compiling " << sourceCli << " ==> " << outCli << "..." << std::endl;
    }

    std::string getSourceCli()
    {
        return sourceCli;
    }

    std::string getOutCli()
    {
        return outCli;
    }
};


} // namespace Compiler