/*Altere o programa acima inserindo as seguintes funções:
Atividade de Estruturas de Dados 
Resolução do Exercicio envolvendo Lista Duplamente encadeada
Desenvolvido por Leonardo Ribeiro 
- Inserir uma pessoa no final da lista;
- Remover a última pessoa da lista;
- Remover determinada pessoa da lista, cujo nome seja informado pelo usuário;
- Percorrer a lista de traz para frente.
- Ordenar a lista
*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<string.h>

using namespace std;

typedef struct pessoas
{
	char nome[30];
	int idade;
	char sexo;
}Pessoas;

typedef struct lista
{
	Pessoas p;
	struct lista *prox;
	struct lista *ant;
}Lista;

void limpa_tela()
{
	system("cls");
}
//Função para criar uma lista 
Lista *cria_lista(void)
{
	return NULL;
}
//Funcao para inserir no inicio da lista
Lista *InsereInicio(Lista *lst)
{
	Lista *novo;
	novo = (Lista* )malloc(sizeof(Lista));
	fflush(stdin);
	cout<<"Nome: ";
	gets(novo->p.nome);
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

Lista *InsereFim(Lista *lst)
{
	Lista *p = lst;
	Lista *novo;
	int cont = 1;
	novo  = (Lista *)malloc(sizeof(Lista));
	while(p->prox != NULL)
	{
		p = p->prox;
		cont++;	
	}
	fflush(stdin);
	cout<<"Nome: ";
	gets(novo->p.nome);
	cout<<"Idade: ";
	cin>>novo->p.idade;
	cout<<"Sexo: ";
	cin>>novo->p.sexo;
	
	novo->prox = NULL;
	novo->ant = p;
	p->prox = novo;
	return lst;		
}

int removeFim(Lista *lst)
{
	
	if(lst == NULL)
	{
		cout<<"[!] Lista Vazia , impossivel remover elementos"<<endl;
	}
	else
	{
		Lista *aux = lst;
		while(aux->prox != NULL)
			aux = aux->prox;
			cout<<aux->p.nome<<" foi removido da lista "<<endl;
		if(aux->ant == NULL)
			lst = aux->prox;
		else
		{
			aux->ant->prox = NULL;
		}
		free(aux);	
		return 1;
	}
}


Lista *removeNome(Lista *lst)
{
	Lista *ant = NULL;
	Lista *p = lst;
	
	char nome[30];
	fflush(stdin);
	cout<<"Informe o nome:";
	gets(nome);
	
	while(p != NULL)
	{
		if(strcmp(p->p.nome , nome) == 0)
			break;	
		ant = p;
		p = p->prox;	
	}
	if(p == NULL)
	{
		return lst;
	}
	if(ant == NULL)
	{
		p = p->prox;
		cout<<p->p.nome<<" foi removido da lista"<<endl;
		free(p);
	}
	else
	{
		ant->prox = p->prox;
		cout<<p->p.nome<<" foi removido da lista"<<endl;
	}
	return lst;
}

//Funcao para pecorrer minha lista duplamente encadeada
void Imprimir(Lista *lst)
{
	Lista *pecorre;
	
	if(lst == NULL)//Verificar se a lista esta vazia
	{
		cout<<"[!] - A lista esta vazia"<<endl;
	}
	else
	{
		for(pecorre = lst; pecorre != NULL; pecorre = pecorre->prox)
		{
			cout<<"Nome:"<<pecorre->p.nome<<endl<<"Idade:"<<pecorre->p.idade<<" anos "<<endl<<"Sexo:"<<pecorre->p.sexo<<endl;
			cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
		}
	}
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
}

void Imprimir_Inverso(Lista* lst)
{
	Lista *pecorre = lst;
	if(lst == NULL)
	{
		cout<<"[!] - Lista vazia esta vazia"<<endl;
	}
	else
	{
		while(pecorre->prox != NULL)
		{
			pecorre = pecorre->prox;
		}
		for(pecorre; pecorre != NULL;pecorre= pecorre->ant)
		{
			cout<<"Nome:"<<pecorre->p.nome<<endl<<"Idade:"<<pecorre->p.idade<<" anos "<<endl<<"Sexo:"<<pecorre->p.sexo<<endl;
			cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
		}	
	}
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
}

void Ordenar(Lista *lst)
{
	Lista *aux;
	Lista *no = lst;
	Pessoas dados;
	
	if(lst == NULL)
	{
		cout<<"[!] Lista vazia, impossivel ordenar a lista"<<endl;
	}
	else
	{
		for(no ; no != NULL; no = no->prox)
		{
			for(aux = no->prox; aux != NULL; aux = aux->prox)
			{
				if(strcmp(no->p.nome, aux->p.nome) > 0)
				{
					dados = no->p;
					no->p = aux->p;
					aux->p = dados;
				}
			}	
		}
		cout<<"Lista ordenada com sucesso"<<endl;
	}
}
//Função principal
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
		cout<<"[7] - Remover pelo fim"<<endl;
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
				system("pause>>NULL");
				break;
			case 2:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[+] - Cadastro no inicio"<<endl;
				cout<<"-----------------------------------"<<endl;
				lst = InsereInicio(lst);
				break;
			case 3:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[+] - Cadastro no Fim"<<endl;
				cout<<"-----------------------------------"<<endl;
				lst = InsereFim(lst);
				break;	
			case 4:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[-] - Removendo pelo nome"<<endl;
				cout<<"-----------------------------------"<<endl;
				lst =removeNome(lst);
				system("pause>>NULL");
				break;
			case 5:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[-] - Imprimindo ordem inversa "<<endl;
				cout<<"-----------------------------------"<<endl;
				Imprimir_Inverso(lst);
				system("pause>>NULL");
				break;
			case 6:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[-] - Ordernar Lista "<<endl;
				cout<<"-----------------------------------"<<endl;
				Ordenar(lst);
				system("pause>>NULL");
				break;
			case 7:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[-] - Removendo pelo fim "<<endl;
				cout<<"-----------------------------------"<<endl;
				removeFim(lst);
				system("pause>>NULL");
				break;
			default:
				cout<<"Opcao incorreta \n";
		}
		
		Sleep(1000);
		limpa_tela();
	}
	while(resp);
}
