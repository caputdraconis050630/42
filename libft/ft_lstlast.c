#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *tmp;

    tmp = lst;
    if (!lst)
        return (0);
    while (tmp)
    {
        if (!(tmp->next))
            return (tmp);
        tmp = tmp->next;
    }
    return (tmp);
}
