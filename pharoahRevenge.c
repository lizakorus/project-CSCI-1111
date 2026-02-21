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
	
printf("\nYou are an archaeologist who one day wakes up in the 26th C.B.E. in the Pyramid of Giza.\n");
printf("You are inside the tomb of Pharaoh Khufu, accidently disturbing his slumber.\n");
printf("You must escape the tomb by navigating through The Kings Chamber, then to The Dark Corridor and finally The Exit Chamber.\n");
printf("But beware the deadly traps and remember- you must escape before time runs out and the Pharaoh awakens enacting his revenge. \n");

printf("----------------------------------\n");

while (!gameOver && timeLeft > 0) {
	switch(currentRoom) {
		
	// =========== ROOM 1 - KINGS CHAMBER ============

		case KINGS_CHAMBER: {
			int choice;
			printf("Kings Chamber:\nYou are encapsulated in darkness.\n");
			printf("Do you want to explore the Chamber for useful items? 1 = yes 0 = no \n");
		    scanf("%d", &choice);
	
			if(choice == 1){
		        printf("You have a torch!\n");
			}
			else {
			    printf("You did not check your inventory. You are unable use item.\n");
			    printf("You are unable to navigate in the darkness.\n");
			    gameOver = 1;
			    break;
			}
			printf("Do you want to light the torch? 1 = yes 0 = no \n");
			scanf("%d", &choice);
				
			if (choice == 1){
				printf("You are able to navigate in the darkness.\n");
	            printf("You make it out of the Kings Chambers.\n"); 
	            currentRoom = DARK_CORRIDOR;                  
	        }
			else {
				printf("You are unable to navigate in the darkness.\n");
	            gameOver = 1;	
	    }
	    break;    
	} 
} 
	// =========== ROOM 2 - DARK CORRIDOR ============
    case DARK_CORRIDOR: {
        int choice;
        int stayInRoom = 1;
		
		printf("----------------------------------\n");

		// stayInRoom allows to replay if you fall into the pit
        while (stayInRoom) {
            printf("\nYou are in the Dark Corridor.\nThere is a deep pit.\n");
            printf("Check room for items? 1 = yes, 0 = no\n");
            scanf("%d", &choice);
			
            // If player checks room for items,
			// they find rope needed to cross the pit
            if (choice == 1) {
                printf("You found a rope!\n");
                printf("You use the rope to cross the pit safely.\n");
                currentRoom = EXIT_CHAMBER;
                stayInRoom = 0;

			// If player doesn't check, they fall into the pit,
			// but there is a chance to replay
            } else if (choice == 0) {
                printf("You fall into the pit!\n");
                printf("Replay? 1 = yes, 0 = no\n");
                scanf("%d", &choice);

				// Replay returns player to the DARK CORRIDOR
                if (choice == 1) {
                    stayInRoom = 1;   

				// Player chooses to quit
                } else if (choice == 0) {
                    printf("Goodbye!\n");
                    gameOver = 1;
                    stayInRoom = 0;    
                }
            }
        }
        break;
    }
	// =========== ROOM 3 - EXIT CHAMBER ============

case EXIT_CHAMBER: {

    int choice;
	
	printf("----------------------------------\n");
	printf("\nExit Chamber:\n");

    // Ask if player wants to search for the Ancient Key
    printf("Search for Ancient Key? 1 = yes 0 = no\n");
    scanf("%d", &choice);

    // If player does not search, they die
    if (choice == 0) {
        printf("You are trapped in the tomb.\n");
        gameOver = 1;
        break;
    }

    printf("You found the Ancient Key!\n");

    // Player gets 3 attempts to solve lever puzzle
    int attempts = 3;
    int solved = 0;  // 0 = not solved, 1 = solved

    printf("\nFive ancient levers stand before you.\n");
    printf("The hint reads: 'The door opens with the number 26.'\n");

    // Loop continues while player still has attempts
    while (attempts > 0 && solved == 0) {

        int lever1, lever2, lever3, lever4, lever5;

        printf("\nYou have %d attempts remaining.\n", attempts);
        printf("Set each lever (1 = up, 0 = down)\n");

        printf("Lever 1: ");
        scanf("%d", &lever1);

        printf("Lever 2: ");
        scanf("%d", &lever2);

        printf("Lever 3: ");
        scanf("%d", &lever3);

        printf("Lever 4: ");
        scanf("%d", &lever4);

        printf("Lever 5: ");
        scanf("%d", &lever5);

        // Check if sequence matches 11010 (26 in binary)
        if (lever1 == 1 &&
            lever2 == 1 &&
            lever3 == 0 &&
            lever4 == 1 &&
            lever5 == 0) {

            solved = 1;  // Puzzle solved
        }
        else {
            attempts--;  // Remove one attempt
            printf("\nThe levers grind incorrectly...\n");
        }
    }

    // If puzzle solved
    if (solved == 1) {

        printf("\nThe levers shift into place.\n");
        printf("A hidden stone door appears.\n");

        printf("Use Ancient Key to unlock it? 1 = yes 0 = no\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You unlock the door.\n");
            printf("You escape!\n");
        }
        else {
            printf("You hesitate. Time runs out.\n");
            printf("You Died\n");
        }
    }
    else {
        // Player failed all attempts
        printf("\nYou failed all attempts.\n");
        printf("The Pharaoh awakens!\n");
        printf("You Died\n");
    }

    // End the round
    gameOver = 1;
    break;
}
// If timer runs out
if (timeLeft == 0) {
    printf("Time has run out.\n");
    printf("You Died.\n");
}

// Ask player if they want to replay
int replayChoice;
printf("\nPlay again? 1 = yes 0 = no\n");
scanf("%d", &replayChoice);

if (replayChoice == 1) {
    playAgain = 1;  // Restart the game
}
else {
    playAgain = 0;  // Exit the game
    printf("Goodbye\n");
}
return 0;
    }
}
}
}





