#include "play.h"

// Fonction principale
void play() {

// initialization of the game
    int nbrPlayer = nbrPlayers(); // Declaration of the number of players
    Player playerList[nbrPlayer]; // Declaration of the player list
    Hexagon grid[L][C]; // Declaration of the grid
    

    playersName(playerList, nbrPlayer); // Declarion of player names
    givePenguin(playerList, nbrPlayer); // penguin attribution
    setZero(playerList, nbrPlayer); // score initialization
    setValue(grid); // initialization of fish on the grid
    placePenguin(grid, nbrPlayer, playerList); // placement of penguins on the grid
    printf("La partie est correctement initialisée\n");

    
// turns and movement of penguins management 
    
    displayAll(grid, nbrPlayer, playerList);

    
    displayStackOfFish(grid);
    printf("\n");
    // displayValue(grid);
    // printf("\n");
    displayStatus(grid);
    printf("\n");
    

    while(isAnyMoveAvailable(nbrPlayer, playerList, grid) != 0) {
        printf("Debut du tour\n");
        gameTurn(nbrPlayer, playerList, grid);
        displayAll(grid, nbrPlayer, playerList);

        
        displayStackOfFish(grid);
        printf("\n");
        // displayValue(grid);
        // printf("\n");
        displayStatus(grid);
        printf("\n");
        
    }
    
    for (int i = 0; i < nbrPlayer; i++) {
        free(playerList[i].penguin);
    }
}