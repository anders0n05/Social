
#ifndef VALIDACOES_H
#define VALIDACOES_H
#include <time.h>//usar hora do sistema atual para validar aniversario

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






#endif
