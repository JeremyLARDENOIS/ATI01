#include <stdio.h>
#include <stdlib.h>

typedef struct Matrice{
	char* nom;
	double** matrice;
    	int nb_ligne;
	int nb_col;
} Matrice;

double** create_tab (int nb_ligne, int nb_col ){
	  double **T;
	    int i;
	      T = (double**) malloc(nb_ligne*sizeof(double*));
	        for (i=0;i<nb_ligne;i++){
			    T[i]= (double*)malloc(nb_col*sizeof(double));
			      }
		  return T;
}

void delete_tab(double** T, int nb_ligne, int nb_col){
	  int i;
	    for (i=0;i<nb_ligne;i++){
		        free(T[i]);
			  }
	      free(T);
}

void afficher_tab(char* nom,double** tableau, int nb_ligne, int nb_col){
	  int i,j;
	  printf("%s:\n",nom);
	  for (i=0;i<nb_ligne;i++){
		        for (j=0;j<nb_col;j++){
				      printf("%lf;",tableau[i][j]);
				          }
			    printf("\n");
			      }
}
int main(){
	Matrice m1 = {"matrice n°1",create_tab(5,5),5,5};
		    /*//Decommenter pour avoir une matrice non-nul
		     *   int i,j;
		     *     for (i=0;i<nb_ligne;i++){
		     *         for (j=0;j<nb_col;j++){
		     *               tableau[i][j]=(double)i+j;
		     *                   }
		     *                       printf("\n");
		     *                         }
		     *                           */
	afficher_tab(m1.nom,m1.matrice,m1.nb_ligne,m1.nb_col);

	delete_tab(m1.matrice,m1.nb_ligne,m1.nb_col);

		        return 0;
}
