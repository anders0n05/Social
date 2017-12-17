#ifndef STRUCT_POST_H
#define STRUCT_POST_H
#include<string>
using namespace std;

typedef struct Post {
	string post;
	string assinatura, usuario;
	struct Post *proximo;
	Post(string post, string usuario) {
		this->post = post;
		this->assinatura = usuario;
		this->usuario = usuario;
		this->proximo = NULL;
	}

	
}Post;


typedef struct Lista_Post {

	Post *inicio;
	Post *final;

}Posts;












#endif