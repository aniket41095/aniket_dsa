/*****************************************************************************
 * Copyright (C) ANIKET G. THORAT aniket41095@gmail.com
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

#ifndef __hotels_h
#define __hotels_h
typedef struct nodes {
	char *name;
	char *address;
	int no;
	struct nodes *next;
}node;

typedef struct {
	 node *head, *tail;
}hotel;

void init(hotel *h);
void dec(hotel *h);
int searchbyname(hotel *h, char *name, int *position);
int searchbyplace(hotel *h, char *plce);
void openfile(int pos);
int print();
/*void traverse(hotel *h);*/
#endif
