#ifndef OPERACIONAL_H
#define OPERACIONAL_H
#include<iostream>
#include <string>
#include "structs.h"

using namespace std;




void adiciona_usuario(string nome,string id,string genero,int senha,int dia,int mes,int ano) {
	Usuario *usuario = new Usuario(nome, genero, id, senha, dia, mes, ano);
	ElementoUsuario *usuarioElemento = new ElementoUsuario(usuario);
	allusers *usuarios = new allusers(usuarioElemento);
	usuarios->inserir_Usuario(new ElementoUsuario(new Usuario(nome, genero, id, senha, dia, mes, ano)));

}

void timeline() {
	system("cls");
	cout << endl;
	cout << "Esta indo bem";

}



#endif
