
#include"includes.h"

 void cocktail_sort(int list[10])
{
  
	 int length,bottom,top, swapped,i,aux;
    length=10;
    bottom = 0;
    top = length - 1;
    swapped = 0; 
    while(swapped == 0 && bottom < top)//Se n�o houver troca de posi��es ou o ponteiro que
    {                                   //sobe ultrapassar o que desce, o vetor esta ordenado
        swapped = 1; 
        //Este for � a �ida� para a direita
        for(i = bottom; i < top; i = i + 1)
        {
            if(list[i] > list[i + 1])   //indo pra direita:testa se o pr�ximo � maior
            {   //indo pra direita:se o proximo � maior que o atual,
                //troca as posi��es
                aux=list[i];
                list[i]=list[i+1];
                list[i+1]=aux;
                swapped = 0;
            }
        }//fecha for
        // diminui o  `top` porque o elemento com o maior valor 
        // j� est� na direita (atual posi��o top)
        top = top - 1; 
        //Este for � a �ida� para a esquerda
        for(i = top; i > bottom; i = i - 1)
        {  if(list[i] < list[i - 1]) 
            {
                aux=list[i];
                list[i]=list[i-1];
                list[i-1]=aux;
                swapped = 0;
            }
        }
        //aumenta o `bottom` porque o menor valor j� est�
        //na posi��o inicial (bottom) 
        bottom = bottom + 1;  
    }//fecha while 
 }// fim da fun�ao