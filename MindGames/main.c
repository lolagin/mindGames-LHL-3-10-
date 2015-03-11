//
//  main.c
//  MindGames
//
//  Created by Lolagin Strange on 3/10/15.
//  Copyright (c) 2015 Lolencorp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct {
    int lives;
    int points;
    char name;
} Player;

Player player1;
Player player2;

bool isRunning = true;

int input, answer, question1, question2, wrong;

void resetPlayers ();
void mainMenu();
void setNames();
void question();



int main() {
#pragma mark isRunning
    while (isRunning) {
        
        setNames();
       
        
        }
        
    
    
    return 0;
}



void mainMenu(){
    int input;
    printf("Welcome to our Math Game!\n");
    
    printf("Press 1 to start the game\n");
    printf("Press 2 to exit\n");
    
    scanf("%d", &input);
    if (input == 2) {
        isRunning = false;
    }
    else if (input == 1) {
        question();
    }
    
}

void setNames() {
    printf("Welcome to our Math Game!\n");
    printf("Please enter player 1's name\n");
    scanf("%s", &player1.name);
    printf("Please enter player 2's name\n");
    scanf("%s", &player2.name);
    printf("Hello, %s and %s\n", &player1.name, &player2.name);
    mainMenu();
    
}


void question () {
    resetPlayers();
    bool isLives = (player1.lives == 0 || player2.lives == 0);
    printf("islives???:  %d", isLives);
    bool turn = true;
    int i = 0;
        Player currentPlayer;
    
    while (!isLives) {
        i++;

            if (turn) {
                currentPlayer = player1; }
            else {
                currentPlayer = player2; }

        question1 = arc4random() %21;
        question2 = arc4random() %21;

        printf("%c: Question %d: %d + %d\n", currentPlayer.name, i, question1, question2);
        scanf("%d", &answer);
        if (question1 + question2 == answer) {
            printf("correct!\n");
            currentPlayer.points++;
            turn = !turn;
        }
        else {
            printf("wrong!\n ");
            currentPlayer.lives--;
            printf("you have %d lives!\n", currentPlayer.lives);
            turn = !turn;
        }
    }
    char loser;
    char winner;
    int winPoints;
    if (player1.points == 0){
        loser = player1.name;
        winner = player2.name;
        winPoints = player2.points;}
    else {
        loser = player2.name;
        winner = player1.name;
    winPoints = player1.points;}
    printf("GAME OVER!\n%s is the LOSER; %s wins with %d points!!! see ya next time!\n",&loser, &winner, winPoints);
    mainMenu();
}


void resetPlayers (){
    player1.points = 0;
    player1.lives = 3;
    player2.points = 0;
    player2.lives = 3;
    
}




