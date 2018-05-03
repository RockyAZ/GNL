#include "get_next_line.h"
/*
int main()
{
	char *str;
	char *str1;
    char *str;

    str = ft_strdup("abcd");
    str1 = ft_strdup("1234");
    str = ft_strjoin(str, str1);
    printf("%s\n", str);
    return (0);

}
*/

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