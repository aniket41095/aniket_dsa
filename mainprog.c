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
#include <limits.h>
#include "hotels.h"
#include "menu.h"

/*
INPUT: Nothing
OUTPUT:	prints the options to the user ,return the choice 'n' of the user */
int print(){
	int n;
	printf("\n1:SEARCH BY NAME\n");
	printf("2:SEARCH BY PLACE\n");
	printf("3:EXIT\n\n");
	printf("ENTER THE NUMBER OF THE OPTION \n");
	scanf(" %d", &n);
	return n;
}

int main(){
	char  hotels[16], place[16];
	int  number, choice, position, x, num = 1;
	hotel m;					/* This list m will contain names of all the hotels */
	order o, k;					/*This list o will contain names of the food the hotel offers and their prices
							The list k will contain	names , quantity, price of the food the user wants*/ 
	init(&m);
	dec(&m);
	minit(&o);
	minit(&k);
	while(1){
		choice =  print();
		switch(choice) {
			case 1:/*search by name */
			
				printf("ENTER HOTEL NAME\n");
				scanf("%s", hotels);			
				position = searchbyname(&m, hotels, &position);		/* calling function searchbyname which searches the 												hotel in the list m*/
				if(position == 0){
					printf("\nHOTEL NOT FOUND\n");
					break;
				}
				else{
					printf("\n");
					mdec(&o, position);					
					printf("\nENTER 0 WHEN BOOKING IS COMPLETED \n");
					help(&o, &k, num);				
					change(&o, &k);
				}

				break;
	
			case 2:/*search by place*/
				printf("\nENTER THE PLACE\n");
				scanf("%s", place);
				x = searchbyplace(&m, place);				/* calling function searchbyplace which searches the 												hotel in the place which is stored in list m*/
				if(x == 0){
					printf("\nHOTEL NOT FOUND\n");
					break;
				}
				else{	
					printf("\nENTER THE NUMBER OF THE HOTEL\n");
					scanf(" %d", &number);
					mdec(&o, number);
					printf("\nENTER 0 WHEN BOOKING IS COMPLETED\n");
					help(&o,&k, num);
					change(&o, &k);				
				}
				break;
		
			case 3:/*exit*/
				exit(0);
		}
	}
}
