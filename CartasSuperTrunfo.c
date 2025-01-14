#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CARTAS_POR_ESTADO 4
#define MAX_CARTAS (NUM_ESTADOS * CARTAS_POR_ESTADO)

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void cadastrarCarta(Carta cartas[], int *totalCartas);
void exibirCarta(Carta carta);
void exibirTodasAsCartas(Carta cartas[], int totalCartas);

int main() {
    Carta cartas[MAX_CARTAS];
    int totalCartas = 0;
    int opcao;

    do {
        printf("\n=== Sistema Super Trunfo: Países ===\n");
        printf("1. Cadastrar uma carta\n");
        printf("2. Exibir todas as cartas\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                if (totalCartas < MAX_CARTAS) {
                    cadastrarCarta(cartas, &totalCartas);
                } else {
                    printf("Limite de cartas atingido!\n");
                }
                break;
            case 2:
                if (totalCartas > 0) {
                    exibirTodasAsCartas(cartas, totalCartas);
                } else {
                    printf("Nenhuma carta cadastrada ainda.\n");
                }
                break;
            case 3:
                printf("Encerrando o sistema. Obrigado por jogar!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

void cadastrarCarta(Carta cartas[], int *totalCartas) {
    Carta novaCarta;

    printf("Digite o estado (A-H): ");
    scanf(" %c", &novaCarta.estado);

    printf("Digite o codigo da carta (ex. A01): ");
    scanf("%s", novaCarta.codigo);

    printf("Digite o nome da cidade: ");
    getchar();
    fgets(novaCarta.nomeCidade, 50, stdin);
    novaCarta.nomeCidade[strcspn(novaCarta.nomeCidade, "\n")] = '\0'; 

    printf("Digite a populacao: ");
    scanf("%d", &novaCarta.populacao);

    printf("Digite a area em km²: ");
    scanf("%f", &novaCarta.area);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &novaCarta.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &novaCarta.pontosTuristicos);

    cartas[*totalCartas] = novaCarta;
    (*totalCartas)++;

    printf("\nCarta cadastrada com sucesso!\n");
    exibirCarta(novaCarta);
}

void exibirCarta(Carta carta) {
    printf("\n--- Dados da Carta ---\n");
    printf("Estado: %c\n", carta.estado);
    printf("Codigo da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.pontosTuristicos);
}

void exibirTodasAsCartas(Carta cartas[], int totalCartas) {
    printf("\n=== Todas as Cartas Cadastradas ===\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("\nCarta %d:\n", i + 1);
        exibirCarta(cartas[i]);
    }
}
