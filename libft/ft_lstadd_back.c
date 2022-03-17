#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    tmp = *lst;
    if (!lst)
        return ;
    if (!(tmp->next))
        tmp->next = new;
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    new->next = 0;
}
