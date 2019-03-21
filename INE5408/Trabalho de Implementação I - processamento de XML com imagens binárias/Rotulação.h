#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <stdexcept>
#include "linked_queue.h"
#include "Coordenada.h"
#include "Imagem.h"
auto fila = structures::LinkedQueue<Coordenada> {};
class Rotulacao {
public:

 void setImg(Image * img) {
        this->largura = img->getWidth();
        this->altura = img->getHeight();
        this->data = img->getData();
        this->label = 1;
}
int contarImagens(std::string arquivo) {
	 int contador = 0;
                int nPos = arquivo.find("<img>", 0);
                while(nPos != -1) {
                    contador++;
                    nPos = arquivo.find("<img>", nPos + 1);
                }
return contador;
}
std::string pegaValores(std::string substr, std::string tag) {
                int first_index = substr.find(tag) + tag.length();
                int last_index = substr.find(tag.insert(1, "/"));
                return substr.substr(first_index, last_index - first_index);
}
Image* criaImagem(std::string arquivo) {
                std::string tag = pegaValores(arquivo, "<img>");

                std::string name = pegaValores(tag, "<name>");
                std::string data = pegaValores(tag, "<data>");
                int width =  std::stoi(pegaValores(tag, "<width>"));
                int height = std::stoi(pegaValores(tag, "<height>"));

                return new Image(name, width, height, data);
}	 	  	 	      	      	    	   	  	  	       	 	

void atualizaValor(int* clone, int i,int j, int pos) {
if (this->data.at(pos) ==  *"1" && clone[pos] == 0) {
    fila.enqueue(*(new Coordenada(i, j)));
     clone[pos] = this->label;
}
}
void pegaVizinhaca(int* clone) {
	while(!fila.empty()) {
		Coordenada aux = fila.dequeue();
		int  auxlinha = aux.getX() * largura;
		pegaLinhaCima(aux, clone, &auxlinha);
		pegaLinhaBaixo(aux, clone, &auxlinha);
		pegaColunaFrente(aux, clone, &auxlinha);
		pegaColunaAtras(aux, clone, &auxlinha);

	}
}
void verificaPixel(int*clone, int coordenada, int i, int j) {
	if(data.at(coordenada) == *"1"){
		if(clone[coordenada] == 0){
			fila.enqueue(*(new Coordenada(i,j)));
			clone[coordenada] = this->label;
			//std::cout << this->label<< std::endl;
			pegaVizinhaca(clone);
			this->label++;
		}
	}
}

void pegaLinhaCima(Coordenada aux, int* clone, int* auxLinha) {
	int novaLinha = aux.getX() + 1;
         if (novaLinha < this->altura) {
            int pos = *auxLinha + this->largura + aux.getY();
            atualizaValor(clone, novaLinha, aux.getY(), pos);
         }	 	  	 	      	      	    	   	  	  	       	 	
}
void pegaLinhaBaixo(Coordenada aux, int* clone, int* auxlinha){
	int novaLinha = aux.getX() - 1;
         if (novaLinha > -1) {
             int pos = *auxlinha - this->largura + aux.getY();
             atualizaValor(clone, novaLinha, aux.getY(), pos);
}
}
void pegaColunaFrente(Coordenada aux, int* clone, int* auxLinha) {
  	int col = aux.getY() + 1;
        if (col < this->largura) {
            int pos = *auxLinha + col;
            atualizaValor(clone, aux.getX(), col, pos);
}
}
void pegaColunaAtras(Coordenada aux, int* clone, int* auxLinha) {
	int col = aux.getY() - 1;
        if (col > -1) {
        int pos = *auxLinha + col;
        atualizaValor(clone, aux.getX(), col, pos);
}
}
int rotular (Image image) {
	int clone[this->altura*this->largura];
	int coordenada = 0;
	
	for(int i =0; i<this->altura; i++){
		for (int j = 0; j<this->largura; j++) {
			coordenada = (i* this->largura) + j;
			verificaPixel(clone, coordenada, i, j);
		}
	}
return this->label -1;
}
void inicializarImagens(std::string arquivo) {
	int n = contarImagens(arquivo);
	Image* arrayImagens = new Image[n];
	int i = 0;
                int nPos = arquivo.find("<img>", 0);
                std::string aux = arquivo;
                while(nPos != -1) {	 	  	 	      	      	    	   	  	  	       	 	
                    aux = arquivo.substr(nPos, arquivo.length() - nPos);
                    arrayImagens[i] = *criaImagem(aux);
                    nPos = arquivo.find("<img>", nPos + 1);
                    i++;
}
    for(int i =0; i< n; i++){
        setImg(&arrayImagens[i]);
        std::cout << arrayImagens[i].getName() << " " << rotular(arrayImagens[i]) << std::endl;
    }

}
private:
std::string data;
int label = 1;
int largura;
int altura;
};