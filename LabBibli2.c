#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int liv=0,myexp=0,alu=0,emp=0,dev=0,boool=0;
char* alug,devol;

struct cadastro{ //estrutura para o cadastro de alunos com nome, curso, telefone e matrícula
    char nome[30],curso[30];
    int tel,matr;

};
struct cadastro ca1; //variavel ca1 do tipo cadastro

struct livroscadastro{ //estrutura cadastro de livros com nome, autor, editora, numero e quantidade de exemplares
    int ex, num;
    char* nomelivro[30],autor[20],editora[20];
    };
struct livroscadastro ca2; //variavel ca2 do tipo livroscadastro

    FILE *arq; //programa em arquivo
void remove_livro(){ //remove livros do acervo

    arq = fopen("acervo.dat","r+b");
    int num;
    num=malloc(sizeof(int));
    printf("\n\nDigite o Numero do Livro a ser Removido: ");
    scanf(" %d", &num);
        if(encontra_livro(num)==0)
            printf("\nEsse Livro nao Existe\n\n");
        else{

                *ca2.autor=NULL;
                *ca2.editora=NULL;
                ca2.num =NULL;
                *ca2.nomelivro = NULL;
                ca2.ex=NULL;
    fwrite(&ca2,sizeof(ca2),1,arq);
    printf("Livro %d removido do acervo.\n",num);
        }
        fclose(arq);
}
void alterar_aluno(){ //altera informaçoes dos alunos


    arq = fopen("aluno.dat","r+b");
    int num, n, m;
    num=malloc(sizeof(int));
    printf("\n\nDigite a Matrícula do Aluno: ");
    scanf(" %d", &num);
        if(encontra_aluno(num)==0)
            printf("\nAluno Nao Existe\n\n");
        else{
                printf("\n\n Digite o Novo Nome do Aluno: ");
                fflush(stdin);
                gets(ca1.nome);
                printf("\n\n Digite o Novo Numero de Matricula: ");
                scanf("%d",&m);
                ca1.matr = m;
                printf("\n\n Digite o Novo Numero de Telefone: ");
                scanf("%d",&n);
                ca1.tel = n;
                printf("\n\n Digite o Novo Curso: ");
                fflush(stdin);
                gets(ca1.curso);
    fwrite(&ca1,sizeof(ca1),1,arq);
    printf("Aluno %d Recadastrado com Sucesso.\n",num);
        }
        fclose(arq);
}
int admin(){ //controle de acesso
    int o;
    char senha[6] = "admin";
    char* entrada;
    entrada=malloc(sizeof(char));
    printf("\n\n                            Acesso\n\n                            1-Funcionario\n\n                            2-Aluno\n\n");
    printf("\n>");
    scanf("%d", &o);
            switch(o){
                case 1:
                    printf("Digite a Senha de Acesso: >");
                    fflush(stdin);
                    fgets(entrada,6,stdin);
                    system("cls");
                    if(strcmp(senha,entrada)==0){
                        printf("\n\n                            Acesso  Avancado Permitido\n");
                        boool=1;
                        return 1;
                        break;
                    }else{
                        printf("\n\n                            Acesso Negado\n");
                        return 0;
                        break;
                        }
                case 2:
                    system("cls");
                    printf("\n\n                            Acesso Padrao \n");
                    return 0;
                    break;
                default:
                    system("cls");
                    printf("Opcao invalida.\n");
                    break;
                    }
           }
