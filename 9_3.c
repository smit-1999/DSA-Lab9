#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int q;
	scanf("%d",&q);
	int query[q];
	int max = -1;
	for(int i=0;i<q;i++){
		scanf("%d",&query[i]);
		if(query[i] > max) max = query[i];
	}
//	printf("max%d\n",max);
	int num[max+1];
	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	num[3] = 3;	
	int min = 100000;
	for(int i=4;i<=max;i++){
		int tmp=100000;
		for(int j=0;j<=i-1;j++){
			if(tmp>i-j+num[j]) {
				tmp = i-j+num[j];
			}
		//	printf("%d %d\n",j,tmp);			
			//printf("minsofar%d",tmp);
		}
		//printf("tmpafter1:%d\n",tmp);
		for(int j=0;j<=i-1;j++){
			for(int k=0;k<=i-1;k++){
				if(j*k == i){
					//printf("found product %d %d\n",j,k);
					if(tmp>num[((j>k)?j:k)]+1)
					tmp = num[((j>k)?j:k)]+1;
				}
			}
			//printf("minofproduct:%d\n",tmp);
		}
		
		num[i] = tmp;
		//for(int l=0;l<=i;l++) printf("%d ",num[l]);
		//printf("\n\n");		
	}
	for(int i=0;i<q;i++){
		printf("%d\n",num[query[i]]);
	}
}
