
#include "func.h"

int main (int argc, char *argv[])
{
 //   setlocale(LC_ALL, "Russian");
//инициализируем окно ncurses
   // setlocale(LC_ALL,"");
 // noecho();

     
  int ch = 0;
  // инициализируем очередь

    pthread_t Server_tid; // идентификатор потока копирования 
//    pthread_t Client_tid; // идентификатор потока статуса копирования 
    pthread_attr_t Server_attr; // атрибуты потока копирования 
  //  pthread_attr_t Client_attr; // атрибуты потока статуса копирования 
    pthread_attr_init(&Server_attr);
  //  pthread_attr_init(&Client_attr);
   // f_name_data.Sourse_Dir=Sourse_Dir;// назначаем аргументы
   // f_name_data.Dest_Dir=Dest_Dir;
   // f_name_data.File_Name=File_Name;
   // f_name_data.copy_progress=30;
    pthread_mutex_init(&mut,NULL);
      	printf("Сервер запущен\n"); 
   pthread_create(&Server_tid,&Server_attr,Server,NULL);// создаем новый поток
  // pthread_create(&Client_tid,&Client_attr,Client_mq,NULL);// создаем новый поток
  // pthread_create(&Status_tid,&Status_attr,Copy_Progress,&f_name_data);
//  pthread_join(Client_tid,NULL);
 
  while (1)
   sleep(1);
  return 0;
}
