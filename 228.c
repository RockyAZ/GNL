#include "get_next_line.h"

int main()
{
	char *str;
	char *str1;

    str = ft_strdup("12345");
    str1 = str;
    str1++;
    str1++;
    str1++;
    str1++;
    printf("%ld\n", str1 - str);
    return (0);
}

/*
int main()
{
	char **str;
int i = 0;
    str = ft_strsplit("abcd*1234*ffff**", '*');
    printf("%s\n", str[0]);

str[0] = NULL;
str[1] = NULL;
str[2] = NULL;
str[3] = 0;
    while (!str[i] || str[i])
        i++;
    printf("III-%d\n", i);
    printf("{P-%s\n", str[i-1]);
    return (0);

}
*/