#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct S_Poly {
    double *poly;
    int degre;
};

typedef struct S_Poly Poly;

/*--------------------------------------------------------*/

int create_tab(Poly * p)
{
    /*Crée un tableau dynamique initié a 0 */
    int i;
    p->poly = (double *) malloc((p->degre + 1) * sizeof(double));
    for (i = 0; i <= p->degre; i++) {
	p->poly[i] = 0;
    }
    return 0;
}

int delete_tab(Poly * p)
{
    /*Supprime un tableau dynamique */
    free(p->poly);
    return 0;
}

int verify_poly(Poly * p)
{
    //Vérifie le degré réel d'un polynome et réajuste son degré si le coefficient du plus grand degre = 0
    if ((p->poly[p->degre] == 0) && (p->degre > 0)) {
	p->degre--;
	p->poly =
	    (double *) realloc(p->poly, (p->degre + 1) * sizeof(double));
	verify_poly(p);
    }

    return 0;
}

int create_poly(Poly * p)
{
    //Genere un polynome
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
    verify_poly(p);
    return 0;
}

int print_poly(Poly p)
{
    //Affiche un polynome
    int i;			//Effectue l'iteration decroissante des degre du polynome
    int first_number;
    first_number = 1;		//Si le premier nombre est passé, on rajoute le signe devant

    printf("La fonction est de degré %d\n", p.degre);
    printf("f(x) = ");

    for (i = p.degre; i >= 0; i--) {
	if ((p.poly[i] != 0) || ((i == 0) && (!first_number))) {	//si le coefficient est différent de 0 ou n'est pas de degré 0 egale a 0
	    if (p.poly[i] > 0) {	//Si le coefficient est positif
		if (!first_number) {	// Si ce n'est pas le premier nombre
		    printf(" + ");
		}
	    	if ((p.poly[i] != 1)||(i==0)) {	//Si le coefficient est positif
			printf("%lg", p.poly[i]);
	   	}
	    }
	    if (p.poly[i] < 0) {	//Si le coefficient est négatif
		if (first_number) {
		    printf("%lg", p.poly[i]);

		} else {
		    printf(" - %lg", -p.poly[i]);
		}
	    }

	    if (i > 1) {	//Affiche x^i
		printf("x^%d", i);
	    }
	    if (i == 1) {	//Affiche x
		printf("x");
	    }
	    first_number = 0;	//On sait donc que le prochain n'est pas le premier nombre
	}
	if ((i == 0) && (first_number)) {	//Si il s'agit d'un polynome = 0
	    printf("0");
	}

    }

    printf("\n");

    return 0;
}

int eval_poly(Poly p, double x, double *res)
{
    //Evalue un polynome et stocke le resultat dans res
    int i;
    *res = 0;

    for (i = 0; i <= p.degre; i++) {
	*res = *res + p.poly[i] * (pow(x, i));
    }

    return 0;
}

int derive(Poly p, Poly * p_dx)
{
    //Effectue la dérivé de p et stocke le résultat dans p_dx
    int i;

    if (p.degre > 0) {
	p_dx->degre = p.degre - 1;
    }
    if (p.degre == 0) {
	p_dx->degre = p.degre;
    }
    create_tab(p_dx);

    for (i = 0; i <= p_dx->degre; i++) {
	p_dx->poly[i] = p.poly[i + 1] * (i + 1);
    }
    return 0;
}

int mul_poly(Poly p1, Poly p2, Poly * pmul)
{
    //Multiplie p1 et p2 et stocke le résultat dans pmul
    int i, j;

    pmul->degre = p1.degre + p2.degre;
    create_tab(pmul);

    for (i = 0; i <= p1.degre; i++) {
        for (j = 0; j <= p2.degre; j++) {
            pmul->poly[i + j] =
                pmul->poly[i + j] + p1.poly[i] * p2.poly[j];
        }
    }
    verify_poly(pmul);
    return 0;
}

int tan_poly(Poly p, double a, Poly * p_tan)
{
    //Effectue la tangeante en a de p et stocke le polynome dans p_tan
    //T(x) = f'(x) (x-a) + f(a)
    Poly p_dx; 		//f'(x)
    derive(p,&p_dx);	
    printf("derivé :\n");
    print_poly(p_dx);
    
    Poly xa;		//(x-a)
    xa.degre = 1;
    create_tab(&xa);
    xa.poly[1] = 1;
    xa.poly[0] = -a;
    printf("(x-a) :\n");
    print_poly(xa);
        
    double pa;		//f(a)
    eval_poly(p,a,&pa);
    printf("f(%lg) = %lg\n",a,pa);

    mul_poly(p_dx,xa,p_tan);			//T(x) = f'(x) (x-a)
    p_tan->poly[0] = p_tan->poly[0] + pa; 	//T(x) = f'(x) (x-a) + f(a)  

    delete_tab(&p_dx);
    delete_tab(&xa);
    return 0;
}


/*---------------------------------------------------------------------------*/

int main()
{
    Poly p, p_tan;
    create_poly(&p);
    
    double a;
    a = 0;

    tan_poly(p,a,&p_tan);

    delete_tab(&p);
    delete_tab(&p_tan);
    return 0;
}
