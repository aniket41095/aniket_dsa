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

#ifndef __menu_h
#define __menu_h
typedef struct mnode {
	char *mname;
	int qty;
	int mno;
	int money;
	struct mnode *next;
}mnode;

typedef struct {
	mnode *head, *tail;
}order;

void minit(order *m);
void mdec(order *m, int pos);
void book(order *m, order *n, int num, int qnty);
void printmenu(order *l);
int printorder(order *n, int no);
int help(order *p, order *q, int number);
void change(order *m, order *n);
void rem(order *l, int num);
void details(order *m, int *amount);
#endif