int encontra_aluno(int n){ //Função para evitar duplicação de alunos

  fread(&ca1,sizeof(ca1),1,arq);
  while (!feof(arq)){
    if (ca1.matr == n){
      fseek(arq,-sizeof(ca1),SEEK_CUR);
      return 1;
    }
    fread(&ca1,sizeof(ca1),1,arq);
  }
  return 0;
}
void atualizar_alunos(){ //Função para cadastrar alunos


  int num = 0,tel;

  arq = fopen("aluno.dat","a+b");
  if (arq == NULL)
    {
    printf("\nErro ao abrir arquivo\n");
    return;
  }
  printf("\nMatricula do Aluno: ");
  scanf("%i",&num);
  if (encontra_aluno(num) == 1)
    printf("Aluno já cadastrado!\n");
  else{
    ca1.matr = num;
    printf("\nNome do Aluno: ");
     fflush(stdin);
    gets(ca1.nome);
    printf("\nCurso: ");
     fflush(stdin);
    gets(ca1.curso);
    printf("\nTelefone: ");
    scanf("%d", &tel);
     ca1.tel = tel;
     alu +=1;
    fwrite(&ca1,sizeof(ca1),1,arq);
    printf("Aluno de Matricula %d cadastrado com sucesso!.\n",num);
  }
}
void listar_alunos(){ //Função para listar alunos
  #define MAX_LINHAS 5
  int lin,pag;

  arq = fopen("aluno.dat","a+b");
  if (arq == NULL)
  {
    printf("\nErro ao abrir arquivo\n");
    return;
  }

  pag = 0;
  lin = MAX_LINHAS;
  fread(&ca1,sizeof(ca1),1,arq);
  while (!feof(arq)){
    if (lin == MAX_LINHAS){
      lin = 0;
      pag++;
      system("Cls");
      printf("               ALUNOS %24s Pag. %03d\n"," ",pag);
      printf("  +-----------+--------------------+---------------------------+-------------+\n");
      printf("  | Matricula |       Nome         |           Curso           |  Telefone   |\n");
      printf("  +-----------+--------------------+---------------------------+-------------+\n\n\n");
    }
    lin++;
      printf("    %10d %20s  %15s     \t%09d   \n\n",ca1.matr,ca1.nome,ca1.curso,ca1.tel);
    fread(&ca1,sizeof(ca1),1,arq);
    if (feof(arq) || (lin == MAX_LINHAS))
    {
      if (!feof(arq))
        system("Pause");
    }
  }
  fclose(arq);
}
int encontra_livro(int n){ //Função para evitar duplicação de livros

  fread(&ca2,sizeof(ca2),1,arq);
  while (!feof(arq))
  {
    if (ca2.num == n)
    {
      fseek(arq,-sizeof(ca2),SEEK_CUR);
      return 1;
    }
    fread(&ca2,sizeof(ca2),1,arq);
  }
  return 0;
}
void atualizar_acervo(){ //Função para cadastrar livros


  int num,ex, topo=0;

  arq = fopen("acervo.dat","a+b");
  if (arq == NULL)
  {
    printf("\nErro ao abrir arquivo\n");
    return;
  }
  printf("\n");
  printf("Numero do livro(0/999): ");
  scanf("%d",&num);
  if (encontra_livro(num) == 1)
    printf("Ja existe livro com este numero!\n");
  else
  {
    ca2.num = num;
    printf("\nTitulo do livro: ");
    fflush(stdin);
    gets(ca2.nomelivro);
    printf("\nAutor do livro: ");
     fflush(stdin);
    gets(ca2.autor);
    printf("\nEditora do Livro: ");
     fflush(stdin);
    gets(ca2.editora);
    printf("\nNumero de Exemplares: ");
     scanf("%d", &ex);
     ca2.ex = ex;
     liv +=1;
    myexp += ca2.ex;
    fwrite(&ca2,sizeof(ca2),1,arq);
    printf("Livro %d incorporado ao acervo.\n\n",num);
  }
  fclose(arq);
}
void listar_acervo(){ // Função para listar livros
  #define MAX_LINHAS 5
  int lin,pag;

  arq = fopen("acervo.dat","a+b");
  if (arq == NULL)
  {
    printf("\nErro ao abrir arquivo\n");
    return;
  }

  pag = 0;
  lin = MAX_LINHAS;
  fread(&ca2,sizeof(ca2),1,arq);
  while (!feof(arq)){
    if (lin == MAX_LINHAS){
      lin = 0;
      pag++;
      system("Cls");
      printf("               ACERVO %24s Pag. %03d\n"," ",pag);
      printf("  +-----+----------------------+---------------------+-----------+------------+\n");
      printf("  | NUM |       TITULO         |        Autor        |  Editora  | Exemplares |\n");
      printf("  +-----+----------------------+---------------------+-----------+------------+\n\n\n");
    }
    lin++;
      printf("    %03d   %20s%    \t%15s \t%10s\t%02d   \n\n",ca2.num,ca2.nomelivro,ca2.autor,ca2.editora,ca2.ex);
    fread(&ca2,sizeof(ca2),1,arq);
    if (feof(arq) || (lin == MAX_LINHAS))
    {
      if (!feof(arq))
        system("Pause");
    }
  }
  fclose(arq);
}
void alugar(){ //Funçao para Alugar Livro do acervo
  int num;

  arq = fopen("acervo.dat","r+b");
  if (arq == NULL)
  {
    printf("\nErro ao abrir arquivo\n");
    return;
  }
  printf("\n");
  printf("Numero do livro ..... ");
  scanf("%d",&num);
  if (encontra_livro(num) == NULL)
    printf("Este livro nao existe!\n");
  else
  {
    fread(&ca2,sizeof(ca2),1,arq);
    if (ca2.ex == 0)
      printf("Exemplares ja emprestados, tente outro livro\n");
    else
    {
      ca2.ex -= 1;
      emp+=1;
      fseek(arq,-sizeof(ca2),SEEK_CUR);
      fwrite(&ca2,sizeof(ca2),1,arq);
      printf("Emprestimo OK!\n");
    }
  }
  fclose(arq);
}
void devolver(){ //Função para Devolução de Livro ao acervo
    int num;

  arq = fopen("acervo.dat","r+b");
    if (arq == NULL){
    printf("\nErro ao abrir arquivo\n");
    return;
    }
  printf("\n");
  printf("Numero do livro ..... ");
  scanf("%d",&num);
    if (encontra_livro(num) == 0)
    printf("Este livro nao existe!\n");
    else{
      ca2.ex += 1;
      fseek(arq,-sizeof(ca2),SEEK_CUR);
      fwrite(&ca2,sizeof(ca2),1,arq);
      printf("Devolucao OK!\n");
      dev += 1;
    }
  fclose(arq);
}
void limpa_tudo(){ //Função para deletar os arquivos
    printf("\nResetar Acervo?[s/n]\n>");
            fflush(stdin);
            char ac=getchar();
                if(ac=='s'){
                    fopen("acervo.dat","w");
                    fclose(arq);
                    printf("\n\nAcervo Deletado com Sucesso");
                }
            printf("\nResetar Alunos?[s/n]\n>");
            fflush(stdin);
            ac=getchar();
                if(ac=='s'){
                    fopen("aluno.dat","w");
                    fclose(arq);
                    printf("\n\nAlunos Deletados com Sucesso");

                }

}
    menu(){ //Menu principal do programa e submenus consequentes
                        int op,op2; //operadores para selecao das opcoes
    printf("\n\n\n\n\n\n\n\t\t--------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\tLabBibli Ver + de 8.000");
    printf("\n\n\t\t--------------------------------------------------");
    admin();
    printf("\n\n                            Bem Vindo a LabBibli :D");
    printf("\n\n\n                            Menu Principal\n\n                            1-Livros\n\n                            2-Alunos\n\n                            3-Relatorios\n\n                            4-Restaurar Configuracoes Iniciais\n\n                            0-Sair :( \n"); //opcoes menu
    printf("\n                            >");
    scanf("%d",&op);
    switch(op)               {
        case 1:
        system("cls");
            submenu1();
            break;
        case 2:
            system("cls");
            submenu2();
            break;
        case 3:
            system("cls");
            if(boool==1)
            submenu3();
            else{
                printf("\n\n       Voce nao tem permissao para acessar essa area\n");
            }
             printf("\nDeseja retornar ao menu principal ?\n\n 1-Sim\n Outra tecla para finalizar.\n>");
            scanf("%d",&op2);
                if(op2==1)  {
                system("cls");      menu();
                }
                else{system("exit");
                }
                break;
        case 4:
            system("cls");
            if(boool==1)
            limpa_tudo();
            else{
                printf("\n\n       Voce nao tem permissao para acessar essa area\n");
            }
                printf("\nDeseja retornar ao menu principal ?\n\n 1-Sim\n Outra tecla para finalizar.\n>");
            scanf("%d",&op2);
                if(op2==1)  {
                system("cls");      menu();
                }
                else{system("exit");
                }
                break;
        case 0:
            system("cls");
            printf("Programa finalizado");
            system("exit");
            break;
        default:
            system("cls");
            printf("Opcao invalida.");
            printf("\nDeseja retornar ao menu principal ?\n\n 1-Sim\n Outra tecla para finalizar.\n>");
            scanf("%d",&op2);
                if(op2==1)  {
                system("cls");      menu();
                }
                else{system("exit");
                }
            }
}
    submenu1(){// Controle de Acervo

        int oplivros,op2,contl,i=0,j=0,aux=0;
        printf("\n\n\n                            Menu de Livros\n\n                            1-Listar\n\n                            2-Cadastrar\n\n                            3-Alugar\n\n                            4-Devolver\n\n                            5-Remover\n\n                            0-Voltar\n");
        printf("\n                            >");
        scanf("%d",&oplivros);
        switch (oplivros)                {

            case 1:
            system("cls");
            listar_acervo();
            printf("\n1-Retornar Menu livros\n\n2-Retornar Menu principal\n\nAperte qualquer tecla para finalizar.\n>");
            scanf("%d",&op2);
            if(op2==1)  {
                system("cls");
                submenu1();

            }else if(op2==2){
                system("cls");
                menu();

            }else{
                system("exit");
            }
            break;
            case 2:
            system("cls");
            atualizar_acervo();
            printf("1-retornar Menu livros\n\n2-retornar Menu principal\n\nAperte qualquer tecla para finalinar.\n>");
            scanf("%d",&op2);
            if(op2==1)  {
                system("cls");
                submenu1();

            }else if(op2==2){
                system("cls");
                menu();

            }else{
                system("exit");


            }
            break;
            case 3:
                system("cls");
                alugar();
                printf("1-retornar Menu livros\n\n2-retornar Menu principal\n\nAperte qualquer tecla para finalinar.\n>");
                scanf("%d",&op2);
                    if(op2==1)  {
                        system("cls");
                        submenu1();

                    }else if(op2==2){
                        system("cls");
                        menu();

                    }else{
                        system("exit");

                }break;
            case 4:
                system("cls");
                devolver();
                printf("1-retornar Menu livros\n\n2-retornar Menu principal\n\nAperte qualquer tecla para finalinar.\n>");
                scanf("%d",&op2);
                    if(op2==1)  {
                        system("cls");
                        submenu1();

                    }else if(op2==2){
                        system("cls");
                        menu();

                    }else{
                        system("exit");

                }break;
            case 5:
                system("cls");
                if(boool==1)
                    remove_livro();
                else{
                    printf("\n\n       Voce nao tem permissao para acessar essa area\n");
                }
                printf("1-retornar Menu livros\n\n2-retornar Menu principal\n\nAperte qualquer tecla para finalinar.\n>");
                scanf("%d",&op2);
                    if(op2==1)  {
                        system("cls");
                        submenu1();

                    }else if(op2==2){
                        system("cls");
                        menu();

                    }else{
                        system("exit");
                    }

                break;
            case 0:
                system("cls");
                menu();
                break;
            default:
                system("cls");
                printf("Opcao invalida.");
                printf("\nDeseja retornar ao menu principal ?\n\n 1-Sim\n Outra tecla para finalizar.\n>");
                scanf("%d",&op2);
                if(op2==1)  {
                    system("cls");
                    menu();

                }else{
                    system("exit");

                }
                }
                }
    submenu2(){ //Controle de Alunos
        int opalunos,op2,i=0;
        system("cls");
        printf("\n\n\n                            Menu de Alunos\n\n                            1-Listar\n\n                            2-Cadastrar\n\n                            3-Alterar\n\n                            0-Voltar\n>");
        scanf("%d",&opalunos);
        printf("\n                            >");
        switch(opalunos){
            case 1:
                system("cls");
                listar_alunos();
                printf("\n\n1-Retornar ao Menu Alunos\n2-Retornar ao Menu Principal\n\nOu aperte qualquer tecla para sair.\n>");
                scanf("%d",&op2);
                if(op2==1){
                    system("cls");
                    submenu2();

                }else if(op2==2){
                    system("cls");
                    menu();

                }else{
                    system("cls");
                    printf("Programa finalizado!");
                    system("exit");

                }break;
            case 2:
                printf("\t\t\tCadastro");
                system("cls");
                atualizar_alunos();
                printf("\n\n1-Retornar ao Menu Alunos\n2-Retornar ao Menu Principal\n\nOu aperte qualquer tecla para sair.\n>");
                scanf("%d",&op2);
                if(op2==1){
                    system("cls");
                    submenu2();

                }else if(op2==2){
                    system("cls");
                    menu();

                }else{
                    system("cls");
                    printf("Programa finalizado!");
                    system("exit");

                }break;

            case 3:
                printf("\t\t\tAlteracao");
                system("cls");
                if(boool==1)
                alterar_aluno();
                else{
                printf("Voce nao tem permissao para acessar essa area");
                }
                  printf("\nDeseja retornar ao menu principal ?\n\n 1-Sim\n Outra tecla para finalizar.\n>");
            scanf("%d",&op2);
                if(op2==1)  {
                system("cls");      menu();
                }
                else{system("exit");
                }
                break;
                break;

            case 0:
                system("cls");
                menu();
                break;

            default:
                system("cls");
                printf("Opcao invalida.");
                printf("\nDeseja retornar ao menu principal ?\n\n 1-Sim\n Outra tecla para finalizar.\n>");
                scanf("%d",&op2);
                if(op2==1)  {
                    system("cls");
                    menu();

                }else{
                    system("exit");

                }

        }

    }
    submenu3(){ //Relatorios
        int oprelatorios,op2;
        system("cls");
        printf("\n\n                            Menu de Relatorios\n\n\n                            1-Relatorio de livros\n\n                            2-Relatorio de Alunos\n\n                            3-Relatorio Geral\n\n                            0-Voltar\n");
        scanf("%d",&oprelatorios);
        printf("\n                            >");
        switch (oprelatorios){
            case 1:
                system("cls");
                printf("\n\n                         Relatorio do Acervo\n\n");
                printf("\n\n                         Numero total de exemplares: %d exemplares", myexp);
                printf("\n\n                         Numero total de livros diferentes: %d livros\n\n\n", liv);
                 printf("\n\n1-Retornar ao Menu Relatorios\n2-Retornar ao Menu Principal\n\nOu aperte qualquer tecla para sair.");
                printf("                         >");
                scanf("%d",&op2);
                if(op2==1){
                    system("cls");
                    submenu3();

                }else if(op2==2){
                    system("cls");
                    menu();

                }else{
                    system("cls");
                    printf("Programa finalizado!");
                    system("exit");
                break;
            case 2:
                system("cls");
                printf("\n\n                         Relatorio de Alunos\n");
                printf("\n\n\n                         A LabBibli conta com um total de: %d alunos matriculados\n\n\n", alu);
                 printf("\n\n1-Retornar ao Menu Relatorios\n2-Retornar ao Menu Principal\n\nOu aperte qualquer tecla para sair.");
                printf("\n>");
                scanf("%d",&op2);
                if(op2==1){
                    system("cls");
                    submenu3();

                }else if(op2==2){
                    system("cls");
                    menu();

                }else{
                    system("cls");
                    printf("Programa finalizado!");
                    system("exit");
                break;
            case 3:
                system("cls");
                printf("\n\n                           Relatorio Geral");
                printf("\n\n\n\n                            Numero de Livros Emprestados: %d livros",emp);
                printf("\n\n                            Numero de Livros Devolvidos: %d livros", dev);
                printf("\n\n                            Total de Exemplares em Falta: %d exemplares",(emp-dev));
                printf("\n\n1-Retornar ao Menu Relatorios\n2-Retornar ao Menu Principal\n\nOu aperte qualquer tecla para sair.");
                printf("\n>");
                scanf("%d",&op2);
                if(op2==1){
                    system("cls");
                    submenu3();

                }else if(op2==2){
                    system("cls");
                    menu();

                }else{
                    system("cls");
                    printf("Programa finalizado!");
                    system("exit");
                break;
            case 0:
                system("cls");
                menu();
                break;
            default:
            system("cls");
            printf("Opcao invalida.");
            printf("\nDeseja retornar ao menu principal ?\n\n 1-Sim\n Outra tecla para finalizar.\n>");
            printf("\n>");
            scanf("%d",&op2);
            if(op2==1)  {
                system("cls");
                menu();

            }else{
                system("exit");

            }

                }

                }
                }
    }

}
 main(){
menu();
}




