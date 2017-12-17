#ifndef INTERFACE_H
#define INTERFACE_H
#include<iostream>
#include<string>
#include"operacional.h"
using namespace std;
#include"validacoes.h"
void criar_user(Usuarios *users);
void solicita_usuario(Usuarios *users) {
	string usuario, mensagem_erro;
	int senha, verifica_primeiro_usuario;
	
	
   
	
	do {
		cout << "Usuario:\t " << endl;
		cin >> usuario;
		cout << "Digite senha:" << endl;
		cin >> senha;
		if (!verificar_usuario_cadastrado(users,usuario,senha,mensagem_erro,verifica_primeiro_usuario)) {
			cout << mensagem_erro;
			if (verifica_primeiro_usuario == NULL) {
				criar_user(users);
			}
		}
		else {
			system("cls");
			system("pause");
			cout << endl << "Bem Vindo" << endl;
			timeline();
		}

	} while (!verificar_usuario_cadastrado(users, usuario, senha, mensagem_erro,verifica_primeiro_usuario));
}

void login(Usuarios *users) {

	solicita_usuario(users);
	
}

void criar_user(Usuarios *users) {
	string user, nome_completo, erro;
	char genero;
	int senha1, senha2, dia_nascimento, mes_nascimento, ano_nascimento;
	
	

	
	do {
		cout << "Nome_usuario";
		cin >> user;

		if (!buscar_elementos_iguais(users,user,erro)) {
			cout << erro << endl;
		}


	} while (!buscar_elementos_iguais(users, user, erro));
	//verifica_usuario_iguais() verificar se usuario ja existe;
	do {
		
		cout << "Senha:\t";
		cin >> senha1;
		cout << endl;
		cout << "Confirme a senha";
		cin >> senha2;
		if (valida_senha_cadastro(senha1, senha2,erro) == false) {
			cout << erro << endl;
		}
	} while (valida_senha_cadastro(senha1, senha2,erro) == false);
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
		do {
			cout << "Digite 'M' para masculino ou 'F' para feminino: " << endl;
			cin >> genero;
			if (!valida_genero(genero, erro)) {
				cout << erro << endl;
			}
		} while (!valida_genero(genero, erro));
			//adiciona_usuario(nome_completo, user, genero, senha1, dia_nascimento, mes_nascimento, ano_nascimento);
			inserir_usuario(users, user, nome_completo, senha1,dia_nascimento, mes_nascimento, ano_nascimento, genero);
			cout << "Cadastro criado com sucesso" << endl;
			system("pause");
			system("cls");
			mostrarElementos(users);
			system("pause");
			login(users);
	

	
	



}




void Mostra_menu() {
	int opcao;
	Usuarios users;
	inicializa_lista(&users);
	cout << "Selecione '1' para Logar, '2' para criar um usuario, '3' Sair" << endl;
	cin >> opcao;
	switch (opcao)
	{
	case 1:
		login(&users);
		break;
	case 2:
		criar_user(&users);
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