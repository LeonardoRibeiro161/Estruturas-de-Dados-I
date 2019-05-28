#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
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

Lista *insereFim(Lista* lst)
{
	Lista *novo;
	Lista *p = lst;
	char nome[30],sexo;
	int idade;
	int cont = 1;
	novo = (Lista* )malloc(sizeof(Lista));
	while(p->prox != NULL)
	{
		p = p->prox;
		cont++;
	}
	cout<<"Nome: ";
	cin>>novo->p.nome;
	cout<<"Idade: ";
	cin>>novo->p.idade;
	cout<<"Sexo: ";
	cin>>novo->p.sexo;
	
	novo->prox = NULL;
	novo->ant = p;
	p->prox = novo;
	
	return lst;
}

Lista *removeNome(Lista* lst)
{
	Lista *ant = NULL;
	Lista *p = lst;
	
	char nome[30];
	cout<<"Informe o nome: ";
	cin>>nome;
	while(p != NULL && strcmp(p->p.nome, nome) == 1)
	{
		ant = p;
		p = p->prox;
	}
	if(p == NULL)
	{
		return lst;
	}
	if(ant == NULL)
	{
		lst = p->prox;
	}
	else
	{
		ant->prox = p->prox;
	}

	return lst;
}

void Imprimir(Lista *lst)
{
	Lista* pecorre;
	
	if(lst == NULL)
	{
		cout<<"Lista vazia"<<endl;
	}
	else
	{
		for(pecorre = lst; pecorre != NULL; pecorre = pecorre->prox)
		{
			cout<<"Nome:"<<pecorre->p.nome <<" Idade: "<<pecorre->p.idade <<" Sexo: "<<pecorre->p.sexo<<endl;
		}
	}
	
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
}

void ImprimirTraz(Lista *lst)
{
	Lista *pecorre;
	Lista *p_inverso;
	if(lst == NULL)
	{
		cout<<"Lista vazia"<<endl;
	}
	else
	{
		while(pecorre->prox != NULL)
		{
			pecorre = pecorre->prox;
		}
		p_inverso = pecorre;
		for(; p_inverso != NULL; p_inverso->ant)
		{
			cout<<"Nome:"<< p_inverso->p.nome <<" Idade: "<< p_inverso->p.idade <<" Sexo: "<< p_inverso->p.sexo<<endl;
		}
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
		cout<<"[4] - Remover pelo nome"<<endl;
		cout<<"[5] - Percorre a lista de tras para frente"<<endl;
		cout<<"[6] - Ordernar lista"<<endl;
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
				system("pause");
				break;
			case 2:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[+] - Cadastro no inicio"<<endl;
				cout<<"-----------------------------------"<<endl;
				lst = insereInicio(lst);
				break;
			case 3:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[+] - Cadastro no Fim"<<endl;
				cout<<"-----------------------------------"<<endl;
				lst = insereFim(lst);
				break;	
			case 4:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[-] - Removendo pelo nome"<<endl;
				cout<<"-----------------------------------"<<endl;
				lst =removeNome(lst);
				break;
			case 5:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[-] - Imprimindo ordem inversa "<<endl;
				cout<<"-----------------------------------"<<endl;
				ImprimirTraz(lst);
				system("pause");
				break;
			default:
				cout<<"Opcao incorreta \n";
		}
		
		Sleep(1000);
		limpa_tela();
	}
	while(resp);
}
/*Altere o programa acima inserindo as seguintes funções:
- Inserir uma pessoa no final da lista; ok
- Remover a última pessoa da lista; ok
- Remover determinada pessoa da lista, cujo nome seja informado pelo usuário;
- Percorrer a lista de traz para frente.
- Ordenar a lista
*/
