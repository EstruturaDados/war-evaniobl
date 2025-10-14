    // bibliotecas 
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    // Constantes globais

    #define MAX_TERRITORIO 5
    #define TAMANHO_STRING 30

    // Definição de estrutura (struct)
    struct Territorio { 
        char nome[TAMANHO_STRING];
        char cor_exercito[TAMANHO_STRING];
        int numero_tropas;
    };

    //Função para limpar o buffer de entrada
    void LimparBufferEntrada () {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    
    }

    void exibirMapa(struct Territorio vetor[], int qtd) {
        int i;
        for (i = 0; i < qtd; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Cor: %s\n", vetor[i].cor_exercito);
        printf("Tropas: %d\n", vetor[i].numero_tropas);
        }
    }

    // Função Main (Principal)
    int main() {

        struct Territorio exercito [MAX_TERRITORIO]; // vetor que vai do "0 ao 4" (5 total)
        int indice_territorio = 0;
        int opcao; // vai ser util na criação de um menu (switch)

    for (indice_territorio < MAX_TERRITORIO){   // Loop para cadastro dentro do vetor
        printf("\n--- Cadastro do território %d ---\n", indice_territorio + 1); //Contador de território durante cadastro
        printf ("Digite o NOME do território: ");
        fgets (exercito[indice_territorio].nome, TAMANHO_STRING, stdin);

        printf ("Digite a COR do território: ");
        fgets (exercito[indice_territorio].cor_exercito, TAMANHO_STRING, stdin);

        // Remove o \n capturado pelo fgets
        exercito[indice_territorio].nome[strcspn(exercito[indice_territorio].nome, "\n")] = '\0';
        exercito[indice_territorio].cor_exercito[strcspn(exercito[indice_territorio].cor_exercito, "\n")] = '\0';

        printf ("Digite o NÚMERO DE TROPAS do território: ");
        scanf ("%d", &exercito[indice_territorio].numero_tropas);

        LimparBufferEntrada();
        indice_territorio++;

        printf ("Território cadastrado com sucesso!\n");
        }

        exibirMapa(exercito, indice_territorio); //chamando função para imprimir situação atual do mapa

    }