#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int busca_binaria(int tamanho, int *v , int busca);
int ordenar(int *vetor, int tamanho)
{
	
	int aux, i, j, busca, num;
	for( i = 0; i < tamanho ; i++)
	{
		for ( j = 0; j < tamanho; j++)
		{
			if (vetor[i] < vetor[j])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
	cout<<"\n Vetor ordenado "<<endl;
	
	for(i = 0; i < tamanho; i++)
	{
		cout<<vetor[i] << " - ";
	}
	cout<<"\n";
	cout<<"Informe o numero que deseja buscar:";
	cin>>busca;
	
	cout <<"O numero "<<busca<<" esta na posicao: "<<busca_binaria(tamanho, vetor, busca)<<endl;
	
}

int busca_binaria(int tamanho, int *v , int busca)
{
	int ini = 0;
	int fim = tamanho -1;
	int meio;
	
	while(ini <= fim)
	{
		meio = (ini + fim )/2;
		if(busca < v[meio])
		{
			fim = meio -1;
			
		}
		else if(busca > v[meio])
		{
			ini = meio +1;
		}
		else
		{
			return meio;
		}
	}return -1
	
}

int main()
{
	
	int vetor[6], vetor_ordenado[6];
	int i, num, tamanho;
	
	for(i = 0; i < 6; i++)
	{
		cout<<"Informe o "<<i<< " numero: ";
		cin>>vetor[i];		
	}
	tamanho = sizeof(vetor) / sizeof(int);
	cout<<"\n Tamanho do vetor: "<<tamanho;
	ordenar(vetor, tamanho);
	
		
}
