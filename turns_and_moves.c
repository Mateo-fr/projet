#include "turns_and_moves.h"

int isAnyMoveAvailable(int nbrPlayers, Player playerList[], Hexagon grid[L][C]) { 
    // Check if at least one move is available
    
    int possible = 0;
    for (int i = 0; i < nbrPlayers; i++) {
        for (int j = 0; j < playerList[i].nbrPenguin; j++) {
            for (int k = 1; k < 7; k++) {
                switch (k) {
                    case 1:
                        if (playerList[i].penguin[j].x - 1 >= 0 && grid[playerList[i].penguin[j].y][playerList[i].penguin[j].x - 1].status == 1) {
                            possible += 1;
                        }
                        break;

                    case 2:
                        if (playerList[i].penguin[j].y % 2 == 0) {
                            if (playerList[i].penguin[j].y - 1 >= 0 && playerList[i].penguin[j].x - 1 >= 0 && grid[playerList[i].penguin[j].y - 1][playerList[i].penguin[j].x - 1].status == 1) {
                                possible += 1;
                            }
                        } else {
                            if (playerList[i].penguin[j].y - 1 >= 0 && grid[playerList[i].penguin[j].y - 1][playerList[i].penguin[j].x].status == 1) {
                                possible += 1;
                            }
                        }
                        break;

                    case 3:
                        if (playerList[i].penguin[j].y % 2 == 0) {
                            if (playerList[i].penguin[j].y + 1 < L && playerList[i].penguin[j].x - 1 >= 0 && grid[playerList[i].penguin[j].y + 1][playerList[i].penguin[j].x - 1].status == 1) {
                                possible += 1;
                            }
                        } else {
                            if (playerList[i].penguin[j].y + 1 < L && grid[playerList[i].penguin[j].y + 1][playerList[i].penguin[j].x].status == 1) {
                                possible += 1;
                            }
                        }
                        break;

                    case 4:
                        if (playerList[i].penguin[j].x + 1 < C && grid[playerList[i].penguin[j].y][playerList[i].penguin[j].x + 1].status == 1) {
                            possible += 1;
                        }
                        break;

                    case 5:
                        if (playerList[i].penguin[j].y % 2 == 0) {
                            if (playerList[i].penguin[j].y - 1 >= 0 && grid[playerList[i].penguin[j].y - 1][playerList[i].penguin[j].x].status == 1) {
                                possible += 1;
                            }
                        } else {
                            if (playerList[i].penguin[j].y - 1 >= 0 && playerList[i].penguin[j].x + 1 < C && grid[playerList[i].penguin[j].y - 1][playerList[i].penguin[j].x + 1].status == 1) {
                                possible += 1;
                            }
                        }
                        break;

                    case 6:
                        if (playerList[i].penguin[j].y % 2 == 0) {
                            if (playerList[i].penguin[j].y + 1 < L && grid[playerList[i].penguin[j].y + 1][playerList[i].penguin[j].x].status == 1) {
                                possible += 1;
                            }
                        } else {
                            if (playerList[i].penguin[j].y + 1 < L && playerList[i].penguin[j].x + 1 < C && grid[playerList[i].penguin[j].y + 1][playerList[i].penguin[j].x + 1].status == 1) {
                                possible += 1;
                            }
                        }
                        break;

                    default:
                        printf("Erreur sw winner");
                        break;
                }
            }
        }
        if (possible == 0) {
            printf("Le joueur %d ne peut plus déplacer ses pingouin \n", i + 1);
        }
    }
    printf("Encore %d mouvements possibles\n", possible);
    return possible;
}

void move(int choice, int turn, Player playerList[], int distance, int direction, Hexagon grid[L][C]) { 
    // Make the move
    switch (direction) {
        case 1:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                playerList[turn].penguin[choice].x -= 1;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 2:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                
                if (playerList[turn].penguin[choice].y % 2 == 0) {
                    playerList[turn].penguin[choice].y -= 1;
                    playerList[turn].penguin[choice].x -= 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;

                } else {
                    playerList[turn].penguin[choice].y -= 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                }
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 3:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                if (playerList[turn].penguin[choice].y % 2 == 0) {
                    playerList[turn].penguin[choice].y += 1;
                    playerList[turn].penguin[choice].x -= 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                } else {
                    playerList[turn].penguin[choice].y += 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                }
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 4:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                playerList[turn].penguin[choice].x += 1;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 5:
        
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                if (playerList[turn].penguin[choice].y % 2 == 0) {
                    playerList[turn].penguin[choice].y -= 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                } else {
                    playerList[turn].penguin[choice].y -= 1;
                    playerList[turn].penguin[choice].x += 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                }
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 6:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                if (playerList[turn].penguin[choice].y % 2 == 0) {
                    playerList[turn].penguin[choice].y += 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                } else {
                    playerList[turn].penguin[choice].y += 1;
                    playerList[turn].penguin[choice].x += 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                }
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        default:
            printf("Erreur switch move\n");
            break;
    }
}

