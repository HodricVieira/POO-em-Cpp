#include <iostream>
using namespace std;

class kbdaccess{
char lastchar;
int buffersize;
static kbdaccess* _instance;

kbdaccess(char c = 'c', int i = 2){
  lastchar = c;
  buffersize = i;
}

public:
  static kbdaccess* instance(){
    if (_instance == NULL){
      _instance = new kbdaccess;
    }
    return _instance;
  }

  //gets e sets de lastchar e buffersize

};
kbdaccess* kbdaccess::_instance = NULL;

int main() {
  std::cout << "Hello World!\n";
}