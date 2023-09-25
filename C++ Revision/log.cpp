#include <iostream>
using std::string;
using namespace std;

class Log // Declared new class named LOG
{

public:                          // set values to constant
  const int loglevelWarning = 1; // Press 1 for warning messages
  const int loglevelError = 2;   // Press 2 for error messages
  const int loglevelInfo = 3;    // press 3 to get info messages

private:
  int m_loglevel;

public:
  void set(int level) // parameter to set the private class member a value...
  {
    m_loglevel = level; // set the value to print message [1] or [2] or [3]
  }
  void warning(const char *message)
  {
    if (m_loglevel == loglevelWarning)
    {

      cout << "Warning: " << message << endl;
    }
  }
  void error(const char *message)
  {
    if (m_loglevel == loglevelError)
    {
      cout << "ERROR: " << message << endl;
    }
  }
  void Info(const char *message)
  {
    if (m_loglevel == loglevelInfo)
    {
      cout << "Info: " << message << endl;
    }
  }
};

int main()
{

  // LOG CLASS MEMBERS ACCESS----------------------------------------------------------------
  Log player1;
  player1.set(2);
  player1.Info("Levi");
  player1.error("Eren");
  player1.warning("Mikasa");

  return 0; //
}
