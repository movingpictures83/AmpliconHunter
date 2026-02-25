#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "AmpliconHunterPlugin.h"

void AmpliconHunterPlugin::input(std::string file) {
   readParameterFile(file);
}

void AmpliconHunterPlugin::run() {}

void AmpliconHunterPlugin::output(std::string file) {
//amplicon_hunter compress --input-dir test/fasta --output test/compressed
//ls -d "$PWD"/test/compressed/*.2bit > test/file_list.txt
//amplicon_hunter run --input test/file_list.txt --primers test/V1V9_primers.txt --output test/amplicons.fa

       	std::string outputfile = file;
 std::string myCommand = "amplicon_hunter ";
 std::string ahCommand = myParameters["command"];
 if (ahCommand == "compress") {
   myCommand += "compress --input-dir "+PluginManager::addPrefix(myParameters["inputdir"])+" --output "+outputfile;
   std::cout << myCommand << std::endl;
   system(myCommand.c_str());
   myCommand = "ls -d "+outputfile+"/*.2bit > "+outputfile+"/file_list.txt";
   std::cout << myCommand << std::endl;
   system(myCommand.c_str());
 }
 else {
   myCommand += "run --input "+PluginManager::addPrefix(myParameters["input"])+" --primers "+PluginManager::addPrefix(myParameters["primers"])+" --output "+outputfile;
   std::cout << myCommand << std::endl;
   system(myCommand.c_str());
 }
}

PluginProxy<AmpliconHunterPlugin> AmpliconHunterPluginProxy = PluginProxy<AmpliconHunterPlugin>("AmpliconHunter", PluginManager::getInstance());
