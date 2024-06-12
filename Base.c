#include <stdio.h>
#include <assert.h>
// Adjust the position with the NumbPad
int AdjsutPos(int Pos)
{

    switch (Pos)
    {
    case 7:
        Pos = 0;
        break;
    case 8:
        Pos = 1;
        break;
    case 9:
        Pos = 2;
        break;
    case 4:
        Pos = 3;
        break;
    case 5:
        Pos = 4;
        break;
    case 6:
        Pos = 5;
        break;
    case 1:
        Pos = 6;
        break;
    case 2:
        Pos = 7;
        break;
    case 3:
        Pos = 8;
        break;
    default:
        Pos = 0;
        break;
    }

    return Pos;
}

int checkifplayable(int Board[],int Pos){
    return (Board[Pos] == (-1));
}

void MakeBoard(int Board[9]){
    for(int i = 0;i < 3;i++ ){

      char slot1 = ' ', slot2 = ' ', slot3 = ' ';
            
        if(Board[(i*3)] == 1){ slot1 = 'X';}else if(Board[(i*3)] == 0){ slot1 = 'O';}

        if(Board[(i*3)+1] == 1){ slot2 = 'X';}else if(Board[((i*3))+1] == 0){ slot2 = 'O';}
        
        if(Board[(i*3)+2] == 1){ slot3 = 'X';}else if(Board[(i*3)+2] == 0){ slot3 = 'O';}
        printf(" %c | %c | %c ",slot1,slot2,slot3);
        
        if(i == 2){ return;}
        
        printf("\n------------\n");
    }
}

/*
      0  |   1   |  2
   -------------------
      3  |   4   |  5
   -------------------
      6  |   7   |  8    
*/


int WinChecker(int Board[9]){

    //_ _ _
    if(Board[0] == Board[1] && Board[2] == Board[1] && Board[0] != -1) return Board[0];
    else if(Board[3] == Board[4] && Board[4] == Board[5] && Board[3] != -1) return Board[3];
    else if(Board[6] == Board[7] && Board[7] == Board[8] && Board[6] != -1) return Board[6];
    //| | |
    else if(Board[0] == Board[3] && Board[3] == Board[6] && Board[0] != -1) return Board[0];
    else if(Board[1] == Board[4] && Board[4] == Board[7] && Board[1] != -1) return Board[1];
    else if(Board[2] == Board[5] && Board[5] == Board[8] && Board[2] != -1) return Board[2];
    // X
    else if(Board[0] == Board[4] && Board[4] == Board[8] && Board[0] != -1) return Board[0];
    else if(Board[2] == Board[4] && Board[4] == Board[6] && Board[2] != -1) return Board[3];

    for(int i = 0; i < 9; i++){
        if(Board[i] == -1) return -1;
    }


    return -2;
}

int main()
{

    int isX = 1;
    int Board[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int RawPos;
    int Pos;
    int WinO = 0;
    int WinX = 0;
    int frst = 0;
   
    while (1)
    {
        if(frst == 0){
            printf("First Play ->");
            frst = 1;
        }
        assert(scanf("%d", &RawPos) != 0);
        Pos = AdjsutPos(RawPos);

        if(checkifplayable(Board,Pos)){

            Board[Pos] = isX;
            if( isX == 1) isX = 0;
            else isX = 1;
            /*
            for(int i = 0; i < 9; i++)
                printf("(%d) | ", Board[i]);
            printf("\n");
            */
            
        }else{

            printf("\nPlay not possible!\n");

        }

        MakeBoard(Board);

        int checkwin = WinChecker(Board);

        if(checkwin != -1){

            char winchar;
            if(checkwin == 1){winchar = 'X';WinX++;}
            else if(checkwin == 0) {winchar = 'O'; WinO++;}
            
            
            if(checkwin == -2){
                printf("\n\n__ Draw! __\n__O - %d x X - %d__\n\n",WinO, WinX);
            }else{

                printf("\n\n__ %c Won! __\n__O - %d x X - %d__\n\n", winchar ,WinO, WinX);

            }

            frst = 0;
            isX = 1;
            for(int j = 0; j < 9; j++){
                Board[j] = -1;
            }

        }
        if(frst == 1)
            printf("\nNext Play ->");
    }
    return 0;
}
