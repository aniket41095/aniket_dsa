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
#include <stdlib.h>
#include <string.h>
#include "hotels.h"
#include "menu.h"

/* 
INPUT- order *p: pointer to the list o, order *q: pointer to list k , int number: number is an integer
output: calls the booking function and calls the printorder funcn after booking is completed
*/
int help(order *p, order *q, int number){
	int no, qty;
	while(1){
		printf("\nSELECT THE MENU ENTER THE NUMBER\n");
      		scanf("%d", &no);
       		if(no == 0){	
               		printorder(q, number);
               		return 1;
		}
       		else{
			printf("ENTER THE QUANTITY\n");
			scanf(" %d", &qty);           					
			book(p, q, no, qty);
	       	}
	}
}

/*
This func prints the order  the user wants*/
int printorder(order *n, int no){
	mnode *q;
	int total = 0, x, y;
	q = n->head;
	if(no){
		printf(" ORDER: ");   
		while(q){
			printf("\n%s :\n\t\tQUANTITY: %d\tCOST OF 1 PRODUCT: %d\n\n", q->mname, q->qty, q->money);
			x = q->qty;
			y = q->money;
			q = q->next;
			total = total + x * y;
		}	
		printf("THE TOTAL AMOUNT IS %d\n", total);
	}
	return total;
}
/*
INPUT- order *m: pointer to the list o , order *n: pointer to list k
This func store the order in list k
*/
void book(order *m, order *n, int num, int qnty){
	mnode *p, *q, *tmp;
	int i = 1;
	p = m->head;
	q = n->head;
	while(p){
		if(p->mno == num){
			tmp = (mnode *)malloc(sizeof(mnode));
			tmp->mname = p->mname;
			tmp->qty = qnty;
			tmp->money = p->money;
			tmp->next = NULL;
			if(n->head == NULL){
				n->head = tmp;
			}
			else{	
				while(q){
					if(q->mname == p->mname){
						q->qty = qnty;
						i = 0;
						break;
					}
					else{
						q = q->next;
					}
				}
				if(i)
					n->tail->next = tmp;
			}
			if(i)
				n->tail = tmp;
		}
		p = p->next;
	
	}

}

/*
This func ask the user to change anythng from the order and calls help func to add and rem func to remove some food from the order
*/
void change(order *m, order *n){
	char c;
	int choice, no, num = 0, x;
	printf("DO YOU WANT TO CHANGE SOMETHING FROM YOUR ORDER? y/n\n");
	scanf(" %c", &c);
	switch(c){
		case 'y':
			printf("ENTER 1 TO ADD OR ENTER 2 TO REMOVE\n");
			scanf("%d", &choice);
			switch(choice) {
				case 1:
					printmenu(m);
					printf("ENTER 0 WHEN BOOKING IS COMPLETED\n");
					help(m, n, num);
					break;
				case 2:
					printf("ENTER THE NUMBER OF THE MENU IN YOUR ORDER YOU WANT TO CHANGE\n");
					scanf("%d", &no);
					rem(n, no);
					break;
				default:
					break;
			}
			break;
		case 'n':
			printf(" FINAL ");
			x = printorder(n, 1);
			details(n, &x);
			exit(0);
		default:
			exit(0);
	}
	change(m,n);
	
}

/* 
This func remove the food or change the quantity of the food
*/
void rem(order *l, int num){
	int no, i = 1, qnty;
	mnode *p, *q;
	printf("ENTER 1 TO CANCEL THAT MENU\nENTER 2 TO CHANGE THAT QUANTITY \n");
	scanf("%d", &no);
	p = l->head;
	while(i != num){
		q = p;
		p = p->next;
		i++;
	}
	switch(no){
		case 1:
			
			q->next = p->next;
			p->next = NULL;
			break;
		
		case 2:
			printf("ENTER THE QUANTITY\n");
			scanf("%d", &qnty);
			p->qty = qnty;
			break;
		default:
			break;
	}
}
/*
this function store the details of user, and their order details in the file
*/
void details(order *m, int *amount){
	char  name[16], last[16], address[16], house[8], list[8] = "ORDER: ",end[16] = "---------------";
	int no, money, i;
	if(*amount != 0){
		mnode *p;
		p = m->head;
		FILE *pp;

		pp = fopen("details.txt", "a");
		printf("\nENTER YOUR FIRST NAME\n");
		scanf(" %s", name);

		printf("\nENTER YOUR LAST NAME\n");
		scanf(" %s", last);
		fprintf(pp,"\nNAME: %s %s\t", name, last);

		printf("\nENTER YOUR HOUSE NUMBER\n");
		scanf(" %s", house);
		printf("\nENTER YOUR LANDMARK\n");
		scanf(" %s", address);
		fprintf(pp, "HOUSE NUMBER: %s\tLANDMARK: %s\n", house, address);

		fprintf(pp, "%s\n", list);
		while(p){
			no = p->qty;
			money = p->money;
			fputs(p->mname, pp);
			fprintf(pp,"\tQTY:%d\t MONEY:%d\n", no, money);
			p = p->next;
		}
		fprintf(pp,"TOTAL AMOUNT IS %d\n ", *amount);
		for(i = 0; i < 3; i++)
			fprintf(pp, "%s", end);
		printf("YOUR ORDER WILL BE DELIVERED TO YOUR PLACE WITHIN 30 MINUTES\n\t\t\t THANK YOU\n");	  
 		fclose(pp);
	}
}	

																		
