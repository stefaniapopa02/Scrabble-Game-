//POPA STEFANIA, 315CD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util/scrabble.h"
#include "util/print_board.h"

void task0(char board[BOARD_SIZE][BOARD_SIZE]){
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            board[i][j] = '.';
        }
    }
}

void task1(char board[BOARD_SIZE][BOARD_SIZE]){

    task0(board);
    int N, i, j, x, y, d, length;
    char *p, *y1, *x1, *d1;
    char input[BOARD_SIZE];
    char q[20];

    fgets(input, BOARD_SIZE, stdin);
    strcpy(q, input);
    N = atoi(q);

    for(i = 1; i <= N; i++){

        fgets(input, 30, stdin);

        p = strtok(input, " ");
        y1 = p;
        y = atoi(y1);

        p = strtok(NULL, " ");
        x1 = p;
        x = atoi(x1);

        p = strtok(NULL, " ");
        d1 = p;
        d = atoi(d1);

        p = strtok(NULL,"\n");

        length = strlen(p);

        if(d == 0){
            for(j = 0; j < length; j++){
                board[y][x] = p[j];
                x++;
            }

        } 
        else if(d == 1){
             for(j = 0; j < length; j++){
                board[y][x] = p[j];
                y++; 
            }
        }

    }

    print_board(board);

}

void task2(){

    int score[25];

    score[0] = 1; // scorul literei 'A'
    score[1] = 3; // scorul literei 'B'
    score[2] = 3; // scorul literei 'C'
    score[3] = 2; // scorul literei 'D'
    score[4] = 1; // scorul literei 'E'
    score[5] = 4; // scorul literei 'F'
    score[6] = 2; // scorul literei 'G'
    score[7] = 4; // scorul literei 'H'
    score[8] = 1; // scorul literei 'I'
    score[9] = 8; // scorul literei 'J'
    score[10] = 5; // scorul literei 'K'
    score[11] = 1; // scorul literei 'L'
    score[12] = 3; // scorul literei 'M'
    score[13] = 1; // scorul literei 'N'
    score[14] = 1; // scorul literei 'O'
    score[15] = 3; // scorul literei 'P'
    score[16] = 10; // scorul literei 'Q'
    score[17] = 1; // scorul literei 'R'
    score[18] = 1; // scorul literei 'S'
    score[19] = 1; // scorul literei 'T'
    score[20] = 1; // scorul literei 'U'
    score[21] = 4; // scorul literei 'V'
    score[22] = 4; // scorul literei 'W'
    score[23] = 8; // scorul literei 'X'
    score[24] = 4; // scorul literei 'Y'
    score[25] = 10; // scorul literei 'Z'

    int player1 = 0, player2 = 0;

    int N, i;
    char *p;
    char input[BOARD_SIZE];
    char nr_w[20];//vector auxiliar in care retinem string-ul reprezentat de numarul de cuvinte introduse
   
    fgets(input, BOARD_SIZE, stdin);
    strcpy(nr_w,input);
    N = atoi(nr_w);

    for(i = 1; i <= N; i++){

        fgets(input, 30, stdin);

        p = strtok(input, " ");
        p = strtok(NULL, " ");
        p = strtok(NULL, " ");
        p = strtok(NULL,"\0");

        if(i % 2 == 1){
            while(*p != '\0'){
                player1+= score[*p - 'A'];
                p++;
            }

        }
        else
        {
            while(*p != '\0'){
                player2+= score[*p - 'A'];
                p++;
            }
        }
    }

    printf("Player 1: %d Points\n", player1);
    printf("Player 2: %d Points\n", player2);
    
}


