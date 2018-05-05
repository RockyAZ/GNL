#include "get_next_line.h"

int main()
{
	char *str;
	char *str1;
char *res;
    str = ft_strdup("123456");
    str1 = str;
    str1++;
    str1++;
    str1++;
//    printf("%ld\n", str1 - str);
res = ft_strdup(str1);
printf("%s\n", res);
res = ft_strdup("\0");
printf("%s\n", res);
printf ("%d\n", *res);
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