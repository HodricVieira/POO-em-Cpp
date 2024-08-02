#include <iostream>
#include <string>
using namespace std;
#define MAXFUNC 10
#define MAXDEP 10

class funcionario{
string nome;
string cpf;
float salario;
int idade;
public:
  funcionario(const string& n, const string cp, float s, int id){nome = n; cpf = cp; salario = s; idade = id;}
  void printinfo(){
    cout << "nome: " << nome << endl;
    cout << "cpf: " << cpf << endl;
    cout << "salario: " << salario << endl;
    cout << "idade: " << idade << endl;
  }
  int getsalario(){return salario;}
  void setsalario(float s){salario = s;}
};

class departamento{
string depnome;
int codigo;
funcionario* func[MAXFUNC];
int qtdfunc;
public:
  departamento(const string& n, int c, int qf = 0){
    depnome = n;
    codigo = c;
    qtdfunc = qf;
  }
  void addfunc(funcionario* f, int i){
    if (qtdfunc < MAXFUNC){
      func[i-1] = f;
      qtdfunc++;
    } else {cout << "erro addfunc\n";}
  }
  funcionario* getfunc(int i){
    return func[i-1];
  }

  int getqtdfunc(){return qtdfunc;}

  void printinfo(){
    cout << "depnome: " << depnome << endl;
    cout << "codigo: " << codigo << endl;
    cout << "qtdfunc: " << qtdfunc << endl;
    for (int i = 0; i < qtdfunc; i++){
      func[i]->printinfo();
    }
  }
};

class empressa{
string empnome;
int cnpj;
departamento* grupdep[MAXDEP];
int qtddep;
public:
  empressa(const string& en, int c, int qt = 0){
    empnome = en;
    cnpj = c;
    qtddep = qt;
  }
  void adddep(departamento* f, int i){
    if (qtddep < MAXFUNC){
      grupdep[i-1] = f;
      qtddep++;
    } else {cout << "erro adddep\n";}
  }
  departamento* getdep(int i){
    return grupdep[i-1];
  }
  void printinfo(){
    cout << "empnome: " << empnome << endl;
    cout << "cnpj: " << cnpj << endl;
    cout << "qtddep: " << qtddep << endl;
    for (int i = 0; i < qtddep; i++){
      grupdep[i]->printinfo();
    }
  }
//aumenta salario (a fazer)
  void aumentasalario(int coddep, float aumentoP100){
    cout << "sheehs";
    departamento* dep = getdep(coddep-1);
    funcionario* func;
    for (int i = 0; i < dep->getqtdfunc(); i++){
      func = dep->getfunc(i);
      func->setsalario(func->getsalario() + (func->getsalario()*aumentoP100/100));
    }
    cout << "saralio alterabo\n";
  }
};

int main() {
  empressa e1("acme", 6666);

  departamento d1("A", 1);
  departamento d2("B", 2);

  funcionario f1("Ivo", "234.345.234-64", 20000.9, 40);
  funcionario f2("Joao", "345.678.876-69", 2, 20);
  funcionario f3("Berg", "485.840.324.83", 0.00000059, 25);
  funcionario f4("Rodrigo", "439.567.205-21", 1000000.2, 200);
  funcionario f5("Gustav", "123.456.789-66", 12000.20, 10);

  e1.adddep(&d1, 1);
  e1.adddep(&d2, 2);
  
  d1.addfunc(&f1, 1);
  d1.addfunc(&f2, 2);
  d2.addfunc(&f3, 1);
  d2.addfunc(&f4, 2);
  d2.addfunc(&f5, 3);

  d1.printinfo();
  //aumentar salario em 10% de um dep solicitado
  float aumento;
  cout << "penetre o aumento\n";
  cin >> aumento;
  e1.aumentasalario(1, aumento);
  d1.printinfo();
}