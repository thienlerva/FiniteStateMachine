/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: codex
 *
 * Created on February 19, 2022, 11:22 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {Mon, Tue, Wed, Thur, Fri, Sat, Sun} WEEK;

typedef enum {
  START,
  AFTER_MINUS,
  AFTER_DOT,
  internal_VALID_END_STATES,
  SECOND_DIGIT_ONWARDS,
  MANTISSA,
  internal_LAST_STATE
} FSM_STATES;

typedef struct {
  FSM_STATES state;
  char *tokens;
  FSM_STATES next_state;
} FSM_STATE_INFO;

int run(FSM_STATES start_state, FSM_STATE_INFO *state_machine, char *cargo);

int runMachine(FSM_STATES start_state, FSM_STATE_INFO *state_machine, char *cargo);

/*
 * Use a simple FSM to verify a floating point number (as a string)
 * 12.13, -18.20, --, -1., 1.13t9
 * https://github.com/garyexplains/examples/tree/master/FSM
 */
int main(int argc, char** argv) {

    static FSM_STATE_INFO state_machine[] = {
        {START, "1234567890", SECOND_DIGIT_ONWARDS},
        {START, "-", AFTER_MINUS},
        {AFTER_MINUS, "1234567890", SECOND_DIGIT_ONWARDS},
        {SECOND_DIGIT_ONWARDS, "1234567890", SECOND_DIGIT_ONWARDS},
        {SECOND_DIGIT_ONWARDS, ".", AFTER_DOT},
        {AFTER_DOT, "1234567890", MANTISSA},
        {MANTISSA, "1234567890", MANTISSA},
        {internal_LAST_STATE, "", internal_LAST_STATE}};
    
    run(START, state_machine, "3.1");
//    run(START, state_machine, "-7");
//    run(START, state_machine, "-22.0");
//    run(START, state_machine, "-22.0");
//    run(START, state_machine, "-22.a0");
//    run(START, state_machine, "-1.");
//    run(START, state_machine, "-");
    
    WEEK day = Wed;
    printf("Day is %d\n", day);
    
   char *str = "0123456789";
   char ch = '1';
   char *ret;

   ret = strchr(str, ch);

    if (ret != NULL)
    {
        printf("%c is found in the %s\n", ch, ret);
    } else {
        printf("Not in the text\n");
    }
   
    return (EXIT_SUCCESS);
}

int run(FSM_STATES start_state, FSM_STATE_INFO *state_machine, char *cargo) {
    
  FSM_STATE_INFO *p_state_machine;
  FSM_STATES current_state = start_state;
  FSM_STATE_INFO *found_state_machine;
  char *c = cargo;
 // --2
  while (*c != 0) {
    found_state_machine = NULL;
    p_state_machine = state_machine;
    printf("Character: %c\n", *c);
    while (p_state_machine->state != internal_LAST_STATE) {
        printf("State %d\n", p_state_machine->state);
        
        if (p_state_machine->state == current_state) {
            printf("Current token: %s\n", p_state_machine->tokens);
            if (strchr(p_state_machine->tokens, *c) != NULL) {
                found_state_machine = p_state_machine;
                printf("Found State machine %d\n", found_state_machine->state);
                break;
             }
        }
        p_state_machine++;
    }
    
    printf("---------\n");
    if (found_state_machine != NULL) {
       
      current_state = p_state_machine->next_state;
      printf("Next state: %d\n", current_state);
      c++;
    } else {
      printf("%s is bad. Failed at %c\n", cargo, *c);
      return -1;
    }
  }
  
  if (current_state > internal_VALID_END_STATES) {
    printf("%s is good.\n", cargo);
    return 1;
  } else {
    printf("%s is bad. More needed.\n", cargo);
    return -2;
  }
}

int runMachine(FSM_STATES start_state, FSM_STATE_INFO *state_machine, char *cargo) {
    
    FSM_STATE_INFO *p_state_machine;
    FSM_STATES current_state = start_state;
    FSM_STATE_INFO *found_state_machine;
    char *c = cargo;
  
    while (*c != 0) {
        found_state_machine = NULL;
        p_state_machine = state_machine;
        printf("Current character: %c\n", *c);
        while (p_state_machine->state != internal_LAST_STATE) {
            
            if (p_state_machine->state == current_state) {
               
                printf("State in if: %d\n", p_state_machine->state);
                switch(p_state_machine->state) {
                    case START:
                        if (strchr(p_state_machine->tokens, *c) != NULL) {
                            found_state_machine = p_state_machine;
                            printf("Found State machine at START %d\n", found_state_machine->state);
                            break;
                        }
                    case AFTER_MINUS:
                        if (strchr(p_state_machine->tokens, *c) != NULL) {
                            found_state_machine = p_state_machine;
                            printf("Found State machine at AFTER_MINUS %d\n", found_state_machine->state);
                            break;
                    }  
                    case SECOND_DIGIT_ONWARDS:
                        if (strchr(p_state_machine->tokens, *c) != NULL) {
                            found_state_machine = p_state_machine;
                            printf("Found State machine at AFTER_DOT %d\n", found_state_machine->state);
                            break;
                        } 
                    case AFTER_DOT:
                        if (strchr(p_state_machine->tokens, *c) != NULL) {
                            found_state_machine = p_state_machine;
                            printf("Found State machine at SECOND_DIGIT_ONWARDS%d\n", found_state_machine->state);
                            break;
                    } 
                    case MANTISSA:
                        if (strchr(p_state_machine->tokens, *c) != NULL) {
                            found_state_machine = p_state_machine;
                            printf("Found State machine at MANTISSA %d\n", found_state_machine->state);
                            break;
                    } 
//                    case internal_LAST_STATE:
//                        found_state_machine = p_state_machine;
//                        printf("internal last state\n");
//                        break;
                    case internal_VALID_END_STATES:
                        printf("internal valid end state\n");
                        break;
                    default:
                        printf("Error\n");
                        return -1;
                }
            }
            p_state_machine++;
        }
        
        printf("---------\n");
        if (found_state_machine != NULL) {
       
            current_state = p_state_machine->next_state;
            printf("Next state: %d\n", current_state);
            c++;
        } else {
            printf("%s is bad. Failed at %c\n", cargo, *c);
            return -1;
        }
    }
  
  if (current_state > internal_VALID_END_STATES) {
    printf("%s is good.\n", cargo);
    return 1;
  } else {
    printf("%s is bad. More needed.\n", cargo);
    return -2;
  }
}


