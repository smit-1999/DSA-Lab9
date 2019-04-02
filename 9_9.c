#include <stdio.h>
#include <stdlib.h>
void sort(int * arr,int n,int * capital,int  * profit){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				int t = arr[i];
				int tmp = capital[i];
				int tmp2 = profit[i]; 
				
				arr[i] = arr[j];
				capital[i] = capital[j];
				profit[i] = profit[j];
				
				arr[j] = t;
				capital[j] = tmp;
				profit[j] = tmp2; 
			}
		}
	}
}
int main(){
	int k,w,n;
	scanf("%d %d %d",&k,&w,&n);
	int profit[n];
	int capital[n];
	int visited[n];
	for(int i=0;i<n;i++){
		scanf("%d",&profit[i]);
		visited[i] = 0;
	}
	 
	for(int i=0;i<n;i++){		
		scanf("%d",&capital[i]);		
	}
	int diff[n];
	for(int i=0;i<n;i++){
		diff[i] = profit[i]-capital[i];
	}
	sort(profit,n,capital,profit);

	int count =  0;
	int flag = 1,currCapital = w;
	
	
	while(flag){
		if(count == k || count == n) {
			flag = 0;
			break;
		}
		int loopFlag = 0;
		for(int i =0;i<n;i++){
			if(visited[i] == 0 && currCapital >= capital[i]){
				visited[i] = 1;
				currCapital += profit[i];
				count += 1;
				loopFlag = 1;
				break; 
			}
		}
		printf("%d ",currCapital);
		if(loopFlag == 0) break;
	
	}
	printf("\n%d",currCapital);
		
}
