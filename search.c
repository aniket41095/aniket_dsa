/*****************************************************************************
 * Copyright (C)Aniket G. Thorat aniket41095@gmail.com
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
#include "hotels.h"

/*
INPUT- hotel *h: POINTER H TO THE LIST "hotel m" , char *name: pointer to the name of the hotel which is to be searched, int *pos: store the position of the hotel searched in the list 
OUTPUT-	RETURNS INT VALUE O IF HOTEL NOT FOUND, RETURNS THE POSITION OF THE HOTEL IN THE LIST IF FOUND
*/

int searchbyname(hotel *h, char *name, int *pos){
	node *p;
	int  x = 1;
	p = h->head;
	pos = &x;	
	while(p){
		if(strcmp(p->name, name) == 0){
			return *pos;
		}
		
		else{
			p = p->next;
			x++;
		}
	}
	if(!p){
		x = 0;
		return 0;
	}			
	return 1;
}

/*
INPUT- hotel *h: pointer to the list, char *plce: pointer to the name of the place where hotel is to be searched
OUTPUT- return int 1 when hotel found, 0 when not found
 */

int searchbyplace(hotel *h, char *plce){
	node *p;
	int  x = 1, i = 0;
	p = h->head;
	while(p){
		if(strcmp(p->address, plce) == 0){	
			printf("HOTEL FOUND: ");
			printf("\t%d: %s\n", x, p->name);
			i = 1;
		}
		p = p->next;
		x++;
		
	}
	return i;
}


