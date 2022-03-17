#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *dst;
    t_list  *tmp;

    if (!lst || !f || !del)
        return (0);
    dst = ft_lstnew(f(lst->content));
    if (!dst)
        return (0);;
    lst = lst->next;
    while (lst)
    {
        tmp = ft_lstnew(f(lst->content));
        if (!tmp)
        {
            ft_lstclear(&dst, del);
            return (0);
        }
        ft_lstadd_back(&dst, f(lst->content));
        lst = lst->next;
    }
    return (dst);
}
