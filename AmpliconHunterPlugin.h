#ifndef AmpliconHunterPLUGIN_H
#define AmpliconHunterPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class AmpliconHunterPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "AmpliconHunter";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
