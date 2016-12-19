#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include"define.h"
#include"bcm2835/src/bcm2835.h"
#include<stdio.h>
#include<string.h>
#include"move.h"
#include"getch.h"
#include"init.h"

void pin_test(char mesg_name[256], uint8_t pin, int time, unsigned int delay);
int test(void);
void test_init(void);

#endif

