#include<stdio.h>

int handshake(int n) {
  
  if (n<=1) {
    return 0;
  }
 return (n-1 + handshake(n-1));
} 



int main(int argc,char *argv[]) {
  
  int n,xeirapsies;
  
  printf("Posa atoma:\n");
  scanf("%d", &n);
  xeirapsies=handshake(n);
  printf("%d\n", xeirapsies);
  return 0;
}