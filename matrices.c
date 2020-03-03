#include <stdio.h>
#include <stdlib.h>

struct S_Matrice{
  char nom [20] ;
  double** matrice;
  int nb_ligne;
  int nb_col;
};

typedef struct S_Matrice Matrice ;

/*--------------------------------------------------------*/

int create_tab (Matrice* m ){
  int i;
  m->matrice = (double**) malloc(m->nb_ligne*sizeof(double*));
  for (i=0;i<m->nb_ligne;i++){
    m->matrice[i]= (double*)malloc(m->nb_col*sizeof(double));
  }
  return 0;
}

int delete_tab (Matrice* m){
  int i;
  for (i=0;i<m->nb_ligne;i++){
    free(m->matrice[i]);
  }
  free(m->matrice);
  return 0;
}

int create_matrice(Matrice* m){
  //return NULL boucle tant que pas bon
  printf("Donnez un nom a la matrice: ");
  scanf("%s",(char*) (&m->nom) );
  printf("Quel est la dimension de la matrice %s (<nb_ligne>x<nb_col>) ?: ",m->nom);
  scanf("%dx%d",&m->nb_ligne,&m->nb_col);
  printf("Remplissons la matrice \"%s\" de taille %dx%d: \n",m->nom,m->nb_ligne,m->nb_col);
  int i,j;
  //Création de la dimension de la matrice
  create_tab(m);
  //remplissage de la matrice
  
  for (i=0;i<m->nb_ligne;i++){
     for (j=0;j<m->nb_col;j++){
        printf("%s [%d] [%d]:",m->nom,i+1,j+1);      
        scanf("%lf",&m->matrice[i][j]);
      } 
  }
 
  return 0 ;
}

int afficher_matrice(Matrice* m){
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
  return 0;
}

int add_matrices(Matrice* mres, Matrice *m1, Matrice *m2){
  int i,j;
  for (i=0;i<mres->nb_ligne;i++){
    for (j=0;j<mres->nb_col;j++){
      mres->matrice[i][j]= m1->matrice[i][j] + m2->matrice[i][j];
    }
  }
  return 0; 
}

int mul_matrices(Matrice* mres, Matrice *m1, Matrice *m2){
  int i,j;
  int x,y; // variable de la position du résultat
  i = 0;
  j = 0;
  x = 0;
  y = 0;
  for (x=0;x<m1->nb_ligne;x++){
    for (y=0;y<m2->nb_col;y++){
      while (i < m1->nb_col){
        mres->matrice[x][y]+= ( m1->matrice[x][j]*m2->matrice[i][y]);
        i ++;
        j ++;
      }
      i=0;
      j=0;
    }
  }
  return 0; 
}

int trace_matrice(Matrice* m, double* trace){
  int i;
  *trace = 0;
  for (i=0;i<m->nb_col;i++){
  *trace = *trace + m->matrice[i][i];
  }

  return 0;
}

int det_matrice(Matrice *m, double* det){
  if (m->nb_col != m->nb_ligne){
  return 1; /*determinant impossible*/
  }
  if (m->nb_ligne == 2){
  /*Formule de determinant de matrice*/
  *det = m->matrice[0][0] * m->matrice[1][1] - m->matrice[0][1] * m->matrice [1][0];
  }
  else {
  int x;
  Matrice mdet;
  mdet.nb_col = mdet.nb_ligne = m->nb_ligne - 1 ;
  create_tab(&mdet);
  for (x=0;x < m->nb_ligne;x++){
    int i;
    int j;
    double det_mdet;
    /*On remplit la matrice du determinant*/
    for (i = 0;i<m->nb_ligne;i++){
      for (j=1;j<m->nb_col;j++){
        //printf("%d:%d\n",i,j);
        if (i < x){
          //printf("i<x %d;%d : %lg \n",i,j,m->matrice[i][j]);
          mdet.matrice[i][j-1] = m->matrice[i][j];
        }
        if (i > x){
          //printf("i>x %d;%d:%lg \n",i,j,m->matrice[i][j]);
          mdet.matrice[i-1][j-1] = m->matrice[i][j];
        }
      }  
    }
    det_mdet = 0;
    afficher_matrice(&mdet);
       
    det_matrice(&mdet,&det_mdet);
    if (x%2 == 0){ //Si c'est un numero de ligne impair (on commence a 1 en matrice mais a 0 en code) 
      *det = *det + det_mdet;
    }
    if (x%2 != 0){ //Si c'est un numero de ligne pair
      *det = *det - det_mdet;
    }
     
  }
  }
  return 0;
}
  
/*---------------------------------------------------------------------------*/
int main(){
  Matrice m1,m2;

  create_matrice(&m1);
  create_matrice(&m2);
  
  afficher_matrice(&m1);
  afficher_matrice(&m2);
  
  /*addition de m1 et m2*/
  if (m1.nb_ligne == m2.nb_ligne && m1.nb_col == m2.nb_col){
    Matrice msum; /*Matrice résultat de la somme*/
    sprintf(msum.nom,"m1 + m2"); /* nsum.nom = "m1 + m2" , affecte un nom a la matrice */
    msum.nb_ligne= m1.nb_ligne;
    msum.nb_col= m1.nb_col;
    create_tab(&msum);
    add_matrices(&msum,&m1,&m2);
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
    create_tab(&mmul);
    
    mul_matrices(&mmul,&m1,&m2);
    afficher_matrice(&mmul);
  }
  else {
    printf("Multiplication impossible\n");
  }

  if (m1.nb_ligne == m1.nb_col){
    double t_m1;
    t_m1 = 0;

    trace_matrice(&m1,&t_m1);
    printf("trace m1 : %lg\n",t_m1);
  }
  else{
    printf("trace de la matrice %s impossible\n",m1.nom);
  }

  if (m2.nb_ligne == m2.nb_col){
    double t_m2;
    t_m2 = 0;

    trace_matrice(&m2,&t_m2);
    printf("trace m2 : %lg\n",t_m2);
  }
  else{
    printf("trace de la matrice %s impossible\n",m2.nom);
  }
  
  if (m1.nb_ligne == m1.nb_col){
    double det_m1;
    det_matrice(&m1,&det_m1);
    printf("determinant de %s = %lg\n",m1.nom,det_m1);
  }
  else{
    printf("determinant %s impossible\n",m1.nom);
  }

  if (m2.nb_ligne == m2.nb_col){
    double det_m2;
    det_matrice(&m2,&det_m2);
    printf("determinant de %s = %lg\n",m2.nom,det_m2);
  }
  else{
    printf("determinant %s impossible\n",m2.nom);
  }
 
  delete_tab(&m1);
  delete_tab(&m2);
  
  return 0;
}
