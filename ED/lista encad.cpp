#include <iostream>
using namespace std;

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

class listaEncad {
  No* cabeca;
  No* cauda;
  int tamanho;
public:
  listaEncad(){
    cabeca = NULL;
    cauda = cabeca;
    tamanho = 0;
    cout << "lista criada\n";
  }
  listaEncad(int cont){
    cabeca = new No(cont);
    cauda  = cabeca;
    tamanho = 1;
    cout << "lista criada\n";
  }
  bool verVazia(){
    if (cabeca == NULL && tamanho == 0){
      //cout << "a lista esta vazia\n";
      return true;}
    else{
      //cout << "a lista não esta vazia\n";
      return false;}
  }
  int gettamanho(){
    return tamanho;
  }
  void insereinicio(int n){
    No* novono = new No(n);
    if (verVazia() == true){
      cabeca = novono;
      cauda = novono;}
    else{
      novono->setproximo(cabeca);
      cabeca = novono;}
    tamanho++;
    cout << "elemento inserido\n";
  }
  void inserefinal(int n){
    No* novono = new No(n);
    if (verVazia() == true){
      cabeca = novono;
      cauda = novono;}
    else{
      cauda->setproximo(novono);
      cauda = novono;}
    tamanho++;
    cout << "elemento inserido\n";
  }
  void insereposicao(int cont, int pos){
    if (pos > tamanho+1 || pos < 1){
      cout << "posicao invalida\n";
    }
    else{
      if (pos == 1 || pos == tamanho+1){
        if (pos == 1){insereinicio(cont);}
        else {inserefinal(cont);}
      }
      else{
        No* novono = new No(cont);
        No* noaux = cabeca;
        for (int i =1; i < pos-1; i++){
          noaux = noaux->getproximo();}
        novono->setproximo(noaux->getproximo());
        noaux->setproximo(novono);
        tamanho++;
        cout << "elemento inserido\n";
      }
    }
  }
  int getconteudo(int pos){
    if (pos >= 1 && pos <= tamanho){
      No* noaux = cabeca;
      int aux;
      for (int i =1; i < pos; i++){
        noaux = noaux->getproximo();}
      aux = noaux->getconteudo();
      cout << "conteudo recebido: " << aux << endl;
      return aux;
    }
    else{
      cout << "posicao invalida\n";
      return -1;
    }
  }
  void setconteudo(int cont,int pos){
    if (pos >= 1 && pos <= tamanho){
      No* noaux = cabeca;
      for (int i =1; i <= pos; i++){
        noaux = noaux->getproximo();}
      noaux->setconteudo(cont);
      cout << "conteudo setado\n";
    }
    else{
      cout << "posicao invalida\n";
    }
  }
  void removeNo(int pos){
    if (pos < 1 || pos > tamanho){
      cout << "posicao invalida\n";}
    else{
      if(pos >1){
       No* noaux = cabeca;
       No* noauxAnt = cabeca;
        for (int i = 1; i < pos-1; i++){
          noaux = noaux->getproximo();
          noauxAnt = noauxAnt->getproximo();
        }
      noaux = noaux->getproximo();
      noauxAnt->setproximo(noaux->getproximo());
      noaux = NULL;
      }
      else{//Quando pos = 1
        No* noaux = cabeca;
        cabeca = cabeca->getproximo();
        noaux = NULL;
      }
      cout << "No removido\n";
      tamanho--;
    } 
  }
  void infolista(){
    cout << "Tamanho atual: " << gettamanho() << endl;
    if (verVazia()==true){
      cout << "lista esta vazia\n";}
    else{
      No* noaux = cabeca;
      cout << noaux->getconteudo() << endl;
      for (int i = 1; i < tamanho; i++){
        noaux = noaux->getproximo();
        cout << noaux->getconteudo() << endl;
      }
    }
  }
  ~listaEncad(){
    cout << "lista finalizada\n";
  }
};

int main() {
  listaEncad l1;
  l1.insereposicao(10, 1);
  l1.insereposicao(20, 2);
  l1.insereposicao(30, 3);  
  l1.insereposicao(15, 2);
  l1.infolista();
  l1.setconteudo(50, 2);
  l1.getconteudo(2);
  l1.removeNo(4);
  l1.infolista();
}