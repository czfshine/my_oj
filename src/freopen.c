#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	freopen("test.txt","w",stdout);

	srand(1);

	for (int i = 0; i < 100; ++i)
	{
		printf("%d %d",rand(),rand());
	}
	return 0;
}