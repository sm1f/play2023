
#include <string>
#include <vector>

#include "App.hpp"


/*=================== Outcome */
Outcome::Outcome(int code, const string& description)
  : m_code(code), m_description(description) {
}

Outcome Outcome::Success() {
  return Outcome(-1, "Success");
}

/*=================== AppConfig */
AppConfig::AppConfig() {}

void AppConfig::Dump(ostream& dumpOut, string prefix) {
  cout << prefix << "AppConfig" << endl;
}

bool AppConfig::Initialize(vector<string>& remainArgs) {
  NYI("");
  return true;
}

/*=================== App */
App::App(string name)
  : m_name(name)
{}

string App::GetName() { return m_name; }

void App::Dump(ostream& dumpOut, string prefix) {
  cout << prefix << "App name: " << m_name << endl;
  DumpAppData(dumpOut, prefix + "  ");
}
void App::DumpAppData(ostream& dumpOut, string prefix) {
  cout << prefix << "App name: " << m_name << endl;
}

Outcome App::ProcessCommandLineArgs(vector<string>& args) {
  NYI("");
  return Outcome::Success();
}

/*=================== SwitchApp */
SwitchApp::SwitchApp(string name)
  : App(name)
{}

/*=================== SwitchApp */
TestApp::TestApp(string name)
  : App(name)
{}