void task3(){

    int score[25];

    score[0] = 1; // scorul literei 'A'
    score[1] = 3; // scorul literei 'B'
    score[2] = 3; // scorul literei 'C'
    score[3] = 2; // scorul literei 'D'
    score[4] = 1; // scorul literei 'E'
    score[5] = 4; // scorul literei 'F'
    score[6] = 2; // scorul literei 'G'
    score[7] = 4; // scorul literei 'H'
    score[8] = 1; // scorul literei 'I'
    score[9] = 8; // scorul literei 'J'
    score[10] = 5; // scorul literei 'K'
    score[11] = 1; // scorul literei 'L'
    score[12] = 3; // scorul literei 'M'
    score[13] = 1; // scorul literei 'N'
    score[14] = 1; // scorul literei 'O'
    score[15] = 3; // scorul literei 'P'
    score[16] = 10; // scorul literei 'Q'
    score[17] = 1; // scorul literei 'R'
    score[18] = 1; // scorul literei 'S'
    score[19] = 1; // scorul literei 'T'
    score[20] = 1; // scorul literei 'U'
    score[21] = 4; // scorul literei 'V'
    score[22] = 4; // scorul literei 'W'
    score[23] = 8; // scorul literei 'X'
    score[24] = 4; // scorul literei 'Y'
    score[25] = 10; // scorul literei 'Z'

    int player1 = 0, player2 = 0;

    int N, i, j;
    char *p;
    char input[BOARD_SIZE], XX[2], YY[2];
    char nr_w[20];
    char word[20];//cuvantul curent

    int x, y, d, length;
    char *x1, *y1, *d1;

    int score1;// scorul cuvantului curent
   
    fgets( input, 10, stdin );
    strcpy( XX, input);

    fgets( input, 10, stdin );
    strcpy( YY, input );

    fgets( input, BOARD_SIZE, stdin );
    strcpy( nr_w, input );
    N = atoi( nr_w );

    for( i = 1; i <= N; i++ ){

        score1 = 0; //inainte de a calcula scorul cuvantului curent, acesta este zero

        fgets( input, 30, stdin );

        p = strtok(input, " ");
        y1 = p;
        y = atoi(y1);

        p = strtok(NULL, " ");
        x1 = p;
        x = atoi(x1);


        p = strtok(NULL, " ");
        d1 = p;
        d = atoi(d1);

        p = strtok(NULL,"\n");
        length = strlen(p);

        strcpy(word, p);//salvam cuvantul curent 
        
       for( j = 0; j < length; j++ ){
            score1+= score[ word[j] - 'A' ];
        }

        int bonus1 = 0 , bonus2 = 0; //variabile folosite pentru a vedea daca word respecta conditiile de bonus 1 respectiv 2 

        for(j = 0; j < length - 1; j++ ){
            if(word[j] == XX[0] ){
                if(word[j + 1] == XX[1]){
                    bonus1 = 1;
                    break;
                }
            }
        }

        if(( word[length - 2] == YY[0] ) && ( word[length - 1] == YY[1] ) ){
            bonus2 = 1;
        }

        if(d == 0){
            for(j = 1; j <= length; j++ ){
                if( bonus1 == 1 ){
                    if( bonus_board[y][x] == 1){
                        score1*= 2;
                    }
                }
                if( bonus2 == 1 ){
                    if( bonus_board[y][x] == 2 ){
                        score1*= 3;
                    }
                }
                x++;
            }
                
        }
           
        if(d == 1){
            for(j = 1; j <= length; j++ ){
                if( bonus1 == 1 ){
                    if( bonus_board[y][x] == 1){
                        score1*= 2;
                    }
                }
                if( bonus2 == 1 ){
                    if( bonus_board[y][x] == 2 ){
                        score1*= 3;
                    }
                }
                y++; 
            }
            
        }           

        if(i % 2 == 1){
            player1+= score1;
        }
        else
        {
            player2+= score1;
        }
        
    }
    
    printf("Player 1: %d Points\n", player1);
    printf("Player 2: %d Points\n", player2);

}

