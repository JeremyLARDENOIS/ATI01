#include <stdio.h>
#include <stdlib.h>

typedef struct Matrice{
	char* nom;
	double** matrice;
    	int nb_ligne;
	int nb_col;
} Matrice;
/*--------------------------------------------------------*/
double** create_tab (int nb_ligne, int nb_col ){
	  double **T;
	  int i;
	  T = (double**) malloc(nb_ligne*sizeof(double*));
	  for (i=0;i<nb_ligne;i++){
	    T[i]= (double*)malloc(nb_col*sizeof(double));
	    }
		  return T;
}

void delete_tab (Matrice *m){
	  int i;
	  for (i=0;i<m->nb_ligne;i++){
		free(m->matrice[i]);
			  }
	      free(m->matrice);
}

Matrice create_matrice(){
	Matrice m;
	printf("Donnez un nom a la matrice: ");
	scanf("%s",&m.nom);
	printf("Quel est la dimension de la matrice %s (<nb_ligne>x<nb_col>) ?: ",m.nom);
	scanf("%dx%d",&m.nb_ligne,&m.nb_col);
	m.matrice = create_tab(m.nb_ligne,m.nb_col);
	printf("Remplissons la matrice \"%s\" de taille %dx%d: \n",m.nom,m.nb_ligne,m.nb_col);
	int i,j;
	
	for (i=0;i<m.nb_ligne;i++){
	        for (j=0;j<m.nb_col;j++){
			printf("%s [%d] [%d]",m.nom,i,j);      
			scanf("%lf",&m.matrice[i][j]);
		}
	
	  }
	  return m ;
}


void afficher_tab(Matrice *m){
	  int i,j;
	  printf("%s:\n",m->nom);
	  for (i=0;i<m->nb_ligne;i++){
		        for (j=0;j<m->nb_col;j++){
				      printf("%lf;",m->matrice[i][j]);
				          }
			    printf("\n");
			      }
}
/*---------------------------------------------------------------------------*/
int main(){
	Matrice m1;
	m1 = create_matrice();
	afficher_tab(&m1);
	delete_tab(&m1);

	return 0;
}
