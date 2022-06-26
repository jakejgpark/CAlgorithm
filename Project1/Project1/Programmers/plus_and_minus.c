#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {

	int i=0;
	int ans=0;
	
	while (i<absolutes_len)
	{
		if (signs[i]==false)
		{
			absolutes[i]*=-1;
		}
		i++;
	}
//	i=0;
//	while (i<absolutes_len)
//	{
//		printf("%d ", absolutes[i]);
//		i++;
//	}
//	
	i=0;
	
	while (i<absolutes_len)
	{
		ans+=absolutes[i];
		i++;
	}
	
	printf("%d", ans);
	
    return 0;
}