void task4(char board[BOARD_SIZE][BOARD_SIZE]){
    task0(board);
    int N, i, j, x, y, d, length, k;
    char *p, *y1, *x1, *d1;
    char input[BOARD_SIZE], used[100][30];///vom folosi matricea used pentru a retine cuvintele care au fost deja puse pe tabla
    char q[20];

    fgets(input, BOARD_SIZE, stdin);
    fgets(input, BOARD_SIZE, stdin);

    fgets(input, BOARD_SIZE, stdin);
    strcpy(q, input);
    N = atoi(q);

    for(i = 1; i <= N; i++){

        fgets(input, 30, stdin);

        p = strtok(input, " ");
        y1 = p;
        y = atoi(y1);

        p = strtok(NULL, " ");
        x1 = p;
        x = atoi(x1);

        p = strtok(NULL, " ");
        d1 = p;
        d = atoi(d1);

        p = strtok( NULL, "\n" );
        strcpy( used[i-1], p );
        
        length = strlen(p);

        if(d == 0){
            for(j = 0; j < length; j++){
                board[y][x] = p[j];
                x++;
            }

        } 
        else if(d == 1){
             for(j = 0; j < length; j++){
                board[y][x] = p[j];
                y++; 
            }
        }

    }

    int gasit = 0;//variabila folosita pentru a sti cand am gasit primul cuvant ce respecta cerintele
    int nr = 0;//contor cu ajutorul caruia vom parcurge vectorul words
    int folosit; //variabila cu ajutorul careia vom verifica daca actualul cuvant a mai fost folosit
    int suprapune;//variabila folosita pt a verifica daca actualul cuvant se suprapune cu alte cuvinte

    while( gasit == 0 ){

        folosit = 0;//la inceput presupunem ca actualul cuvant nu a mai fost folosit

        for(i = 0; i < N; i++){//cautam in vectorul used si verificam daca actualul cuvant a mai fost folosit
            if( strcmp( used[i], words[nr] ) == 0 ){
                folosit = 1;
                break;
            }
        }

        if( folosit == 0 ){
            length = strlen(words[nr]);
            for( i = 0; i < BOARD_SIZE; i++ ){
                for( j = 0; j < BOARD_SIZE; j++ ){
                    if( board[i][j] == words[nr][0] ){//verificam daca prima litera din cuvantul curent se afla deja pe tabla
                        if( ( j - 1 + length ) <= 14 ){//daca actualul cuvant nu iese din marginile tablei de joc cand incercam sa il punem pe orizontala 
                            suprapune = 0; 
                            for( k = 1; k <= length -1; k++){//verificam daca se suprapune cu alte cuvinte
                                if( board[i][j+k] != '.'){
                                    suprapune = 1;
                                    break;
                                }
                            }
                            if(suprapune == 0){//daca nu se suprapune cu alte cuvinte
                                gasit = 1;
                                for( k = 1; k < length; k++){//daca toate cerintele sunt respectate, asezam cuvantul pe tabla de joc
                                    board[i][j+k] =  words[nr][k];
                                }
                            }
                        }
                        if(gasit == 0){
                            if( ( i - 1 + length ) <= 14 ){//daca actualul cuvant nu iese din marginile tablei de joc cand incercam sa il punem pe verticala 
                                suprapune = 0; 
                                for( k = 1; k <= length -1; k++){//verificam daca se suprapune cu alte cuvinte
                                    if( board[i + k][j] != '.'){
                                        suprapune = 1;
                                        break;
                                    }
                                }
                                if(suprapune == 0){//daca nu se suprapune cu alte cuvinte
                                    gasit = 1;
                                    for( k = 1; k < length; k++){//daca toate cerintele sunt respectate, asezam cuvantul pe tabla de joc
                                        board[i + k][j] =  words[nr][k];
                                    }
                                }
                            }
                        }
                    }
                    if( gasit == 1){
                        break;
                    }
                
                }
            }
        }

        nr++;
    }

    print_board(board);

}

