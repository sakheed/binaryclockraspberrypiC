#include "display.h"

int main(void){
    int hours;
    int minutes;
    int seconds;
    int checkTime;
    checkTime =0;
    while(true){
        hours =-1;
        minutes = -1;
        seconds = -1;
        scanf("%d: %d: %d", &hours, &minutes, &seconds);
        checkTime = check_time(hours,minutes,seconds);
        if (checkTime ==0){
            display_time(hours, minutes, seconds);
            sleep(1);
        }
        else{
            break;
        }
    }

        close_display();
        return 0;
}

