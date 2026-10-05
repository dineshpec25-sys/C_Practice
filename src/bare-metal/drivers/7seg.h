#include "/home/acer/bare_metal/gpio.h"

#ifndef SEG7_H
#define SEG7_H

#define A_HIGH GIVE_OUT('B',4,HIGH)
#define B_HIGH GIVE_OUT('H',6,HIGH)
#define C_HIGH GIVE_OUT('H',5,HIGH)
#define D_HIGH GIVE_OUT('H',4,HIGH)
#define E_HIGH GIVE_OUT('H',3,HIGH)
#define F_HIGH GIVE_OUT('E',3,HIGH)
#define G_HIGH GIVE_OUT('G',5,HIGH)

void clear_all()
{
	GIVE_OUT('B', 4,LOW);
	GIVE_OUT('H', 6, LOW);   
	GIVE_OUT('H', 5, LOW);   
	GIVE_OUT('H', 4, LOW);   
	GIVE_OUT('H', 3, LOW);   
	GIVE_OUT('E', 3, LOW);   
	GIVE_OUT('G', 5, LOW);   
}

void zero()
{
	A_HIGH;
	B_HIGH;
	C_HIGH;
	D_HIGH;
	E_HIGH;
	F_HIGH;
}

void one()
{
	B_HIGH;
	C_HIGH;
}

void two()
{
	A_HIGH;
	B_HIGH;
	G_HIGH;
	E_HIGH;
	D_HIGH;
}

void three()
{
	A_HIGH;
	B_HIGH;
	G_HIGH;
	C_HIGH;
	D_HIGH;
}

void four()
{
	B_HIGH;
	C_HIGH;
	F_HIGH;
	G_HIGH;
}

void five()
{
	A_HIGH;
	F_HIGH;
	G_HIGH;
	C_HIGH;
	D_HIGH;
}

void six()
{
	A_HIGH;
	C_HIGH;
	D_HIGH;
	E_HIGH;
	F_HIGH;
	G_HIGH;
}

void seven()
{
	A_HIGH;
	B_HIGH;
	C_HIGH;
}

void eigth()
{
	A_HIGH;
	B_HIGH;
	C_HIGH;
	D_HIGH;
	E_HIGH;
	F_HIGH;
	G_HIGH;
}

void nine()
{
	A_HIGH;
	B_HIGH;
	C_HIGH;
	D_HIGH;
	F_HIGH;
	G_HIGH;
}

void seg_7(int num)
{
	MODE_SET('B',4,OUT);
	MODE_SET('H',6,OUT);
	MODE_SET('H',5,OUT);
	MODE_SET('H',4,OUT);
	MODE_SET('H',3,OUT);
	MODE_SET('E',3,OUT);
	MODE_SET('G',5,OUT);
	MODE_SET('E',5,OUT);
	switch(num)
	{
		case 0:zero(); break;
		case 1:one(); break;
		case 2:two(); break;
		case 3:three(); break;
		case 4:four(); break;
		case 5:five(); break;
		case 6:six(); break;
		case 7:seven(); break;
		case 8:eigth(); break;
		case 9:nine(); break;
	}
}

#endif 
