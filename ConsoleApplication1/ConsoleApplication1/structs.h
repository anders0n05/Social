#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
using namespace std;
struct Usuario {
	string nome, genero, id;
	int senha, dia, mes, ano;



	Usuario(string nome, string genero, string id, int senha, int dia, int mes, int ano) {

		this->nome = nome;
		this->genero = genero;
		this->id = id;
		this->senha = senha;
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;


	}

};

struct ElementoUsuario {

	Usuario *info;
	ElementoUsuario *proximo;

	ElementoUsuario(Usuario *dados_usuario) {
		this->info = dados_usuario;
		this->proximo = NULL;
	}
};

struct allusers {

	ElementoUsuario *inicio;


	allusers(ElementoUsuario *inicio) {
		this->inicio = inicio;
	}

	void inserir_Usuario(ElementoUsuario *novoUsuario) {

		if (this->inicio == NULL) {
			this->inicio = novoUsuario;
			return;
		}
		ElementoUsuario *UserAtual = this->inicio; 

		while (UserAtual != NULL) {
			if (UserAtual->proximo == NULL) {
				UserAtual->proximo = novoUsuario;
				break;
			}
			UserAtual = UserAtual->proximo;
		}
	}

	bool valida_usuario_logado(string usuario, int senha, string &mensagem_erro) {
		
		if (this->inicio == NULL) {
			
			return true;			
		}
		else {
			ElementoUsuario *userAtual = this->inicio;

			while (userAtual != NULL) {
				if (userAtual->info->id == usuario) {
					if (userAtual->info->senha != senha) {
						mensagem_erro = "Usuario Existe, mas a senha esta incorreta";
						return false;
					}
					else {
						return true;
					}
				}
				else {
					mensagem_erro = "Usuario Nao existe, tente novamente";
					return false;
				}
				userAtual = userAtual->proximo;
			}
		}


	}
	
	bool valida_usuario_nome_igual(string usuario, string &erro) {
		allusers *unico_user;
		ElementoUsuario *usuario_cadastrado;
		
		if (this->inicio == NULL) {

			return true;
		}
		
		ElementoUsuario *userAtual = this->inicio;
		while (userAtual != NULL) {
			if (userAtual->info->id == usuario) {

				erro = "Este usuario ja existe";
				return false;
			}
			userAtual = userAtual->proximo;
	    }
		return true;


};






#endif