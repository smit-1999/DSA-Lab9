#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int n,m,x;
	scanf("%d %d %d",&n,&m,&x);
	int arr1[n],arr2[m];
	int prSum1[n],prSum2[m];
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr1[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&arr2[i]);
	}
	prSum1[0] = arr1[0];
	for(int i=1;i<n;i++){
		prSum1[i]=prSum1[i-1]+arr1[i];
	}
	prSum2[0] = arr2[0];
	for(int i=1;i<m;i++){
		prSum2[i]=prSum2[i-1]+arr2[i];
	}
	int max = -1;
	int count = 0;
	for(int i=0;i<n;i++){
		if(prSum1[i]<=x) {
			count+=1;
			if(count>max) max = count;
		}
	}
//	printf("%d %d\n",max,count);
	count = 0;
	for(int i=0;i<m;i++){
		if(prSum2[i]<=x) {
			count+=1;
			if(count>max) max = count;
		}
	}
//	printf("%d %d\n",max,count);
	
	for(int i=0;i<m;i++){
		int tmp=i+1;
		int tmpSum=prSum2[i];
		for(int j=0;j<n;j++){
			if(arr1[j]+tmpSum<=x){
				tmp+=1;
				tmpSum+=arr1[j];
			}
			else{
				break;
			}
		}
		if(tmp>max && tmpSum<=x) {			
		//	printf("%d %d %d\n",max,tmp,i);	
			max=tmp;
		}
	}
//	printf("max1:%d\n",max);
/*	for(int l=0;l<n;l++){
		printf("%d ",prSum1[l]);
	}*/
//	printf("\n");
	for(int i=0;i<n;i++){
		int tmp=i+1;
		int tmpSum = prSum1[i];
		for(int j=0;j<m;j++){
			if(arr2[j]+tmpSum<=x){
				tmp+=1;
				tmpSum+=arr2[j];
			}
			else break;
		}
	//	printf("%d %d %d\n",tmpSum,tmp,i);
		if(tmp>max && tmpSum<=x) {
		//	printf("%d %d %d\n",max,tmp,i);
			max=tmp;	
		}
	}
	printf("%d",max);
}

/*
5 4 10
4 2 4 6 1
2 1 8 5
*/
