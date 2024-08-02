#include <iostream>

using namespace std;

class endereco{
  string logradouro;
  string cidade;
  string cep;
public:
  endereco(string lgr, string cdd, string cp){
    logradouro = lgr;
    cidade = cdd;
    cep = cp;
  }
  string getlogradouro(){return logradouro;}
  string getcidade(){return cidade;}
  string getcep(){return cep;}
  void setlogradouro(string st){logradouro = st;}
  void setcidade(string st){cidade = st;}
  void setcep(string st){cep = st;}
};

class pessoa{
  string nome;
  int idade;
public:
  pessoa(const string n, int i){
    nome = n;
    idade = i;
  }
  string getnome(){return nome;}
  int getidade(){return idade;}
  void setnome(string n){nome = n;}
  void setidade(int i){idade = i;}
  void printInfo(){
  
  }
};

class aluno : public pessoa {
  float cra;
  int matricula;
public:
  aluno(const string n, int i, float cr, int m):pessoa(n, i){
    cra = cr;
    matricula = m;
  }

};

class servidorPublico : public pessoa {
  int departamento;
  int siape;
public:
  servidorPublico(const string& n, int i, int d, int s):pessoa(n, i){
    departamento = d;
    siape = s;
  }
};

class professor : public servidorPublico {
  string titulacao;
public:
  professor(const string& n, int i, int d, int s, const string& t):servidorPublico(n, i, d, s){
    titulacao = t;
  }
};

class tecnico : public servidorPublico {
  int cargo;
public:
  tecnico(const string& n, int i, int d, int s, int c):servidorPublico(n, i, d, s){
    cargo = c;
  }
};

int main() {
  professor p("kampeinhaimer", 62, 2, 2345, "baluco");
}