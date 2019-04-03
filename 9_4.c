#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	int dist[n],petrol[n];
	for(int i=0;i<n;i++){
		scanf("%d %d",&petrol[i],&dist[i]);
	}
	for(int i=0;i<n;i++){
		int currCapacity = petrol[i],flag = 1;
		for(int j=i+1;j<n;j++){
			if(currCapacity < dist[j-1]){
				flag = 0;
				break;
			}
			else{
				currCapacity -= dist[j-1];
				currCapacity += petrol[j]; 
			}
		}
		if(flag == 1){
			if(currCapacity >= dist[n-1]){
				currCapacity -= dist[n-1];
				currCapacity += petrol[0];
				int j=1;
				for( j=1;j<=i;j++){
						if(currCapacity >= dist[j-1]){
							currCapacity -= dist[j-1];
							currCapacity += petrol[j];
						}
						else{
							break;
						}				
				}
				if(j == i+1) {
					printf("%d",i);
					exit(0);
						
				}
			}
			else{
				continue;
			}

				
		} 

	}
}
