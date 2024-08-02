#include <iostream>

using namespace std;

class animal {
  string nome;
  int idade;
public:
  animal(const string ani, int id){nome = ani; idade = id;}
  void info(){
    cout << "nome: " << nome << endl;
    cout << "idade: " << idade << endl;
  }
};

class papagaio : public animal{
  float envergadura;
  bool falante;
public:
  papagaio(const string nm, int id, float enverg, bool fal):animal(nm, id){
    envergadura = enverg; falante = fal;
  }
  void info(){
    cout << "nome: " << nome << endl;
    cout << "idade: " << idade << endl;
    cout << "envergadura: " << envergadura << endl;
    cout << "falante: " << falante << endl;
  }
};

class gato: public animal{
  string pelagem;
  float tamgarra;
public:
  gato(const string nm, int id, const string pelo, float tg):animal(nm, id){
    pelagem = pelo; tamgarra = tg;
  }
  void info(){
    cout << "nome: " << nome << endl;
    cout << "idade: " << idade << endl;
    cout << "pelagem: " << pelagem << endl;
    cout << "tamanho da garra: " << tamgarra << endl;
  }
};


int main() {
  std::cout << "Hello World!\n";
}