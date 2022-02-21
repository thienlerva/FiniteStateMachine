/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: codex
 *
 * Created on February 20, 2022, 10:39 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum {
    STOP,
    RUN    
} MOTOR_STATES;

typedef struct {
    MOTOR_STATES current_state;
    int gear;
    int speed;
    char *motor_status;
    MOTOR_STATES next_state;
} STATE_INFO;

int runMotor(MOTOR_STATES start_state, STATE_INFO *state_machine);
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
   
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void led_on() {
    printf("Light is on\n");
}

void led_off() {
    printf("Light is off\n");
}

int main(int argc, char** argv) {

    static STATE_INFO state_machine[] = {
        {STOP, 0, 0, "Engine has stopped", RUN},
        {RUN, 1, 10, "Engine is running", STOP},
   
    };
    
    //runMotor(RUN, state_machine);
    
    enum states {
        LED_ON,
        LED_OFF
    };

    enum states state = LED_ON;
  
    
    while (1) {
        if (state == LED_OFF) {
            led_on();
            state = LED_ON;
        } else {
            led_off();
            state = LED_OFF;
        }
        delay(2000);
       
    }
    
    
    return (EXIT_SUCCESS);
}

int runMotor(MOTOR_STATES start_state, STATE_INFO *state_machine) {
    
    STATE_INFO *p_state_machine;
    MOTOR_STATES current_state = start_state;
    int input;
    
    do {
        printf("Enter the integer: ");
        scanf("%d", &input);
        p_state_machine = state_machine;
        
        
        while(p_state_machine->current_state != 3) {
            printf("Current state %d\n", current_state);
            printf("Current state %d\n", p_state_machine->current_state);
            if(p_state_machine->current_state == current_state) {
                switch(input) {
                    case 0:
                        printf("%s\n", p_state_machine->motor_status);
                        break;
                    case 1:
                        printf("%s\n", p_state_machine->motor_status);
                        break;
                    default:
                    printf("Something went wrong\n");
                    
                }
        }
        p_state_machine++;
        }
        
 
    } while (input != 5);
    
}

