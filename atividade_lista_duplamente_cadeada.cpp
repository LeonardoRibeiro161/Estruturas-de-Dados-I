#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


typedef struct DPessoa
{
	char nome[30];
	int idade;
	char sexo;
	
}Pessoa;

typedef struct lista
{
	Pessoa p;
	struct lista *ant;
	struct lista *prox;
}Lista;

//Funcao para inserir no inicio da lista
Lista* cria_lista(void)
{
	return NULL;
}

Lista *insereInicio(Lista* lst)
{
	Lista *novo;
	char nome[30],sexo;
	int idade;
	
	novo = (Lista* )malloc(sizeof(Lista));
	cout<<"Nome: ";
	cin>>novo->p.nome;
	cout<<"Idade: ";
	cin>>novo->p.idade;
	cout<<"Sexo: ";
	cin>>novo->p.sexo;
	
	novo->prox = lst;
	novo->ant = NULL;
	
	if(lst != NULL)
	{
		lst->ant = novo;
		return novo;
	}
}


void Imprimir(Lista *lst)
{
	Lista* pecorre;
	for(pecorre = lst; pecorre != NULL; pecorre = pecorre->prox)
	{
		cout<<"Nome :"<<pecorre->p.nome <<" Idade: "<<pecorre->p.idade <<" Sexo: "<<pecorre->p.sexo<<endl;
	}
}

void limpa_tela()
{
	system("cls");
}
int main()
{
	Lista *lst;
	lst = cria_lista();
	int resp;
	do
	{
		cout<<"[1] - Exibir lista"<<endl;
		cout<<"[2] - Adicionar no inicio"<<endl;
		cout<<"[3] - Adicionar no fim"<<endl;	
		cout<<"[4] - Remover fim da lista"<<endl;
		cout<<"[5] - Remover pelo nome"<<endl;
		cout<<"[6] - Percorre a lista de tras para frente"<<endl;
		cout<<"[7] - Ordernar lista"<<endl;
		cout<<"Opcao: "<<endl;
		cin>>resp;
		switch(resp)
		{
			case 1:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[+] - Pessoas cadastradas"<<endl;
				cout<<"-----------------------------------"<<endl;
				Imprimir(lst);
				break;
			case 2:
			limpa_tela();
			cout<<"-----------------------------------"<<endl;
			cout<<"[+] - Cadastro no inicio"<<endl;
			cout<<"-----------------------------------"<<endl;
			lst = insereInicio(lst);	
		}
	}
	while(resp);
}
/*Altere o programa acima inserindo as seguintes funções:
- Inserir uma pessoa no final da lista;
- Remover a última pessoa da lista;
- Remover determinada pessoa da lista, cujo nome seja informado pelo usuário;
- Percorrer a lista de traz para frente.
- Ordenar a lista
*/
