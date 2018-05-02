#include "get_next_line.h"
/*
void f(t_list **cp)
{
    static t_list *ccp;

    ccp = NULL;
    ccp = ft_lstnew("ABCD", 5);
    printf("%s\n", ccp->content);
    *cp = ccp;
}
*/
int main()
{
static t_list *cp;

if (cp == NULL)
    printf("IT IS NULL\n");
else
    printf("IT IS NOT\n");
return (0);
}
