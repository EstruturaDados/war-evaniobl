    // bibliotecas 
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    // Definição de estrutura (struct)
    typedef struct {
        char nome[30];
        char cor_exercito[10];
        int numero_tropas;
    } Territorio;

    //Função para limpar o buffer de entrada
    void LimparBufferEntrada () {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

    }

    // Parâmetros:
    //   - Territorio *ptr_territorio : ponteiro base para o vetor de territórios.
    //       (na chamada, é o mesmo ponteiro 'exercito' usado no cadastro)
    //       Cada incremento em (ptr_territorio + i) acessa o i-ésimo território.
    //
    //   - int qtd : quantidade total de territórios cadastrados.
    //       (na chamada, é passado 'indice_territorio', que indica quantos
    //        cadastros foram feitos)
    void exibirMapa(Territorio *ptr_territorio, int qtd) { 
        int i;
        for (i = 0; i < qtd; i++) { // Loop que percorre todos os territórios cadastrados
        printf("\nTerritório %d:\n", i + 1); // Exibe o número do território atual
        // Exibe os campos do território acessado via ponteiro
        printf("Nome: %s\n", (ptr_territorio + i)->nome);
        printf("Cor: %s\n", (ptr_territorio + i)->cor_exercito);
        printf("Tropas: %d\n", (ptr_territorio + i)->numero_tropas);
        }
    }

    // Função Main (Principal)
    int main() {

    int Qtd_Territorio;
    int indice_territorio = 0;

    //pedindo ao usuário o número de territórios que vão participar
    do {
        printf ("Digite o número de territórios/participantes (mínimo 2): ");

    // Validação de tipo:
    // Se scanf() não conseguir ler um número inteiro (retorna != 1),
    // então a entrada é inválida (ex: letras, símbolos, etc).
        if (scanf("%d", &Qtd_Territorio) != 1) { 
            printf("Entrada inválida! Digite um número inteiro.\n");
            LimparBufferEntrada();
    continue;
    }
    // Validação de faixa:
    // Garante que o valor seja pelo menos 2.
        if (Qtd_Territorio < 2) {
            printf ("É necessário ter pelo menos 2 territórios para o jogo.\n");
            LimparBufferEntrada();
    continue;
    }
    LimparBufferEntrada(); 

    break;

    } while(1);

    // Ponteiro para o vetor de territórios alocado dinamicamente.
    Territorio *exercito = (Territorio*) malloc(Qtd_Territorio * sizeof(Territorio));

    if (exercito == NULL) { // conferindo se malloc retorna nulo
        printf("Erro ao alocar memória!\n");
    return 1;
    }

    while (indice_territorio < Qtd_Territorio) {   // Loop para cadastro dentro do vetor
        printf("\n--- Cadastro do território %d ---\n", indice_territorio + 1); //Contador de território durante cadastro

        printf ("Digite o NOME do território: ");
        // local + i-ésimo da struct territorio. Exemplo: (exercito + 0)->nome     equivale a      exercito[0].nome
        fgets ((exercito + indice_territorio)->nome, 30, stdin); 

        printf ("Digite a COR do território: ");
        fgets ((exercito + indice_territorio)->cor_exercito, 10, stdin); 

        // Remove o \n capturado pelo fgets
        (exercito + indice_territorio)->nome[strcspn((exercito + indice_territorio)->nome, "\n")] = '\0';
        (exercito + indice_territorio)->cor_exercito[strcspn((exercito + indice_territorio)->cor_exercito, "\n")] = '\0';

        printf ("Digite o NÚMERO DE TROPAS do território: ");
        scanf ("%d", &((exercito + indice_territorio)->numero_tropas));

        LimparBufferEntrada();
        indice_territorio++;

        printf ("Território cadastrado com sucesso!\n");
        }

        // A função exibirMapa() recebe:
        //   → o ponteiro base do vetor (exercito)
        //   → a quantidade de territórios cadastrados (indice_territorio)
        // Assim, ela percorre o vetor e imprime cada campo.
        //
        exibirMapa(exercito, indice_territorio); //chamando função para imprimir situação atual do mapa

        // Libera a memória alocada e evitar vazamentos de memória
        free(exercito);

        return 0;
    }