#include "7seg.h"
int main(void)
{
	while(1)
	{
		for(int n = 1; n <= 9; n++)
		{
			clear_all();
			seg_7(n);
			stay_still(300000UL);
		}
	}
}
