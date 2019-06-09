#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define tamanho 3

using namespace std;

typedef struct pilha
{
	int item[tamanho];
	int topo;
	
}Pilha;

//Para criar uma pilha inicia ele com valor -1
void cria_pilha(Pilha *p)
{
	p->topo = -1;
}

int vazia(Pilha *p)
{
	if(p->topo == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int cheia(Pilha *p)
{
	if(p->topo == tamanho-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
//Função para inserção de dados no topo da pilha
void Insere(Pilha *p, int num)
{
	
	if(cheia(p) == 1) //Verifica se a pilha esta cheia
	{
		cout<<"Pilha esta cheia"<<endl; 
	}
	else 
	{
		//Inserção no topo
		p->topo++;
		p->item[p->topo] = num;
	}
}
//Funcoa para remoção de um elemento na pilha
int Remove(Pilha *p)
{
	int aux;
	if(vazia(p) == 1)
	{
		cout<<"Impossivel remover o elemento, a pilha esta vazia"<<endl;
	}
	else
	{
		aux = p->item[p->topo];
		p->topo--;
		return aux;
	}
}

int main()
{
	Pilha *p = (Pilha *)malloc(sizeof(Pilha));
	int num, i;
	
	if( p == NULL)
	{
		cout<<"Falha ao alocar memoria no sistema"<<endl;
	}
	else
	{
		cria_pilha(p);
	
		for(i = 0; i < tamanho; i ++)
		{
			cout<<"Informe o "<<i+1 <<" numero: ";
			cin>>num;
			Insere(p, num);
		}
		cout<<"Desempilhando..."<<endl;
		while(p->topo != NULL)
		{
			cout<<p->item[p->topo]<<endl;
			num = Remove(p);
			cout<<num<<endl;
			
		}
	}
	
}
