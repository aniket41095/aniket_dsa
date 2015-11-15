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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "hotels.h"

/* 
INPUT- hotel *h: pointer to the list m 
OUTPUT- head and tail pointer initialised to NULL 
*/
void init(hotel *h){
	h->head = NULL;
	h->tail = NULL;
}

/*
INPUT- hotel *h: pointer to list m
OUTPUT- store the names, address, number of the hotels in the list m
  */
void dec(hotel *h){
	int i = 1, j, totalno = 10;				/*totalno is the numbers of hotels */
	char c, *p, *q, arr1[16], arr2[32];
	node *tmp;
	FILE *fp, *pp;
	fp = fopen("list.txt", "r");			/*list.txt file contains the names of all the hotels*/
	pp = fopen("add.txt", "r");			/*add.txt file contains the name of all the hotels  */
	while(i <= totalno){			
		tmp = (node *)malloc(sizeof(node));
		j = 0;
		while((c = fgetc(fp)) != '\n'){
			arr1[j] = c;
			j++;
		}
		arr1[j] = '\0';
		p = arr1;
		tmp->name = malloc(strlen(arr1)+1);
		strcpy(tmp->name, p);

		tmp->no = i;	

		j = 0;
		while((c = fgetc(pp)) != '\n'){
			arr2[j] = c;
			j++;
		}
		arr2[j] = '\0';
		q = arr2;
		tmp->address = malloc(strlen(arr2)+1);
		strcpy(tmp->address, q);

		if(h->head == NULL){
			h->head = tmp;
		}
		else{
			h->tail->next = tmp;
		}
		h->tail = tmp;
		tmp->next = NULL;
		i++;
	}
	/*traverse(h);*/
	fclose(fp);
	fclose(pp);
}
/*THIS FUNC I HAD USE TO PRINT THE LIST*/
/*void traverse(hotel *h){
		node *p;
		p = h->head;
		while(p){
			printf("\n%d:  NAME:%s   ADDRESS: %s\n", p->no, p->name, p->address);
			p = p->next;
		}
}
*/
