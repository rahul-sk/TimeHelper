/*
 * * TimeHelper.c
 * *
 * * Created on Nov, 2020
 * *
 * *
 * * @Author: Rahul S Koimattur
 * *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <spawn.h>
#include <sys/wait.h>
#include <assert.h>
#include<time.h>
#define STR_SIZE 8

/*
 *@ Function      : get_current_time
 *@ return        : void 
 *@ brief         : This function retrieves the current local time and stores it in the str_out variable.
 */
void get_current_time(char* str_out,unsigned int str_size)
{
		time_t current_time;
                struct tm * time_info;
		time(&current_time);
		time_info = localtime(&current_time);
		strftime(str_out, str_size+1, "%H:%M:%S", time_info);
		
}

/*
 *@ Function      : get_end_time
 *@ return        : void
 *@ Argument      : timeout value which has to be added to the current time
 *@ brief         : This function adds the time value(increment_hrs) to the current time value and stores this value in the str_out variable.
 */


void get_end_time(int increment_hrs,char* str_out,unsigned int str_size)
{
        time_t current_time;
        struct tm * time_info;
	time(&current_time);
        time_info = localtime(&current_time);
	strftime(end_time_string, str_size+1, "%H:%M:%S", time_info);
        char hrs[3] = {0};
		char min[3] = {0};
		char sec[3] = {0};
		for(int i=0;i<2;i++)
		{
			hrs[i]=end_time_string[i];
		}
		int timeout=increment_hrs;
		int inthrs;
		sscanf(hrs, "%d", &inthrs);
		int time1 = inthrs+timeout;
		sprintf(hrs,"%d", time1);
		for(int i=0;i<2;i++)
		{
			end_time_string[i]=hrs[i];
		}
		strncpy(str_out,end_time_string, str_size);

}

int main()
{
char cur_time[STR_SIZE+1];
char end_time[STR_SIZE+1];
get_current_time(cur_time,STR_SIZE);
get_end_time(timeout,end_time,STR_SIZE);
return 0;
}
