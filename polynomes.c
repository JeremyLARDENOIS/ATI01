#include <stdio.h>
#include <stdlib.h>

struct S_Poly {
    double *poly;
    int degre;
};

typedef struct S_Poly Poly;

/*--------------------------------------------------------*/

int create_tab(Poly * p)
{
    /*Crée un tableau dynamique */
    p->poly = (double *) malloc((p->degre + 1) * sizeof(double));
    return 0;
}

int delete_tab(Poly * p)
{
    free(p->poly);
    return 0;
}

int create_poly(Poly * p)
{
    //return NULL boucle tant que pas bon
    printf("Quel est le degre du polynome ? : ");
    scanf("%d", &p->degre);
    printf("Remplissons le polynome de degre %d\n", p->degre);
    //Création de la dimension de la poly
    create_tab(p);
    //remplissage de la poly
    int i;
    for (i = p->degre; i >= 0; i--) {
	printf("X^%d : ", i);
	scanf("%lg", &p->poly[i]);
    }
    return 0;
}

int afficher_poly(Poly * p)
{
    int i;
    int first_number;
    first_number = 1;		//Si le premier nombre est passé, on rajoute le signe devant

    printf("f(x) = ");

    for (i = p->degre; i >= 0; i--) {
	if (p->poly[i] != 0){//si le coefficient est différent de 0
		if (p->poly[i] > 0){//Si le coefficient est positif
			if (!first_number){ // Si ce n'est pas le premier nombre
				printf(" + ");
			}	
			printf("%lg",p->poly[i]);
		}
		if (p->poly[i] < 0){//Si le coefficient est négatif
			printf(" - %lg",-p->poly[i]);
		}
		
		if (i > 1){ //Affiche x^i
			printf("x^%d",i);
		}
		if (i == 1){//Affiche x
			printf("x");
		}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		first_number=0;//On sait donc que le prochain n'est pas le premier nombre
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
