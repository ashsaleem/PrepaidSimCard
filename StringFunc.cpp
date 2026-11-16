#include"StringFunc.h"

void copyString(char* destination, const char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}
bool cmpString(const char* destination, const char* source)
{
	int i = 0;
	while (source[i] != '\0' && destination[i] != '\0')
	{
		if (destination[i] == source[i])
		{
			i++;
		}
		else
		{
			return false;
		}
	}
	return (destination[i] == '\0' && source[i] == '\0');
}