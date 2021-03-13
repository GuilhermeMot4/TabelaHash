/* Alunos: Eduardo Purkote e Guilherme Mota 
GRR's      20182960          20197268
   **Arquivo do Programa Principal**
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "myht.c"

int main()
{
  FILE *entrada, *saida;
  tabelaHash tabelaHash1[M];
  tabelaHash tabelaHash2[M];
  tabelaHash tabelaHash3[2*M];
  int i, j, k,  chave;
  //int *resultBusca; 
  char op;

  entrada = stdin;
  if(!entrada)
  {
    printf("Erro no arquivo de entrada!\n");
    exit(1);
  }

  //inicia as tabelas 
  iniciarHash(tabelaHash1, "T1");
  iniciarHash(tabelaHash2, "T2");

  //leitura
  op = getchar();
  while(op != EOF)
  {
    scanf("%i", &chave);
	switch(op)
    {
	  case 'i':
	    inserir(chave, tabelaHash1, tabelaHash2);	
		break;
	  case 'r':
		remover(chave, tabelaHash1, tabelaHash2);
		break;

	}
	op = getchar();
	if(op == '\n')
	  op = getchar();
  }

  //define e imprime no arquivo de saída
  saida = stdout;
  if(!saida)
  {
    printf("Erro no arquivo de saída!\n");
    exit(1);
  }
  else
  {
	for (i = 0; i < M; i++)
	{
	  tabelaHash3[i].indice = tabelaHash1[i].indice;
	  tabelaHash3[i].valor = tabelaHash1[i].valor;
	  strcpy(tabelaHash3[i].tabela, tabelaHash1[i].tabela);
	  tabelaHash3[i].vazio = tabelaHash1[i].vazio;
	}


	for (j = 0; j < M; j++)
	{
	  tabelaHash3[j + M].indice = tabelaHash2[j].indice;
	  tabelaHash3[j + M].valor = tabelaHash2[j].valor;
	  strcpy(tabelaHash3[j + M].tabela, tabelaHash2[j].tabela);
	  tabelaHash3[j + M].vazio = tabelaHash2[j].vazio;
	}

	qsort(tabelaHash3, 2*M, sizeof(tabelaHash), compara);

	for (k = 0; k < M*2; k++)
	{
	    	if(tabelaHash3[k].vazio == 0)
			  fprintf(saida, "%i,%s,%i\n", tabelaHash3[k].valor, tabelaHash3[k].tabela ,tabelaHash3[k].indice);
	}
  }
    
  fclose(entrada);
  fclose(saida);

  return 0;
}
