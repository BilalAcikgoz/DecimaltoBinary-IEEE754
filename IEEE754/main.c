#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) 
{
	int sayi1, sayi3, kayanNoktaSayisi;
	float sayi2, kalanSayi;
    	
	printf("Cevirmek istediginiz sayi degerini giriniz: ");  
	scanf("%f", &sayi2);
	
	sayi1 = sayi2;
	kalanSayi = sayi2 - sayi1;
    
 // INT TO BINARY
    
    int i, j;
	sayi3 = sayi1;	
		
	for(i = 0; sayi1 >= 2; i++)
		sayi1 /= 2;        

	int *intDizi = malloc(sizeof(int) * i);
	int *intDizi2 = malloc(sizeof(int) * i);
	
	for(j =0;;j++)
	{
		if(sayi3 < 2)
		{
			intDizi[j] = sayi3 % 2;   
			break;
		}
	
		intDizi[j] = sayi3 % 2;  
		sayi3 /= 2;
	} 
	
	for(int k = j, m = 0; k >= 0; k--, m++)
	{
		intDizi2[m] = intDizi[k];
		kayanNoktaSayisi++;
	}
	
	kayanNoktaSayisi -= 1;  

 // FLOAT TO BINARY 
 
    int *kalanDizi;
	kalanDizi = (int *)(malloc(sizeof(int) * 23));  
	
	for(int i = 0; i < 23; i++)
	{
		kalanSayi *= 2;  
		
		if(kalanSayi > 1)
		{
			kalanDizi[i] = 1;
			kalanSayi -= 1;  
		}
		
		else if(kalanSayi < 1)
		{
			kalanDizi[i] = 0; 
		}
		
		else if(kalanSayi == 1)
		{
		    kalanDizi[i] = 1; 
		}    
	}		  
	
	
	for(int j = 0; j < 23; j++)
	{   	
	    if (kalanDizi[j] != 0 && kalanDizi[j] != 1)
            break;   
	     
    }
    
 // EXPONENT KISMI
 
    int exponent = kayanNoktaSayisi + 127;
    int exponentCopy = exponent;
    
    if(sayi2 < 0)
      printf("1  -  ");
    else
	  printf("0  -  ");  
    
    for(int i = 0; exponent >= 2; i++)
        exponent /= 2;
        
    int *exponentDizi = malloc(sizeof(int) * i);
	
	for(int j = 0;; j++)
	{
		if(exponentCopy < 2)
		{
			exponentDizi[j] = exponentCopy % 2;
			break;
		}
		
		exponentDizi[j] = exponentCopy % 2;
		exponentCopy /= 2;
	}
	
	for(int k = j; k >= 0; k--)
	   printf("%d  ", exponentDizi[k]); 
	   
	printf("-  ");   
	   
 // MANTISSA KISMI	 
 
    int *mantissaDizi = malloc(sizeof(int) * 23);
	int l;
	
	for(int i = j - 1, k = 0; i >= 0; i--, k++)
	{
		mantissaDizi[k] = intDizi[i];
		l = k + 1;
	}  
	
	for(int j = 0, m = l; j < 23; j++, m++)
	    mantissaDizi[m] = kalanDizi[j];
		
	for(int i = 0; i < 23; i++)
	    printf("%d  ", mantissaDizi[i]);
		
	
	free(intDizi);
	free(intDizi2);
	free(kalanDizi);
	free(exponentDizi);	
	free(mantissaDizi);		    
      
    
	return 0;
}	
