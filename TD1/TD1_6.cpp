/* Premier programme en C */
#include<stdlib.h>
#include<stdio.h>


int main1()
{
	int x = 14, y = 13;
	if (x > y)
	{
		if (x < 20)
		{
			x -= 10;
		}
		else
		{
			x += 10;
		}
	}
	printf("Partie 1 : %d\n", x);
	return 0;
}

int main2()
{
	int x = 4, y = 3;
	x = x + y;
	y = x - y;
	printf("Partie 2 : %d\n", y);
	return 0;
}

int main3()
{
	int x = 0, y = 100;
	while (x * x <= y)
	{
		x += 1;
	}
	printf("Partie 3 : L'instruction a ete executee %i fois", x);
	return 0;
}



int main()
{
	main1();
	main2();
	main3();
	return EXIT_SUCCESS;
}

