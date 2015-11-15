TITLE: FOOD ORDERING SYSTEM
NAME: ANIKET THORAT
MIS: 111308079
-------------------------------------------------------------------------------------------------------------------------------------------
My program gives a platform to check out various hotels in pune.
User can search the hotels according to name or place which the user will get in a single software.
If the hotel is found user can check the menu of the hotel.
This property basically we do not get in  a single software.So i tried to solve that problem.
You can order the food you want.Once the booking is complete and then you realise to change that i.e you want to change the quantity of the food, add some more food to your order list or cancel the order.
The total details of your order is stored in a permanent file i.e we can print the receipt.  
-------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------
I had stored the names of hotels in a file named "list.txt" and address in "add.txt" file . The names of hotels and their addresses are stored in the list using this text file.

I had stored the menu list in a file named "1.txt", "2.txt" and so on upto 10(no of menu) and their prices in files 1price.txt, 2price.txt and so on.The names of menu and their prices are stored are stored in another list using this files.
----------------------------------------------------------------------------------------------------------------------------------------
hotels.h, menu.h:
	this file contain the code for the declaration of the structure type

init.c
	this file contains the code to initialise the list and store the names of the hotels in the list

mainprog.c
	this file contains the code for the main() function, the main logic of the code

minit.c
	this file contains the code to store the menu list in the list

other.c
	this file contains the code for booking in which the ordered list is stored in another list, change the ordered list, remove the menu 		from the list, print the order and store the user details in the list

search.c
	this file contains the code to search the hotel by name or search hotels in a place.

