#include <stdio.h>
#include <stdlib.h>

struct S_Poly {
    double* poly;
    int degre;
};

typedef struct S_Poly Poly;

/*--------------------------------------------------------*/

int create_tab(Poly* p)
{
	/*Crée un tableau dynamique*/
    p->poly = (double *) malloc((p->degre+1) * sizeof(double));
    return 0;
}

int delete_tab(Poly* p)
{
    free(p->poly);
    return 0;
}

int create_poly(Poly* p)
{
    //return NULL boucle tant que pas bon
    printf ("Quel est le degre du polynome ? : ");
    scanf("%d", &p->degre);
    printf("Remplissons le polynome de degre %d\n",p->degre);
    //Création de la dimension de la poly
    create_tab(p);
    //remplissage de la poly
	int i;
	for (i = p->degre; i >= 0; i--){
		printf("X^%d : ",i);
		scanf("%lg",&p->poly[i]);
	}
    return 0;
}

int afficher_poly(Poly* p)
{
    int i;
    printf("f(x) = ");
    
    for (i = p->degre; i >= 0; i--) {
	    if (p->poly[i] > 0){
	    	printf(" + %lg", p->poly[i]);
	    	if (i > 0){
			printf(" x^%d",i);
		}
	    }
	    if (p->poly[i] < 0){
	    	printf(" - %lg",-p->poly[i]);
	    	if (i > 0){
			printf(" x^%d",i);
		}
	    }//signe en haut ; nombre en bas
	    if (p->poly[i] > 0){
	    	printf(" + %lg", p->poly[i]);
	    	if (i > 0){
			printf(" x^%d",i);
		}
	    }
	    if (p->poly[i] < 0){
	    	printf(" - %lg",-p->poly[i]);
	    	if (i > 0){
			printf(" x^%d",i);
		}
	    }
    }
    printf("\n");
    return 0;
}

/*---------------------------------------------------------------------------*/

int main()
{
    Poly p;

    create_poly(&p);

    afficher_poly(&p);

    delete_tab(&p);

    return 0;
}
