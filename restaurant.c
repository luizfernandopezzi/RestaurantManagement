#include <stdio.h>  //Funções Principais em C
#include <string.h> //Biblioteca de funções para manipular strings
#include <ctype.h>  //Necessário para toupper (transforma minúsculas em maiúsculas)
#include <conio.h>  //Necessário para getch e putch

#define cod_coz 100
#define nome_coz 100
#define cpf_coz 100
#define nasc_coz 100
#define end_coz 100
#define fone_coz 100
#define rece 100
#define cod_ing 100
#define nome_ing 100
#define desc_ing 100
#define val_ing 100
#define quant_ing 100
#define cod_rec 100
#define nome_rec 100
#define cal_rec 100
#define coz_rec 100
#define desc_rec 1000
#define ing_rec 1000

struct coz
{
    int codigo[cod_coz];
    char nome[nome_coz];
    char cpf[cpf_coz];
    char nascimento[nasc_coz];
    char endereco[end_coz];
    char fone[fone_coz];
    char receitas[rece];
};
struct coz cozinheiro[5];

struct rec
{
    int codigo[cod_rec];
    char nome[nome_rec];
    char cal[cal_rec];
    char desc[desc_rec];
    char coz[coz_rec];
    char ing[ing_rec];
};
struct rec receita[20];

struct ing
{
    int codigo[cod_ing];
    char nome[nome_ing];
    char desc[desc_ing];
    char quant[quant_ing];
    char valor[val_ing];
};
struct ing ingrediente[10];

void format1() //Função usada para formatação de texto OK
{
    printf("********************************************************\n");
}

void criararquivo() // Cria a arquivo a ser utilizado OK
{
    FILE *arq1;
    FILE *arq2;
    FILE *arq3;
    arq1 = fopen("cozinheiro.dat", "ab");
    fread(&cozinheiro, sizeof(struct coz), 5, arq1);
    fclose(arq1);
    arq2 = fopen("receita.dat", "ab");
    fread(&receita, sizeof(struct rec), 20, arq2);
    fclose(arq2);
    arq3 = fopen("ingrediente.dat", "ab");
    fread(&ingrediente, sizeof(struct ing), 10, arq3);
    fclose(arq3);
}

void loadnomescoz() // Carrega apenas os nomes dos cozinheiros OK
{
    int n;

    FILE *arq;
    arq = fopen("cozinheiro.dat", "rb");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        for (n = 0; n < 5; n++)
        {
            fread(&cozinheiro, sizeof(struct coz), 5, arq);
            printf("\n-Cozinheiro %02d: %s", (n + 1), cozinheiro[n].nome);
        }
        printf("\n\n");
    }
    fclose(arq);
}

void loadcoz() // carregar todos os dados de todos os cozinheiros OK
{
    int n;
    char op1;
    system("CLS");

    FILE *arq;
    arq = fopen("cozinheiro.dat", "rb");
    printf("=======================================================\nLista de Cozinheiros:");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        for (n = 0; n < 5; n++)
        {
            fread(&cozinheiro, sizeof(struct coz), 5, arq);
            printf("\n=======================================================");
            printf("\n\nCozinheiro %d\n\nNome: %s\nEspecialidades: %s\nCPF: %s\nData de nascimento: %s\nEndereco: %s\nTelefone: %s\n", (n + 1), cozinheiro[n].nome,
                   cozinheiro[n].receitas, cozinheiro[n].cpf, cozinheiro[n].nascimento, cozinheiro[n].endereco, cozinheiro[n].fone);
        }
        printf("\n=======================================================\n\n");
        printf("A) Voltar...");
    }
    fclose(arq);
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula

        switch (op1)
        {
        case 'A':
            menucozinheiro();
            break;
        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A');
    fclose(arq);
}

void loadcoz1(int n) // carregar tods os dados de um cozinheiro OK
{
    int read;
    FILE *arq;
    arq = fopen("cozinheiro.dat", "rb");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        read = fread(cozinheiro, sizeof(struct coz), 5, arq);
        printf("\nNome: %s\nEspecialidades: %s\nCPF: %s\nData de nascimento: %s\nEndereco: %s\nTelefone: %s\n\n", cozinheiro[n].nome,
               cozinheiro[n].receitas, cozinheiro[n].cpf, cozinheiro[n].nascimento, cozinheiro[n].endereco, cozinheiro[n].fone);
    }
}

