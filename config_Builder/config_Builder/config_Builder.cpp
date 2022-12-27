#include <iostream>
#include "Config.h"
#include "Builder.h"
using namespace std;

int main() {
	Director* director = new Director(new bigBuilder);
	Config* config = director->construct();
	/*int w = config->getInteger(0, "size","width");
	int h = config->getInteger(0,"size", "height");
	cout << config->getDouble(0, "thr", "conf")<<endl;
	cout << config->getDouble(0, "thr","iou")<<endl;
	cout << w << " " << h<<endl;
	if (config->getBool(false, "is"))
		cout << "TRUE"<<endl;
	else
		cout << "FALSE" << endl;
	config->setInteger(400, "size", "width");
	config->setBool(true, "is");
	config->setDouble(0.45, "thr", "conf");
	config->WriteConfigFile();*/
	cout << config->getInteger(0, "size", "width") << endl;
	return 0;
}