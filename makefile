all:
	gcc main.c serv_mq.c -o Chat_server -lpthread -lrt
