#include <iostream>
using namespace std;

#define QTD_PNEU = 4

class motor{
  float tamanho;
  int serial;
public:
  motor(float tam = 0, int srl = 0){
    tamanho = tam;
    serial = srl;
  }
  float gettamanho(){return tamanho;}
  void settamanho(float tam){tamanho = tam;}
  int getserial(){return serial;}
  void setserial(int srl){serial = srl;}
  void printInfo(){
    cout << "motor::tamanho" << tamanho << endl;
    cout << "motor::serial" << serial << endl;
  }
  ~motor(){
    cout << "motor finalizado" << endl;
  }
};

class freio{
  int abs;
  float temperatura;
public:
  freio(float tmpr = 0, int abss = 0){
    temperatura = tmpr;
    abs = abss;
  }
  float gettemperatura(){return temperatura;}
  void settemperatura(float tmpr){temperatura = tmpr;}
  int getabs(){return abs;}
  void setabs(int abss){abs = abss;}
  void printInfo(){
    cout << "freio::temperatura" << temperatura << endl;
    cout << "freio::abs" << abs << endl;
    }
  ~freio(){
    cout << "freio finalizado" << endl;
    }
};

class pneu{
  int aro;
  float pressao;
public:
  pneu(float prss = 0, int aroo = 0){
    aro = aroo;
    pressao = prss;
  }
  float getpressao(){return pressao;}
  void setpressao(float prss){pressao = prss;}
  int getaro(){return aro;}
  void setaro(int aroo){aro = aroo;}
  void printInfo(){
    cout << "pneu::pressao" << pressao << endl;
    cout << "pneu::aro" << aro << endl;
    }
  ~pneu(){
    cout << "pneu finalizado" << endl;
  }
};

class carro{
  int nportas;
  int anofabr;
  int qtdpneu;
  motor* mtrcarro;
  freio* frcarro;
  pneu* pnucarro;
public:
  carro(float tam, int srl, float tmpr, int abss, float prss, int aroo, int nprt, int anofb, int qpneu){
    mtrcarro = new motor(tam, srl);
    frcarro = new freio(tmpr, abss);
    pnucarro = new pneu[qpneu];
    for(int i = 0; i < qpneu; i++){
      pnucarro[i].setaro(aroo);
      pnucarro[i].setpressao(prss);
    }
    nportas = nprt;
    anofabr = anofb;
    qtdpneu = qpneu;
  }
  void printInfo(){
    cout << "carro:: nportas" << nportas << endl;
    cout << "carro:: anofabr" << anofabr << endl;
    cout << "carro:: qtdpneu" << qtdpneu << endl;
  }
  ~carro(){
    delete mtrcarro;
    delete frcarro;
    delete pnucarro;
    cout << "carro finalizado" << endl;
  }
};


int main() {
  carro c1(1.8, 232143, 60, 1, 32, 15, 4, 2023, 4);
  carro* c2 = new carro(2.0, 675574, 80, 0, 64, 18, 3, 2021, 5);
  c1.printInfo();
  c2->printInfo();
  delete c2;
}