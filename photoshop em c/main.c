/*
Pedro Cézar S. de Souza
*/
void definirCorTexto(int cor)
{
  if (cor >= 29 && cor <= 36)
  {
    printf("\x1b[%dm", cor);
  }
}
//blibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "libs/libbmp.h"
#include "libs/imghelpers.h"
#include <math.h>



int main()
{
  // Utilize apenas imagens .bmp com o formato 24 (true color)
  // converta em: https://online-converting.com/image/convert2bmp/
  bmp_img img;
// char filename[] = "Arte.bmp/lenna(2).bmp";
    char filename[] = "Arte/lenna.bmp";

  printf("\n");
  IMG_TAM t = pegarTamanho(filename);
  int l = t.qtdLinhas, c = t.qtdColunas;

  // matriz para manipular as cores
  int R[l][c];
  int G[l][c];
  int B[l][c];

  int R1[l][c];
  int G1[l][c];
  int B1[l][c];
    carregaImagem(t, R, G, B, filename);
   // processar a imagem atravez das matrizes R G B


  // Filtro cão
  char filename1[] = "Arte/catioro.bmp";
  printf("\n");
  IMG_TAM t1 = pegarTamanho(filename1);
  int l1 = t1.qtdLinhas,c1 = t1.qtdColunas;
  int R2[l1][c1];
  int G2[l1][c1];
  int B2[l1][c1];
  carregaImagem(t1,R1,G1,B1,filename1);
 int op = 0;


//Variaveis
 /* Part 1 - case A */
 int tamanhoBorda = 0;
 char menu;
 char continuar;
 int escolha = 0;

 /* Part 2 - Case b */
  
 /////case 1/////
 char selecione;
 float aux = 0;
 int tiraCor = 0;
  
 /////case 2/////
 int qtdImg = 0, deslocamento = 0, zoom = 0;  
  
 /////case 3/////
 float brilho = 0; 
 int ruidoIntens = 0;
 
 /////case 4/////
 float intensidade = 0; 
  
 /////case 5/////
 int MAX = 0; 
 int a = 4;
 int check[28];
 int resp = 0;
  
 /////case 7/////
 char pause; 
 int center = (rand() % 150) + c / 3, r = (rand() % 150) + c / 5;

 /////case 8/////
int rBlur;
int gBlur;
int bBlur;
int itsd = 0;

// definirCorTexto(valor) puxar a função de cor
printf("\e[1;1H\e[2J"); //linpar as confirmaçõe d salvamento acima

  do  //loop para menu 
  {
    carregaImagem(t, R, G, B, filename); // Zera os efeitos na imagem, carregando o arquivo original.

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        R1[i][j] = R[i][j];
        G1[i][j] = G[i][j];
        B1[i][j] = B[i][j];

        R[i][j] -= 50;
        B[i][j] -= 50;
        G[i][j] -= 50;
      }
    }
    
    // efeito para almentar a nitidez, assim dando mais destaque nas mudanças dos efeitos

    definirCorTexto(35);
    printf("========== MENU PRINCIPAL  ========== \n\n");

    definirCorTexto(31);
    printf("Escolha uma das opções abaixo: \n");
    printf("\t(A) - - Proposto - ----\n");
    printf("\t(B) - - Efeitos - ----\n");
    printf("\t(C) - - Encerrar - ----\n");

    definirCorTexto(32);
    printf("Digite o código desejado: ");
    scanf(" %c", &menu);
    definirCorTexto(29);

    /////////////////////menu de seleção /////////////////

    switch (menu) {
      case 'a':
      case 'A':
        printf("(1) Bordas" "\n(2) Inverter imagem " "\n\nEscolha o modelo do seu efeito: ");
        scanf("%d", &escolha);
printf("\n");
      switch (escolha) {
        case 1:
          definirCorTexto(32);
          printf("Diga o tamanho da borda em inteiro (recomendado até 50): ");
          scanf("%d", &tamanhoBorda);

          for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
              if (i < j) {
                R[i][j] += 70;
                B[i][j] += 70;
                G[i][j] += 70;
              } else if (i < tamanhoBorda || i >= l - tamanhoBorda || j < tamanhoBorda || j > c - tamanhoBorda) {
                 R[i][c - j] = 0;
                 B[i][c - j] = 0;
                 G[i][c - j] = 0;
              }
            }
          }

        for (int i = 0; i < l; i++) {
          for (int j = 0; j < c; j++) {
            if (i < tamanhoBorda || i >= l - tamanhoBorda || j < tamanhoBorda || j > c - tamanhoBorda) {
              R[i][c - j] = 0;
              B[i][c - j] = 0;
              G[i][c - j] = 0;
            }
          }
        }

        definirCorTexto(35);
        printf("\nCarregando...\n\n");

        definirCorTexto(36);
        salvaImagem(t, R, G, B, "saida.bmp");
        mostrarNoReplit("saida.bmp");

        printf("\n\nSeu efeito está pronto !!\n");

        definirCorTexto(31);

        printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
               "(n) Para NÃO\n:");
        scanf(" %c", &continuar);

        if (continuar != 's' && continuar != 'S') {
          printf("PROGRAMA FINALIZADO!!");
          return 0;
        }
        break;
        
      case 2: // inverter imag
        for (int i = 0; i < l; i++) {
          for (int j = 0; j < c; j++) {
            R[i][j] = R1[i][c - j];
            G[i][j] = G1[i][c - j];
            B[i][j] = B1[i][c - j];
          }
        }

        definirCorTexto(35);
        printf("\nCarregando...\n\n");

        definirCorTexto(36);
        salvaImagem(t, R, G, B, "saida.bmp");
        mostrarNoReplit("saida.bmp");

        printf("\n\nSeu efeito está pronto !!\n");

        definirCorTexto(31);

        printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "  "(n) Para NÃO\n:");
        scanf(" %c", &continuar);

        if (continuar != 's' && continuar != 'S') {
          printf("PROGRAMA FINALIZADO!!");
          return 0;
        }
        
       break;

      }
      break;

      case 'b':
      case 'B':

      printf("(1) Manipulação de core ao extremo e personalizado"
      "\n(2) Zoom e Multiplicar imagem" "\n(3) Preto & Branco com intensidade & noise"
      "\n(4) Cor inversa - (R, B, G) e Nível de brilho" "\n(5) Pixelado" 
      "\n(6) Fragmentado com Ruido" "\n(7) Noise-Retro, tv antiga" 
        "\n(8) Borrão" "\n(9) Sobre por Imagem"
      "\n\n" "Escolha o modelo do seu efeito:");
      scanf("%d", &escolha);
        
      printf("\n");

      switch (escolha)
      {

       case 1:
        printf("\nselecione o como vai ser o seu efeito: (R, B, G): ");
        scanf(" %c", &selecione);

       // case 1 red
       // case 2 blue
       // case 3 greem
       // personalize tudo (limite do if e cor retirada)

      if (selecione == 'R' || selecione == 'r') {
        //ALL RED
        for (int i = 0; i < l; i++){
          for (int j = 0; j < c; j++){

            if (R[i][j] > 120)
              R[i][j] += 120;

            if (G[i][j] > 100)
              G[i][j] -= 100;

            if (B[i][j] > 100)
              B[i][j] -= 100;
          }
        }
      }
      
       else if (selecione == 'G' || selecione == 'g'){
        // ALL BLUE
        for (int i = 0; i < l; i++)
        {
          for (int j = 0; j < c; j++)
          {

            if (R[i][j] > 100)
              R[i][j] -= 100;

            if (G[i][j] > 120)
              G[i][j] += 120;

            if (B[i][j] > 100)
              B[i][j] -= 100;
          }
        }
      }
      
      else if (selecione == 'B' || selecione == 'b'){
        // ALL GREEN
        for (int i = 0; i < l; i++)
        {
          for (int j = 0; j < c; j++)
          {

            if (R[i][j] > 100)
              R[i][j] -= 100;

            if (G[i][j] > 100)
              G[i][j] -= 100;

            if (B[i][j] > 120)
              B[i][j] += 120;
          }
        }
      }

      else{
        //personalize
        printf("Diga qual cor deseja alterar R B G ");
        scanf(" %c", &selecione);
        printf("\nDiga o valor que desejar!\n\n");

        printf("Qual o grau da tonalidade ela vai tomar: ");
        scanf("%f", &aux);

        printf("Diga o valor que ira retirar em inteiro: ");
        scanf("%d", &tiraCor);
        if (selecione == 'R' || selecione == 'r'){
          for (int i = 0; i < l; i++)
          {
            for (int j = 0; j < c; j++)
            {

              if (R[i][j] > aux)
                R[i][j] += aux;

              if (G[i][j] > tiraCor)
                G[i][j] -= tiraCor;

              if (B[i][j] > tiraCor)
                B[i][j] -= tiraCor;
            }
          }
        }
        
        if (selecione == 'B' || selecione == 'b'){
          for (int i = 0; i < l; i++)
          {
            for (int j = 0; j < c; j++)
            {

              if (R[i][j] > tiraCor)
                R[i][j] -= tiraCor;

              if (G[i][j] > aux)
                G[i][j] += aux;

              if (B[i][j] > tiraCor)
                B[i][j] -= tiraCor;
            }
          }
        }
        
        if (selecione == 'G' || selecione == 'g'){
          for (int i = 0; i < l; i++)
          {
            for (int j = 0; j < c; j++)
            {

              if (R[i][j] > tiraCor)
                R[i][j] -= tiraCor;

              if (G[i][j] > tiraCor)
                G[i][j] -= tiraCor;

              if (B[i][j] > aux)
                B[i][j] += aux;
            }
          }
       }
     }
         
      definirCorTexto(35);
      printf("\nCarregando...\n\n");

      definirCorTexto(36);
      salvaImagem(t, R, G, B, "saida01.bmp");
      mostrarNoReplit("saida01.bmp");

      printf("\n\nSeu efeito está pronto !!\n");

      definirCorTexto(31);

      printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
      scanf(" %c", &continuar);

      if (continuar != 's' && continuar != 'S') {
        printf("PROGRAMA FINALIZADO!!");
        return 0;
      }
      break;

        
    case 2:
//zomm e multiplicar img
    printf("\nGostaria de multiplicar em quantas imagens?\n" "Diga: ");
    scanf("%d", &qtdImg);
      
    printf("Valor de apliação (Zoom): ");
    scanf("%d", &zoom);

    printf("Diga o delocamento da imagem ex:" "( valores>=200 e valores <= 300)\n: ");
      scanf("%d", &deslocamento);

      for(int i = 0; i<l; i++){
      for(int j = 0; j< c; j++){
        if(j<c && j >= 0 && i >=0 && i < l){
          
        int linha = (((qtdImg * i) % l) / zoom - 1) + deslocamento;
        int coluna = (((qtdImg * j) % c) / zoom - 1) + deslocamento;

        if(linha>=0){
          linha = linha % l;
        }
      else{
        linha = 0;
      }


      if(coluna >= 0){
        coluna = coluna % c;
      }

      else{
        coluna =0;
      }

      R[i][j] = R1[linha][coluna];
      G[i][j] = G1[linha][coluna];
      B[i][j] = B1[linha][coluna];
          }    
        }
      }

      definirCorTexto(35);
      printf("\nCarregando...\n\n");

      definirCorTexto(36);
      salvaImagem(t, R, G, B, "saida01.bmp");
      mostrarNoReplit("saida01.bmp");

      printf("\n\nSeu efeito está pronto !!\n");

      definirCorTexto(31);

      printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
      scanf(" %c", &continuar);

      if (continuar != 's' && continuar != 'S')
      {
        printf("PROGRAMA FINALIZADO!!");

        return 0;
      }
      break;

     case 3:
      // preto e branco com intensidade & noise

       
      printf("\nDiga a intensidade do efeito: ");
      scanf("%f", &intensidade);
      int grau = 100;

      if (grau * 3 <= intensidade)
        grau += intensidade;

      for (int i = 0; i < l; i++)
      {
        for (int j = 0; j < c; j++)
        {
          int corAtual = (R1[i][j] + B1[i][j] + G1[i][j]) * (intensidade / grau);
          R[i][j] = corAtual;
          B[i][j] = corAtual;
          G[i][j] = corAtual;
        }
      }

       definirCorTexto(36);
       printf("\n");
       salvaImagem(t, R, G, B, "saida01.bmp");
       mostrarNoReplit("saida01.bmp");

       definirCorTexto(31);
       printf("\n\nAcima está o preto em branco tradicional!\n Vamos tentar reproduzir O Noise!\n");
      
       definirCorTexto(36);
       printf("\nDiga o nivel de claridade em ruido do Noise: ");
	       scanf("%d", &ruidoIntens); 
  

        if(ruidoIntens < 1){
        ruidoIntens = 5;
        }

        if(ruidoIntens > 30){
          ruidoIntens=15;
          }
  
	       for(int i = 0; i < l; i++){
	         for(int j = 0; j < c; j++){
	         int corNova = (int)(R[i][j] * 0.1 + G[i][j] * 0.1 + B[i][j] * 0.1);
	           R[i][j] = corNova;
	           B[i][j] = corNova;
	            G[i][j] = corNova;
	          }
           
	           for(int k = 0; k < c; k++){
	           int b = rand() % t.qtdColunas;
	           int a = rand() % t.qtdLinhas;
	           int noise = (int)(((R[a][b] * ruidoIntens)/10) + ((G[b][a] * ruidoIntens)/10) + ((B[b][a] * ruidoIntens)/10));
	          R[i][k] += (int)(noise/(ruidoIntens-3) + ruidoIntens * 5);
	          B[i][k] += (int)(noise/(ruidoIntens-3) + ruidoIntens * 5);
	          G[i][k] += (int)(noise/(ruidoIntens-3) + ruidoIntens * 5);
	       }
	     }

       
      definirCorTexto(35);
      printf("\nCarregando...\n\n");

      definirCorTexto(36);
      salvaImagem(t, R, G, B, "saida01.bmp");
      mostrarNoReplit("saida01.bmp");

      printf("\n\nSeu efeito está pronto !!\n");

      definirCorTexto(31);

      printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
      scanf(" %c", &continuar);

      if (continuar != 's' && continuar != 'S')
      {
        printf("PROGRAMA FINALIZADO!!");

        return 0;
      }

      break;

    case 4:
      // cor inversa  - (R, B, G) e brilho 

    printf("Diga qual a instensida do brilho, valores negativos ou positivos: ");
      scanf("%f", &brilho);

      for (int i = 0; i < l; i++)
      {
        for (int j = 0; j < c; j++)
        {

          R[i][j] = 255 - R1[i][j];
          B[i][j] = 255 - B1[i][j];
          G[i][j] = 255 - G1[i][j];
        }
      }


      for (int i = 0; i < l; i++)
          {
            for (int j = 0; j < c; j++)
            {
                R[i][j] += brilho;
                G[i][j] += brilho;
                B[i][j] += brilho;
            }
          }
      
      definirCorTexto(35);
      printf("\nCarregando...\n\n");

      definirCorTexto(36);
      salvaImagem(t, R, G, B, "saida01.bmp");
      mostrarNoReplit("saida01.bmp");

      printf("\n\nSeu efeito está pronto !!\n");

      definirCorTexto(31);

      printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
      scanf(" %c", &continuar);

      if (continuar != 's' && continuar != 'S')
      {
        printf("PROGRAMA FINALIZADO!!");

        return 0;
      }

      break;


        
       case 5:
     //pixelado   //28 é o valor maximo que o int atua

     printf("Selecione valores que sigam o modelo de progressão de 4 pelo dobro, ex: 4, 8, 16, 32, 64\n");
  
     for (int i = 0; i < 28; i++) {
        check[i] = a;
        a *= 2;
     }
    
    do {
        printf("Digite o valor que deseja pixelar: ");
        scanf("%d", &MAX);
        
        for (int i = 0; i < 28; i++) {
            if (MAX == check[i]) {
                resp = 1;
            }
        }

    } while (resp != 1);

         
         
      for (int i = 0; i < l; i += MAX) {
        for (int j = 0; j < c; j += MAX) {
      
      // Variáveis para acumular e calcular a média.
      int rgbAcc[3] = {0}; // 0: RED, 1: GREEN, 2:BLUE
      int medR = 0;
      int medG = 0;
      int medB = 0;

         // Variáveis para definir até onde o loop interno deve ir.
      int lMax = i + MAX;
      int cMax = j + MAX;

      // Acumula o RGB dos píxeis definidos (ex: [0.0, 0.1, 1.0, 1.1])
      for (int x = i; x < lMax; x++) {
        for (int y = j; y < cMax; y++) {
          rgbAcc[0] += R[x][y];
          rgbAcc[1] += G[x][y];
          rgbAcc[2] += B[x][y];
        }
      }

      // Média dos pixeis acumulados
      medR = rgbAcc[0] / (MAX * MAX);
      medG = rgbAcc[1] / (MAX * MAX);
      medB = rgbAcc[2] / (MAX * MAX);

      for (int x = i; x < lMax; x++) {
        for (int y = j; y < cMax; y++) {
          R[x][y] = medR;
          G[x][y] = medG;
          B[x][y] = medB;
        }
      }
    }
  }
         
      definirCorTexto(35);
      printf("\nCarregando...\n\n");

      definirCorTexto(36);
      salvaImagem(t, R, G, B, "saida01.bmp");
      mostrarNoReplit("saida01.bmp");

      printf("\n\nSeu efeito está pronto !!\n");

      definirCorTexto(31);

      printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
      scanf(" %c", &continuar);

      if (continuar != 's' && continuar != 'S')
      {
        printf("PROGRAMA FINALIZADO!!");

        return 0;
      }

      break;

       case 6:
       // Fragmentado com ruido
      
      for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
         if (i <= l / 2 && j <= c / 2){
         R[i][j] = R1[i + l / 2][j];
         G[i][j] = G1[i + l / 2][j];
         B[i][j] = B1[i + l / 2][j];
           if (i >= j){
          R[i][j] -= rand() % 255;
          G[i][j] -= rand() % 255;
          B[i][j] -= rand() % 255;
        }
      }
        else if (i >= l / 2 && j <= c / 2){
         R[i][j] = R1[i][(c / 2) + j];
         G[i][j] = G1[i][(c / 2) + j];
         B[i][j] = B1[i][(c / 2) + j];
            if (i + j >= 512){
             R[i][j] -= rand() % 255;
             G[i][j] -= rand() % 255;
             B[i][j] -= rand() % 255;
            }
           }
        else if (i <= l / 2 && j >= c / 2){
         R[i][j] = R1[i][j - c / 2];
         G[i][j] = G1[i][j - c / 2];
         B[i][j] = B1[i][j - c / 2];
            if (i + j <= 512){
            R[i][j] -= rand() % 255;
            G[i][j] -= rand() % 255;
            B[i][j] -= rand() % 255;
           }
         }
        else if (i >= l / 2 && j >= c / 2){
          R[i][j] = R1[i - l / 2][j];
          G[i][j] = G1[i - l / 2][j];
          B[i][j] = B1[i - l / 2][j];
             if (i < j){
              R[i][j] -= rand() % 255;
              G[i][j] -= rand() % 255;
              B[i][j] -= rand() % 255;
            }
          }
            if (i == l / 2 || j == c / 2){
                R[i][j] = 0;
                G[i][j] = 0;
                B[i][j] = 0;
              }
            }
          }
	    
      
       definirCorTexto(35);
      printf("\nCarregando...\n\n");

      definirCorTexto(36);
      salvaImagem(t, R, G, B, "saida01.bmp");
      mostrarNoReplit("saida01.bmp");

      printf("\n\nSeu efeito está pronto !!\n");

      definirCorTexto(31);

      printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
      scanf(" %c", &continuar);

      if (continuar != 's' && continuar != 'S')
      {
        printf("PROGRAMA FINALIZADO!!");

        return 0;
      }

      break;

        
       case 7:

      //noise retro, tv antiga
      for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
          for (int k = -1; k < 2; k++){
            int varCor = rand() % 512;

           if (R[i][k] != R[i][k + j]){
             int randomColor[3] = {rand() % 255};
           if (randomColor[0] > randomColor[1] && randomColor[0] > randomColor[2]){
             int max = randomColor[0];
             R[(varCor * i) % 512][(varCor * k) % 512] -= max;
           }
        else if (randomColor[1] > randomColor[0] && randomColor[1] > randomColor[2]){
             int max = randomColor[1];
             G[(varCor * i) % 512][(varCor * k) % 512] -= max;
           }
        else if (randomColor[2] > randomColor[1] && randomColor[2] > randomColor[0]){
           int max = randomColor[2];
           B[(varCor * i) % 512][(varCor * k) % 512] -= max;
         }
       }
           int NoCor = (R[i][j] + G[i][j] + B[i][j]) * .3;
           R[i][j] = NoCor;
           G[i][j] = NoCor;
           B[i][j] = NoCor;
         }
        }
      }


       definirCorTexto(36);
       printf("\n");
       salvaImagem(t, R, G, B, "saida01.bmp");
       mostrarNoReplit("saida01.bmp");
       definirCorTexto(31);
       printf("\n\nAcima está a Tv 80's !\n Vamos  reproduzir Uma tv dos anos 2000 \n");
       definirCorTexto(36);
        printf("Digite qualquer tecla: "); //pause
          scanf(" %c", &pause);
       carregaImagem(t, R, G, B, filename);

	     for (int i = 0; i < l; i++) {
		    for (int j = 0; j < c; j++) {
			      int centerDistance = (pow((i - center), 2)) + (pow((j - center), 2));
			    if ((centerDistance >= pow(r, 2))) {
			    if (R[i][j] < 200) {
				  	  R[i][j] = 0;
				     	G[i][j] = 0;
				     	B[i][j] = 0;
			     	}
             else {
				    	if (j < c / 3) {
				    		R[i][j] = rand() % 255 - j / 2;
				    		G[i][j] = rand() % 255 - j / 2;
					     	B[i][j] = 0;
					    } 
            else if (j > c - (c / 3)) {
						  R[i][j] = 0;
						  G[i][j] = rand() % 255 - j / (512 / l - j);
						  B[i][j] = rand() % 255 - j / (512 / l - j);
					   }
               else {
					     	G[i][j] = 0;
					     	B[i][j] = rand() % 255 - j / (512 / l - j);
					     	R[i][j] = rand() % 255 - j / (512 / l - j);
					   }
			    }
			  }
			   if (R[i][j] < 200) {
			       	R[i][j] = 0;
			       	G[i][j] = 0;
			       	B[i][j] = 0;
			      }
         else if ((centerDistance <= pow(r, 2))) {
				      R[i][j] = R[i][j];
				      G[i][j] = G[i][j];
			       	B[i][j] = B[i][j];
			      }
		      }
	      }


         
       definirCorTexto(35);
       printf("\nCarregando...\n\n");

       definirCorTexto(36);
       salvaImagem(t, R, G, B, "saida01.bmp");
       mostrarNoReplit("saida01.bmp");

       printf("\n\nSeu efeito está pronto !!\n");

       definirCorTexto(31);

       printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
       scanf(" %c", &continuar);

       if (continuar != 's' && continuar != 'S'){
        printf("PROGRAMA FINALIZADO!!");

        return 0;
      }

      break;

        
       case 8:

        printf("Diga o nivel de borrão da imagem Use de (10 a 15): ");
         scanf("%d", &itsd);


      for(int i = 1; i < l - itsd + 1; i++) {
      for(int j = 1; j < c; j++) {
          rBlur = 0;
          gBlur = 0;
          bBlur = 0;
        
      for(int x = 0; x < itsd; x++) {
      for(int y = 0; y < itsd; y++) { 
        rBlur += R[i + x][j + y];
        gBlur += G[i + x][j + y];
        bBlur += B[i + x][j + y];
      }
    }
         R[i][j] = rBlur / (itsd * itsd);
         G[i][j] = gBlur / (itsd * itsd);
         B[i][j] = bBlur / (itsd * itsd);
      }
    }


       definirCorTexto(35);
       printf("\nCarregando...\n\n");

       definirCorTexto(36);
       salvaImagem(t, R, G, B, "saida01.bmp");
       mostrarNoReplit("saida01.bmp");

       printf("\n\nSeu efeito está pronto !!\n");

       definirCorTexto(31);

       printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
       scanf(" %c", &continuar);

       if (continuar != 's' && continuar != 'S'){
        printf("PROGRAMA FINALIZADO!!");

        return 0;
      }

      break;

        
      case 9:
        printf("\nNão funciona aqui, favor acessar: \n");
       definirCorTexto(31);
        printf("https://replit.com/@VictorGoncalv14/Atividade-Matriz#main.c");
          definirCorTexto(35);
       printf("\n\n\nCarregando...\n\n");

       definirCorTexto(36);
       salvaImagem(t, R, G, B, "saida01.bmp");
       mostrarNoReplit("saida01.bmp");

       printf("\n\nSeu efeito está pronto !!\n");

       definirCorTexto(31);

       printf("\n\n Deseja continuar a busca? \n Digite (s) Para SIM \n Ou Digite "
             "(n) Para NÃO\n:");
       scanf(" %c", &continuar);

       if (continuar != 's' && continuar != 'S'){
        printf("PROGRAMA FINALIZADO!!");

        return 0;
      }
        break;
    }

    break;

  case 'c':
  case 'C':
    printf("\n PROGRAMA FINALIZADO!");

    return 0;

    break;
  }

  //    system("pause");

  printf("\e[1;1H\e[2J"); // system("clear"); ou system("cls");  escape ANSI 
}
while (continuar == 's' || continuar == 'S')
  ;

return 0;
}