void savecoz() // Salvar cozinheiro dados do cozinheiro OK
{
    int ret;
    FILE *arq;

    arq = fopen("cozinheiro.dat", "wb+"); // fopen abre um arquivo, wb significa abrir no modo write (gravação).

    if (arq == NULL)
    { // se arq = null é porque o arquivo não existe
        printf("Erro ao abrir arquivo\n");
    }
    else
    {
        ret = fwrite(cozinheiro, sizeof(struct coz), 5, arq); // fwrite irá gravar os dados da memória no arquivo, sizeof serve para ver quanto espaço ocupa a estrutura
        if (ret != 5)
        {
            printf("Erro ao salvar dados\n");
        }
        else
        {
            printf("\nDados do cozinheiro salvos.\n");
        }
        fclose(arq);
    }
}

int menucozinheiro() //Função responsável pelo menu cozinheiro OK
{
    char op1;

    system("CLS");
    format1();
    printf("Cozinheiros:\n");
    format1();
    printf("\nA) Adicionar cozinheiro...\nB) Excluir cozinheiro...\nC) Visualizar todos...\nD) Voltar...\n\n");
    format1();
    printf("\nOpcao de letra: ");
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula

        switch (op1)
        {
        case 'A':
            addcoz();
            break;
        case 'B':
            excoz();
            break;
        case 'C':
            loadcoz();
            break;
        case 'D':
            main();
            break;
        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A' && op1 != 'B' && op1 != 'C' && op1 != 'D');
}

int addcoz() // Menu adicionar cozinheiro OK
{
    char op1[2];
    system("CLS");
    format1();
    printf("Adicionar cozinheiro:\n");
    format1();

    loadnomescoz();

    format1();
    printf("A) Voltar...\n\nAdicionar cozinheiro em qual posicao? (Pressione enter apos a escolha) ");
    do
    {
        gets(op1);

        strupr(op1); // converte todos os caracteres de str para maiúsculo.

        if (strcmp(op1, "A") == 0)
            menucozinheiro();
        else if (strcmp(op1, "1") == 0)
            question(1);
        else if (strcmp(op1, "2") == 0)
            question(2);
        else if (strcmp(op1, "3") == 0)
            question(3);
        else if (strcmp(op1, "4") == 0)
            question(4);
        else if (strcmp(op1, "5") == 0)
            question(5);
        else
            printf("\nOpcao invalida! Tente novamente:");
    } while (op1 != "1" && op1 != "2" && op1 != "3" && op1 != "4" && op1 != "5" && op1 != "A");
    return 0;
}

int question(int n) // Questionário sobre cozinheiro OK
{
    char op1;
    system("CLS");
    format1();

    printf("Cozinheiro %d\n", n);
    format1();

    loadcoz1((n - 1));
    format1();

    printf("\nModificar:\nA) Nome\t\t\tD) Nascimento\t\tG) Voltar...\nB) Especialidades\tE) Endereco\nC) CPF\t\t\tF) Telefone\n");
    printf("\nOpcao: ");
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula
        printf("\n\n");
        format1();

        switch (op1)
        {
        case 'A':
        {
            printf("\nNome do Cozinheiro: ");
            gets(cozinheiro[(n - 1)].nome);
        }
        break;
        case 'B':
        {
            printf("\nEspecialidades: ");
            gets(cozinheiro[(n - 1)].receitas);
        }
        break;
        case 'C':
        {
            printf("\nCPF: ");
            gets(cozinheiro[(n - 1)].cpf);
        }
        break;
        case 'D':
        {
            printf("\nData de nascimento: ");
            gets(cozinheiro[(n - 1)].nascimento);
        }
        break;
        case 'E':
        {
            printf("\nEndereco: ");
            gets(cozinheiro[(n - 1)].endereco);
        }
        break;
        case 'F':
        {
            printf("\nTelefone: ");
            gets(cozinheiro[(n - 1)].fone);
        }
        break;
        case 'G':
            addcoz();
            break;

        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A' && op1 != 'B' && op1 != 'C' && op1 != 'D' && op1 != 'E' && op1 != 'F' && op1 != 'G');

    savecoz();
    question(n);
    return 0;
}

int excoz() // Menu excluir cozinheiro OK
{
    char op1[2];
    system("CLS");
    format1();
    printf("Excluir cozinheiro:\n");
    format1();
    loadnomescoz(cozinheiro);
    format1();
    printf("A) Voltar...\n\nQual cozinheiro voce deseja excluir? (Pressione ENTER apos a escolha) ");
    do
    {
        gets(op1);

        strupr(op1); // converte todos os caracteres de str para maiúsculo.

        if (strcmp(op1, "A") == 0)
            menucozinheiro();
        else if (strcmp(op1, "1") == 0)
            excozsub(1);
        else if (strcmp(op1, "2") == 0)
            excozsub(2);
        else if (strcmp(op1, "3") == 0)
            excozsub(3);
        else if (strcmp(op1, "4") == 0)
            excozsub(4);
        else if (strcmp(op1, "5") == 0)
            excozsub(5);
        else
            printf("\nOpcao invalida! Tente novamente:");
    } while (op1 != '1' && op1 != '2' && op1 != '3' && op1 != '4' && op1 != '5' && op1 != 'A');
    return 0;
}

int excozsub(int n) // Função responável por zerar dados dos cozinheiros OK
{

    strcpy(cozinheiro[(n - 1)].nome, "");
    strcpy(cozinheiro[(n - 1)].receitas, "");
    strcpy(cozinheiro[(n - 1)].cpf, "");
    strcpy(cozinheiro[(n - 1)].nascimento, "");
    strcpy(cozinheiro[(n - 1)].endereco, "");
    strcpy(cozinheiro[(n - 1)].fone, "");

    savecoz(cozinheiro);
    excoz();

    return 0;
}

//

void loadnomesrec() // Carrega apenas os nomes das receitas OK
{
    int n;

    FILE *arq;
    arq = fopen("receita.dat", "rb");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        for (n = 0; n < 20; n++)
        {
            fread(&receita, sizeof(struct rec), 20, arq);
            printf("\n-Receita %02d: %s", (n + 1), receita[n].nome);
        }
        printf("\n\n");
    }
    fclose(arq);
}

void loadrec() // carregar todos os dados de todas as receitas OK
{
    int n;
    char op1;
    system("CLS");

    FILE *arq;
    arq = fopen("receita.dat", "rb");
    printf("=======================================================\nLista de Receitas:");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        for (n = 0; n < 20; n++)
        {
            fread(&receita, sizeof(struct rec), 20, arq);
            printf("\n=======================================================");
            printf("\n\nReceita %d\n\nNome: %s\nIngredientes: %s\nDescricao: %s\nCozinheiro Responsavel: %s\nCalorias por 100g: %s\n", (n + 1), receita[n].nome,
                   receita[n].ing, receita[n].desc, receita[n].coz, receita[n].cal);
        }
        printf("\n=======================================================\n\n");
        printf("A) Voltar...");
    }
    fclose(arq);
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula

        switch (op1)
        {
        case 'A':
            menureceita();
            break;
        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A');
    fclose(arq);
}

void loadrec1(int n) // carregar tods os dados de uma receita OK
{
    int read;
    FILE *arq;
    arq = fopen("receita.dat", "rb");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        read = fread(receita, sizeof(struct rec), 20, arq);
        printf("\nNome: %s\nIngredientes: %s\nDetalhes: %s\nCozinheiro Responsavel: %s\nCalorias por 100g: %s\n\n", receita[n].nome,
               receita[n].ing, receita[n].desc, receita[n].coz, receita[n].cal);
    }
}

