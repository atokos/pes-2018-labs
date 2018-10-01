#include "project.h"

tLight_State TRAFFIC_state_G;
tWord TRAFFIC_time_in_state_G;
tWord gotoGreen;

/* Durations are supplied in seconds */
#define RED_DURATION (5 * 1000 / TIMER_INTERVAL)
#define RED_GREEN_DURATION (0.5 * 1000 / TIMER_INTERVAL)
#define GREEN_DURATION (5 * 1000 / TIMER_INTERVAL)
#define GREEN_RED_DURATION (0.5 * 1000 / TIMER_INTERVAL)
#define AMBER_DURATION (5 * 1000 / TIMER_INTERVAL)


Traffic_Init(void) {
    TRAFFIC_state_G = AMBER;
    TRAFFIC_time_in_state_G = 0;
    gotoGreen = FALSE;
}

Traffic_Update(void) {

    TRAFFIC_time_in_state_G++;

    switch(TRAFFIC_state_G){
        case RED:
            /* Turn red led on, green off */
            if(TRAFFIC_time_in_state_G > RED_DURATION || gotoGreen) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = RED_GREEN;
                gotoGreen = FALSE;
            }

        case RED_GREEN:
            /* Turn red led on, green on */
            if(TRAFFIC_time_in_state_G > RED_GREEN_DURATION) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = GREEN;
            }

        case GREEN:
            /* Turn red led off, green oon */
            if(TRAFFIC_time_in_state_G > GREEN_DURATION) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = GREEN_RED;
            }

        case GREEN_RED:
            /* Turn red led on, green off */
            if(TRAFFIC_time_in_state_G > GREEN_RED_DURATION) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = RED;
            }

        case AMBER:
            /* Turn red led on, green off */
            if(TRAFFIC_time_in_state_G > RED_DURATION) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = RED;
            }
    }
}