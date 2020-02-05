#include <stdio.h>
#include <stdlib.h>

/*
struct Matrice{
	int a ;

};
*/

int** create_tab (int nb_ligne, int nb_col){
	int **T,i;
	T = (int**) malloc(nb_ligne*sizeof(int*));
	for (i=0;i>nb_ligne;i++){
		T[i]= (int*)malloc(nb_col*sizeof(int));
	}
	return T;
}

void delete_tab(int** T, int nb_ligne, int nb_col){
	int i;
	for (i=0;i<nb_ligne;i++){
		free(T[i]);
	}
	free(T);
}

void afficher_tab(int** tableau, int nb_ligne, int nb_col){
	int i,j;
	for (i=0;i<nb_ligne;i++){
		for (j=0;j<nb_col;j++){
			printf("%d",tableau[i][j]);
		}
	}
}
int main(){
	/*
	struct Matrice matrice1;
	matrice1.str="Bonjour";
	printf("");
	
	int a [20][20]  ;
	a [2][1]= 5;	
	printf ("%d \n",a[2][1]);
	*/
	int nb_ligne = 5, nb_col = 5;
	//int **tableau = create_tab(5,5);
	int tableau [nb_ligne][nb_col];	
	int i,j;
	for (i=0;i<nb_ligne;i++){
		for (j=0;j<nb_col;j++){
			tableau[i][j] = i+j;// -> ne marche pas
		}
	}
	//afficher_tab(tableau,nb_ligne,nb_col);

	for (i=0;i<nb_ligne;i++){
		for (j=0;j<nb_col;j++){
			printf("%d ;",tableau[i][j]);// -> ne marche pas
		}
		printf("\n");
	}




	//delete_tab(tableau,nb_ligne,nb_col);

	//printf ("\n");
	return 0;
}
