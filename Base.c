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
        
        if(i == 2){printf("\n Next Play ->"); return;}
        
        printf("\n------------\n");
    }
}

int main()
{

    int isX = 1;
    int Board[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int RawPos;
    int Pos;
    int Win = 0;

    printf("First Play ->");
    while (Win == 0)
    {

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
    }
    return 0;
}