void saverec() // Salvar dados das receitas OK
{
    int ret;
    FILE *arq;

    arq = fopen("receita.dat", "wb+"); // fopen abre um arquivo, wb significa abrir no modo write (gravação).

    if (arq == NULL)
    { // se arq = null é porque o arquivo não existe
        printf("Erro ao abrir arquivo\n");
    }
    else
    {
        ret = fwrite(receita, sizeof(struct rec), 20, arq); // fwrite irá gravar os dados da memória no arquivo, sizeof serve para ver quanto espaço ocupa a estrutura
        if (ret != 20)
        {
            printf("Erro ao salvar dados\n");
        }
        else
        {
            printf("\nDados da receita salvos.\n");
        }
        fclose(arq);
    }
}

int menureceita() //Função responsável pelo menu receita
{
    char op1;

    system("CLS");
    format1();
    printf("Receitas:\n");
    format1();
    printf("\nA) Adicionar receita...\nB) Excluir receita...\nC) Visualizar todas...\nD) Voltar...\n\n");
    format1();
    printf("\nOpcao de letra: ");
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula

        switch (op1)
        {
        case 'A':
            addrec();
            break;
        case 'B':
            exrec();
            break;
        case 'C':
            loadrec();
            break;
        case 'D':
            main();
            break;
        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A' && op1 != 'B' && op1 != 'C' && op1 != 'D');
}

int addrec() // Menu adicionar receita OK
{
    char op1[2];
    system("CLS");
    format1();
    printf("Adicionar receita:\n");
    format1();

    loadnomesrec();

    format1();
    printf("A) Voltar...\n\nAdicionar receita em qual posicao? (Pressione enter apos a escolha)  ");
    do
    {
        gets(op1);

        strupr(op1); // converte todos os caracteres de str para maiúsculo.

        if (strcmp(op1, "A") == 0)
            menureceita();
        else if (strcmp(op1, "1") == 0)
            question1(1);
        else if (strcmp(op1, "2") == 0)
            question1(2);
        else if (strcmp(op1, "3") == 0)
            question1(3);
        else if (strcmp(op1, "4") == 0)
            question1(4);
        else if (strcmp(op1, "5") == 0)
            question1(5);
        else if (strcmp(op1, "6") == 0)
            question1(6);
        else if (strcmp(op1, "7") == 0)
            question1(7);
        else if (strcmp(op1, "8") == 0)
            question1(8);
        else if (strcmp(op1, "9") == 0)
            question1(9);
        else if (strcmp(op1, "10") == 0)
            question1(10);
        else if (strcmp(op1, "11") == 0)
            question1(11);
        else if (strcmp(op1, "12") == 0)
            question1(12);
        else if (strcmp(op1, "13") == 0)
            question1(13);
        else if (strcmp(op1, "14") == 0)
            question1(14);
        else if (strcmp(op1, "15") == 0)
            question1(15);
        else if (strcmp(op1, "16") == 0)
            question1(16);
        else if (strcmp(op1, "17") == 0)
            question1(17);
        else if (strcmp(op1, "18") == 0)
            question1(18);
        else if (strcmp(op1, "19") == 0)
            question1(19);
        else if (strcmp(op1, "20") == 0)
            question1(20);
        else
            printf("\nOpcao invalida! Tente novamente:");
    } while (op1 != "1" && op1 != "2" && op1 != "3" && op1 != "4" && op1 != "5" && op1 != "6" && op1 != "7" &&
             op1 != "8" && op1 != "9" && op1 != "10" && op1 != "11" && op1 != "12" && op1 != "13" && op1 != "14" &&
             op1 != "15" && op1 != "16" && op1 != "17" && op1 != "18" && op1 != "19" && op1 != "20" && op1 != "A");
    return 0;
}

int question1(int n) // Questionário sobre receitas  OK
{
    char op1;
    int m;
    system("CLS");
    format1();

    printf("Receita %d\n", n);
    format1();
    loadrec1((n - 1));
    format1();
    printf("\nModificar:\nA) Nome\t\t\tC) Calorias / 100g\t\tE) Detalhes...\nB) Ingredientes\t\tD) Cozinheiro Responsável\tF) Voltar...\n");
    printf("\nOpcao: ");
    //do {
    op1 = getche();
    op1 = toupper(op1); // Converte para maiúscula
    printf("\n\n");
    format1();

    switch (op1)
    {
    case 'A':
    {
        printf("\nNome da Receita: ");
        gets(receita[(n - 1)].nome);
    }
    break;
    case 'B':
    {
        printf("\nIngredientes: ");
        gets(receita[(n - 1)].ing);
    }
    break;
    case 'C':
    {
        printf("\nCalorias a cada 100g: ");
        gets(receita[(n - 1)].cal);
    }
    break;
    case 'D':
    {
        printf("\nCozinheiro Responsavel:\n ");
        loadnomescoz();
        printf("\nQual cozinheiro e responsavel pela receita? ");
        do
        {
            scanf("%d", &m);
            if (m != 1 && m != 2 && m != 3 && m != 4 && m != 5)
            {
                printf("\nOpcao invalida! Tente novamente:");
            }
            else
            {
                strcpy(&receita[(n - 1)].coz, &cozinheiro[(m - 1)].nome);
            }
        } while (m != 1 && m != 2 && m != 3 && m != 4 && m != 5);
    }
    break;

    case 'E':
    {
        printf("\nDetalhes: ");
        gets(receita[(n - 1)].desc);
    }
    break;
    case 'F':
        addrec();
        break;

    default:
    {
        printf("\nOpcao invalida! Tente novamente:");
    }
    }
    while (op1 != 'A' && op1 != 'B' && op1 != 'C' && op1 != 'D' && op1 != 'E' && op1 != 'F')
        ;

    saverec();
    question1(n);
    return 0;
}

int exrec() // Menu excluir receita OK
{
    char op1[2];
    system("CLS");
    format1();
    printf("Excluir receita:\n");
    format1();
    loadnomesrec(receita);
    format1();
    printf("A) Voltar...\n\nQual receita  deseja excluir? (Pressione enter apos a escolha) ");
    do
    {
        gets(op1);

        strupr(op1); // converte todos os caracteres de str para maiúsculo.

        if (strcmp(op1, "A") == 0)
            menureceita();
        else if (strcmp(op1, "1") == 0)
            exrecsub(1);
        else if (strcmp(op1, "2") == 0)
            exrecsub(2);
        else if (strcmp(op1, "3") == 0)
            exrecsub(3);
        else if (strcmp(op1, "4") == 0)
            exrecsub(4);
        else if (strcmp(op1, "5") == 0)
            exrecsub(5);
        else if (strcmp(op1, "6") == 0)
            exrecsub(6);
        else if (strcmp(op1, "7") == 0)
            exrecsub(7);
        else if (strcmp(op1, "8") == 0)
            exrecsub(8);
        else if (strcmp(op1, "9") == 0)
            exrecsub(9);
        else if (strcmp(op1, "10") == 0)
            exrecsub(10);
        else if (strcmp(op1, "11") == 0)
            exrecsub(11);
        else if (strcmp(op1, "12") == 0)
            exrecsub(12);
        else if (strcmp(op1, "13") == 0)
            exrecsub(13);
        else if (strcmp(op1, "14") == 0)
            exrecsub(14);
        else if (strcmp(op1, "15") == 0)
            exrecsub(15);
        else if (strcmp(op1, "16") == 0)
            exrecsub(16);
        else if (strcmp(op1, "17") == 0)
            exrecsub(17);
        else if (strcmp(op1, "18") == 0)
            exrecsub(18);
        else if (strcmp(op1, "19") == 0)
            exrecsub(19);
        else if (strcmp(op1, "20") == 0)
            exrecsub(20);

        else
            printf("\nOpcao invalida! Tente novamente:");
    } while (op1 != "1" && op1 != "2" && op1 != "3" && op1 != "4" && op1 != "5" && op1 != "6" && op1 != "7" &&
             op1 != "8" && op1 != "9" && op1 != "10" && op1 != "11" && op1 != "12" && op1 != "13" && op1 != "14" &&
             op1 != "15" && op1 != "16" && op1 != "17" && op1 != "18" && op1 != "19" && op1 != "20" && op1 != "A");
    return 0;
}

int exrecsub(int n) // Função responável por zerar dados das receitas OK
{

    strcpy(receita[(n - 1)].nome, "");
    strcpy(receita[(n - 1)].desc, "");
    strcpy(receita[(n - 1)].cal, "");
    strcpy(receita[(n - 1)].desc, "");
    strcpy(receita[(n - 1)].coz, "");

    saverec(receita);
    exrec();

    return 0;
}

//

void loadnomesing() // Carrega apenas os nomes dos ingredientes OK
{
    int n;

    FILE *arq;
    arq = fopen("ingrediente.dat", "rb");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        for (n = 0; n < 10; n++)
        {
            fread(&ingrediente, sizeof(struct ing), 10, arq);
            printf("\n-Ingrediente %02d: %s", (n + 1), ingrediente[n].nome);
        }
        printf("\n\n");
    }
    fclose(arq);
}

