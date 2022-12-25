
#include <iostream>
#include <string>
#include <vector>

#include "App.hpp"

using namespace std;

#define MOUT(txt) cout << "main (" << __LINE__ << "): " << txt << endl;

int mainUsingDefaultApp(bool help) {
  MOUT("Start");
  App app("app");
  cout << app.GetName() << endl;
  if (help) {
    cout << "help called" << endl;
    return 0;
  } else {
    NYI("");
    return -1;
    
  }
}

int main(int argc, const char** argv) {
  MOUT("=========================== start argc: " << argc);
  if (argc == 1) {
    cout << "Using default, no args" << endl;
    return mainUsingDefaultApp(false);
  } else if (argc >= 2) {
    string arg1 = string(argv[1]);
    MOUT("First arg is " << arg1);
    if (arg1 == "help") { // out of order, but first
      return mainUsingDefaultApp(true);
    } else {
      vector<string> argsToProcess;
      // 0 is name of program
      for (int i = 1; i < argc; i++) {
	argsToProcess.push_back(string(argv[i]));
      }
  
      if (arg1 == "App") {
	App app("app");
	app.Dump(cout,"App: ");
      } else if (arg1 == "Config") {
	AppConfig config;
	config.Dump(cout, "prefix:  ");
	//      config.InitializePreCommandLine();
	config.Dump(cout, "postIP : ");
	//      config.Intialize(argc, argv);
	config.Dump(cout, "postCL : ");
	return 0;
      } else if (arg1 == "SwitchApp") {
	SwitchApp app("app");
	cout << app.GetName() << endl;
      } else if (arg1 == "Test") {
	TestApp app("Test");
	cout << app.GetName() << endl;
      
      } else {
	SwitchApp app("SwitchApp");
	cout << app.GetName() << endl;
      }
    }
  }

  return -1;
}
