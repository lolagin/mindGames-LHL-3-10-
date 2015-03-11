//
//  main.c
//  MindGames
//
//  Created by Lolagin Strange on 3/10/15.
//  Copyright (c) 2015 Lolencorp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int input, answer, question1, question2, wrong;


int mainMenu(int input){
    printf("Welcome to Zach's Math Game!\n");
    printf("Press 1 to start the game\n");
    printf("Press 2 to exit\n");
    
    scanf("%d", &input);
    
    question1 = arc4random() %21;
    question2 = arc4random() %21;
    if (input == 1) {
        printf("Question 1: %d + %d\n", question1, question2);
        
        scanf("%d", &answer);
        if (question1 + question2 == answer) {
            printf("correct!\n");
            wrong = 0;
        }
        else {
            printf("wrong!\n ");
            wrong = 1;
            
            
        }
        
    }
    if (input == 2) {
        exit(0);
    }
    
    return 0;
    
}


int main() {
    mainMenu(input);
    
    if (mainMenu(wrong = 1)) {
        mainMenu(input);
    }
    
    
    
    return 0;
}
