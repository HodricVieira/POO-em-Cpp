#include <iostream>
using namespace std;

//Pilha Estatica(a fazer)
class pilhaEstat{
  int tamatual;
  int tammax;
  int* lista;
public:
  pilhaEstat(int max){
    lista = new int[max-1];
    tammax = max;
    tamatual = 0;
  }
  bool vervazia(){
    if (tamatual == tammax){return true;}
    else {return false;}
  }

  void inserevalor(int n){
    if (vervazia() == true){
      lista[0] = 0;
    }
    else{
      
    }
    
  }
};



//Pilha Encadeada
class No {
  int conteudo;
  No* proximo;
public:
  No(int cont = 0){
    conteudo = cont;
    proximo = NULL;
  }
  int getconteudo(){
    return conteudo;
  }
  void setconteudo(int novocont){
    conteudo = novocont;
  }
  No* getproximo(){
    return proximo;
  }
  void setproximo(No* p){
    proximo = p;
  }
  ~No(){
    cout << "No finalizado\n";
  }
};

class pilhaEncad {
  No* cabeca;
  int tamanho;
public:
  pilhaEncad(){
    cabeca = NULL;
    tamanho = 0;
    cout << "pilha criada\n";
  }
  pilhaEncad(int cont){
    cabeca = new No(cont);
    tamanho = 1;
    cout << "pilha criada\n";
  }
  bool verVazia(){
    if (cabeca == NULL && tamanho == 0){
      //cout << "a pilha esta vazia\n";
      return true;}
    else{
      //cout << "a pilha não esta vazia\n";
      return false;}
  }
  int gettamanho(){
    return tamanho;
  }
  void insereno(int n){
    No* novono = new No(n);
    if (verVazia() == true){
      cabeca = novono;
    }
    else{
      novono->setproximo(cabeca);
      cabeca = novono;}
    tamanho++;
    cout << "elemento inserido\n";
  }
  int getconteudo(){
    return cabeca->getconteudo();
  }
  void removeno(){
    No* noaux = cabeca;
    cabeca = cabeca->getproximo();
    noaux = NULL;
    cout << "No removido\n";
    tamanho--;
  }
  void infopilha(){
    cout << "Tamanho atual: " << gettamanho() << endl;
    if (verVazia()==true){
      cout << "pilha esta vazia\n";}
    else{
      No* noaux = cabeca;
      cout << noaux->getconteudo() << endl;
      for (int i = 1; i < tamanho; i++){
        noaux = noaux->getproximo();
        cout << noaux->getconteudo() << endl;
      }
    }
  }
  ~pilhaEncad(){
    cout << "pilha finalizada\n";
  }
};

int main() {
  std::cout << "Hello World!\n";
}