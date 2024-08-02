#include <iostream>
using namespace std;

class aluno {
    int matricula;
    float cra;

    public:
        aluno(int m, float c){
          matricula = m;
          cra = c;
          cout << "aluno criado" << endl;
        }
        int get_matricula(){
            return matricula;
        }
        void set_matricula(int m){
            matricula = m;
        }
        float get_cra(){
            return cra;
        }
        void set_cra(float new_cra){
            cra = new_cra;
        }
      ~aluno(){
        cout << "aluno finalizado" << endl;
      }
};

class turma {
 int qtd_aluno;
};

int main(){
    aluno a1(1012, 82);
    int x = a1.get_matricula();
    a1.set_cra(9.5);
    float y = a1.get_cra();
    cout << "matricula: " << x << endl;
    cout << "cra: " << y << endl;
}