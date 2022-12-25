



#include <iostream>
#include <string>

using namespace std;

#define NYI(txt) cout << "NYI (" << __FILE__ << ": " << __LINE__ << "): " << txt << endl;

class Outcome {
public:
  Outcome(int code, const string& description);
  virtual ~Outcome() = default;

  static Outcome Success();
  
private:
  int m_code;
  string m_description;
};

class AppConfig {
public:
  AppConfig();
  virtual ~AppConfig() = default;

  virtual bool Initialize(vector<string>& remainingArgs);
  
  void Dump(ostream& dumpOut, string prefix);
};

class App {
public:
  App(string name);
  virtual ~App() = default;

  string GetName();

  virtual Outcome ProcessCommandLineArgs(vector<string>& args);

  virtual void Dump(ostream& dumpOut, string prefix);
  void DumpAppData(ostream& dumpOut, string prefix);
  //  void DumpConfig();
  
private:
  string m_name;
  
};


class SwitchApp : public App {
public:
  SwitchApp(string name);
  virtual ~SwitchApp() = default;
  
  
};

class TestApp : public App {
public:
  TestApp(string name);
  virtual ~TestApp() = default;
};
