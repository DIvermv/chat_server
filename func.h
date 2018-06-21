#ifndef FUNC_H
#define FUNC_H


#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/msg.h>
//struct  Panel  ReadDir(char * Dir_Name); // функция смены каталога
//void update_screen(struct DCommander DCommander);
//void update_panel(struct Panel Pan, int delta, int activ);
//struct DCommander press_enter(struct DCommander DCom);
//int Th_Copy_file(char* Sourse_Dir,char * Dest_Dir, char* File_Name );
 // потоковые функции
pthread_mutex_t mut;
int Server(void * f_data);
//int Client_mq(void * f_data);
// int Copy_file(void * f_name_data);
// int Copy_Progress(void * f_data);
#endif
