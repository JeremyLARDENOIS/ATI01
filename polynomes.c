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
    /*Supprime un tableau dynamique*/
    free(p->poly);
    return 0;
}

int copy_poly(Poly p1, Poly* p2)
{
    //p1 copié vers p2
    int i;
    p2->degre = p1.degre;
    p2->poly = (double *) realloc(p2->poly, (p1.degre + 1) * sizeof(double));
	for (i=0; i <= p2->degre;i++){
		p2->poly[i]= p1.poly[i];
	}

    return 0;
}

int verify_poly(Poly * p)
{
    //Vérifie le degré réel d'un polynome et réajuste son degré si le coefficient du plus grand degre = 0
    if ((p->poly[p->degre] == 0) && (p->degre > 0)) {
	p->degre--;
    	p->poly = (double *) realloc(p->poly, (p->degre + 1) * sizeof(double));
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
    int i; 			//Effectue l'iteration decroissante des degre du polynome
    int first_number;
    first_number = 1;		//Si le premier nombre est passé, on rajoute le signe devant

    printf("La fonction est de degré %d\n", p.degre);
    printf("f(x) = ");

    for (i = p.degre; i >= 0; i--) {
	if ((p.poly[i] != 0)||((i==0)&&(!first_number))) {	//si le coefficient est différent de 0 ou n'est pas de degré 0 egale a 0
	    if (p.poly[i] > 0) {	//Si le coefficient est positif
		if (!first_number) {	// Si ce n'est pas le premier nombre
		    printf(" + ");
		}
		printf("%lg", p.poly[i]);
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
        if ((i==0)&&(first_number)) { //Si il s'agit d'un polynome = 0
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

    if (p.degre > 0){
    	p_dx->degre = p.degre - 1;
    } if (p.degre == 0 ){
    	p_dx->degre = p.degre;
    }
    create_tab(p_dx);

    for (i = 0; i <= p_dx->degre; i++) {
	p_dx->poly[i] = p.poly[i + 1] * (i + 1);
    }
    return 0;
}

int add_poly(Poly p1, Poly p2, Poly * psum)
{
    int i;

    psum->degre = (p1.degre >= p2.degre ? p1.degre : p2.degre);	// renvoie le degré max
    create_tab(psum);

    for (i = 0; i <= p1.degre; i++) {
	psum->poly[i] = p1.poly[i];
    }
    for (i = 0; i <= p2.degre; i++) {
	psum->poly[i] = psum->poly[i] + p2.poly[i];
    }
    verify_poly(psum);
    return 0;
}

int sub_poly(Poly p1, Poly p2, Poly * psub)
{
    int i;

    psub->degre = (p1.degre >= p2.degre ? p1.degre : p2.degre);	// renvoie le degré max
    create_tab(psub);

    for (i = 0; i <= p1.degre; i++) {
	psub->poly[i] = p1.poly[i];
    }
    for (i = 0; i <= p2.degre; i++) {
	psub->poly[i] = psub->poly[i] - p2.poly[i];
    }
    verify_poly(psub);
    return 0;
}

int mul_poly(Poly p1, Poly p2, Poly * pmul)
{
    int i, j;

    pmul->degre = p1.degre+p2.degre;	
    create_tab(pmul);

    for (i = 0; i <= p1.degre; i++) {
    for (j = 0; j <= p2.degre; j++) {
	pmul->poly[i+j] = pmul->poly[i+j] + p1.poly[i]*p2.poly[j];
    }}
    verify_poly(pmul);
    return 0;
}

int div_poly(Poly p, Poly pdiv, Poly * pq, Poly *pr )
{
	int i;
	Poly pqdiv, prsub;
	//double q;

	pq->degre = p.degre - pdiv.degre; 
	pr->degre = p.degre - pq->degre;
	pqdiv.degre = pq->degre + pdiv.degre;
	prsub.degre = p.degre;
		
	create_tab(pq);
	create_tab(pr);
	create_tab(&pqdiv);
	create_tab(&prsub);

	for (i = pq->degre;i >= 0; i--){
		copy_poly(p,pr);
		//Il faut que je soustraie le polynome pq * pdiv à p
		mul_poly(*pq,pdiv,&pqdiv);
		printf("pqdiv %d",i);
		print_poly(pqdiv);
		sub_poly(*pr,pqdiv,&prsub);			
		printf("prsub %d",i);
		print_poly(prsub);
		//copy_poly(prsub,&p);
		//printf("p %d",i);

		pq->poly[i] = prsub.poly[i+p.degre-1]/pdiv.poly[pdiv.degre];
		printf("pqpoly[%d] = %lg ",i,pq->poly[i]);
		//printf("pq %d",i);
		//print_poly(*pq);
/*		//Il faut que je soustraie le polynome pq * pdiv à p
		mul_poly(pq,pdiv,&pqdiv);
		printf("pqdiv %d",i);
		print_poly(pqdiv);
		/
		sub_poly(p,pqdiv,&pres);			
		printf("pres %d",i);
		print_poly(pres);
		copy_poly(pres,&p);
		printf("p %d",i);
		print_poly(p);

		pqdiv.poly[pqdiv.degre] = 0;
		verify_poly(&pqdiv);
*/	}
		mul_poly(*pq,pdiv,&pqdiv);
		sub_poly(*pr,pqdiv,&prsub);			
		copy_poly(prsub,pr);	
	
	delete_tab(&pqdiv);
	delete_tab(&prsub);

    return 0;
}

/*---------------------------------------------------------------------------*/

int main()
{
//CREER LE MENU
    int menu;

    while (1) {			//Boucle infinie
	printf("Que voulez-vous faire ?\n \
0 : Quitter\n \
1 : Evaluer un polynome\n \
2 : Dérivé un polynome\n \
3 : Additionner deux polynomes\n \
4 : Multiplier deux polynomes\n \
5 : Effectuer une division polynomiale\n\n \
-> ");
	scanf("%d", &menu);

	if (menu == 0) {	//Quitter
	    return 0;
	}
	if (menu == 1) {	// Evaluer
	    Poly p;
	    double res;
	    double x;

	    create_poly(&p);

	    print_poly(p);

	    printf("Pour quelle valeur de x souhaitez-vous calculer ? ");
	    scanf("%lg", &x);

	    eval_poly(p, x, &res);
	    printf("f(%lg) = %lg\n", x, res);

	    delete_tab(&p);

	}
	if (menu == 2) {	//Dérivé
	    Poly p, p_dx;

	    create_poly(&p);
	    print_poly(p);

	    printf("La dérivé de ce polynome est :\n");

	    derive(p, &p_dx);
	    print_poly(p_dx);

	    delete_tab(&p_dx);
	    delete_tab(&p);
	}
	if (menu == 3) {	//Addition
	    Poly p1, p2, psum;

	    printf("Pour le premier polynome\n");
	    create_poly(&p1);

	    printf("Pour le second polynome\n");
	    create_poly(&p2);
	    //COMMENT FAIRE SI POLYNOME PAS DE MEME DEGRE 
	    //prendre le degre max
	    //remplir par le plus grand des deux jusqu'a arrivé au plus petit des polynomes
	    add_poly(p1, p2, &psum);
	    print_poly(psum);
		
	    delete_tab(&p1);
	    delete_tab(&p2);
	    delete_tab(&psum);
	}
	if (menu == 4) {	//Multiplication
	    Poly p1, p2, pmul;

	    printf("Pour le premier polynome\n");
	    create_poly(&p1);

	    printf("Pour le second polynome\n");
	    create_poly(&p2);
	    mul_poly(p1, p2, &pmul);
	    print_poly(pmul);

	    delete_tab(&p1);
	    delete_tab(&p2);
	    delete_tab(&pmul);
	}
	if (menu == 5) {	//Division
	    Poly p, pdiv, pq, pr;

	    printf("Pour le dividende\n");
	    create_poly(&p);

	    printf("Pour le diviseur\n");
	    create_poly(&pdiv);
	    div_poly(p, pdiv, &pq, &pr);

	    printf("Le quotient est : \n");
	    print_poly(pq);
	    printf("Le reste est : \n");
	    print_poly(pr);

	    delete_tab(&p);
	    delete_tab(&pdiv);
	    delete_tab(&pq);
	    delete_tab(&pr);
	}
	printf("\n");
    }
    return 1;			//ne devrait pas arriver car on ne doit pas sortir de la boucle précédente
}
