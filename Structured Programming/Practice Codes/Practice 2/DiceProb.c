#include <stdio.h>
#include <stdlib.h>

float** initialize_matrix(int nRow, int nColumn) // Dinamik 2 boyutlu matris icin hafizada yer ayirilir.
{
	int i;
	float **matrix;
	
	matrix = (float**) malloc(sizeof(float*) * nRow); // Hafizada yer ayirilir veya NULL degeri doner.
	
	// Matris olusturuldu.
	
	// NULL olup olmadiginin kontrolu yapilir.
	
	if(matrix == NULL){
		printf("Bellek ayrilamadi...");
		exit(-1);
	}
	
	for(i=0; i<nRow; i++){
		matrix[i] = (float*) calloc(nColumn, sizeof(float));
		
		/*
		 Bellek alani ayirildiktan sonra satir sayisi kadar alan sifirlanarak doldurulur.
		 Matrisin ilk adresi, matrix[i] adresinde saklanir.
		*/
		
		matrix[i][0] = i + 3;
	}

	return matrix;
}

void calc_prob(float **matrix) // Olasiliklar tek tek hesaplanip matrise yazilir.
{
	int i, j, k, sum;
	
	for(i=1; i<=6; i++){
		
		for(j=1; j<=6; j++){
			
			for(k=1; k<=6; k++){
				sum = i + j + k;
				matrix[sum-3][1] += (float) 1 / (6*6*6);
			}
		}
	}
	
	// return matrix;
}

void print_probs(float **matrix, int nRow) // Matris yazdirilir.
{
	int i;
	
	printf("Toplam Olasilik:\n\n");
	
	for(i=0; i<nRow; i++){
		printf("%f\t%f\n", matrix[i][0], matrix[i][1]);
	}
}

void free_matrix(float **matrix, int nRow) // Bellegin gereksiz kullanimini engellemek icin hafizadaki yer bosaltilir.
{
	int i;
	
	// Bellek, satir satir bosaltilir. (Once, alinan diziler serbest birakilir.)
	
	for(i=0; i<nRow; i++){ 
		free(matrix[i]); // Matrisin i. degeri 'free' yapilir.
	}
	
	free(matrix); // Matrisin hepsini tutan pointerin bellekteki yeri bosaltilir.
}

int main()
{
	float **matrix;
	int nRow = 16, nColumn = 2;
	
	matrix = initialize_matrix(nRow, nColumn);

	calc_prob(matrix);
	
	print_probs(matrix, nRow);
	
	free_matrix(matrix, nRow);
	
	getch();
	
	return 0;
}
