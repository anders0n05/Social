#ifndef INTERFACE_H
#define INTERFACE_H
#include<iostream>
#include<string>
#include"operacional.h"
using namespace std;
#include"validacoes.h"
void solicita_senha() {
	int senha


		do {
			cout << "senha:\t" << endl;
			cin << senha;
			if (valida_senha() == false) {
				cout << "Senha Invalida" << endl;
			}
			else {
				timeline();
			}
		} while (valida_senha() == false);
	
}
void solicita_usuario() {
	string usuario;
	do {
		cout << "Usuario:\t " << endl;
		cin >> usuario;
		
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
	string user, nome_completo, genero;
	int senha, int senha2, dia_nascimento, mes_nascimento, ano_nascimento;
	cout << "Nome_usuario";
	cin >> user;

	//verifica_usuario_iguais() verificar se usuario ja existe;
	do {
		cout << "Senha:\t";
		cin >> senha1;
		cout << "Confirme a senha";
		cin >> senha2;
		if (valida_senha_cadastro(senha1, senha2) == false) {
			cout << "As senhas nao conferem";
		}
	} while (valida_senha_cadastro(senha1, senha2) == false);
	cout << "Nome Completo: \t";
	cin >> nome_completo;
	
	do {
		cout << "Data Nascimento:";
		
		cin >> dia_nascimento;
		cin >> mes_nascimento;
		cin >> ano_nascimento;
		if (!valida_data_nascimento(dia_nascimento, mes_nascimento,ano_nascimento)) {
			cout << "Voce nao tem idade para criar a rede social" << endl;
		}
		else {
			cout << "Genero:\t" << endl;
			cin >> genero;
			adiciona_usuario(nome_completo, user, genero, senha1, dia_nascimento, mes_nascimento, ano_nascimento);
			cout << "Cadastro criado com sucesso" << endl;
			system("cls");
			timeline();
		}
	
	} while (!valida_data_nascimento(dia_nascimento, mes_nascimento, ano_nascimento));

	
	



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