#include <stdio.h>
#include <stdlib.h>

typedef struct Matrice{
	char nom [20] ;
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
	scanf("%s",m.nom);
	printf("Quel est la dimension de la matrice %s (<nb_ligne>x<nb_col>) ?: ",m.nom);
	scanf("%dx%d",&m.nb_ligne,&m.nb_col);
	m.matrice = create_tab(m.nb_ligne,m.nb_col);
	printf("Remplissons la matrice \"%s\" de taille %dx%d: \n",m.nom,m.nb_ligne,m.nb_col);
	int i,j;
	
	for (i=0;i<m.nb_ligne;i++){
	        for (j=0;j<m.nb_col;j++){
			printf("%s [%d] [%d]:",m.nom,i,j);      
			scanf("%lf",&m.matrice[i][j]);
		}
	
	  }
	  return m ;
}


void afficher_matrice(Matrice *m){
	int i,j;
	printf("matrice %s:\n",m->nom);
	for (i=0;i<m->nb_ligne;i++){
		for (j=0;j<m->nb_col;j++){
			printf("%lg",m->matrice[i][j]);
		      	if (j != m->nb_col-1){
			      printf("\t;\t");
			}
		}
		printf("\n");
	}
}

double** add_matrices(Matrice *m1, Matrice *m2){
	//DEFINIR UNE EXCEPTION SI LES MATRICES NE SONT PAS DE MEME TAILLES
	double** matrice;
	matrice = create_tab(m1->nb_ligne,m1->nb_col);
	int i,j;
	for (i=0;i<m1->nb_ligne;i++){
		for (j=0;j<m1->nb_col;j++){
			matrice[i][j]= m1->matrice[i][j] + m2->matrice[i][j];
		}
	}
	return matrice; 
}

double** sub_matrices(Matrice *m1, Matrice *m2){
	//DEFINIR UNE EXCEPTION SI LES MATRICES NE SONT PAS DE MEME TAILLES
	double** matrice;
	matrice = create_tab(m1->nb_ligne,m1->nb_col);
	int i,j;
	for (i=0;i<m1->nb_ligne;i++){
		for (j=0;j<m1->nb_col;j++){
			matrice[i][j]= m1->matrice[i][j] - m2->matrice[i][j];
		}
	}
	return matrice; 
}

/*---------------------------------------------------------------------------*/
int main(){
	Matrice m1,m2;
	m1 = create_matrice();
	m2 = create_matrice();
	
	afficher_matrice(&m1);
	afficher_matrice(&m2);
	if (m1.nb_ligne == m2.nb_ligne && m1.nb_col == m2.nb_col){
		Matrice msum;
		sprintf(msum.nom,"somme"); // nsum.nom = "somme"
		msum.nb_ligne= m1.nb_ligne;
		msum.nb_col= m1.nb_col;
		msum.matrice= add_matrices(&m1,&m2);
		afficher_matrice(&msum);
	}
	else {
		printf("Addition impossible\n");
	}
	if (m1.nb_ligne == m2.nb_ligne && m1.nb_col == m2.nb_col){
		Matrice mdif;
		sprintf(mdif.nom,"difference"); // nsum.nom = "difference"
		mdif.nb_ligne= m1.nb_ligne;
		mdif.nb_col= m1.nb_col;
		mdif.matrice= sub_matrices(&m1,&m2);
		afficher_matrice(&mdif);
	}
	else {
		printf("Soustraction impossible\n");
	}

	delete_tab(&m1);
	delete_tab(&m2);
	
	return 0;
}
