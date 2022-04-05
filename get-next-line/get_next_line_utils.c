#include "get_next_line.h"

t_list	*get_node(t_list *head, int fd)
{
	t_list	*node;

/* fd: 3인 노드가 있을 때 */
	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node); /* 그 노드 리턴 */
		else
			node = node->next;
	}

/* fd:3인 노드가 없거나 아예 연결리스트가 없을 때 */
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);

/* 새로 만든 노드에는 쓰레기값이 들어있다. 초기화시킨다. */
	node->fd = fd;
	node->save = NULL;
	node->prev = head;
	node->next = head->next;

/* 앞뒤 노드에 나를 넣어준다. */
	if (head->next) /* head->next가 NULL이면 할 필요가 없음 */
		head->next->prev = node;
	head->next = node;

	return (node);
}

/**************************************************************************/

void	del_node(t_list **node)
{
	free((*node)->save); /* 1. save 프리 */
	(*node)->prev->next = (*node)->next; /* 2. 앞 노드에 다음 노드 정보 넣기 */
	if ((*node)->next)
	{
		(*node)->next->prev = (*node)->prev; /* 3. 뒷 노드에 앞 노드 정보 넣기 */
	}
	free(*node); /* 4. node 프리 */
	*node = NULL; /* (댕글링 포인터 방지) */
}

/* free_node()에 node의 이중포인터를 넘겨주어야 하는데,
** node의 포인터만 복사해오면 그것의 주소값은 함수 내에서는 알길이 없으므로
** 이중포인터로 받아와야 한다. */

char	*read_iter(char **s_save, int fd)
{
	char		*buf;
	ssize_t		nread;
	char		*temp; /* append_buf()하며 리셋되는 save를 free하기 위해서 */
	char		*new;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	nread = 0;
	new = *s_save;

/* while문이 돌아가는 경우: 뭔가가 read될 때
** 1. save가 NULL && 뭔가가 더 read됨 (즉, 처음 읽는 파일일 때)
** 2. save에 있는 문자열에 \n이 없음 && 뭔가가 더 read됨 */
	while (new == NULL || !ft_strchr(new, '\n'))
	{
/* read의 성공check를 while문 조건식에 넣으면 가독성이 떨어져서 여기에 넣었다.
** 또 \n이 있는 인자는 read하지 않도록 이곳에 배치했다. */
		nread = read(fd, buf, BUFFER_SIZE);
		if (nread <= 0)
			break ;
		buf[nread] = '\0';
		temp = new;
		new = append_buf(new, buf); /* ft_strjoin(temp, buf)과 같은 결과를 낸다. */
		free(temp);
	}
	free(buf);
	buf = NULL;
	if (nread < 0)
		return (NULL);
	return (new);
}

/**************************************************************************/

/* save에 내용이 있을 때만 동작한다 */
char	*get_line(char const *save)
{
	size_t	len; /* return할 line의 길이를 저장 */
	char	*line;

	if (ft_strchr(save, '\n')) /* \n이 있을 때 */
	{
		len = ft_strchr(save, '\n') - save + 1; /* +1은 \n을 위한 자리 */
	}
	else /* \n이 없을 때 == 마지막 줄일 때 */
	{
		len = ft_strchr(save, '\0') - save;
	}
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, save, len + 1);
	return (line);
}

/**************************************************************************/

/* line 반환하고 남은 부분을 남겨두기 위한 함수
** offset에는 ft_strlen(line)이 들어온다 */
char	*set_remains(char **s_save, size_t offset)
{
	char	*new;

/* s_save + offset은 \n 다음을 시작지점으로 하는 문자열을 의미한다. */
	new = malloc(ft_strlen(*s_save + offset) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, *s_save + offset, ft_strlen(*s_save + offset) + 1);
	free(*s_save);
	*s_save = NULL;
	return (new);
}

/**************************************************************************/

/* 이전에 만든 ft_strjoin()과 거의 같은 기능을 하는 함수다.
** 1. 두 번째 인자에 NULL이 들어올 일이 없는 점
      (add할 buf가 있을 때만 사용되는 함수임. save만 리턴하는 부분 필요없음.)
** 2. 함수 사용을 줄이기 위해 ft_strdup를 함께 쓰는 대신 ft_strlcpy만 써야 하는 점
** 3. 가독성을 위한 변수명 수정
** 을 위해 약간 변경했다. */
char	*append_buf(char const *save, char const *buf)
{
/* save에 buf가 덧붙여진 새로운 문자열을 반환 */
	char	*new;

	if (buf == NULL)
		return (NULL);

/* 처음 읽는 파일일 때 */
	else if (save == NULL && buf)
	{
		new = malloc(ft_strlen(buf) + 1);
		if (new == NULL)
			return (NULL);
		ft_strlcpy(new, buf, ft_strlen(buf) + 1); /* buf copy */
		return (new);
	}

/* if (*save && *buf) */
	new = malloc(ft_strlen(save) + ft_strlen(buf) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, save, ft_strlen(save) + 1); /* save copy */
	ft_strlcpy(new + ft_strlen(save), buf, ft_strlen(buf) + 1); /* buf copy */
	
	return (new);
}

/**************************************************************************/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s) /* s에 NULL이 들어오지 않도록 조심해야 한다. */
	{
		len++;
		s++;
	}
	return (len);
}

/**************************************************************************/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	if (*s == (char)c) /* s의 terminating-NUL도 체크한다. */
		return ((char *)s);
	else
		return (NULL);
}

/**************************************************************************/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i]) /* (dstsize - 1)만큼 복사하고 */
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize) /* 마지막에는 NUL을 넣어준다 */
	{
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}