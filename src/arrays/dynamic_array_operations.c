#include<stdio.h>

int main()
{
	int *dynamic_array;
	int capacity=0;
	while(1)
	{
		int choice;
		printf("\t-------------------------------\n");
		printf("\t\tDynamic Array\n");
		printf("\t1. Add elements\n");
		printf("\t2. Delete elements\n");
		printf("\t3. Search elements\n");
		printf("\t4. Display Array\n");
		printf("Enter the choice :");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 0:
				{
					free(dynamic_array);
					return 0;
				}
			case 1:
				{
					dynamic_array=add_elements(dynamic_array, &capacity);
					break;
				}
			case 2:
				{
					dynamic_array=delete_elements(dynamic_array, &capacity);
					break;
				}
			case 3:
				{
					search_elements(dynamic_array, capacity);
					break;
				}
			case 4:
				{
					display_array(dynamic_array, capacity);
					break;
				}
		}
	}
}
