#include <string>
#include <sstream>
#include <iostream>
#include <vector> 
#include <iterator>

using namespace std;

class Filme {
private:
	int numero;
	string titulo;
	int faixaEtaria;
	string estilo;
public:
	Filme(int n=-1, string t="", int f=-1, string e="");
	~Filme();
	int obtemNumero() const;
	string obtemTitulo() const;
	int obtemFaixaEtaria() const;
	string obtemEstilo() const;
	string str() const;
	void defineNumero(int n);
	void defineTitulo(string t);
	void defineFaixaEtaria(int f);
	void defineEstilo(string e);
	bool operator<(const Filme &f) const;
};

Filme::Filme(int n, string t, int f, string e){
    numero = n;
    titulo = t;
    faixaEtaria = f;
    estilo = e;
 }

 Filme::~Filme(){
    //cout << titulo << " [Foi destruido...]" << endl; 
 }

 int Filme::obtemNumero() const {return numero;}
 string Filme::obtemTitulo() const {return titulo;}
 int Filme::obtemFaixaEtaria() const {return faixaEtaria;}
 string Filme::obtemEstilo() const {return estilo;}

 string Filme::str() const{
        stringstream ss;
        ss << titulo << " [" << numero << "] - ";
        if(faixaEtaria == -1){
            ss << "LIVRE";
        } else {
         ss << faixaEtaria << " anos";
        }
        ss << " - " << estilo << endl;

        return ss.str();
}

 void Filme::defineNumero(int n) {numero = n;}
 void Filme::defineTitulo(string t) {titulo = t;}
 void Filme::defineFaixaEtaria(int f) {faixaEtaria = f;}
 void Filme::defineEstilo(string e) {estilo = e;}

 bool Filme::operator<(const Filme &f) const{
              if(this->titulo < f.titulo){
          return true;
     } else {
          return false;
     }
 }

vector<string> splitCSV(string linha, char separador=';') {
vector<string> res;
string campo = "";
for (int i=0; i<linha.size(); ++i) {
char c = linha.at(i);
if (c == separador) {
res.push_back(campo);
campo = "";
}
else
campo.append(1,c);
}
res.push_back(campo);
return res;
}

int main(){
  string linha;
    vector<Filme> filmes; 

  while (getline(cin, linha)) {
  	vector<string> campos = splitCSV(linha,';');

    int id = stoi(campos[0]);
    string nome = campos[1];
    int faixa = stoi(campos[2]);
    string estilo = campos[3];

    Filme temp(id, nome, faixa, estilo);
    filmes.push_back(temp);
  }

for(int i = 0; i < filmes.size(); i++) {
    while (filmes[i]) {
        if (filmes[i] > filmes[i+1]) {
            filmes[i] = filmes[i+1];
        }
        
    }
   }
   
   
   	
   for(int i = 0; i < filmes.size(); i++) {
        cout << filmes[i].str();
   }
}
