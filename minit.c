/*****************************************************************************
 * Copyright (C) Aniket G. Thorat aniket41095@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "menu.h"

/*
this func initialise the head and tail pointer of list o, k to NULL
*/
void minit(order *m){
	m->head = NULL;
	m->tail = NULL;
}

/*
This func store the name, price of the food offered by the hotels in the list o
m is the pointer to the list o
*/
void mdec(order *m, int pos) {
	int i = 1, j, k, l;		
	char c, *p, arr1[16];
	FILE *fp, *pp;
	char name[4], price[4];
	mnode *tmp;
	name[0] = pos + '0';
	name[1] = '\0';
	strcat(name, ".txt");
	fp = fopen(name, "r");
	price[0] = pos + '0';
	price[1] = '\0';	
	strcat(price, "price.txt");
	pp = fopen(price, "r");
	while(i <= 8){			
		tmp = (mnode*)malloc(sizeof(mnode));
		j = 0;
		while((c = fgetc(fp)) != '\n'){
			arr1[j] = c;
			j++;
		}
		arr1[j] = '\0';
		p = arr1;
		tmp->mname = malloc(strlen(arr1)+1);
		tmp->mno = i;
		strcpy(tmp->mname, p);
		j = 0;
		l  = k = 0;
		while((c = fgetc(pp)) != '\n'){
			k = k *10 + c - '0';
			l++;
		}
		tmp->money = k;
		if(m->head == NULL){
			m->head = tmp;
		}
		else{
			m->tail->next = tmp;
		}
		m->tail = tmp;
		tmp->next = NULL;
		i++;
	}
	fclose(fp);
	fclose(pp);
	printmenu(m);
}

/*
this func prints the food the hotel offers
*/
void printmenu(order *l){
	mnode *p;
	p = l->head;
	while(p){
		printf("%d: NAME: %s\tPRICE OF THE PRODUCT : %d\n", p->mno, p->mname, p->money);
		p = p->next;
	}
}