void loading() // carregar todos os dados de todos os ingredientes OK
{
    int n;
    char op1;
    system("CLS");

    FILE *arq;
    arq = fopen("ingrediente.dat", "rb");
    printf("=======================================================\nLista de Ingredientes:");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        for (n = 0; n < 10; n++)
        {
            fread(&ingrediente, sizeof(struct ing), 10, arq);
            printf("\n=======================================================");
            printf("\n\nIngrediente %d\n\nNome: %s\nDescricao: %s\nQuantidade: %s\nValor: %s\n", (n + 1), ingrediente[n].nome,
                   ingrediente[n].desc, ingrediente[n].quant, ingrediente[n].valor);
        }
        printf("\n=======================================================\n\n");
        printf("A) Voltar...");
    }
    fclose(arq);
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula

        switch (op1)
        {
        case 'A':
            menuingrediente();
            break;
        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A');
    fclose(arq);
}

void loading1(int n) // carregar tods os dados de um ingrediente OK
{
    int read;
    FILE *arq;
    arq = fopen("ingrediente.dat", "rb");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo...");
    }
    else
    {
        read = fread(ingrediente, sizeof(struct ing), 10, arq);
        printf("\nNome: %s\nDescricao: %s\nQuantidade: %s\nValor: %s\n\n", ingrediente[n].nome,
               ingrediente[n].desc, ingrediente[n].quant, ingrediente[n].valor);
    }
}

