#include <iostream>

using namespace std;
#define TAMVETOR 10

class Conta {
  int numero;
  float saldo;
  string titular;
public:
  Conta(){}
  Conta(const string nome, int num, float sd){
    titular = nome;
    numero = num;
    saldo = sd;
  }
  void depositar(float valordep){
    saldo = saldo + valordep;
    cout << "valor depositado\n";
  }
  void sacar(float valorsac){
    saldo = saldo - valorsac;
    cout << "valor sacado\n";
  }
  void info(){
    cout << "titular: " << titular << endl;
    cout << "numero: " << numero << endl;
    cout << "saldo: " << saldo << endl;
  }
};

class ContaCorrente : public Conta{
  float limite;
  Conta cc;
public:
  ContaCorrente(const string nome, int num, float sd, float lim){
    limite = lim;
    cc = Conta(nome, num, sd);
  }
  void sacar(float valorsac){
    cc.sacar(valorsac);
  }
  void info(){
    cc.info();
    cout << "limite: " << limite << endl;
    cout << "-------------------------------\n";
  }
};

class ContaPoupanca : public Conta{
  float rendimento;
  Conta cc;
public:
  ContaPoupanca(const string nome, int num, float sd, float rend){
    rendimento = rend;
    cc = Conta(nome, num, sd);
  }
  void info(){
    cc.info();
    cout << "limite: " << rendimento << endl;
    cout << "-------------------------------\n";
  }
};

class Banco {
  Conta* vetcontas;
  int numcontas;
public:
  Banco(){
    vetcontas = new Conta[TAMVETOR];
    numcontas = 0;
  }
  void adicionarConta(Conta c){
    vetcontas[numcontas] = c;
    numcontas++;
  }
  void listarContas(){
    for (int i = 0; i < numcontas; i++){
      vetcontas[i].info();
    }
  }
  ~Banco(){
    delete vetcontas;
  }
};



int main() {
Banco b1;
ContaCorrente cc1("CC1", 1, 32, 500);
ContaPoupanca cp1("CP1", 2, 50, 1.5);

b1.adicionarConta(cc1);
b1.adicionarConta(cp1);

b1.listarContas();
//Os numeros que aparecem no print são diferentes
}