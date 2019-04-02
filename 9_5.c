#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort(int * freq,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(freq[i]<freq[j]){
				int t = freq[i];
				freq[i] = freq[j];
				freq[j] = t;
			}
		}
	}			
}
int main(){
	char str[50];
	scanf("%s",str);
	int freq[256];
	for(int i=0;i<256;i++) freq[i] = 0;
	for(int i=0;i<strlen(str);i++){
		freq[str[i]] += 1;
	}
	sort(freq,256);
	int sum = 0;
	for(int k=0;k<256;k++) sum += freq[k];
	for(int i=0;i<256;i++){
		if(freq[i] == 0) continue;
		else{
			if(freq[i] > sum-freq[i]+1){
				printf("Not possible");
				exit(0);
			}
			else{
				int t = freq[i];
				freq[i] = 0;
				for(int j=i+1;j<256;j++){
					if(freq[j]!=0 && freq[j]>=t) {
						freq[j] = 0;
						t=0;
					}
					else if(freq[j]!=0 && freq[j]<t){
						freq[j] = 0;
						t -= freq[j];
					}
					if(t<=0){
						freq[j] += (-1*t);
						break;
					}					
				}
				sort(freq,256);
				for(int k=0;k<256;k++) sum+=freq[k];
			}
		}
	}
	printf("Possible");
}
