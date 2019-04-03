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
	count = 0;
	for(int i=0;i<m;i++){
		if(prSum2[i]<=x) {
			count+=1;
			if(count>max) max = count;
		}
	}
}
