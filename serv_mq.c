#include "func.h"
#include <pthread.h>
int prgs;
//struct mq_attr attr;
int Server(void * f_data)
{	
      	printf("Сервер запущен\n"); 
	char temp[256];
	char mess[256];
	int msqid; // IPC дескриптор для очереди сообщений 
   char pathname[] = "/initrd.img"; // Имя файла,  использующееся для генерации ключа.
    key_t key; /* IPC ключ */

   struct mymsgbuf
    {
        long mtype;
	struct mysbuf
	 {
        	short pid;	
                char mtext[256];
	 } myscbuf;
    }mybuf;

    if((key = ftok(pathname,0)) < 0){// генерируем ключ
       printf("Can\'t generate key\n");
        return(-1);
    }
    // Пытаемся получить доступ по ключу к очереди сообщений, если она существует, или создать ее, с правами доступа read & write для всех пользователей 
    if((msqid = msgget(key, 0666 | IPC_CREAT)) < 0){
      printf("Can\'t get msqid\n");
        return(-1);
    }
int c=0;
int len;
int number_of_client=0;
int client_pid[256];
char client_nik[256][256];
	            printf("Сервер запущен. Подключена очередь %i\n",msqid); 
 while(1)
   {
      if((len = msgrcv(msqid, (struct msgbuf *) &mybuf, 256, 1, 0))>0)  // считано сообщение ненулевой длины 
          { 
		  

	            printf("Прочитано сообщение:%s \n", mybuf.myscbuf.mtext); 
		  int check=-1;
		  for(int i=0;i<number_of_client;i++)// проверяем, есть ли клиент
			  if(mybuf.myscbuf.pid==client_pid[i])
				  check=i;
		  if(check>-1) // клиент существует
		  {
		  
                          strcpy(mess,client_nik[check]);
			  strcat(mess,": ");
			  strcat(mess,mybuf.myscbuf.mtext);
		  }
		  else// клиент поступил впервые
		  {
			  client_pid[number_of_client]=mybuf.myscbuf.pid;
			  strcpy(client_nik[number_of_client],mybuf.myscbuf.mtext);
			  number_of_client++;
	            printf("Зарегистрирован %d с именем %s.Количество пользователей - %i.\n",mybuf.myscbuf.pid,mybuf.myscbuf.mtext,number_of_client); 
                          strcpy(mess,"System: ");
			  strcat(mess,mybuf.myscbuf.mtext);
			  strcat(mess," inter.");
		  }
		for(int i=0;i<number_of_client;i++) // выводим в очередь на всех пользователей
		 {
		
                    mybuf.mtype=client_pid[i];
                    strcpy(mybuf.myscbuf.mtext,mess);
                    len=strlen(mybuf.myscbuf.mtext)+sizeof(mybuf.myscbuf.pid)+1;
                    msgsnd(msqid, (struct msgbuf *) &mybuf, len, 0);
		 }	
          }
   } 
pthread_exit(0); }  





/*
int Client_mq(void * f_data)
 {
   int msqid; // IPC дескриптор для очереди сообщений 
   char pathname[] = "upd_scr.c"; // Имя файла,  использующееся для генерации ключа.
   key_t key; // IPC ключ
   pid_t Pid;
   struct mymsgbuf
    {
        long mtype;
	struct mysbuf
	{
	short pid;	
        char mtext[256];
	} myscbuf;
    }mybuf;
   Pid=getpid();
 if((key = ftok(pathname,0)) < 0){
        printf("Can\'t generate key\n");
    pthread_exit(-1);
    } 
 if((msqid = msgget(key, 0666 | IPC_CREAT)) < 0){
        printf("Can\'t get msqid\n");
    pthread_exit(-1);
    }

    char temp[256];
    char nik[256];
    unsigned int prio = 1;
    WINDOW *win_c = newwin(4,COLS-1 , LINES-4, 1);
 
   // pthread_mutex_lock(&mut);
   
      mvwaddstr(win_c,1, 1, "Enter your nickname:");
      wrefresh(win_c);
   // pthread_mutex_unlock(&mut);
      mvwgetstr(win_c,2, 1, nik);
    // регистрируемся 
    mybuf.mtype=1;
    mybuf.myscbuf.pid=Pid;
    strcpy(mybuf.myscbuf.mtext,nik);
   int len=strlen(mybuf.myscbuf.mtext)+sizeof(Pid)+1;
     msgsnd(msqid, (struct msgbuf *) &mybuf, len, 0);



      strcpy(temp,"");
      strcat(temp,"Your nickname: ");
     strcat(temp,nik);
     char nk[256];
    strcpy(nk,temp); 
    char t[256];
   // mybuf.mtype=1;
   // mybuf.myscbuf.pid=Pid;
   while(1)
   {
            pthread_mutex_lock(&mut);
      werase(win_c); //чистим экран
     // box(win_c, 0, 0);
      mvwaddstr(win_c,0, 1, nk);
      wrefresh(win_c);
            pthread_mutex_unlock(&mut);
      mvwgetstr(win_c,1, 1, temp);
   // strcpy(mybuf.myscbuf.mtext,nik);
   // strcat(mybuf.myscbuf.mtext,": ");
   // strcat(mybuf.myscbuf.mtext,temp);
      strcpy(mybuf.myscbuf.mtext,temp);
     msgsnd(msqid, (struct msgbuf *) &mybuf, strlen(mybuf.myscbuf.mtext)+sizeof(Pid), 0);
   }
    delwin(win_c);
    pthread_exit(0);
 }
*/
