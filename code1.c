#include <stdio.h>

int main(){
    int NFLScore;
    while(1){
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &NFLScore);
        if((NFLScore == 1) || (NFLScore == 0)){
            break;
        }
        for(int t = 0; t*6 <= NFLScore; t++){
            for(int f = 0; f*3<= NFLScore; f++ ){
                for(int s = 0; s*2 <= NFLScore; s++){
                    for(int c = 0; c*8 <= NFLScore; c++){
                        for(int g = 0; g*7 <= NFLScore; g++){
                            if(((t*6) + (f*3) + (s*2) + (c*8) + (g*7)) == NFLScore) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",c,g,t,f,s); 
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Program ending.");
}