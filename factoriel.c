#include <stdio.h>
#include <stdlib.h>

/*-------------Fonction-----------------*/

int fact_it (int factoriel, int* res){
	int i;
	*res = 0;
	
	for (i=0;i<=factoriel;i++){
		*res = *res * factoriel;
	}

	return 0;
}

int fact_rec (int factoriel, int* res){
	*res = 0;


	return 0;
}


/*---------------Main-------------------*/

int main (){
	int factoriel, resultat;
	printf("Choisissez un nombre : ");
	scanf("%d",&factoriel);
	
	fact_it (factoriel, &resultat);
	printf ("%d!=%d\n",factoriel,resultat);

	fact_rec(factoriel, &resultat);
	printf ("%d!=%d\n",factoriel,resultat);

	return 0;
}
