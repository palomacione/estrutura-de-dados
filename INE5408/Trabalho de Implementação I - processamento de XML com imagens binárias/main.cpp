#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "Parsing.h"
#include "Rotulação.h"

std::string abrirArquivo(std::string nome) {
    using namespace std;
    ifstream file;
    file.open(nome);
    string content;
    string line;
    if (!file.is_open()) {
        throw invalid_argument("Falha ao abrir");
    }
    while(getline(file, line))
        content+= line;

    return content;

    }
int main () {
std::string nomeArquivo;
std::cin >> nomeArquivo;

if(testeParsing(nomeArquivo)) {
    std::string arquivo = abrirArquivo(nomeArquivo);
    Rotulacao analisar;
    analisar.inicializarImagens(arquivo);
}

return 0;
}	 	  	 	      	      	    	   	  	  	       	 	
