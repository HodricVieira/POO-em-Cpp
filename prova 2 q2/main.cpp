#include <iostream>
#include <string>
using namespace std;

class Produto {
  string nome;
  float preco;
  int quantidade_estoque;
  static int total_produto;
public:
  Produto(const string &n, float p, int qtd){
    nome = n; preco = p; quantidade_estoque = qtd;
    total_produto++;
  }

  ~Produto(){total_produto--;}

  string getnome(){return nome;}
    // set nome
    float getpreco(){return preco;}
    // set preco
    int getquantidade_estoque(){return quantidade_estoque;}
    // set quanridade_estoque

  virtual void print_info(){
    cout << "nome: " << nome << endl;
    cout << "preco: " << preco << endl;
    cout << "qauntidade em estoque: " << quantidade_estoque << endl;
  }
};
int Produto::total_produto = 0;

class Sapato : public Produto{
  string cor;
  int tamanho;
public:
  Sapato(const string &n, float p, int qtd, const string c, int t):Produto(n, p, qtd){ cor = c; tamanho = t;}

  string getcor(){return cor;}
  // set cor
  int gettamanho(){return tamanho;}
  // set tamanho

  void print_info(){
    cout << "nome: " << getnome() << endl;
    cout << "preco: " << getpreco() << endl;
    cout << "qauntidade em estoque: " << getquantidade_estoque() << endl;
    cout << "cor: " << cor << endl;
    cout << "tamanho: " << tamanho << endl;
  }
};

class Tenis : public Sapato{
  string marca;
public:
  Tenis(const string &n, float p, int qtd, const string &c, int t, const string &m):Sapato(n, p, qtd, c, t){marca = m;} 

  // get e set tenis

  void print_info(){
    cout << "nome: " << getnome() << endl;
    cout << "preco: " << getpreco() << endl;
    cout << "qauntidade em estoque: " << getquantidade_estoque() << endl;
    cout << "cor: " << getcor() << endl;
    cout << "tamanho: " << gettamanho() << endl;
    cout << "marca: " << marca << endl;
  }
};

int main() {
  Sapato s1("lo verde", 10.99, 40, "verde", 25);
  Tenis t1("O Tenis", 200.50, 3, "dourado", 37, "Balenciaga");
  
  Sapato* p_s1 = &s1;
  Tenis* p_t1 = &t1;
  // sem tempo para mais deles
  
  Produto* listaprodutos[2];
  listaprodutos[0] = p_s1;
  listaprodutos[1] = p_t1;
  
  for (int i = 0; i < 2; i++){
    listaprodutos[i]->print_info();
  }
}