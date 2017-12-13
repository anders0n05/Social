#ifndef INTERFACE_H
#define INTERFACE_H
#include<iostream>
#include<string>
#include"operacional.h"
using namespace std;
#include"validacoes.h"

void solicita_usuario() {
	string usuario, mensagem_erro;
	int senha;

	allusers *funcoes=NULL;
	do {
		cout << "Usuario:\t " << endl;
		cin >> usuario;
		cout << "Digite senha:" << endl;
		cin >> senha;
		if (!funcoes->valida_usuario_logado(usuario, senha, mensagem_erro)) {
			cout << mensagem_erro;
		}
		else {
			cout << endl << "Bem Vindo" << endl;
			timeline();
		}

	} while (funcoes->valida_usuario_logado(usuario,senha,mensagem_erro) == false);
}

void login() {

	solicita_usuario();
	
}

void criar_user() {
	string user, nome_completo, genero, erro;
	int senha1, senha2, dia_nascimento, mes_nascimento, ano_nascimento;



	allusers *funcoes;//preciso inicializar com algo aqui estou pesquisando
	do {
		cout << "Nome_usuario";
		cin >> user;

		if (!funcoes->valida_usuario_nome_igual(user, erro)) {
			cout << erro;
		}


	} while (!funcoes->valida_usuario_nome_igual(user,erro));
	//verifica_usuario_iguais() verificar se usuario ja existe;
	do {
		
		cout << "Senha:\t";
		cin >> senha1;
		cout << endl;
		cout << "Confirme a senha";
		cin >> senha2;
		if (valida_senha_cadastro(senha1, senha2) == false) {
			cout <<endl<< "As senhas nao conferem";
		}
	} while (valida_senha_cadastro(senha1, senha2) == false);
	cout << "Nome Completo: \t";
	cin >> nome_completo;
	
	do {
			
			cout << "Data Nascimento:";
			cout << "dia" << endl;
			cin >> dia_nascimento;
			cout << "Mes" << endl;
			cin >> mes_nascimento;
			cout << "Ano" << endl;
			cin >> ano_nascimento;
			if (!valida_data_nascimento(dia_nascimento, mes_nascimento, ano_nascimento)) {
			cout << "Voce nao tem idade para criar a rede social" << endl;
			}
		} while (!valida_data_nascimento(dia_nascimento, mes_nascimento, ano_nascimento));
		
			cout << "Genero:\t" << endl;
			cin >> genero;
			adiciona_usuario(nome_completo, user, genero, senha1, dia_nascimento, mes_nascimento, ano_nascimento);
			cout << "Cadastro criado com sucesso" << endl;
			system("cls");
			timeline();
		
	
	

	
	



}




void Mostra_menu() {
	int opcao;
	cout << "Selecione '1' para Logar, '2' para criar um usuario, '3' Sair" << endl;
	cin >> opcao;
	switch (opcao)
	{
	case 1:
		login();
		break;
	case 2:
		criar_user();
		break;
	case 3:
		system("end");
		break;
	default:
		cout << endl<<"Digite uma Opcao Valida" << endl;
		break;
	}


}






#endif