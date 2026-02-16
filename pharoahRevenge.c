#include <stdio.h>
#define KINGS_CHAMBER 1
#define DARK_CORRIDOR 2
#define EXIT_CHAMBER 3
#define MAX_TIME 10

int main () {
int playAgain = 1;
while (playAgain == 1) {
int currentRoom = KINGS_CHAMBER;
int timeLeft = MAX_TIME;
int gameOver = 0;
printf("\nYou are an archaeologist who one day wakes up in the 26th C.B.E. in the Pyramid of Giza.");
printf("You are inside the tomb of Pharaoh Khufu, accidently disturbing his slumber. Your mission");
printf("is to escape the tomb by avoiding deadly traps and unlocking ancient mechanisms before the Pharaoh enacts his revenge.\n");

while (!gameOver && timeLeft > 0) {
	switch(currentRoom) {
	case KINGS_CHAMBER: {
	 int choice;
	printf("Kings Chamber:\nYou are encapsulated in darkness.\n");
	printf("Check inventory? 1 = yes 0 = no \n");
    scanf("%d", &choice);
    if(choice == 0){
       printf("You did not check your inventory. You are unable use item.\n");
       printf("You are unable to navigate in the darkness\n");
       gameOver = 1;
       break;
    } else if(choice == 1){
        printf("You have a torch. Light it? 1 = yes 0 = no \n");
        scanf("%d", &choice);

        if(choice == 0){
            printf("You are unable to navigate in the darkness\n");
            gameOver = 1;
        } else if(choice ==1){
            printf("You are able to navigate in the darkness\n");
            printf("You make it out of the Kings Chambers\n"); 
            currentRoom = DARK_CORRIDOR; 
        }
    }
    break;    
} 


if (gameOver || timeLeft == 0){
    printf("You Died\n");

}
int choice;
printf("Play again? 1 = yes 0 = no\n");
scanf("%d", &choice);

if(choice == 1){
    playAgain = 1;
} else {
    playAgain = 0;
    printf("Goodbye\n");     
    }
    return 0;   
    } 

// timeleft,  before starting Dark Corridor

   



