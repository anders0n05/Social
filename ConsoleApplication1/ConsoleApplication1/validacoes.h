#ifndef VALIDACOES_H
#define VALIDACOES_H
#include <ctime>//usar hora do sistema atual para validar aniversario
bool valida_data_nascimento(int dia_nascimento, int mes_nascimento, int ano_nascimento) {//funcao responsavel por validar a data de nascimento do usuario com base em dia mes e ano

	time_t t = time(NULL);
	tm *ltm = localtime(&t);

	int ano = 1900 + ltm->tm_year;
	int mes = 1 + ltm->tm_mon;
	int dia = ltm->tm_mday;
	int hora = ltm->tm_hour;

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








#endif
