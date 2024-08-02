#include <iostream>
using namespace std;

class Pessoa {
int idade;
float altura;

static int qtdp;
static int somaidade;
static float somaaltura;

public:
  Pessoa(int i, float h){
    idade = i; 
    altura = h;
    qtdp++;
    somaidade += idade;
    somaaltura += altura;
  }

  int getidade(){return idade;}
  void setidade(int i){idade = i;}
  float getaltura(){return altura;}
  void setaltura(float h){altura = h;}

  static float mediaidade (){
    return (somaidade)/qtdp;
  }
  static float mediaaltura(){
    return (somaaltura)/qtdp;
  }



  ~Pessoa(){
    cout << "endpessoa\n";
    qtdp--;
    somaidade -= idade;
    somaaltura -= altura;
  }
};
int Pessoa::qtdp = 0;
int Pessoa::somaidade = 0;
float Pessoa::somaaltura = 0;


int main() {
  Pessoa p1(22, 180);
  Pessoa p2(33, 150);
  Pessoa p3(44, 170);

  cout << "media de idade: " << Pessoa::mediaidade() << endl;
  cout << "media de altura: " << Pessoa::mediaaltura() << endl;
};