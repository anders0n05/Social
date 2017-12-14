
#ifndef VALIDACOES_H
#define VALIDACOES_H
#include <time.h>//usar hora do sistema atual para validar aniversario
#include"interface.h"
#include <string>
using namespace std;
bool valida_genero(char genero,string &erro) {

	switch (genero)
	{
	case 'M': genero = 'M'; break;
	case 'F': genero = 'F'; break;
		return true;
	default:
		erro = "Digite uma opcao Valida";
		return false;
		break;
	}

	

}
bool valida_data_nascimento(int dia_nascimento, int mes_nascimento, int ano_nascimento) {//funcao responsavel por validar a data de nascimento do usuario com base em dia mes e ano
	/*foi pesquisado na documentacao do visual studio como usar a struct data, a implementacao
	 consiste em validar a idade por dia, sendo possivel um usuario que esta fazendo aniversario no mesmo
	 dia criar o login*/

	struct tm newtime;
	time_t t = time(NULL);
	__time64_t long_time;
	errno_t err;
	_time64(&long_time);
	err = _localtime64_s(&newtime, &long_time);


	int ano = 1900 + newtime.tm_year;
	int mes = 1 + newtime.tm_mon;
	int dia = newtime.tm_mday;
	

	if ((ano - ano_nascimento)>18) {
		return true;
	}
	else if ((ano - ano_nascimento) == 18) {
		if ((dia - dia_nascimento) >= 0 && (mes - mes_nascimento) >= 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else if ((ano - ano_nascimento)<18) {
		return false;
	}

	return true;

}

bool valida_senha_cadastro(int senha1, int senha2,string &mensagem_erro) {

	if (senha1 == senha2) {
		return true;
	}
	mensagem_erro = "As senhas nao conferem";
	return false;

}

bool buscar_elementos_iguais(Usuarios *allusers, string usuario, string &mensagem_erro) {
	User *user;
	user = allusers->inicio;
	if (user == NULL) {

		return true;
	}
	else {
		while (user != NULL) {
			if (user->usuario == usuario) {
				mensagem_erro = "Ja existe esse usuario ";
				return false;

			}

			//se nao achar nada pode retornar verdadeiro
			user = user->proximo;
		}

		return true;
	}
}




//funcao responsavel por verificar o usuario que esta logando (login)

bool verificar_usuario_cadastrado(Usuarios *allusers, string usuario, int senha, string &mensagem_erro,int &situacao) {
	User *user;
	user = allusers->inicio;
	if (user == NULL) {
		mensagem_erro = "faca o cadastro primeiro";
		situacao = NULL;// forca o usuario fazer cadastro, pois a lista esta vazia;
		return false;

	}
	
		while (user != NULL) {
			if (user->usuario == usuario) {
				if (user->senha == senha) {
					return true;
				}
				mensagem_erro = "Sua senha esta incorreta";
				return false;
				
			}
			
			user = user->proximo;
		}
		mensagem_erro = "Não encontramos nenhum usuario com este nome";
		return false;
	
}







#endif
