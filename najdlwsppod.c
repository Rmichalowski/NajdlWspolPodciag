#include <stdio.h>
#include<string.h>



void NWP(char x[], char y[], int m, int n, int c[][n+1], char b[][n+1]){
  for(int i = 0 ; i<=m ; i++){           //zerowanie pierwszej kolumny i wiersza
    c[i][0] = 0;
    for(int j = 0 ; j<=n ; j++){
      c[0][j] = 0;
    }
  }

  for(int i = 1 ; i<=m ; i++){ //tworzenie tablicy dziedziczącej po sobie oraz tablicy ze sciezka
    for(int j=1 ; j<=n ; j++){
        if (x[i] == y[j]){
          c[i][j] = c[i-1][j-1] + 1;
          b[i][j] = '\\';     //jesli ukazuje się nowy wspolny znak
        }
        else if (c[i-1][j] >= c[i][j-1]){   //jesli znak jest dziedziczony z gory
          c[i][j] = c[i-1][j];
          b[i][j] = '|';
        }
        else{
          c[i][j] = c[i][j-1];   //jesli znak jest dziedziczony z boku albo go nie ma
          b[i][j] = '-';
        }
    }
  }

  for(int i=0;i<=m;i++){ //drukowanie tablicy
    if(i==0)
    printf("    ");
    else
      printf("%C ",x[i-1]);
    }
      printf("\n");
  for(int j =0;j<=n;j++){
    if(j==0)
    printf("  ");
    else
      printf("%C ",y[j-1]);
    for(int i =0;i<=m;i++){
        printf("%i ",c[i][j]);

      }
      printf("\n");
    }
}

void printnwp(char x[], char y[], int m, int n, int nn,char b[][nn]){ //drukowanie nwp
	if(m == 0 || n == 0) return;

	//gdzie idziemy i znow funkcja
	if(b[m][n] == '\\'){
		printnwp(x, y, m-1, n-1,nn, b);
		printf("%C", x[m-1]);
	}
  else if (b[m][n] == '|')
      printnwp(x, y, m - 1, n,nn, b);
	else
      printnwp(x, y, m, n - 1,nn, b);
}


int main (){

char pod1[] = "abbaac";
char pod2[] = "bacbacba";
int m = strlen(pod1);
int n = strlen(pod2);
int c[m+1][n+1];
char b[m+1][n+1];
NWP(pod1,pod2,m,n,c,b);
printf("\n");
int nn = n+1;
printnwp(pod1,pod2,m,n,nn,b);
  return 0;
}
