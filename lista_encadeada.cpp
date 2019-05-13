#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct lista Lista;
struct lista
{
	int cod;
	char nome;
	Lista* prox;
};
//Criar Lista
Lista* cria_Lista(void)
{
	return NULL;
}
//Adicionar elemento na lista
Lista* insere(Lista* lst, int cod, char nome)
{
	Lista* novo =(Lista *)malloc(sizeof(Lista));
	novo->cod = cod;
	novo->nome = nome;
	novo->prox = lst;
	return novo;
}


Lista* insere_posicao(Lista* lst, int posicao, int codigo, char nome)
{
	int cont = 1;
	Lista* p = lst;
	Lista* novo = (Lista* )malloc(sizeof(Lista* ));
	while(cont != posicao)
	{
		p = p->prox;
		cont++;
	}
	novo->cod = codigo;
	novo->nome = nome;
	p->prox = novo;
	return lst;
}

//Lista vazia
int vazia(Lista* lst)
{
	return (lst == NULL);
}
Lista* imprime(Lista* lst)
{
	Lista *p;
	
	for(p=lst;p != NULL; p =p->prox)
	{
		cout<<"Codigo: "<< p->cod <<" Nome do Livro: "<< p->nome<<endl;
	}
}
void limpa_tela()
{
	system("cls");
}
//Remover elemento da lista
Lista* remove(Lista *lst, int cod)
{
	Lista* p = lst;
	Lista *a = NULL;
	while(p != NULL && p->cod != cod)
	{
		a = p;
		p = p->prox;
	}
	if(p == NULL)
	{
		return(lst );
	
	}
	if (a == NULL){
		lst=p->prox;  
	
    } else
	{
		a->prox = p->prox; 
	
	}
	free(p);
	return lst;
}
Lista* busca(Lista* lst, int codigo)
{
	Lista* p;
	for(p=lst; p!= NULL; p=p->prox){
	if (p->cod == codigo)
		cout<<"Codigo: "<< p->cod <<" Nome do Livro: "<< p->nome<<endl;
		return p;
    }
	return NULL;   //NÃO ACHOU O ELEMENTO
}
int main()
{
	int opcao, qte_elementos, codigo,posicao;
	char nome;
	Lista * lst;
	lst = cria_Lista();	
	do
	{
		cout<<"-----------------------------------"<<endl;
		cout<<"[+] - MENU PRINCIPAL"<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"[1] Exibir Cadastro"<<endl;
		cout<<"[2] Adicionar livro"<<endl;
		cout<<"[3] Remover livro"<<endl;
		cout<<"[4] Buscar livro"<<endl;
		cout<<"[5] Tamanho da Lista"<<endl;
		cout<<"[6] Adicionar na posicao"<<endl;
		cout<<"Opcao:";
		cin>>opcao;		
		switch(opcao)
		{
			case 1:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[+] - Livros cadastrados"<<endl;
				cout<<"-----------------------------------"<<endl;
				imprime(lst);
				cout<<"-----------------------------------"<<endl;
				break;
			case 2:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[+] - Cadastro de Livros:"<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"Informe a quantidade de elementos:";
				cin>>qte_elementos;
				for(int i;i < qte_elementos;i++)
				{
					cout<<"--> Codigo:"<<endl;
					cin>>codigo;
					cout<<"-->Nome:"<<endl;
					cin>>nome;
					lst = insere(lst, codigo,nome);
				}
				cout<<"-----------------------------------"<<endl;
				limpa_tela();
				break;
			case 3:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[-] - Remocao de Livros"<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"Insira o codigo para remocao: ";
				cin>>codigo;
				lst = remove(lst, codigo);
				cout<<"Elemento removido"<<endl;
				cout<<"-----------------------------------"<<endl;
				break;
			case 4:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[!] - Buscar livros"<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"Pesquise o codigo: ";
				cin>>codigo;
				if(busca(lst,codigo) == NULL) 
				{
					cout<<"O livro nao esta adicionado na lista"<<endl;
				}
				else{
					cout<<"O livro esta adicionado na lista"<<endl;
				}
				break;
			case 5:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[!] - Tamanho da Lista"<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"Tamanho da Lista: "<<sizeof(lst)<<endl;
				break;
			case 6:
				limpa_tela();
				cout<<"-----------------------------------"<<endl;
				cout<<"[+] - Cadastro de Livros:"<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"Informe a quantidade de elementos:";
				cin>>qte_elementos;

				for(int i;i < qte_elementos;i++)
				{
					cout<<"Informe a posicao:";
					cin>>posicao;
					cout<<"--> Codigo:"<<endl;
					cin>>codigo;
					cout<<"-->Nome:"<<endl;
					cin>>nome;
					lst = insere_posicao(lst, posicao,codigo,nome);
				}
				cout<<"-----------------------------------"<<endl;
				limpa_tela();
				break;
			default:
				cout<<"Opcao invalida"<<endl;
		}		
	}
	while(opcao);		
}
