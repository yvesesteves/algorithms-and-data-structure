#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct individuo
{
  int codigo_genetico[10]; // valores binarios aleatorios
  float aptidao_abs;       // pontencial de cada individuo (0.0 <= aptidao <= 10.0)
  float aptidao_relativa;  // deve ser calculada em tempo de execução...
};
typedef struct individuo individuo;

struct populacao
{
  individuo *pop; // um vetor de N individuos
  int tamanho;    // tamanho N da população (N = 100)
};
typedef struct populacao populacao;

float numero_aleatorio(int tam)
{
  float sorteio = (((float)rand()) / ((float)RAND_MAX)) * tam;
  return sorteio;
}

int numero_aleatorio_bin()
{
  int sorteio = (rand() % 100);
  return sorteio % 2;
}

void roleta(populacao *pop, int qtd_ind)
{
  float sorteio = 0;
  float soma_apt_rel = 0;
  for (int j = 0; j < 2; j++)
  {
    soma_apt_rel = 0;
    sorteio = numero_aleatorio(1);
    printf("\n================");
    printf("\nsorteio: %f", sorteio);
    for (int i = 0; i < qtd_ind; i++)
    {
      soma_apt_rel = soma_apt_rel + pop->pop[i].aptidao_relativa;
      if (soma_apt_rel >= sorteio)
      {
        printf("\nsum: %f", soma_apt_rel);
        printf("\nindividuo %d", i + 1);
        printf("\napt rel: %f", pop->pop[i].aptidao_relativa);
        printf("\napt abs: %f", pop->pop[i].aptidao_abs);
        printf("\ncodigo genetico: ");
        for (int k = 0; k < 10; k++)
        {
          printf("%d ", pop->pop[i].codigo_genetico[k]);
        }
        printf("\n");
        break;
      }
    }
  }
}

int main()
{
  int tam_pop = 0;
  float sorteio = 0;
  int sorteio_bin = 0;
  int num = 0;
  float soma_aptidao = 0;
  srand(time(NULL));
  populacao populacao;

  printf("Entre com a quantidade de individuos: ");
  scanf("%d", &tam_pop);
  populacao.tamanho = tam_pop;

  populacao.pop = (individuo *)malloc(tam_pop * sizeof(individuo));

  for (int i = 0; i < tam_pop; i++)
  {
    sorteio = numero_aleatorio(10);
    populacao.pop[i].aptidao_abs = sorteio;
    soma_aptidao = soma_aptidao + sorteio;
    for (int j = 0; j < 10; j++)
    {
      sorteio_bin = numero_aleatorio_bin();
      populacao.pop[i].codigo_genetico[j] = sorteio_bin;
    }
  }

  for (int i = 0; i < tam_pop; i++)
  {
    populacao.pop[i].aptidao_relativa = populacao.pop[i].aptidao_abs / soma_aptidao;
  }

  roleta(&populacao, populacao.tamanho);

  return 0;
}