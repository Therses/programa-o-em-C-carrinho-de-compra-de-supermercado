#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

int itensCarrinho = 0;

struct Produto{
    int codigo;
    char descricao[100];
    float precounit;
} Catalogo[100];

struct Carrinho {
    int numitem;
    struct Produto produto;
    int qtd;
    float precototal;
} Carrinho[100];

void main(){

    int i = 0;
    Catalogo[i].codigo = 1;
    strcpy(Catalogo[i].descricao, "COCA-COLA 2 LT");
    Catalogo[i].precounit = 5.98;

    i = i + 1;

    Catalogo[i].codigo = 2;
    strcpy(Catalogo[i].descricao, "FANTA 2 LT");
    Catalogo[i].precounit = 5.23;

    i = i + 1;
    Catalogo[i].codigo = 3;
    strcpy(Catalogo[i].descricao, "SKOL LATINHA");
    Catalogo[i].precounit = 2.98;

     i = i + 1;
    Catalogo[i].codigo = 4;
    strcpy(Catalogo[i].descricao, "ARROZ 5 KG");
    Catalogo[i].precounit = 11.00;

    i = i + 1;
    Catalogo[i].codigo = 5;
    strcpy(Catalogo[i].descricao, "FEIJÃO 2KG");
    Catalogo[i].precounit = 5.00;

    i = i + 1;
    Catalogo[i].codigo = 6;
    strcpy(Catalogo[i].descricao, "LEITE 1LT");
    Catalogo[i].precounit = 3.00;

    i = i + 1;
    Catalogo[i].codigo = 7;
    strcpy(Catalogo[i].descricao, "MACARRÃO 500G");
    Catalogo[i].precounit = 4.90;

    i = i + 1;
    Catalogo[i].codigo = 8;
    strcpy(Catalogo[i].descricao, "ÓLEO 1LT");
    Catalogo[i].precounit = 4.00;

    i = i + 1;
    Catalogo[i].codigo = 9;
    strcpy(Catalogo[i].descricao, "AÇUCAR 500G");
    Catalogo[i].precounit = 2.00;

    i = i + 1;
    Catalogo[i].codigo = 10;
    strcpy(Catalogo[i].descricao, "CAFÉ 1KG");
    Catalogo[i].precounit = 12.40;

    i = i + 1;
    Catalogo[i].codigo = 11;
    strcpy(Catalogo[i].descricao, "AZEITE 500ML");
    Catalogo[i].precounit = 7.94;

    i = i + 1;
    Catalogo[i].codigo = 12;
    strcpy(Catalogo[i].descricao, "SABONETE");
    Catalogo[i].precounit = 1.53;

    i = i + 1;
Catalogo[i].codigo = 13;
    strcpy(Catalogo[i].descricao, "MARGARINA 100G");
    Catalogo[i].precounit = 4.78;

    i = i + 1;
    Catalogo[i].codigo = 14;
    strcpy(Catalogo[i].descricao, "AMACIANTE 800ML");
    Catalogo[i].precounit = 6.98;

    i = i + 1;
    Catalogo[i].codigo = 15;
    strcpy(Catalogo[i].descricao, "ÁGUA 2LT");
    Catalogo[i].precounit = 3.18;


    setlocale(LC_ALL, "Portuguese");
    menuPrincipal();
}

void menuPrincipal()
{
    fflush(stdin);
    system("cls");
    int opcao;

    printf("\t_                                                                _");
    printf("\n\t|                                                                |");
    printf("\n\t|                           MERCADINHO DO JOSÉ                   |");
    printf("\n\t|                                                                |");

    printf("\n\n\n\n\t\t\t\tMENU PRINCIPAL\n\n");
    printf("\n\t 1. ADICIONAR PRODUTOS\n");
    printf("\n\t 2. VER CARRINHO\n");
    printf("\n\t 3. FECHAR CARRINHO\n");
    printf("\n\t 4. SAIR\n\n");
    printf("DIGITE A SUA OPÇÃO: ");

    scanf("%d", &opcao);

    switch(opcao)
    {
        case 1:
            system("cls");
            addProduto();
            break;
        case 2:
            system("cls");
            exibe();
            break;

        case 3:
            system("cls");
            fecha();
            break;

        case 4:
            system("cls");
            printf("OBRIGADO POR COMPRAR COM NOSSO AMIGO JOSÉ.\n\n");
            break;

        default:
            system("cls");
            printf("OPÇÃO INVÁLIDA.\n\n");
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.\n\n");
            getch();
            system("cls");
            menuPrincipal();
    }
}

void addProduto(){
    int codigoProduto;

    printf("Cód.\tProduto\t\tPreço\n");
    for(int i = 0; i < 15; i++){
        printf("%d\t", Catalogo[i].codigo);
        printf("%s\t", Catalogo[i].descricao);
        printf("%.2f\n", Catalogo[i].precounit);
    }

    printf("\nQual produto deseja adicionar?: ");
    scanf("%d", &codigoProduto);

    Carrinho[itensCarrinho].numitem = itensCarrinho + 1;

    int existe = 0;
    for (int i = 0; i < 15; i++){
        if (Catalogo[i].codigo == codigoProduto){
           Carrinho[itensCarrinho].produto = Catalogo[i];
        existe = 1;
        }
    }

    if (existe == 1){
        printf("Qual a quantidade?: ");
        scanf("%d", &Carrinho[itensCarrinho].qtd);
        Carrinho[itensCarrinho].precototal = Carrinho[itensCarrinho].produto.precounit * Carrinho[itensCarrinho].qtd;

        itensCarrinho = itensCarrinho + 1;
    }
    else {
        printf("Produto não encontrado, voltando ao menu.");
        getch();
    }

    menuPrincipal();
}

void exibe(){
    if (itensCarrinho > 0){
        float totalCarrinho = 0;
        printf("Nº\tCód.\tProduto\t\tPreço\tQtd.\tPreço Total\n");
        for(int i = 0; i < itensCarrinho; i++){
            printf("%d\t", Carrinho[i].numitem);
            printf("%d\t", Carrinho[i].produto.codigo);
            printf("%s\t", Carrinho[i].produto.descricao);
            printf("%.2f\t", Carrinho[i].produto.precounit);
            printf("%d\t", Carrinho[i].qtd);
            printf("%.2f\n", Carrinho[i].precototal);
            totalCarrinho = totalCarrinho + Carrinho[i].precototal;
        }

        printf("Total: %.2f", totalCarrinho);
    }
    else {
        printf("Sem produtos! aperte para voltar ao menu");
    }

    getch();
    menuPrincipal();
}

void fecha(){
    float totalCarrinho = 0;
printf("Nº\tCód.\tProduto\t\tPreço\tQtd.\tPreço Total\n");

    for(int i = 0; i < itensCarrinho; i++){
        printf("%d\t", Carrinho[i].numitem);
        printf("%d\t", Carrinho[i].produto.codigo);
        printf("%s\t", Carrinho[i].produto.descricao);
        printf("%.2f\t", Carrinho[i].produto.precounit);
        printf("%d\t", Carrinho[i].qtd);
        printf("%.2f\n", Carrinho[i].precototal);
        totalCarrinho = totalCarrinho + Carrinho[i].precototal;
    }

    printf("Total: %.2f", totalCarrinho);
    printf("\nObrigado por comprar conosco.");
    getch();
}

