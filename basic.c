#include<stdio.h>
#include<stdlib.h>
int binaryToDecimal(int num){
    int val=0;
    int index=0;
    while(num>0){
        val+=((num%10)*(1<<index));
        num/=10;
        index++;
    }

    return val;
}
int main(){
    
    printf("%d",binaryToDecimal(1011));

}