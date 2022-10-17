#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {

	int i=0;
	int ans=0;
	
	while (i<absolutes_len)
	{
		if (signs[i]==false)
		{
			ans+=-absolutes[i];
		}
		else
		{
			ans+=absolutes[i];
		}
		i++;
	}

	printf("%d", ans);
	
    return 0;
}
