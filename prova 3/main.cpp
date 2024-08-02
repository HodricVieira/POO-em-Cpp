#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pagamento {
float valor;
int data;
int numero_cartao;
public:
  Pagamento (float v, int dt, int nc){valor = v; data = dt; numero_cartao = nc;}

  float getvalor (){return valor;}

  virtual string printinfo(){ //O print info precissa ser assim par ser printado pelo operador << de fatura.
    return "Valor: " + to_string(valor) + "\nData: " + to_string(data) + "\n numero do cartão: " + to_string(numero_cartao);
  }
};

class Pagamento_online : public Pagamento {
string nome_site;
int codigo_seguranca;
public:
  Pagamento_online (float v, int dt, int nc, const string &nm, int cs):Pagamento(v, dt, nc){
    nome_site = nm; codigo_seguranca = cs;
  }

  string printinfo(){
    return Pagamento::printinfo() + "\nnome do site: " + nome_site + "\ncodigo de segurança: " + to_string(codigo_seguranca);
  }

};

class Pagamento_presencial : public Pagamento {
string nome_loja;
public:
  Pagamento_presencial (float v, int dt, int nc, const string &nm):Pagamento(v, dt, nc){nome_loja = nm;}

  string printinfo(){
    return Pagamento::printinfo() + "nome da loja: " + nome_loja;
  }
};

template <class T>
class fatura {
double limite_credito;
vector<T*> pagamentos;//vetor de pagamentos
public:
  fatura (double lc){
    limite_credito = lc;  
  }

  double getlimite_credito(){return limite_credito;}

  void adicionar_pagamento (T* X){// adiciona o pagamento caso ele não exceda o limite
    if (X->getvalor() > limite_credito){
      throw string("Valor acima do limite de credito");
    }
    else {pagamentos.push_back(X);}
  }

  float calcular_valor_total(){// percorre o vector e soma os valores dos pagamentos
    float total;
    for (int i = 0; i < pagamentos.size(); i++){
      total += pagamentos[i]->getvalor();
    }
    cout << total << endl;
    return total;
  }

  friend ostream& operator<<(ostream& os, const fatura<T>& f){
    for (auto p : f.pagamentos) { // com os print infos em formato de string ele entra no os e pode ser retornado
       os << p->printinfo() << endl;
    }
    return os;
  }

  void operator+ (T* x){
    adicionar_pagamento(x);
  }

  void operator- (Pagamento y){// procura o objeto no vector, se está lá guarda a posição e então remove pela posição, se não estiver vai pro throw
    int aux = -1;
    for (int i = 0; i < pagamentos.size(); i++){
      if (pagamentos[i] == y){aux = i;}
    }
    if (aux != -1){pagamentos.erase(aux);}
    else{throw string("Esse pagamento não está nessa fatura");}
  }

  friend void transferir_pagamentos(fatura<T> &f1, fatura<T> &f2) {
        for (int i = 0; i < f1.pagamentos.size(); i++) {
            f2.adicionar_pagamento(f1.pagamentos[i]);
          //adiciona os pagamentos de f1 para f2
        }
        f1.pagamentos.clear(); // e então limpa f1
    }
};

int main() {

  Pagamento* p1 = new Pagamento(100, 20032023, 111);
  Pagamento* p2 = new Pagamento(150, 27122023, 222);
  Pagamento* p3 = new Pagamento(50, 17042023, 333);
  Pagamento* p4 = new Pagamento(170, 10062023, 444);
  Pagamento* p5 = new Pagamento(890, 02072023, 555);
  Pagamento* p6 = new Pagamento(900, 13082023, 666);
  Pagamento* p7 = new Pagamento(2340, 23032023, 777);
  Pagamento* p8 = new Pagamento(64748, 12042023, 888);
  Pagamento* p9 = new Pagamento(37280, 22122023, 999);
  
  fatura<Pagamento> f1(200);
  fatura<Pagamento> f2(3000);
  fatura<Pagamento> f3(40000);

  try {
  f1.adicionar_pagamento(p1);
  f1 + p2;
  f1 + p3;
  } catch (std::string erro) {
	cout << erro << endl;
  }

  try {
  f2.adicionar_pagamento(p4);
  f2 + p5;
  f2 + p6;
  } catch (std::string erro) {
	cout << erro << endl;
  }

  try {
  f3.adicionar_pagamento(p7);
  f3 + p8;
  f3 + p9;
  } catch (std::string erro) {
	cout << erro << endl;
  }

  cout << "Fatura 1: " << endl;
  cout << f1 << endl;
  cout << "Fatura 2: " << endl;
  cout << f2 << endl;
  cout << "Fatura 3: " << endl;
  cout << f3 << endl;

  transferir_pagamentos(f1, f2);

  cout << "Fatura 1: " << endl;
  cout << f1 << endl;
  cout << "Fatura 2: " << endl;
  cout << f2 << endl;
  cout << "Fatura 3: " << endl;
  cout << f3 << endl;
}