void task5(char board[BOARD_SIZE][BOARD_SIZE]){

    task0(board);

    int score[25];

    score[0] = 1; // scorul literei 'A'
    score[1] = 3; // scorul literei 'B'
    score[2] = 3; // scorul literei 'C'
    score[3] = 2; // scorul literei 'D'
    score[4] = 1; // scorul literei 'E'
    score[5] = 4; // scorul literei 'F'
    score[6] = 2; // scorul literei 'G'
    score[7] = 4; // scorul literei 'H'
    score[8] = 1; // scorul literei 'I'
    score[9] = 8; // scorul literei 'J'
    score[10] = 5; // scorul literei 'K'
    score[11] = 1; // scorul literei 'L'
    score[12] = 3; // scorul literei 'M'
    score[13] = 1; // scorul literei 'N'
    score[14] = 1; // scorul literei 'O'
    score[15] = 3; // scorul literei 'P'
    score[16] = 10; // scorul literei 'Q'
    score[17] = 1; // scorul literei 'R'
    score[18] = 1; // scorul literei 'S'
    score[19] = 1; // scorul literei 'T'
    score[20] = 1; // scorul literei 'U'
    score[21] = 4; // scorul literei 'V'
    score[22] = 4; // scorul literei 'W'
    score[23] = 8; // scorul literei 'X'
    score[24] = 4; // scorul literei 'Y'
    score[25] = 10; // scorul literei 'Z'

    int player1 = 0, player2 = 0;

    int N, i, j, k;
    char *p;
    char input[BOARD_SIZE], XX[2], YY[2], used[100][30];///vom folosi matricea used pentru a retine cuvintele care au fost deja puse pe tabla
    char nr_w[20];
    char word[20];//cuvantul curent

    int x, y, d, length;
    char *x1, *y1, *d1;

    int score1;// scorul cuvantului curent
    int bonus1, bonus2;
   
    fgets( input, 10, stdin );
    strcpy( XX, input);

    fgets( input, 10, stdin );
    strcpy( YY, input );

    fgets( input, BOARD_SIZE, stdin );
    strcpy( nr_w, input );
    N = atoi( nr_w );

    for( i = 1; i <= N; i++ ){

        score1 = 0; //inainte de a calcula scorul cuvantului curent, acesta este zero

        fgets( input, 30, stdin );

        p = strtok(input, " ");
        y1 = p;
        y = atoi(y1);

        p = strtok(NULL, " ");
        x1 = p;
        x = atoi(x1);


        p = strtok(NULL, " ");
        d1 = p;
        d = atoi(d1);

        p = strtok(NULL,"\n");
        strcpy( used[i-1], p );

        length = strlen(p);

        if(d == 0){
            for(j = 0; j < length; j++){
                board[y][x + j] = p[j];
            }

        } 
        else if(d == 1){
             for(j = 0; j < length; j++){
                board[y + j][x] = p[j];
            }
        }
        
        strcpy(word, p);//salvam cuvantul curent 
        
       for( j = 0; j < length; j++ ){
            score1+= score[ word[j] - 'A' ];
        }

        bonus1 = 0 , bonus2 = 0; //variabile folosite pentru a vedea daca word respecta conditiile de bonus 1 respectiv 2 

        for(j = 0; j < length - 1; j++ ){
            if(word[j] == XX[0] ){
                if(word[j + 1] == XX[1]){
                    bonus1 = 1;
                    break;
                }
            }
        }

        if(( word[length - 2] == YY[0] ) && ( word[length - 1] == YY[1] ) ){
            bonus2 = 1;
        }

        if(d == 0){
            for(j = 1; j <= length; j++ ){
                if( bonus1 == 1 ){
                    if( bonus_board[y][x] == 1){
                        score1*= 2;
                    }
                }
                if( bonus2 == 1 ){
                    if( bonus_board[y][x] == 2 ){
                        score1*= 3;
                    }
                }
                x++;
            }
                
        }
           
        if(d == 1){
            for(j = 1; j <= length; j++ ){
                if( bonus1 == 1 ){
                    if( bonus_board[y][x] == 1){
                        score1*= 2;
                    }
                }
                if( bonus2 == 1 ){
                    if( bonus_board[y][x] == 2 ){
                        score1*= 3;
                    }
                }
                y++; 
            }
            
        }           

        if(i % 2 == 1){
            player1+= score1;
        }
        else
        {
            player2+= score1;
        }

    }
    
    int nr = 0;//contor cu ajutorul caruia vom parcurge vectorul words
    int folosit; //variabila cu ajutorul careia vom verifica daca actualul cuvant a mai fost folosit
    int suprapune;//variabila folosita pt a verifica daca actualul cuvant se suprapune cu alte cuvinte

    char cuv_max[30];
    int score_max = 0;
    int lin_max, col_max, dir_max;
    
    int scor_oriz, scor_vert;
    int lin, col;

    for(nr = 0; nr < 100; nr++){

        folosit = 0;//la inceput presupunem ca actualul cuvant nu a mai fost folosit

        for(i = 0; i < N; i++){//cautam in vectorul used si verificam daca actualul cuvant a mai fost folosit
            if( strcmp( used[i], words[nr] ) == 0 ){
                folosit = 1;
                break;
            }
        }

        if( folosit == 0 ){

            bonus1 = 0;
            bonus2 = 0;
            score1 = 0;

            length = strlen(words[nr]);

            for( k = 0; k < length; k++ ){
                score1 = score1 + score[ words[nr][k] - 'A' ];
            }

            for(k = 0; k < length - 1; k++ ){
                if(words[nr][k] == XX[0] ){
                    if(words[nr][k + 1] == XX[1]){
                        bonus1 = 1;
                        break;
                    }
                }
            }

            if(( words[nr][length - 2] == YY[0] ) && ( words[nr][length - 1] == YY[1] ) ){
                bonus2 = 1;
            }

            for( i = 0; i < BOARD_SIZE; i++ ){
                for( j = 0; j < BOARD_SIZE; j++ ){
                    if( board[i][j] == words[nr][0] ){//verificam daca prima litera din cuvantul curent se afla deja pe tabla

                        lin = i;//retinem linia primei litere din cuvant
                        col = j;//retinem coloana primei litere din cuvant

                        if( ( j - 1 + length ) <= 14 ){//daca actualul cuvant nu iese din marginile tablei de joc cand incercam sa il punem pe orizontala 
                            suprapune = 0; 
                            for( k = 1; k <= length -1; k++){//verificam daca se suprapune cu alte cuvinte
                                if( board[i][j+k] != '.'){
                                    suprapune = 1;
                                    break;
                                }
                            }
                            if(suprapune == 0){//daca nu se suprapune cu alte cuvinte,calculam scorul cuvantului curent

                                scor_oriz = score1;
                               
                                for(k = 1; k <= length; k++ ){
                                    if( bonus1 == 1 ){
                                        if( bonus_board[lin][col + k -1] == 1){
                                            scor_oriz*= 2;
                                        }
                                    }
                                    if( bonus2 == 1 ){
                                        if( bonus_board[lin][col + k -1] == 2 ){
                                            scor_oriz*= 3;
                                        }
                                    }
                                }

                                if(scor_oriz > score_max) {
                                    score_max = scor_oriz;
                                    strcpy(cuv_max, words[nr]);
                                    lin_max = lin;
                                    col_max = col;
                                    dir_max = 0;
                                }    
                                else if(scor_oriz == score_max){
                                    if(lin < lin_max){
                                        strcpy(cuv_max, words[nr]);
                                        lin_max = lin;
                                        col_max = col;
                                        dir_max = 0;
                                    }else
                                    {
                                        if(lin == lin_max){
                                            if(col < col_max){
                                                strcpy(cuv_max, words[nr]);
                                                col_max = col;
                                                dir_max = 0;
                                            }
                                        }
                                    }
                                    
                                }
                               
                            }
                        }

                        if( ( i - 1 + length ) <= 14 ){//daca actualul cuvant nu iese din marginile tablei de joc cand incercam sa il punem pe verticala
                            suprapune = 0; 
                            for( k = 1; k <= length -1; k++){//verificam daca se suprapune cu alte cuvinte
                                if( board[i + k][j] != '.'){
                                    suprapune = 1;
                                    break;
                                }
                            }
                            if(suprapune == 0){//daca nu se suprapune cu alte cuvinte,calculam scorul cuvantului curent
                               
                                scor_vert = score1;
                               
                                for(k = 1; k <= length; k++ ){
                                    if( bonus1 == 1 ){
                                        if( bonus_board[lin + k -1][col] == 1){
                                            scor_vert*= 2;
                                        }
                                    }
                                    if( bonus2 == 1 ){
                                        if( bonus_board[lin + k -1][col] == 2 ){
                                            scor_vert*= 3;
                                        }
                                    }
                                }

                                if(scor_vert > score_max) {
                                    score_max = scor_vert;
                                    strcpy(cuv_max, words[nr]);
                                    lin_max = lin;
                                    col_max = col;
                                    dir_max = 1;
                                }       
                                else if(scor_vert == score_max){
                                    if(lin < lin_max){
                                        strcpy(cuv_max, words[nr]);
                                        lin_max = lin;
                                        col_max = col;
                                        dir_max = 1;
                                    }else
                                    {
                                        if(lin == lin_max){
                                            if(col < col_max){
                                                strcpy(cuv_max, words[nr]);
                                                col_max = col;
                                                dir_max = 1;
                                            }
                                        }
                                    }
                                    
                                }
                            }

                        }
                        
                    }
                }
            }
        }
    }

    if( (player2 + score_max) >= player1 ){
        
        length = strlen(cuv_max);

        if(dir_max == 0){
                for(i = 1; i < length; i++){
                    board[lin_max][col_max + i] = cuv_max[i];
                }

        } 
        else if(dir_max == 1){
                for(i = 1; i < length; i++){
                board[lin_max + i][col_max] = cuv_max[i];
            }
        }

        print_board(board);

    }
    else{
        printf("Fail!");
    }
}

