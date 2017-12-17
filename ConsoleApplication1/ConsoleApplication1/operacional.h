#ifndef OPERACIONAL_H
#define OPERACIONAL_H
#include<iostream>
#include <string>
#include "struct_usuario.h"
#include"STRUCT_POST.h"
using namespace std;



void inicializa_lista(Usuarios *usuarios) {

	usuarios->inicio = NULL;
	usuarios->final = NULL;

	
}

void inserir_usuario(Usuarios *usuarios, string usuario, string nome_completo, int senha, int dia, int mes, int ano, char genero){
User *novo;
novo = new Usuario(usuario, nome_completo, senha, dia, mes, ano, genero);
if (usuarios->inicio == NULL) {
	usuarios->inicio = novo;
	usuarios->final = novo;
}
else {

	usuarios->final->proximo = novo;
	usuarios->final = novo;
}




}
void inicializa_post(Posts *posts) {

	posts->inicio = NULL;
	posts->final = NULL;


}
void mostrarElementos(Usuarios *allusers) {

	User *aux;
	aux = allusers->inicio;
	if (aux == NULL) {
		cout << "Lista vazia";
	}
	else {
		while (aux != NULL) {
			cout << "Usuario" << aux->usuario << endl;
			cout << "Senha" << aux->senha << endl;
			cout << "Sexo: " << aux->genero << endl;
			aux = aux->proximo;
		}
	}

}
void inserir_post(Posts *posts,string post,string usuario) {
	Post *novo;
	novo = new Post(post,usuario);
	if (posts->inicio == NULL) {
		posts->inicio = novo;
		posts->final = novo;
	}
	else {

		posts->final->proximo = novo;
		posts->final = novo;
	}




}



void ler_post(Posts *posts,string post,string usuario) {

	
	getline(cin, post);
	//cin >> post;
	inserir_post(posts,post, usuario);

}
#endif
