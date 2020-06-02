/**
 * 
 * Grupo:
 *  Antônio Vinicius
 *  Gustavo Medeiros Madeira
 *  Lucas Silva dos Anjos
 * Turma: CO.N1.11
 * Atividade Interdisciplinar
*/

#include <stdio.h>
#include <stdlib.h>

// DEFINE O TAMANHA MAX DE LINHAS E COLUNAS
#define LIN_MAX 50
#define COL_MAX 90

int main(){

    /*
    ------------------------------------------
    Código onde abre-se arquivo de texto, pesquisado online e adaptado.
    SITE: https://www.programiz.com/c-programming/c-file-input-output
    ACESSO: 25/05/2020 às 13:33;
    SITE: https://pt.wikibooks.org/wiki/Programar_em_C/Entrada_e_saída_em_arquivos
    ACESSO: 25/05/2020 às 13:44.
    */

    /*      VARIÁVEIS       */

    //CONTADORES QUE CONSTROEM A MATRIZ NO FOR
    int i, j, ctl_maior_sequencia = 1;
    //VARIÁVEL QUE DESIGNA O DIA COM A MAIOR QUANTIDADE DE CONTÁGIOS EM CADA PAÍS
    int dia_maior_contador = 0;
    // VARIÁVEL QUE GUARDA A POSIÇÃO DO DIA COM MAIOR N° DE CONTÁGIOS DO VETOR 'num_contagios'
    int dia_maior_contagios = 0;

    // VETOR DA QUANTIDADE DE PAÍSES
    int total_contagio[LIN_MAX], n_contagio_maior[LIN_MAX], dia_contagio_maior[LIN_MAX],num_contagios[LIN_MAX], paises [LIN_MAX]; //qnt_contagios[LIN_MAX] retirado esse vetor

    // ESTA MATRIZ JUNTA DE FORMA MAIS SIMPLIFICADA OS PAÍSES COM OS DIAS, ONDE A COLUNA 'D' DE DIA PERTENCE AO PAÍS 'P'
    int matriz_info[LIN_MAX][COL_MAX];
    
    // VARIÁVEL 'P' REPRESENTA A QNT DE PAISES E 'D' A QNT DE DIAS ANALIZADOS
    int P, D;

    // VARIÁVEL DO ARQUIVO PARA PEGAR DADOS
    FILE *arquivo_dados;

    // VARIÁVEL PARA NOME DE ARQUIVO DE DADOS
    char arquivo_nome[] = "dados.txt";

    // ABRE ARQUIVO COM DADOS
    arquivo_dados = fopen(arquivo_nome, "r");

    // VERIFICA SE ARQUIVO REALMENTE EXISTE E/OU TEVE ERRO DE LEITURA
    if (!arquivo_dados) {
        printf("Erro, ao abrir arquivo.");

        // PARA EXECUÇÃO DO PROGRAMA
        exit(1);
    }

//---------------------------------------------------------------------------------------------------------------------

    /*      ARMAZENANDO DADOS       */

    // PEGA O VALOR P (paises)
    fscanf(arquivo_dados, "%d", &P);
    printf("%d\n", P);
    
    // PEGA O VALOR D (dias)
    fscanf(arquivo_dados, "%d", &D);
    printf("%d\n", D);

    
    
    // PEGA OS DADOS DO ARQUIVO, N° DE CONTAGIOS DO DIA j NO PAÍS i
    for (i = 0; i < P; i++) {
        for (j = 0; j < D ; j++) {
            fscanf(arquivo_dados, "%d", &matriz_info[i][j]);
            printf("%d\n", matriz_info[i][j]);
        }
    }

    // FECHA E PARA A LEITURA DO ARQUIVO
    fclose(arquivo_dados);

    printf("\n");

//---------------------------------------------------------------------------------------------------------------------

    /*      INICIALIZANDO       */

    //ZERANDO OS VETORES
    for (i = 0; i < P; i++) {
        total_contagio[i] = 0;
        paises [i] = 0;
        // qnt_contagios[i] = 0; vetor não existe mais
    }

    for(j = 0; j < D; j++){
        n_contagio_maior[j] = 0;
        dia_contagio_maior[j] = 0;
        num_contagios[j] = 0;
    }

//---------------------------------------------------------------------------------------------------------------------

    /*      1° REQUISITO        */

    // SOMA O NÚMERO DE CONTÁGIOS DE CADA PÁIS E COLOCA OS SEUS VALORES EM UM VETOR
    for(i = 0; i < P; i++){
        for(j = 0; j < D; j++){
            total_contagio[i] += matriz_info[i][j];
        }
    }

    // IMPRIME O NÚMERO TOTAL DE CONTÁGIOS POR PAÍS
    printf("N%cmero total de cont%cgios por pa%cs: \n", 163, 160, 161);
    for(i = 0; i < P; i++){
        printf("Pa%cs %d: %d\n", 161, i+1, total_contagio[i]);
    }
    printf("\n");

//---------------------------------------------------------------------------------------------------------------------

    /*      2° REQUISITO       */

    // DETERMINA O DIA QUE TEVE O MAIOR NÚMERO DE CONTÁGIOS, E O NÚMERO DE CONTÁGIOS NESTE DIA, POR PÁIS
    for(i = 0; i < P; i++){
        // REINICIA O CONTADOR DE 'DIA COM MAIOR CONTAGIO'
        dia_maior_contador = 0;
        for(j = 0; j < D; j++){
            if(matriz_info[i][j] > matriz_info[i][dia_maior_contador]){
                dia_maior_contador = j;
            }
            dia_contagio_maior[i] = dia_maior_contador;
        }
    }

    printf("Dia com maior n%cmero de cont%cgios por pa%cs: \n", 163, 160, 161);
    // IMPRIME O DIA EM QUE TEVE O MAIOR NÚMERO DE CONTÁGIOS POR PAÍS, E O NÚMERO DE CONTÁGIOS NESTE DIA
    for(i = 0; i < P; i++){
        printf("Pa%cs %d: %d (%d)\n", 161, i+1, dia_contagio_maior[i]+1, matriz_info[i][dia_contagio_maior[i]]);
    }
    printf("\n");

//---------------------------------------------------------------------------------------------------------------------

    /*      3° REQUISITO       */

    // PERCORRE A MATRIZ DE INFORMAÇÕES, SOMAMOS O N° DE CONTÁGIOS DE CADA DIA, DE TODOS OS PAÍSES
    for (i = 0; i < P; i++) {
        for (j = 0; j < D; j++) {
            num_contagios[j] += matriz_info[i][j];
        }
    }

    for (i = 0; i < D; i++) {
        // VERIFICA SE O DIA i TEM MAIS CONTÁGIOS QUE O 'DIA ATUAL COM MAIOR CONTÁGIOS'
        if (num_contagios[i] > num_contagios[dia_maior_contagios]) {
            dia_maior_contagios = i;
        }
    }

    printf("Dia com maior n%cmero de cont%cgios\n", 163, 160);
    printf("%d: %d\n", dia_maior_contagios+1, num_contagios[dia_maior_contagios]);
    printf("\n");

//---------------------------------------------------------------------------------------------------------------------

    /*      4° REQUISITO       */

    for(i = 0; i < P; i++){
        // VARIAVEL REINICIA SEU VALOR (default) AO PASSAR DE PAIS (i)
        ctl_maior_sequencia = 1;
        for(int j = 0; j < D; j++){
            if( j + 1 <= D ){
                if(matriz_info [i] [j] <  matriz_info [i] [j + 1] ){
                    // CASO SEJA UMA SEGUENCIA CRESCENTE AUMENTA-SE O CONTROLADOR
                    ctl_maior_sequencia += 1;
                } else {
                    // MAS SE NÃO FOR REINICIA VALOR (default)
                    ctl_maior_sequencia = 1;
                }

                if (ctl_maior_sequencia > paises[i]) paises [i] = ctl_maior_sequencia;
            }
        }
    }

    printf("Maior sequ%cncia crescente de cont%cgios por pa%cs", 136, 160, 161);
    printf("\n");

    // IMPRIME A MAIOR SEQUÊNCIA CRESCENTE DE CONTÁGIOS POR PAÍS
    for(i = 0; i < P; i++){
        printf("Pa%cs %d: %d ""\n", 161, i + 1, paises [i]);
    }

    return 0;
}