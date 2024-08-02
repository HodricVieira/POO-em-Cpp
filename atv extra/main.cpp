#include <iostream>

using std::cout;
using std::endl;

class pessoa {
	int cpf;
	int idade;
	float altura;
	static int contador;
	static float soma_altura;
public:
	pessoa(int c, int i, float a) {
		cpf = c;
		idade = i;
		altura = a;
		soma_altura += a;
		contador++;
	}
	/* gets e sets */
	static int get_contador() {
		return contador;
	}
	static float get_media_altura() {
		if (contador > 0) {
			return soma_altura / contador;
		}
		else {
			return 0;
		}
	}
};

class professor : public pessoa {
	int matricula;
	int ano_admissao;
	int titulacao;
	static int soma_idade;
	static int contador;
public:
	professor(int c, int i, float a,
		  int m, int aa, int t):
		   pessoa(c, i, a) {
		matricula = m;
		ano_admissao = aa;
		titulacao = t;
		soma_idade += i;
		contador++;
	}
	/* gets e sets */
	static float get_media_idade() {
		if (contador == 0) 
			return 0;

		return ((float)soma_idade)/contador;
	}
};

class aluno : public pessoa {
	int matricula;
	float cra;
	static int soma_idade;
	static int contador;
public:
	aluno(int c, int i, float a, 
	      int m, float cr):pessoa(c,i,a) {
		matricula = m;
		cra = cr;
		soma_idade += i;
		contador++;
	}
	void set_matricula(int m) {
		matricula = m;
	}
	int get_matricula() {
		return matricula;
	}
	void set_cra(float c) {
		cra = c;
	}
	float get_cra() {
		return cra;
	}
	static float get_media_idade() {
		if (contador == 0) 
			return 0;
		return ((float)soma_idade)/contador;
	}
};

class turma {
	int codigo;
	professor* responsavel;
	aluno** grupo;
	int tamanho;
	int qtd_alunos;
	static turma* instance;
	turma() {
		codigo = 0;
		responsavel = nullptr;
		qtd_alunos = 0;
		tamanho = 0;
	}
public:
	~turma() {
		delete[] grupo;
	}
	static turma* get_instance() {
		if (instance == nullptr) {
			instance = new turma;
		} 
		return instance;	
	}
	void set_responsavel(professor* p) {
		responsavel = p;
	}
	professor* get_responsavel() {
		return responsavel;
	}
	void create_grupo(int i) {
		//grupo = (aluno**)malloc(
		//		sizeof(aluno*)*i);
		grupo = new aluno*[i];
		tamanho = i;
	}
	void add_aluno(aluno* a) {
		if (grupo == NULL) {
			cout << "Turma nao alocada";
			cout << endl;
			return;
		}
		if (qtd_alunos < tamanho) {
			grupo[qtd_alunos] = a;
			qtd_alunos++;
		} else { 
			cout << "Turma lotada!";
			cout << endl;
		}
	}
	aluno* get_aluno(int i) {
		return grupo[i];
	}
	float get_media_cra() {
		if (qtd_alunos == 0) {
			return 0;
		}
		float soma = 0;
		for (int i = 0; i < qtd_alunos; i++) {
			soma += grupo[i]->get_cra();
		}
		return (soma / qtd_alunos);
	}
};

int pessoa::contador = 0;
int aluno::contador = 0;
int professor::contador = 0;
int professor::soma_idade = 0;
int aluno::soma_idade = 0;
float pessoa::soma_altura = 0;
turma* turma::instance = nullptr;

/*int main() {
	aluno a1(1011, 29, 1.80, 202109, 8.5);
	aluno a2(2345, 22, 1.67, 202010, 7.6);
	aluno a3(1234, 32, 1.81, 201906, 7.0);

	professor p1(9876, 45, 1.76, 1764, 1999, 3);

	turma* t = turma::get_instance();

	t->create_grupo(5);

	t->set_responsavel(&p1);

	t->add_aluno(&a1);
	t->add_aluno(&a2);
	t->add_aluno(&a3);

	cout << "a) quantidade de pessoas: ";
	cout << pessoa::get_contador() << endl;
	cout << "b) media dos cra: ";
	cout << t->get_media_cra() << endl; 
	cout << "c) media altura pessoas: ";
	cout << pessoa::get_media_altura() << endl;
	cout << "d.1) media idade profs: ";
	cout << professor::get_media_idade() << endl;
	cout << "d.2) media idade alunos: ";
	cout << aluno::get_media_idade() << endl;

	return 0;
}*/

///////////////////////////////////////////
#include <string>

