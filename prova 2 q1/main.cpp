#include <iostream>
#include <string>
using namespace std;

class Produto {       //classe abstrata
protected:
  string nome;
  float preco;
  int quantidade_estoque;
public:
  Produto(const string &n, float p, int qtd){nome = n; preco = p; quantidade_estoque = qtd;}

  string getnome(){return nome;}
  // set nome
  float getpreco(){return preco;}
  // set preco
  int getquantidade_estoque(){return quantidade_estoque;}
  // set quanridade_estoque
  
  virtual void print_info()=0;
};


class Material: public Produto {
protected:
  string tipo_material;
public:
  Material(const string &n, float p, int qtd, const string &tm):Produto(n, p, qtd){
    tipo_material = tm;
  }

  string gettipo_material(){return tipo_material;}
  // set tipo_material

  void print_info(){
    cout << "nome: " << getnome() << endl;
    cout << "preco: " << getpreco() << endl;
    cout << "qauntidade em estoque: " << getquantidade_estoque() << endl;
    cout << "tipo de material: " << tipo_material << endl;
  }
};


class Ferramenta : public Produto {
protected:
  string tipo_ferramenta;
public:
  Ferramenta(const string &n, float p, int qtd, const string &tf):Produto(n, p, qtd){
    tipo_ferramenta = tf;
  }

  string gettipo_ferramenta(){return tipo_ferramenta;}
  // set tipo_ferramenta

  void print_info(){
    cout << "nome: " << getnome() << endl;
    cout << "preco: " << getpreco() << endl;
    cout << "qauntidade em estoque: " << getquantidade_estoque() << endl;
    cout << "tipo de ferramenta: " << tipo_ferramenta << endl;
  }

  // Fiz novamente os gets de produto em ferramenta para contornar o conflito dos gets
  // em ferramenta eletrica
  string getnome2(){return getnome();}
  float getpreco2(){return getpreco();}
  int getquantidade_estoque2(){return getquantidade_estoque();}

};


class Ferramenta_Eletrica : protected Ferramenta, protected Material {
public:
  Ferramenta_Eletrica(const string &n, float p, int qtd, const string &tm, const string &tf):
  Material(n, p, qtd, tm), Ferramenta(n, p, qtd, tf){}

  void print_info(){
    cout << "nome: " << getnome2() << endl;
    cout << "preco: " << getpreco2() << endl;
    cout << "qauntidade em estoque: " << getquantidade_estoque2() << endl;
    cout << "tipo de ferramenta: " << gettipo_ferramenta() << endl;
    cout << "tipo de material: " << gettipo_material() << endl;
  }
};


int main() {
  Ferramenta f1("pa", 32.50, 20, "pa");
  Ferramenta f2("big hammer", 29.50, 30, "martelo");
  Material m1("carvalho", 2.00, 40, "madeira");
  Material m2("ferro", 1.50, 60, "metal");
  Ferramenta_Eletrica fe1("perfurador 3000", 500.00, 5, "plastico e metal", "broca");
  Ferramenta_Eletrica fe2("lanterna 500v", 50.99, 10, "plastico", "lanterna");

  Ferramenta* p_f1 = &f1;
  Ferramenta* p_f2 = &f2;
  Material* p_m1 = &m1;
  Material* p_m2 = &m2;
  Ferramenta_Eletrica* p_fe1 = &fe1;
  Ferramenta_Eletrica* p_fe2 = &fe2;

  Produto* listaprodutos[6];
  listaprodutos[0] = p_f1;
  listaprodutos[1] = p_f2;
  listaprodutos[2] = p_m1;
  listaprodutos[3] = p_m2;
  listaprodutos[4] = p_fe1;
  listaprodutos[5] = p_fe2;
  // fiquei sem tempo pra resolver o conflito de p_fe1 e p_fe2
  
  for (int i = 0; i < 6; i++){
    listaprodutos[i]->print_info();
  }
}