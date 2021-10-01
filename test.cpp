#include <stdio.h>

int main()
{
	int d, m, y, day;
	printf("Enter the Date \n");
	scanf("%d", &d);

	printf("Enter the Month \n");
	scanf("%d", &m);

	printf("Enter the Year \n");
	scanf("%d", &y);

	day = (d += m < 3 ? y - 1 : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;

	printf("the day of the week is : %d", day);

	switch (day)
	{
	case 0:
		printf("Sunday.\n");
		break;

	case 1:
		printf("Monday.\n");
		break;

	case 2:
		printf("Tuesday.\n");
		break;

	case 3:
		printf("Wednesday.\n");
		break;

	case 4:
		printf("Thursday.\n");
		break;

	case 5:
		printf("Friday.\n");
		break;

	case 6:
		printf("Saturday.\n");
		break;

	default:
		printf("The number you have enter is invalid");
		break;
	}
}
//  TASK:
//  day=(d+=m<3?y-1:y-2,23*m/9+d+4+y/4-y/100+y/400)%7
//  please elaborate
