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
      printf("%s [%d] [%d]:",m.nom,i+1,j+1);      
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


double** mul_matrices(Matrice *m1, Matrice *m2){
  double** mres;
  mres = create_tab(m2->nb_ligne,m1->nb_col);
  int i,j;
  int x,y; // variable de la position du résultat
  i = 0;
  j = 0;
  x = 0;
  y = 0;
  for (x=0;x<m1->nb_ligne;x++){
    for (y=0;y<m2->nb_col;y++){
      while (i < m1->nb_col){
        mres[x][y]=mres[x][y] + ( m1->matrice[x][j]*m2->matrice[i][y]);
        printf("%lg\n",mres[x][y]);
        i ++;
        j ++;
      }
      printf("affectation\n");
      i=0;
      j=0;
    }
  }
  return mres; 
}

double det_matrice(Matrice *m){
  double det;
  switch(m->nb_ligne){
    case 1
  }
  
  
  return det;
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
    sprintf(msum.nom,"m1 + m2"); // nsum.nom = "m1 + m2"
    msum.nb_ligne= m1.nb_ligne;
    msum.nb_col= m1.nb_col;
    msum.matrice= add_matrices(&m1,&m2);
    afficher_matrice(&msum);
  }
  else {
    printf("Addition impossible\n");
  }

  if (m1.nb_col == m2.nb_ligne) {
    Matrice mmul;
    sprintf(mmul.nom,"m1 * m2"); // nsum.nom = "m1 * m2"
    mmul.nb_ligne= m1.nb_ligne;
    mmul.nb_col= m2.nb_col;
    mmul.matrice= mul_matrices(&m1,&m2);
    afficher_matrice(&mmul);
  }
  else {
    printf("Multiplication impossible\n");
  }
  
  if (m1.nb_ligne == m1.nb_col){
    double det_m1;
    det_m1 = det_matrice(&m1);
    printf("%lg\n",det_m1);
  }
  else{
    printf("determinant %s impossible\n")
  }
  
  delete_tab(&m1);
  delete_tab(&m2);
  
  return 0;
}
