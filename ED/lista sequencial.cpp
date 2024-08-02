#include <iostream>
using namespace std;

class listaSeq {
  int tamMax; 
  int tamAtual;
  int* lista;

public:
    listaSeq(int tam){
      tamAtual = 0;
      tamMax = tam;
      lista = new int[tamMax];
      for (int i = 0;i < tam; i++){
        lista[i] = 0;
        }
    }

    bool verificaVazia(){
      if (tamAtual == 0){
        cout << "a lista está vazia" << endl;
        return true;
        }
      else{
        cout << "a lista não está vazia" << endl;
        return false;
        }
      }
    bool verificaCheia(){
      if (tamAtual == tamMax){
        cout << "a lista está cheia" << endl;
        return true;
        }
      else {
        cout << "a lista não está cheia" << endl;
        return false;
        }
      }
      int tamanho(){
      cout << tamAtual << endl;
      return tamAtual;
    }
    int getposicao(int pos){
      int dado;
      if ((pos > tamAtual) || (pos <= 0))
        return -1;
      dado = lista[pos-1];
      cout << "eis aui o dado: " << dado << endl;
      return dado;
    }
    void modifica(int pos, int n){
      if ((pos > tamAtual) || (pos <= 0))
        printf("erro em modificar\n");
      else 
        lista[pos - 1] = n;
        printf("modificado\n");
    }
    void insere(int pos, int n){
      if ((tamAtual == tamMax) || (pos > tamAtual+1) || (pos<=0))
        printf("erro ao inserir\n");
      else {
        lista[pos-1] = n;
        tamAtual++;
        }
      }
      int remove(int pos){
      int dado;
      if ((pos > tamAtual) || (pos < 1 ))
        return -1;
      dado = lista[pos-1];
      for (int i = pos - 1; i < tamAtual - 1; i++){
        lista[i] = lista[i+1];
      }
      tamAtual--;
      return dado;
    }
    void verlista(){
      for(int i; i < (tamAtual-1); i++){
        cout << lista[i] << endl;
      }
    }
  ~listaSeq(){
    delete lista;
    cout << "lista deletada" << endl;
  }
};

int main() {
  int x = 10;
  listaSeq lista1(10);
  lista1.insere(1, 57);
  printf("travaqui\n");
  lista1.getposicao(1);
  
}