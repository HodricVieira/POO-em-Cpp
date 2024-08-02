#include <iostream>

using namespace std;
#define MAXALUNOS 10

class Pessoa {
  string nome;
  int idade;
  int cpf;
public:
  Pessoa(const string nm, int idd, int cp){
    nome = nm;
    idade = idd;
    cpf = cp;
  }
};

class Aluno : public Pessoa {
  float mensalidade;
public:
  Aluno(const string nm, int idd, int cp, float mensalid):Pessoa(nm, idd, cp){
    mensalidade = mensalid;
  }
};

class Instrutor : public Pessoa {
  float salario;
public:
  Instrutor(const string nm, int idd, int cp, float sal):Pessoa(nm, idd, cp){
    salario = sal;
  }
};

class Aula {
  string nome;
  float horario;
  float duracao;
  Instrutor professor;
  Aluno listaalunos[MAXALUNOS];
  int qtdalunos;
public:
// não descobri a tempo um jeito para resolver o construtor de aula
  Aula(const string nm, float hor, float dur, Instrutor prof){
    nome = nm;
    horario = hor;
    duracao = dur;
    professor = prof;
    qtdalunos = 0;
  }
};


int main() {
}