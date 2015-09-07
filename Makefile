all	:	
		gcc main.c `pkg-config --cflags --libs opencv`