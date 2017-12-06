#ifndef INTERFACE_H
#define INTERFACE_H
#include<iostream>
#include<string>
using namespace std;

int solicita_senha() {
	int senha


		do {
			cout << "senha:\t" << endl;
			cin << senha;
			if (valida_senha() == false) {
				cout << "Senha Invalida" << endl;
			}
		} while (valida_senha() == false);
	return senha
}
string solicita_usuario() {
	string usuario;
	do {
		cout << "Usuario:\t " << endl;
		cin >> usuario;
		return usuario;
		if (valida_usuario() == true) {//criar funcao que valida o usuario
			solicita_senha();//caso passe ira solicitar senha
		}
		else {
			cout << "Usuario nao existe" << endl;
		}
	} while (valida_usuario() == false);
}

void login() {

	solicita_usuario();
}

void criar_user() {
	string user, nome_completo;
	int senha, int senha2;
	cout << "Nome_usuario";
	cin >> user;

	//verifica_usuario_iguais() verificar se usuario ja existe;
	do {
		cout << "Senha:\t";
		cin >> senha1;
		cout << "Confirme a senha";
		cin >> senha2;
		if (valida_senha_cadastro(senha1, senha2) == false) {
			cou << "As senhas nao conferem";
		}
	} while (valida_senha_cadastro(senha1, senha2) == false);
	cout << "Nome Completo: \t";
	cin >> nome_completo;
	cout << "Data Nascimento:";//continuar data nascimento;
	cin << dia;
	cin << mes
	cin << ano;
}




void Mostra_menu() {
	int opcao;
	cout << "Selecione '1' para Logar, '2' para criar um usuario, '3' Sair" << endl;
	cin >> opcao;
	switch (opcao)
	{
	case 1:
		//login();
		break;
	case 2:
		//criar_user();
		break;
	case 3:
		//encerro o programa
		break;
	default:
		cout << endl<<"Digite uma Opcao Valida" << endl;
		break;
	}


}






#endif