void saveing() // Salvar cozinheiro dados do ingrediente OK
{
    int ret;
    FILE *arq;

    arq = fopen("ingrediente.dat", "wb+"); // fopen abre um arquivo, wb significa abrir no modo write (gravação).

    if (arq == NULL)
    { // se arq = null é porque o arquivo não existe
        printf("Erro ao abrir arquivo\n");
    }
    else
    {
        ret = fwrite(ingrediente, sizeof(struct ing), 10, arq); // fwrite irá gravar os dados da memória no arquivo, sizeof serve para ver quanto espaço ocupa a estrutura
        if (ret != 10)
        {
            printf("Erro ao salvar dados\n");
        }
        else
        {
            printf("\nDados do ingrediente salvos.\n");
        }
        fclose(arq);
    }
}

int menuingrediente() //Função responsável pelo menu ingrediente
{
    char op1;

    system("CLS");
    format1();
    printf("Ingredientes:\n");
    format1();
    printf("\nA) Adicionar ingrediente...\nB) Excluir ingrediente...\nC) Visualizar todos...\nD) Voltar...\n\n");
    format1();
    printf("\nOpcao de letra: ");
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula

        switch (op1)
        {
        case 'A':
            adding();
            break;
        case 'B':
            exing();
            break;
        case 'C':
            loading();
            break;
        case 'D':
            main();
            break;
        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A' && op1 != 'B' && op1 != 'C' && op1 != 'D');
}

int adding() // Menu adicionar ingrediente OK
{
    char op1[2];
    system("CLS");
    format1();
    printf("Adicionar ingrediente:\n");
    format1();

    loadnomesing();

    format1();
    printf("A) Voltar...\n\nAdicionar ingrediente em qual posicao? (Pressione enter apos a escolha)  ");
    do
    {
        gets(op1);

        strupr(op1); // converte todos os caracteres de str para maiúsculo.

        if (strcmp(op1, "A") == 0)
            menuingrediente();
        else if (strcmp(op1, "1") == 0)
            question2(1);
        else if (strcmp(op1, "2") == 0)
            question2(2);
        else if (strcmp(op1, "3") == 0)
            question2(3);
        else if (strcmp(op1, "4") == 0)
            question2(4);
        else if (strcmp(op1, "5") == 0)
            question2(5);
        else if (strcmp(op1, "6") == 0)
            question2(6);
        else if (strcmp(op1, "7") == 0)
            question2(7);
        else if (strcmp(op1, "8") == 0)
            question2(8);
        else if (strcmp(op1, "9") == 0)
            question2(9);
        else if (strcmp(op1, "10") == 0)
            question2(10);
        else
            printf("\nOpcao invalida! Tente novamente:");
    } while (op1 != "1" && op1 != "2" && op1 != "3" && op1 != "4" && op1 != "5" && op1 != "6" && op1 != "7" && op1 != "8" && op1 != "9" && op1 != "10" && op1 != "A");
    return 0;
}

int question2(int n) // Questionário sobre ingrediente OK
{
    char op1;
    system("CLS");
    format1();

    printf("Ingrediente %d\n", n);
    format1();

    loading1((n - 1));
    format1();

    printf("\nModificar:\nA) Nome\t\t\tC) Quantidade\t\tE) Voltar...\nB) Descricao\t\tD) Valor\n");
    printf("\nOpcao: ");
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula
        printf("\n\n");
        format1();

        switch (op1)
        {
        case 'A':
        {
            printf("\nNome do Ingrediente: ");
            gets(ingrediente[(n - 1)].nome);
        }
        break;
        case 'B':
        {
            printf("\nDescricao: ");
            gets(ingrediente[(n - 1)].desc);
        }
        break;
        case 'C':
        {
            printf("\nQuantidade: ");
            gets(ingrediente[(n - 1)].quant);
        }
        break;
        case 'D':
        {
            printf("\nValor: ");
            gets(ingrediente[(n - 1)].valor);
        }
        break;
        case 'E':
            adding();
            break;

        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A' && op1 != 'B' && op1 != 'C' && op1 != 'D' && op1 != 'E');

    saveing();
    question2(n);
    return 0;
}

int exing() // Menu excluir ingrediente OK
{
    char op1[2];
    system("CLS");
    format1();
    printf("Excluir ingrediente:\n");
    format1();
    loadnomesing(ingrediente);
    format1();
    printf("A) Voltar...\n\nQual ingrediente voce deseja excluir? (Pressione enter apos a escolha) ");
    do
    {
        gets(op1);

        strupr(op1); // converte todos os caracteres de str para maiúsculo.

        if (strcmp(op1, "A") == 0)
            menuingrediente();
        else if (strcmp(op1, "1") == 0)
            exingsub(1);
        else if (strcmp(op1, "2") == 0)
            exingsub(2);
        else if (strcmp(op1, "3") == 0)
            exingsub(3);
        else if (strcmp(op1, "4") == 0)
            exingsub(4);
        else if (strcmp(op1, "5") == 0)
            exingsub(5);
        else if (strcmp(op1, "6") == 0)
            exingsub(6);
        else if (strcmp(op1, "7") == 0)
            exingsub(7);
        else if (strcmp(op1, "8") == 0)
            exingsub(8);
        else if (strcmp(op1, "9") == 0)
            exingsub(9);
        else if (strcmp(op1, "10") == 0)
            exingsub(10);
        else
            printf("\nOpcao invalida! Tente novamente:");
    } while (op1 != "1" && op1 != "2" && op1 != "3" && op1 != "4" && op1 != "5" && op1 != "6" && op1 != "7" && op1 != "8" && op1 != "9" && op1 != "10" && op1 != "A");
    return 0;
}

int exingsub(int n) // Função responável por zerar dados dos ingredientes OK
{

    strcpy(ingrediente[(n - 1)].nome, "");
    strcpy(ingrediente[(n - 1)].desc, "");
    strcpy(ingrediente[(n - 1)].quant, "");
    strcpy(ingrediente[(n - 1)].valor, "");

    saveing(ingrediente);
    exing();

    return 0;
}

int main(void) //Função responsável pelo menu principal do algoritmo OK
{
    char op1;

    system("cls");
    criararquivo();
    format1();
    printf("Algoritmo para restaurantes:\n");
    format1();
    printf("\nA) Cozinheiros...\nB) Receitas...\nC) Ingredientes...\nD) Sair\n\n");
    format1();
    printf("\nDigite a letra referente a opcao desejada: ");
    do
    {
        op1 = getche();
        op1 = toupper(op1); // Converte para maiúscula

        switch (op1)
        {
        case 'A':
            menucozinheiro();
            break;
        case 'B':
            menureceita();
            break;
        case 'C':
            menuingrediente();
            break;
        case 'D':
            return 0;
            ;
            break;
        default:
        {
            printf("\nOpcao invalida! Tente novamente:");
        }
        }
    } while (op1 != 'A' && op1 != 'B' && op1 != 'C' && op1 != 'D');
}
