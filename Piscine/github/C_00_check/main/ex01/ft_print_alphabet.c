#include <unistd.h>

void ft_print_alphabet(void);

void ft_print_alphabet(void){
	char a = 'a';
	while(a  <= 'z'){
		write(1, &a, 1);
	   	a+=1;
	}
}

