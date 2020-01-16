#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEAKRSPWNTIME 15

int roll_log(){
    float randm;
    randm = rand();
    randm = randm/RAND_MAX; //roll random number between 0 and 1
    if(randm <= 0.55517108804){ //p = (190/255)^2 chance for double logs
        return 2;
    }
    else if(randm <= 0.93502499039){ //p = (190/255) chance for single log
        return 1;
    }
    else return 0;  //in other case no logs
}

int deplete_roll(int tdepl, int time){
    float randm;
    randm = rand();
    randm = randm/RAND_MAX;
    if(randm <= 0.125){   //chance for teak tree to deplete
        tdepl = time;
    }
    return tdepl;   //return tick of depletion
}

int main()
{
    srand(time(NULL));

    int time = 0, fintime, pos = 1, logs = 0, t1depl = -100, t2depl = -100, t3depl = -100;
    //printf("Simulate 1.5 tick teak for how many ticks?\n");
    //scanf("%i", &fintime);
    fintime = 6000000;

    while(time < fintime){
        if(pos == 1){
            if(t1depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 2;
                logs += roll_log();
                t1depl = deplete_roll(t1depl, time);
            }
            else if(t2depl <= time - TEAKRSPWNTIME +2){ //additional time to go to pos 2 and go to pos 3 without losing ticks
                time += 5;
                pos = 3;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t3depl <= time - TEAKRSPWNTIME +5){ //additional time to go to pos 2 and go to pos 7 without losing ticks
                time += 8;
                pos = 7;
                logs += roll_log();
                t3depl = deplete_roll(t3depl, time);
            }
            else time++;    //simulation of perfect scenario when all trees are depleted, unfeasible but makes simulation easier to make, should have minimal impact as this is a rare case
        }
        else if(pos == 2){
            if(t1depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 1;
                logs += roll_log();
                t1depl = deplete_roll(t1depl, time);
            }
            else if(t2depl <= time - TEAKRSPWNTIME +2){ //additional time to go to pos 1 and go to pos 3 without losing ticks
                time += 5;
                pos = 3;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t3depl <= time - TEAKRSPWNTIME +5){ //additional time to go to pos 1 and go to pos 7 without losing ticks
                time += 8;
                pos = 7;
                logs += roll_log();
                t3depl = deplete_roll(t3depl, time);
            }
            else time++;
        }
        else if(pos == 3){
            if(t2depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 4;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t1depl <= time - TEAKRSPWNTIME +1){
                time += 4;
                pos = 2;
                logs += roll_log();
                t1depl = deplete_roll(t1depl, time);
            }
            else if(t3depl <= time - TEAKRSPWNTIME +3){
                time += 6;
                pos = 7;
                logs += roll_log();
                t3depl = deplete_roll(t3depl, time);
            }
            else time++;
        }
        else if(pos == 4){
            if(t2depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 5;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t3depl <= time - TEAKRSPWNTIME +2){
                time += 5;
                pos = 7;
                logs += roll_log();
                t3depl = deplete_roll(t3depl, time);
            }
            else if(t1depl <= time - TEAKRSPWNTIME +4){
                time += 7;
                pos = 2;
                logs += roll_log();
                t1depl = deplete_roll(t1depl, time);
            }
            else time++;
        }
        else if(pos == 5){
            if(t2depl <= time - TEAKRSPWNTIME && t3depl <= time - TEAKRSPWNTIME +3){
                time += 3;
                pos = 6;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t2depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 4;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t3depl <= time - TEAKRSPWNTIME +3){
                time += 6;
                pos = 7;
                logs += roll_log();
                t3depl = deplete_roll(t3depl, time);
            }
            else if(t1depl <= time - TEAKRSPWNTIME +2){
                time += 5;
                pos = 1;
                logs += roll_log();
                t1depl = deplete_roll(t1depl, time);
            }
            else time++;
        }
        else if(pos == 6){
            if(t3depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 7;
                logs += roll_log();
                t3depl = deplete_roll(t3depl, time);
            }
            else if(t2depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 5;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t1depl <= time - TEAKRSPWNTIME +4){
                time += 7;
                pos = 1;
                logs += roll_log();
                t1depl = deplete_roll(t1depl, time);
            }
            else time ++;
        }
        else if(pos == 7){
            if(t2depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 6;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t3depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 8;
                logs += roll_log();
                t3depl = deplete_roll(t3depl, time);
            }
            else if(t1depl <= time - TEAKRSPWNTIME +6){
                time += 9;
                pos = 1;
                logs += roll_log();
                t1depl = deplete_roll(t1depl, time);
            }
            else time ++;
        }
        else if(pos == 8){
            if(t3depl <= time - TEAKRSPWNTIME){
                time += 3;
                pos = 7;
                logs += roll_log();
                t3depl = deplete_roll(t3depl, time);
            }
            else if(t2depl <= time - TEAKRSPWNTIME +3){
                time += 6;
                pos = 6;
                logs += roll_log();
                t2depl = deplete_roll(t2depl, time);
            }
            else if(t1depl <= time - TEAKRSPWNTIME +5){
                time += 8;
                pos = 1;
                logs += roll_log();
                t1depl = deplete_roll(t1depl, time);
            }
            else time++;
        }
        else{
            printf("error");
            break;
        }
    }
    printf("total xp: %0.1f\nxp/hr: %0.1f\ntotal logs: %i\nlogs/hr: %0.1f\ntotal hours: %0.1f\n", logs*85*1.025, logs*85*1.025*6000/time, logs, logs*6000.0/time, time/6000.0);
}
