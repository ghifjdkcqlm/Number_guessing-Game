// the guessing game 
// we will generate a random number and ask the player to guess it. If the player guesses a higher number than the computer generated random number then the program displays 'lower number please'
// similarly if user guess us too low prgrm displays 'higher number please'
// when the user gueses the correct number the program displays the number of guesses taken by player to arrive at the number 

#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
int main() {

    srand(time(0));  
    int num = rand()%100+1;
    //87printf("%d\n", num);  

    //keep running the loop until number is guessed 

    int usernum;
    int flag= 0; 

     printf("enter your guess, any number btw 1 to 100\n");

    do{

       

    scanf("%d",&usernum); 

    if(usernum>num){
        printf("guess lower number\n");
        flag++;
    }
    else if(usernum<num){ 
        printf("guess higher num\n"); 
        flag++;
    }
    else{
        printf("you guessed right\n");
        printf("number of turns taken --> %d",flag);
    }

    }while(usernum!=num);


}
