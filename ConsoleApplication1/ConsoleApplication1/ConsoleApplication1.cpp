// ConsoleApplication1.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include "interface.h"
#include"struct_usuario.h"

int main()
{
	Usuarios users;
	inicializa_lista(&users);
	Posts posts;
	inicializa_post(&posts);
	Mostra_menu(&users,&posts);

}

