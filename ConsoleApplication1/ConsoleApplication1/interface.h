#ifndef INTERFACE_H//realizar a interface com o usuario
#define INTERFACE_H
#include<iostream>
#include<string>
#include"operacional.h"
using namespace std;
#include"validacoes.h"
void criar_user(Usuarios *users,Posts *posts);
void Mostra_menu(Usuarios *users,Posts *posts);
void timeline(string usuario,Posts *posts,Usuarios *users) {
	
	int opcao, opcao2;
	char post[280];
	cout << endl << "\t" << endl;
	exibir_posts(posts);
	cout << endl << "Usuario Logado:" << usuario << endl;
	cout << "Digite 1 para incluir um Post ou 2 para voltar ao menu principal";
	cin >> opcao;
	switch (opcao)
	{

		case 1:
			cout << "Post:" << endl;
			ler_post(posts,post,usuario);
			cout << "<1> para voltar a timeline";
				cin >> opcao2;
				if (opcao2 == 1) {
					timeline(usuario,posts,users);
					system("pause");
				}
				break;
		case 2:
			system("cls");
			Mostra_menu(users,posts);
			break;
		default:
			cout << endl << "opcao invalida";
			break;
	}

}

void solicita_usuario(Usuarios *users,Posts *posts) {
	string usuario, mensagem_erro;
	int senha, verifica_primeiro_usuario;
	
	
   
	
	do {
		cout << "Usuario:\t " << endl;
		cin >> usuario;
		cout << "Digite senha:" << endl;
		cin >> senha;
		if (!verificar_usuario_cadastrado(users,usuario,senha,mensagem_erro,verifica_primeiro_usuario)) {
			cout << mensagem_erro;
			system("pause");
			system("cls");
			if (verifica_primeiro_usuario == NULL) {
				criar_user(users,posts);
			}
		}
		else {
			system("cls");
			system("pause");
			cout << endl << "Bem Vindo" << endl;
			timeline(usuario,posts,users);
		}

	} while (!verificar_usuario_cadastrado(users, usuario, senha, mensagem_erro,verifica_primeiro_usuario));
}

void login(Usuarios *users,Posts *posts) {

	solicita_usuario(users,posts);
	
}

void criar_user(Usuarios *users,Posts *posts) {
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
			system("cls");
			cout << "Cadastro criado com sucesso" << endl;
			system("pause");
			system("cls");
			login(users,posts);
	

	
	



}




void Mostra_menu(Usuarios *users,Posts *posts) {
	int opcao;
	
	cout << "Selecione '1' para Logar, '2' para criar um usuario, '3' Sair" << endl;
	cin >> opcao;
	switch (opcao)
	{
	case 1:
		login(users,posts);
		break;
	case 2:
		criar_user(users,posts);
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << endl<<"Digite uma Opcao Valida" << endl;
		break;
	}


}






#endif