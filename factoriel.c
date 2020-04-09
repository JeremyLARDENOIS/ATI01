#include <stdio.h>
#include <stdlib.h>

/*-------------Fonction-----------------*/

int fact_it(int factoriel, int *res)
{
    //Effectue le factoriel du premier argument, et met le résultat dans le second argument
    //de façon iterative
    int i;
    *res = 1;

    for (i = 1; i <= factoriel; i++) {
	*res = *res * i;
    }

    return 0;
}

int fact_rec(int factoriel, int *res)
{
    //Effectue le factoriel du premier argument, et met le résultat dans le second argument
    //de façon récursive
    if (factoriel > 1) {
	*res = factoriel * (*res);
	factoriel = factoriel - 1;
	fact_rec(factoriel, res);
    }


    return 0;
}

/*---------------Main-------------------*/

int main()
{
    int factoriel, resultat;
    printf("Choisissez un nombre : ");
    scanf("%d", &factoriel);

    fact_it(factoriel, &resultat);
    printf("De façon itérative : %d! = %d\n", factoriel, resultat);

    resultat = 1;
    fact_rec(factoriel, &resultat);
    printf("De façon récursive : %d! = %d\n", factoriel, resultat);

    return 0;

}
