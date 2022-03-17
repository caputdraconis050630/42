
#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *lst;

    lst = (t_list *)malloc(sizeof(t_list));
    lst->content = content;
    lst->next = 0;
    return (lst);
}
