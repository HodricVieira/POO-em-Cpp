#include <iostream>
using namespace std;

class turma {
  int codigo;
  int* matriculas;
  int qtd_matriculas;
public:
  turma(int c, int q){
    codigo = c;
    qtd_matriculas = q;
    matriculas = (int*)malloc(q*sizeof(int));
    }
  int add_Matricula(int m, int pos){
    if (pos >= qtd_matriculas)
      return -1;
    else {
      matriculas[pos] = m;
      return pos;
    }
  int get_matricula();www
  }
};

int main() {
  
}