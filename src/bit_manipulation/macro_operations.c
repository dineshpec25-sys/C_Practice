#include<stdio.h>
#include<stdint.h>

#define SET_BIT(reg, bit) (reg |= (1 << bit))
#define CLEAR_BIT(reg, bit) (reg &= ~(1 << bit))
#define TOGGLE_BIT(reg, bit) (reg ^= (1 << bit))
#define CHECK_BIT(reg, bit) ((reg >> bit) & 1)

int main()
{
	uint8_t reg=0;

	printf("Entre the initial register :");
	scanf("%hhu", &reg);

	int no_op;
	
	printf("Enter the number of operations to be performed :");
	scanf("%d", &no_op);

	for(int i = 0; i < no_op; i++)
	{
		int op;
		printf("Enter the operation :");
		scanf("%d", &op);

		uint8_t bit = 0;
		printf("Enter the number :");
		scanf("%hhu", &bit);

		switch (op)
		{
			case 1: {printf("The output : %u\n", SET_BIT(reg, bit));
				 break;}
			case 2: {printf("The output : %u\n", CLEAR_BIT(reg, bit));
					break;}
			case 3: {printf("The output : %u\n", TOGGLE_BIT(reg, bit));
					break;}
			case 4: {printf("The output : %u\n", CHECK_BIT(reg, bit));
					break;}
			default: {printf("No such options Available!!!\n");
		}
	}
	}
}