void task6(char board[BOARD_SIZE][BOARD_SIZE]){

    task0(board);

    int score[25];

    score[0] = 1; // scorul literei 'A'
    score[1] = 3; // scorul literei 'B'
    score[2] = 3; // scorul literei 'C'
    score[3] = 2; // scorul literei 'D'
    score[4] = 1; // scorul literei 'E'
    score[5] = 4; // scorul literei 'F'
    score[6] = 2; // scorul literei 'G'
    score[7] = 4; // scorul literei 'H'
    score[8] = 1; // scorul literei 'I'
    score[9] = 8; // scorul literei 'J'
    score[10] = 5; // scorul literei 'K'
    score[11] = 1; // scorul literei 'L'
    score[12] = 3; // scorul literei 'M'
    score[13] = 1; // scorul literei 'N'
    score[14] = 1; // scorul literei 'O'
    score[15] = 3; // scorul literei 'P'
    score[16] = 10; // scorul literei 'Q'
    score[17] = 1; // scorul literei 'R'
    score[18] = 1; // scorul literei 'S'
    score[19] = 1; // scorul literei 'T'
    score[20] = 1; // scorul literei 'U'
    score[21] = 4; // scorul literei 'V'
    score[22] = 4; // scorul literei 'W'
    score[23] = 8; // scorul literei 'X'
    score[24] = 4; // scorul literei 'Y'
    score[25] = 10; // scorul literei 'Z'

    int player1 = 0, player2 = 0;

    int N, i, j, k, l;
    char *p;
    char input[BOARD_SIZE], XX[2], YY[2], used[100][30];///vom folosi matricea used pentru a retine cuvintele care au fost deja puse pe tabla
    char nr_w[20];
    char word[20];//cuvantul curent

    int x, y, d, length;
    char *x1, *y1, *d1;

    int score1;// scorul cuvantului curent
    int bonus1, bonus2;
    int c = -1;//contor pentru numarul de cuvinte folosite pana in prezent

    int nr ;//contor cu ajutorul caruia vom parcurge vectorul words
    int folosit; //variabila cu ajutorul careia vom verifica daca actualul cuvant a mai fost folosit
    int suprapune;//variabila folosita pt a verifica daca actualul cuvant se suprapune cu alte cuvinte

    char cuv_max[30];
    int score_max;
    int lin_max, col_max, dir_max;
    
    int scor_oriz, scor_vert;
    int lin, col;
   
    fgets( input, 10, stdin );
    strcpy( XX, input);

    fgets( input, 10, stdin );
    strcpy( YY, input );

    fgets( input, BOARD_SIZE, stdin );
    strcpy( nr_w, input );
    N = atoi( nr_w );

    for( l = 1; l <= N; l++ ){

        score1 = 0; //inainte de a calcula scorul cuvantului curent, acesta este zero

        fgets( input, 30, stdin );

        p = strtok(input, " ");
        y1 = p;
        y = atoi(y1);

        p = strtok(NULL, " ");
        x1 = p;
        x = atoi(x1);

        p = strtok(NULL, " ");
        d1 = p;
        d = atoi(d1);

        p = strtok(NULL,"\n");
        strcpy( used[++c], p );

        length = strlen(p);

        if(d == 0){
            for(j = 0; j < length; j++){
                board[y][x + j] = p[j];
            }

        } 
        else if(d == 1){
             for(j = 0; j < length; j++){
                board[y + j][x] = p[j];
            }
        }
        
        strcpy(word, p);//salvam cuvantul curent 
        
       for( j = 0; j < length; j++ ){
            score1+= score[ word[j] - 'A' ];
        }

        bonus1 = 0 , bonus2 = 0; //variabile folosite pentru a vedea daca word respecta conditiile de bonus 1 respectiv 2 

        for(j = 0; j < length - 1; j++ ){
            if(word[j] == XX[0] ){
                if(word[j + 1] == XX[1]){
                    bonus1 = 1;
                    break;
                }
            }
        }

        if(( word[length - 2] == YY[0] ) && ( word[length - 1] == YY[1] ) ){
            bonus2 = 1;
        }

        if(d == 0){
            for(j = 1; j <= length; j++ ){
                if( bonus1 == 1 ){
                    if( bonus_board[y][x] == 1){
                        score1*= 2;
                    }
                }
                if( bonus2 == 1 ){
                    if( bonus_board[y][x] == 2 ){
                        score1*= 3;
                    }
                }
                x++;
            }
                
        }
           
        if(d == 1){
            for(j = 1; j <= length; j++ ){
                if( bonus1 == 1 ){
                    if( bonus_board[y][x] == 1){
                        score1*= 2;
                    }
                }
                if( bonus2 == 1 ){
                    if( bonus_board[y][x] == 2 ){
                        score1*= 3;
                    }
                }
                y++; 
            }
            
        }           

        player1+= score1;

        score_max = 0;

        for(nr = 0; nr < 100; nr++){

            folosit = 0;//la inceput presupunem ca actualul cuvant nu a mai fost folosit

            for(i = 0; i <= c; i++){//cautam in vectorul used si verificam daca actualul cuvant a mai fost folosit
                if( strcmp( used[i], words[nr] ) == 0 ){
                    folosit = 1;
                    break;
                }
            }

            if( folosit == 0 ){

                bonus1 = 0;
                bonus2 = 0;
                score1 = 0;

                length = strlen(words[nr]);

                for( k = 0; k < length; k++ ){
                    score1 = score1 + score[ words[nr][k] - 'A' ];
                }

                for(k = 0; k < length - 1; k++ ){
                    if(words[nr][k] == XX[0] ){
                        if(words[nr][k + 1] == XX[1]){
                            bonus1 = 1;
                            break;
                        }
                    }
                }

                if(( words[nr][length - 2] == YY[0] ) && ( words[nr][length - 1] == YY[1] ) ){
                    bonus2 = 1;
                }

                for( i = 0; i < BOARD_SIZE; i++ ){
                    for( j = 0; j < BOARD_SIZE; j++ ){
                        if( board[i][j] == words[nr][0] ){//verificam daca prima litera din cuvantul curent se afla deja pe tabla

                            lin = i;//retinem linia primei litere din cuvant
                            col = j;//retinem coloana primei litere din cuvant

                            if( ( j - 1 + length ) <= 14 ){//daca actualul cuvant nu iese din marginile tablei de joc cand incercam sa il punem pe orizontala 
                                suprapune = 0; 
                                for( k = 1; k <= length -1; k++){//verificam daca se suprapune cu alte cuvinte
                                    if( board[i][j+k] != '.'){
                                        suprapune = 1;
                                        break;
                                    }
                                }
                                if(suprapune == 0){//daca nu se suprapune cu alte cuvinte,calculam scorul cuvantului curent

                                    scor_oriz = score1;
                                
                                    for(k = 1; k <= length; k++ ){
                                        if( bonus1 == 1 ){
                                            if( bonus_board[lin][col + k -1] == 1){
                                                scor_oriz*= 2;
                                            }
                                        }
                                        if( bonus2 == 1 ){
                                            if( bonus_board[lin][col + k -1] == 2 ){
                                                scor_oriz*= 3;
                                            }
                                        }
                                    }

                                    if(scor_oriz > score_max) {
                                        score_max = scor_oriz;
                                        strcpy(cuv_max, words[nr]);
                                        lin_max = lin;
                                        col_max = col;
                                        dir_max = 0;
                                    }    
                                    else if(scor_oriz == score_max){
                                        if(lin < lin_max){
                                            strcpy(cuv_max, words[nr]);
                                            lin_max = lin;
                                            col_max = col;
                                            dir_max = 0;
                                        }else
                                        {
                                            if(lin == lin_max){
                                                if(col < col_max){
                                                    strcpy(cuv_max, words[nr]);
                                                    col_max = col;
                                                    dir_max = 0;
                                                }
                                            }
                                        }
                                        
                                    }
                                
                                }
                            }

                            if( ( i - 1 + length ) <= 14 ){//daca actualul cuvant nu iese din marginile tablei de joc cand incercam sa il punem pe verticala
                                suprapune = 0; 
                                for( k = 1; k <= length -1; k++){//verificam daca se suprapune cu alte cuvinte
                                    if( board[i + k][j] != '.'){
                                        suprapune = 1;
                                        break;
                                    }
                                }
                                if(suprapune == 0){//daca nu se suprapune cu alte cuvinte,calculam scorul cuvantului curent
                                
                                    scor_vert = score1;
                                
                                    for(k = 1; k <= length; k++ ){
                                        if( bonus1 == 1 ){
                                            if( bonus_board[lin + k -1][col] == 1){
                                                scor_vert*= 2;
                                            }
                                        }
                                        if( bonus2 == 1 ){
                                            if( bonus_board[lin + k -1][col] == 2 ){
                                                scor_vert*= 3;
                                            }
                                        }
                                    }

                                    if(scor_vert > score_max) {
                                        score_max = scor_vert;
                                        strcpy(cuv_max, words[nr]);
                                        lin_max = lin;
                                        col_max = col;
                                        dir_max = 1;
                                    }       
                                    else if(scor_vert == score_max){
                                        if(lin < lin_max){
                                            strcpy(cuv_max, words[nr]);
                                            lin_max = lin;
                                            col_max = col;
                                            dir_max = 1;
                                        }else
                                        {
                                            if(lin == lin_max){
                                                if(col < col_max){
                                                    strcpy(cuv_max, words[nr]);
                                                    col_max = col;
                                                    dir_max = 1;
                                                }
                                            }
                                        }
                                        
                                    }
                                }

                            }
                            
                        }
                    }
                }
            }
        }
        player2+= score_max;
        strcpy( used[++c], cuv_max );
        length = strlen(cuv_max);

        if(dir_max == 0){
            for(i = 1; i < length; i++){
                board[lin_max][col_max + i] = cuv_max[i];
            }

        } 
        else if(dir_max == 1){
                for(i = 1; i < length; i++){
                board[lin_max + i][col_max] = cuv_max[i];
            }
        }

    }
    print_board(board);
    if( player1 > player2 ){
        printf("Player 1 Won!");
    }
    else
    {
        printf("Player 2 Won!");
    }
    
}


int main(){
    char input[BOARD_SIZE];
    char board[BOARD_SIZE][BOARD_SIZE];
    fgets(input, BOARD_SIZE, stdin);
    if(input[0] == '0'){
        task0(board);
        print_board(board);
    }
    else if(input[0] == '1'){
        task1(board);
    }
    else if(input[0] == '2'){
        task2();
    }
    else if(input[0] == '3'){
        task3();
    }
    else if(input[0] == '4'){
        task4(board);
    }
    else if(input[0] == '5'){
        task5(board);
    }
    else if(input[0] == '6'){
        task6(board);
    }
    
    
}