int isMovePossible(int direction, int distance, int turn, int choice, Player playerList[], Hexagon grid[L][C]) { // check if the move is possible

    int py = playerList[turn].penguin[choice].y;
    int px = playerList[turn].penguin[choice].x;

    switch (direction) {
        case 1:
            for(int i = 0; i< distance; i++) {
                if(px -1 < 0){
                    printf("Vous sortez du plateau !\n");
                    return 1;
                }
                if(grid[px -1][py].status != 1){
                    printf("Obstable sur la route !\n");
                    return 1;
                }
                else{
                    printf("mouvement valide");
                    px -= 1;
                }
            }
        return 2;
        break;

        case 2:
            for(int i = 0; i< distance; i++){
                if(py%2 == 0){
                    if(px -1 < 0 || py -1 < 0){
                        printf("Vous sortez du plateau !\n");
                        return 1;
                    }
                    if(grid[px - 1][py - 1].status != 1){
                        printf("Obstable sur la route !\n");
                        return 1;
                    }
                    else{
                        py -= 1;
                        px -= 1;
                    }
                }
                else{
                    if(py -1 < 0){
                        printf("Vous sortez du plateau !\n");
                        return 1;
                    }
                    if(grid[px][py - 1].status != 1 ){
                        printf("Obstable sur la route !\n");
                        return 1;
                    }
                    else{
                        py -= 1;
                    }
                }
            }
        return 2;
        break;

        case 3:
            for(int i = 0; i< distance; i++){
                if(py%2 == 0){
                    if(px -1 < 0 || py +1 > 8){
                        printf("Vous sortez du plateau !\n");
                        return 1;
                    }
                    if(grid[px - 1][py + 1].status != 1){
                        printf("Obstable sur la route !\n");
                        return 1;
                    }
                    else{
                        py += 1;
                        px -= 1;
                    }
                }
                else{
                    if(py +1 > 8){
                        printf("Vous sortez du plateau !\n");
                        return 1;
                    }
                    if(grid[px][py + 1].status != 1){
                        printf("Obstable sur la route !\n");
                        return 1;
                    }
                    else{
                        py += 1;
                    }
                }
            }
        return 2;
        break;

        case 4:
            for(int i = 0; i< distance; i++) {
                if(px +1 > 8){
                    printf("Vous sortez du plateau !\n");
                    return 1;
                }
                if(grid[px + 1][py].status != 1){
                    printf("Obstable sur la route !\n");
                    return 1;
                }
                else{
                    printf("mouvement valide");
                    sleep(4);
                    px += 1;
                }
            }
        return 2;
        break;

        case 5:
            for(int i = 0; i< distance; i++){
                if(py%2 == 0){
                    if(py -1 < 0){
                        printf("Vous sortez du plateau !\n");
                        return 1;
                    }
                    if(grid[px][py - 1].status != 1){
                        printf("Obstable sur la route !\n");
                        return 1;
                    }
                    else{
                        py -= 1;
                    }
                }
                else{
                    if(py -1 < 0 || px + 1 > 8){
                        printf("Vous sortez du plateau !\n");
                        return 1;
                    }
                    if(grid[px + 1][py - 1].status != 1){
                        printf("Obstable sur la route !\n");
                        return 1;
                    }
                    else{
                        py -= 1;
                        px += 1;
                    }
                }
            }
        return 2;
        break;

        case 6:
            for(int i = 0; i< distance; i++){
                if(py%2 == 0){
                    if(py +1 > 8){
                        printf("Vous sortez du plateau !\n");
                        return 1;
                    }
                    if(grid[px][py + 1].status != 1){
                        printf("Obstable sur la route !\n");
                        return 1;
                    }
                    else{
                        py += 1;
                    }
                }
                else{
                    if(py +1 > 8 || px + 1 > 8){
                        printf("Vous sortez du plateau !\n");
                        return 1;
                    }
                    if(grid[px + 1][py + 1].status != 1 ){
                        printf("Obstable sur la route !\n");
                        return 1;
                    }
                    else{
                        py += 1;
                        px += 1;
                    }
                }
            }
        return 2;
        break;

        default:
            return 1;
            printf("Erreur sw moveverification");
        break;
    }
}

