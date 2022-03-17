
#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int     cnt;
    t_list  *tmp;

    cnt = 0;
    tmp = lst;
    while (tmp)
    {
        cnt += 1;
        tmp = lst->next;
        if (!tmp)
            break;
    }
    return (cnt);
}
