#include <stdio.h>
#include <stdlib.h>
#include "comparison.h"

int main()
{
	/*
	Soru: Bir sirket, calisanlarinin yaslarini bir dizide tutmaktadir. En yasli 3 calisanin yaslari toplamini, tek
	bir donguyle, baska bir C dosyasina yazdiginiz karsilastirma fonksiyonunu yeni bir header dosyasina dahil
	edip algoritmanizda kullanarak C projenizi olusturun.
	*/
	
	int arr[] = {27, 32, 23, 45, 30, 19, 34, 27, 33, 20, 37, 29, 39, 51};
	int N = (sizeof(arr) / sizeof(int));
	int i, max1 = 0, max2 = 0, max3 = 0;
	
	for(i=0; i<N; i++){
		
		if(compare(arr[i], max1)){
			max3 = max2;
			max2 = max1;
			max1 = arr[i];
		}
		else if(compare(arr[i], max2)){
			max3 = max2;
			max2 = arr[i];
		}
		else if(compare(arr[i], max3)){
			max3 = arr[i];
		}
	}
	
	int sum = max1 + max2 + max3;
	
	printf("Sirasiyla en yasli uc kisi           =  %d %d %d\n", max1, max2, max3);
	printf("En yasli uc kisinin yaslari toplami  =  %d\n", sum);
	
	getch();
	
	return 0;
}
