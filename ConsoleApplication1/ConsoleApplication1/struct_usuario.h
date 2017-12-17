#ifndef STRUCT_USUARIO_H //responsavel por criar o objeto Usuario
#define STRUCT_USUARIO_H
#include <string>
using namespace std;
typedef struct Usuario {
	string usuario, nome_completo;
	int senha, dia, mes, ano;
	struct Usuario *proximo;
	char genero;

	Usuario(string usuario, string nome_completo, int senha, int dia, int mes, int ano, char genero) {
		this->usuario = usuario;
		this->senha = senha;
		this->nome_completo = nome_completo;
		this->senha = senha;
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
		this->genero = genero;
		this->proximo = NULL;
	}
	
}User;

typedef struct Lista_usuario {

	User *inicio;
	User *final;

}Usuarios;






#endif