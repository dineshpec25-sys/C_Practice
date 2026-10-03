void mode(char port, char *mode)
{
	unsigned int dir_add[11] = {0x21,0x24,0x27,0x2A,0x2D,0x30,0x33,0x101,0x104,0x107,0x10A};
	volatile unsigned char *port=(volatile unsigned char*) port_add[port-64];
	volatile unsigned char *dir=(volatile unsigned char*) dir_add[port-64];

	if(strcmp(("OUT", (char*)mode) == 0))
		*dir=0xFF;
	else
		*dir=0x00;
}

void status(char port, char *status)
{
unsigned int port_add[11] = {0x22,0x25,0x28,0x2B,0x2E,0x31,0x34,0x102,0x105,0x108,0x10B};
	volatile unsigned char *port=(volatile unsigned char*) port_add[port-64];

	if(strcmp(("HIGH", (char*)status) == 0))
	*port=0xFF;
	else if(strcmp(("LOW", (char*)status) == 0)
		*port=0x00;
}
