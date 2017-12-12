
#ifndef VALIDACOES_H
#define VALIDACOES_H
#include <time.h>//usar hora do sistema atual para validar aniversario
#include<xloctime>
#include <string>
using namespace std;
bool valida_data_nascimento(int dia_nascimento, int mes_nascimento, int ano_nascimento) {//funcao responsavel por validar a data de nascimento do usuario com base em dia mes e ano
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



}

bool valida_senha_cadastro(int senha1, int senha2) {

	if (senha1 == senha2) {
		return true;
	}
	return false;

}
bool valida_usuario_logado(string usuario,int senha,string &mensagem_erro) {
	allusers *unico_user;
	ElementoUsuario *usuario_cadastrado;
	if (unico_user->inicio==NULL) {
				if (usuario != usuario_cadastrado->info->id) {
					mensagem_erro = "Usuario Nao Existe";
					return false;
				}
				else if (senha != usuario_cadastrado->info->senha) {
					mensagem_erro = "Usuario Existe, mas a senha esta incorreta";
					return false;
				}
				return true;
	}
	else {
		usuario_cadastrado = unico_user->inicio;

		while (usuario_cadastrado != NULL) {
			if (usuario_cadastrado->info->id == usuario) {
						if (usuario_cadastrado->info->senha != senha) {
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
			usuario_cadastrado = usuario_cadastrado->proximo;
		}
	}


}

bool valida_usuario_nome_igual(string usuario,string &erro) {
	allusers *unico_user;
	ElementoUsuario *usuario_cadastrado;
	if (unico_user->inicio == NULL) {
		if (usuario_cadastrado->info->id == usuario) {
			erro = "Este nome de usuario ja existe";
			return false;
		}
		
		else {
			usuario_cadastrado = unico_user->inicio;

			while (usuario_cadastrado != NULL) {
				if (usuario_cadastrado->info->id == usuario) {
					
					erro = "Usuario ja existe";
					return false;
				}
				
				usuario_cadastrado = usuario_cadastrado->proximo;
			}
			return true;
		}
	}



}




#endif