void choiceMove(int choice, Player playerList[], int turn, Hexagon grid[L][C]) { // Make the player choose the move

    int direction = 0;
    int distance = 0;

    do {
        printf("Choose direction : \n");
        printf("1 : Haut\n2 : Haut-Gauche\n3 : Haut-Droite\n4 : Bas\n5 : Bas-Gauche\n6 : Bas-Droite \n"); 
        if (scanf("%d", &direction) != 1) {  // Check input, ensure it's a number
            printf("Invalid input. ");  
            while (getchar() != '\n');  // Clear input buffer to discard incorrect inputs
            continue;  // Continue the loop
        }
        if (direction < 1 || direction > 6) { 
            printf("Invalid input. Choose valid option. ");
        } 
    } while (direction < 1 || direction > 6); 
    
    do { 
        printf("Choose distance : \n");
        if (scanf("%d", &distance) != 1) {  // Check input, ensure it's a number
            printf("Invalid input. ");  
            while (getchar() != '\n');  // Clear input buffer to discard incorrect inputs
            continue;  // Continue the loop
        }
        if ( distance < 1 || distance > 8) { 
            printf("Invalid input. Choose valid option ");
        } 
    } while (distance < 1 || distance > 8);

    if( isMovePossible(direction, distance, turn, choice, playerList, grid) == 2 ) {
        move(choice, turn, playerList, distance, direction, grid);
    }
    else {
        printf("Mouvement pas valide\n");
        choiceMove(choice, playerList, turn, grid);
    }
}

int isMoveAvailable(int turn, int choice, Player playerList[], Hexagon grid[L][C]) { // check if move is available for one penguin
    int possible = 0;
    int py = playerList[turn].penguin[choice].y;
    int px = playerList[turn].penguin[choice].x;

    for(int i = 1; i < 7; i++) {

        switch (i) {
            case 1:
                if(py -1 < 0) {
                }
                else if(grid[px][py - 1].status != 1) {
                }
                else {
                    possible += 1;
                }
            break;

            case 2:
                if(px % 2 == 0){
                    if(py -1 < 0 || px -1 < 0) {
                    }
                    else if(grid[px - 1][py - 1].status != 1) {
                    }
                    else {
                        possible += 1;
                    }
                }
                else{
                    if(px -1 < 0) {
                    }
                    else if(grid[px - 1][py].status != 1) {
                    }
                    else {
                        possible += 1;
                    }
                }
            break; 

            case 3:
                if(px % 2 == 0) {
                    if(py -1 < 0 || px +1 > 8) {
                    }
                    if(grid[px + 1][py - 1].status != 1) {
                    }
                    else {
                        possible += 1;
                    }
                }
                else{ // a changer les valeurs calculs
                    if(px +1 > 9) {
                    }
                    if(grid[px + 1][py - 1].status != 1) {
                    }
                    else {
                        possible += 1;
                    }
                }
            break;
            
            case 4:
                if(py +1 > 9) {
                }
                else if(grid[px][py + 1].status != 1) {
                }
                else {
                    possible += 1;
                }
            break;

            case 5:
                if(px % 2 == 0) { // a modif les valeurs calcul
                    if(px -1 < 0){
                    }
                    else if(grid[px - 1][py].status != 1){
                    }
                    else{
                        possible += 1;
                    }
                }
                else{
                    if(py + 1 > 8 || px -1 < 0){
                    }
                    else if(grid[px - 1][py + 1].status != 1){
                    }
                    else{
                        possible += 1;
                    }
                }
            break;

            case 6:
                if(px % 2 == 0) { // a modif les valeurs calcul
                    if(py +1 > 8){
                    }
                    else if(grid[px + 1][py].status != 1){
                    }
                    else{
                        possible += 1;
                    }
                }
                else{
                    if(py +1 > 8 || px +1 > 8){
                    }
                    else if(grid[px + 1][py + 1].status != 1){
                    }
                    else{
                        possible += 1;
                    }
                }
            break;
            default:
                printf("Erreur sw isMovepossible");
            break;
        }
    }
    return possible;
}

void gameTurn(int nbrPlayers, Player playerList[], Hexagon grid[L][C]) { // Play turns

    int choiceP = 0;
    int turn = 0;

    for(int i = 0; i < nbrPlayers; i++) {
        printf("C'est au tour du joueur : %d\n", i+1);
        do{
            printf("choisisser un pingouin capable de bouger : \n");
            if(scanf("%d", &choiceP) != 1) {
                printf("Mauvaise saisie. ");
                while (getchar() != '\n');
                continue;
            }
        }while(choiceP - 1 < 0 || choiceP - 1 > playerList[i].nbrPenguin || isMoveAvailable(turn, choiceP - 1, playerList, grid) == 0);
        choiceMove(choiceP - 1, playerList, turn, grid);
        turn += 1;
        displayAll(grid, nbrPlayers, playerList);
    }
}