#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sol[100];
//j i
int ver_diag(int nracum,int term){
	int i;
	for(i = term; i >= 0; i --){
		if((nracum + ((term-i)+1) == sol[i]) || (nracum - ((term-i)+1 )== sol[i]))
			return 0;
	}
	return 1;
}
int ver_linie(int nracum,int term){
	int i;
	for(i = term; i >= 0; i --){
		if(nracum == sol[i])
			return 0;
	}
	return 1;
}


void dama(int n , int i, int fostult){
	int j=fostult + 1;
	if(i!=-1)
	while(j < n){
		//printf("\n\n\n ga %d %d \n\n\n",i,j);
		if((ver_linie(j,i)==1) && (ver_diag(j,i)==1)){//printf("%d %d n\n",i,j);
			break;
		}
		j++;
	}
	//printf("%d %d\n\n",i,j);
	if (i==n-1){
		for(int h=0; h<=i; h++){
				printf("%d ",sol[h]);
		}
	printf("\n");}
	if(j==n){
		if(i==-1){
			return;	
		}
		dama(n,i-1,sol[i]);
		
	}
	if(i!=n-1 && j!=n){
		sol[i+1]=j;
		dama(n,i+1,-1);
	}
	//if(i==n-1 && j!=n){
		//printeazza sol
		//for(int h=0; h<n; h++){
			//printf("%d ",sol[h]);
		//}
		//printf("\n");
		//dama(n,i,j);
	//}


}

int main() {
	//printf("\n\nccc\n\n");
	dama(5,0,-1);
	return 0;
}

