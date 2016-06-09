#include "stdlib.h"
#include "stdio.h"

void merge(int * result, int * first,int * second)
{
	int zF = sizeof(first);
	int zS = sizeof(second);
	int iR=0,iF=0,iS=0;
	while(iF < zF || iS < zS)
	{
		if(iF>zF)
		{
			result[iR]=second[iS];
			iS++;
			iR++;
			continue;
		}
		if(iS>zS)
		{
			result[iR]=first[iF];
			iF++;	
			iR++;
			continue;
		}

		if(first[iF]<second[iS])
		{
			result[iR]=first[iF];
			iF++;
		}
		else
		{
			result[iR]=second[iS];
			iS++;
		}
		iR++;
	}
}  

int main(int argc,char** argv)
{
	int * i = malloc(sizeof(int)*30);
	int a[8] ={1,2,3,4,5,6,7,8};
	int b[8] = {1,2,3,4,5,6,7,8};
	merge(i,a,b);
	for(int z = 0;z<16;z++){
		printf("[%d],",i[z]);
	}
	printf("\n","");
}