#define ANO_CORRENTE 2023
#define QTD_VEICULOS 3

using std::cout;
using std::endl;

class veiculo {
    int ano_fabricacao;
    float valor;
protected:
    virtual void print_info() {
        cout << "Ano de fabricação: " << ano_fabricacao << endl;
        cout << "Valor: " << valor << endl;
    }
public:
    veiculo(int a, float v) : ano_fabricacao(a), valor(v) {}
    int get_ano_fabricacao() { return ano_fabricacao; }
    float get_valor() { return valor; }
    void set_ano_fabricacao(int a) { ano_fabricacao = a; }
    void set_valor(float v) { valor = v; }
    virtual float ipva_calculado() = 0;
};

class carro : public veiculo {
    int quantidade_portas;
    float motor;
public:
    carro(int a, float v, int q, float m) : veiculo(a, v), 
            quantidade_portas(q), motor(m) {}
    int get_quantidade_portas() { return quantidade_portas; }
    float get_motor() { return motor; }
    void set_quantidade_portas(int q) { quantidade_portas = q; }
    void set_motor(float m) { motor = m; }
    void print_info() {
        veiculo::print_info();
        cout << "Quantidade de portas: " << quantidade_portas << endl;
        cout << "Motor: " << motor << endl;
    }
    float ipva_calculado() {
        return ((ANO_CORRENTE - get_ano_fabricacao()) * (motor/10)) + (get_valor()/1000);
    }
};

class moto : public veiculo {
    float cilindradas;
    int aro;
public:
    moto(int a, float v, float c, int aro) : veiculo(a, v), 
            cilindradas(c), aro(aro) { }
    float get_cilindradas() { return cilindradas; }
    int get_aro() { return aro; }
    void set_cilindradas(float c) { cilindradas = c; }
    void set_aro(int a) { aro = a; }
    void print_info() {
        veiculo::print_info();
        cout << "Cilindradas: " << cilindradas << endl;
        cout << "Aro: " << aro << endl;
    }
    float ipva_calculado() {
        return ((ANO_CORRENTE - get_ano_fabricacao()) * (cilindradas/100)) + (get_valor()/1100);
    }    
};

class caminhao : public veiculo {
    int quantidade_eixos;
    float carga;
public:
    caminhao(int a, float v, int q, float c) : veiculo(a, v), 
                quantidade_eixos(q), carga(c) { }
    int get_quantidade_eixos() { return quantidade_eixos; }
    float get_carga() { return carga; }
    void set_quantidade_eixos(int q) { quantidade_eixos = q; }
    void set_carga(float c) { carga = c; }
    void print_info() {
        veiculo::print_info();
        cout << "Quantidade de eixos: " << quantidade_eixos << endl;
        cout << "Carga: " << carga << endl;
    }
    float ipva_calculado() {
        return ((ANO_CORRENTE - get_ano_fabricacao()) * (quantidade_eixos/2)) + (carga/1000) + (get_valor()/900);
    }
};

/*
Explique como poderia ser implementada a classe MotoCarro, sendo que esta
possui características das classes Moto e Carro. Explique o mecanismo utilizado
e quais são os possíveis problemas a serem enfrentados e como podem ser 
solucionados.
*/

class moto_carro : public moto, public carro {
    int quantidade_rodas;
public:
    moto_carro(int qr, int a, float v, float c, int aro,
               int qp, float m) :
            moto(a, v, c, aro), 
            carro(a, v, qp, m), quantidade_rodas(qr) { }
    int get_qtd_rodas() { return quantidade_rodas; }
    void set_quantidade_rodas(int q) { quantidade_rodas = q; }
};

int main() {
    veiculo* veiculos[QTD_VEICULOS];
    carro c1(2010, 10000, 4, 1.6);
    moto m1(2015, 5000, 150, 17);
    caminhao ca1(2018, 20000, 4, 10000);
    moto_carro mc1(4, 2019, 10000, 150, 17, 4, 1.6);

    mc1.carro::set_valor(15000);
    mc1.moto::set_ano_fabricacao(2020);

    veiculos[0] = &c1;
    veiculos[1] = &m1;
    veiculos[2] = &ca1;

    c1.print_info();
    m1.print_info();
    ca1.print_info();

    float media = 0;
    float soma_ipva = 0;

    for (int i = 0; i < QTD_VEICULOS; i++) {
        soma_ipva += veiculos[i]->ipva_calculado();
    }
    cout << "Media dos IPVA: " << soma_ipva/QTD_VEICULOS << endl;

    return 0;
}