#include "libft.h"

void	ft_atoi_tester()

{
	const char *str = "-abc12345";
	int num = ft_atoi(str);
	printf("the integer value is: %d\n", num);
	return (0);
}

void	ft_bzero_tester()
 {
     char prueba[50] ="Marventis";
     int length = 25;

     printf("before ft_bzero: \"%s\"\n", prueba);
     ft_bzero(prueba, length);
     printf("after ft_bzero: \"%s\"\n", prueba);
     return (0);
 }

void	ft_calloc_tester()
{
	int *ptr;
	size_t num_elements = SIZE_MAX;
	size_t element_size = SIZE_MAX;

	ptr = (int *) ft_calloc (num_elements, element_size);
	if (ptr == NULL)
	{
		printf("Error there's no memory to save. %p\n", ptr);
		return (1);
	}
	printf("Array values:\n");
	for (size_t i = 0; i < num_elements; i++)
	{
		printf ("%d", ptr[i]);
	}
	free (ptr);
	printf("\n");
	return (0);
}

void	ft_isalnum_tester()
{
   int alnum= ft_isalnum (' ');
   printf("%d \n", alnum);
   return (0);
}

void	ft_isalpha_tester()
{
	int character = ft_isalpha(' ');
	printf("%d\n", character);
	return (0);
} 

void	ft_isascii_tester()
{
   int ascii = ft_isascii(65);
   printf("%d \n", ascii);
   return (0);
} 

void	ft_isdigit_tester()
{
   int num = ft_isdigit ('1');
   printf ("%d \n", num);
   return (0);
} 

void	ft_isprint_tester()
{
   int print = ft_isprint(12);
   printf("%d \n", print);
   return (0);
}

void	ft_itoa_tester()
{
	int	numb = 12345;
	char *str_numb = ft_itoa(numb);

	if (str_numb == NULL)
	{
		printf("Error: ther'es no enough memory to save.\n");
		return (1);
	}
	printf("The number %d converted to string is: %s\n", numb, str_numb);

	free (str_numb);

	return (0); 
}

void	ft_lstadd_back_tester()
{
	t_list	*list = NULL;
	t_list	*lst1;
	t_list	*new;

	lst1 = ft_lstnew("Marventis");
	new = ft_lstnew("Tiamant");
	if (!lst1 || !new)
	{
		free(lst1);
		free(new);
		return (-1);
	}
	list = lst1;
	printf("Before the function: %s\n", (char *)(*list).content);
	ft_lstadd_back(&list, new);
	printf("After the function %s, ", (char *)(*list).content);
	printf("%s\n", (char *)(*list).next->content);
	free(lst1);
	free(new);
	return (0);
}

void	ft_lstadd_front_tester()
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew("Cat");
	new = ft_lstnew("Dog");
	ft_lstadd_front(&list, new);
	printf("%s\n", (char *) list->content);
	printf("%s\n", (char *) list->next->content);
}
void	delet(void *delete)
{
	free(delete);
	delete = NULL;
}
void	ft_lstclear_tester()
{
	t_list	*list = NULL;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*current;

	lst1 = ft_lstnew(ft_strdup("Martentis"));
	lst2 = ft_lstnew(ft_strdup ("Tiamant"));

	ft_lstadd_front(&list, lst1);
	ft_lstadd_front(&list, lst2);
	printf("Content:\n");

	current = list;
	while (current != NULL)
	{
		printf("%s\n", (char *)(current->content));
		current = current->next;
	}

	ft_lstclear(&list, &delet);

	if (!list)
		printf("The list has been successfully deleted.\n");

	else
		printf("The list hasn't been successfully deleted.\n");

	return (0);
}
void	be_free(void *data)
{
	free(data);
}
void	ft_lstdelone_tester()
{
	t_list *list = NULL;
	t_list *lst1;
	t_list *lst2;

	lst1 = ft_lstnew(ft_strdup("Marventis"));
	lst2 = ft_lstnew (ft_strdup("Ignisaria"));

	if(!lst1 || !lst2)
	{
		if (lst1)
			ft_lstdelone(lst1, be_free);
		if (lst2)
			ft_lstdelone(lst2, be_free);
		return (-1);
	}
	lst1->next = lst2;
	list = lst1;

	printf("Contenido antes de eliminar: %s\n", (char *)list->content);

	t_list *temp = list->next;
	ft_lstdelone(list, be_free);
	list = temp;

	if (list)
		printf ("Contenido actual: %s\n", (char *)list->content);
	else
		printf ("Contenido después de eliminar la lista");
	return (0);
}

static void	 print_content(void *content)
{
	printf("%s\n", (char *)content);
}

static void uppercase_content(void *up)
{
	char *str = ((char *)up);
	int i = 0;

	while (str[i] != '\0')
	{
		printf("%c", str[i] - 32);
		i++;
	}
	printf("\n");
}

void	ft_lstiter_tester()
{
	t_list	*lst = NULL;
	t_list	*temp = NULL;

	ft_lstadd_back(&lst, ft_lstnew("marventis"));
	ft_lstadd_back(&lst, ft_lstnew("zefiria"));

	printf("list content:\n");
	ft_lstiter(lst, &print_content);

	printf("\nList content in uppercase:\n");
	ft_lstiter(lst, &uppercase_content);

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	return (0);
}

void	ft_lstlast_tester()
{
	t_list *lst;
	t_list *lst1;
	t_list *lst2;
	t_list *lst3;

	lst1 = ft_lstnew("Marvel");
	lst2 = ft_lstnew("DC");
	lst3 = ft_lstnew("Sony");

	if (!lst1 || !lst2 || !lst3)
	{
		free(lst1);
		free(lst2);
		free(lst3);
		return (-1);
	}

	lst3->next = NULL;
	lst2->next = lst3;
	lst1->next = lst2;
	lst = lst1;

	t_list *last_node = ft_lstlast(lst);
	if(last_node)
		printf("%s\n", (char*)last_node->content);
	else
		printf("The list is empty");

	free(lst1);
	free(lst2);
	free(lst3);
	return (0);
}
static void	*dup_str(void *content)
{
	char *str = (char *)content;

	char *duplicate = ft_strdup(str);
	int i = 0;

	while (duplicate[i] != '\0')
	{
		duplicate[i] = ft_toupper(duplicate[i]);
		i++;
	}
	return (duplicate);
}
static void print_str (void *content)
{
	char *str = (char *)content;
	printf("%s\n", str);
}

void	ft_lstmap_tester()
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew("Marventis");
	node2 = ft_lstnew("Tiamant");

	node1->next = node2;

	t_list *new_list = ft_lstmap(node1, dup_str, free);

	printf("New list item:\n");
	ft_lstiter(new_list, print_str);

	ft_lstclear(&new_list, free);

	return(0);
}

void	ft_lstnew_tester()
{
	t_list	*list;
	void	*content;

	content = "Cat";
	list = ft_lstnew(content);
	printf("%s\n", (char *)list->content);
	return (0);
}

void	ft_lstsize_tester()
{
	t_list	*lst = NULL;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*lst4;

	lst1 = ft_lstnew("Marventis");
	lst2 = ft_lstnew("Zefiria");
	lst3 = ft_lstnew("Ignisaria");
	lst4 = ft_lstnew("Tiamant");

	if(!lst1 || ! lst2 || !lst3 || !lst4 )
	{
		free(lst1);
        free(lst2);
        free(lst3);
        free(lst4);
        return (-1);
	}

	lst4->next = NULL;
	lst3->next = lst4;
	lst2->next = lst3;
	lst1->next = lst2;
	lst = lst1;
	printf("%d\n", ft_lstsize(lst));

	free(lst1);
    free(lst2);
    free(lst3);
    free(lst4);

	return (0);
}

void	ft_memchr_tester()
{
	char str[] = "Hello, World!";
    int searchChar = 'W';
	size_t num = 50;
    void *result = ft_memchr(str, searchChar, num);
    if (result != NULL) 
	{
        printf("The character '%c' was found at position %ld.\n",
		 searchChar, (size_t)(result - (void *)str));
    } 
	else 
	{
        printf("the character '%c' wasn't found.\n", searchChar);
    }
    return (0);
} 

void	ft_memcmp_tester()
{
    char str1[] = "Hello Marventis";
    char str2[] = "Hello Marventi";
    size_t size = sizeof(str1);

    int result = ft_memcmp(str1, str2, size);

    if (result == 0) 
        printf("The strings are equal.\n");
	else if (result < 0) 
        printf("The first string is smaller than the second.\n");
	else 
        printf("The first string is greater than the second.\n");
    return (0);
}

void	ft_memcpy_tester()
{
		char src[50] = "The batipunteros rules";
		char dest[50] = "The marventinianos rules";

		printf("Before memcpy  = %s\n", dest);
		ft_memcpy(dest, src, 5);
		printf("Afters memcpy = %s\n", dest);
		return (0);
} 

void	ft_memmove_tester()
{
	char src[50] = "The batipunteros rules";
	char dest[50] = "The marventinianos rules";

	printf("Before memmove  = %s\n", dest);
	ft_memmove(dest, src, 0);
	printf("After memmove = %s\n", dest);
	return (0);
}

void	ft_memset_tester()
{
	char string[] = "The batipunteros rules";
	ft_memset(string, 'a', 10);
	printf("%s\n", string);
	return (0);
}

void	ft_putchar_fd_tester()
{
	char	c;
	int		fd;

	fd = 1;
	c = 'A';
	ft_putchar_fd(c,fd);
	return (0);
}

void	ft_putendl_fd_tester()
{
	char *str = "Batman";
	ft_putendl_fd(str, 1);
	printf("Result: %s\n", ft_putendl_fd);
	return (0);
}

void	ft_putnbr_fd_tester()
{
	ft_putnbr_fd(12345, 1);
	return (0);
}

void	ft_putstr_fd_tester()
{
	char str[] = "I want to sleep.\n";
	int	fd = 1;

	ft_putstr_fd(str, fd);
	return (0);
}

void	ft_split_tester()
{
	char const *str = NULL;
	char c = ' ';

	char **token = ft_split(str, c);

	if (token == NULL)
	{
		printf("Error when splitting string.\n");
		return (1);
	}

	int i = 0;
	while (token[i] != NULL)
	{
		printf("Token %d: %s\n", i + 1, token[i]);
		free(token[i]);
		i++;
	}
	free(token);

	return (0);
}

void	ft_strchr_tester()
{
	char test[] = "Batman has many gadgets that starts with bat";
	char * ptr;
	int    character = 'p';
	ptr = ft_strchr( test, character);
	printf( "The first appearence os the letter %c in '%s' is from '%s'\n",
            character, test, ptr );
}


void	ft_strdup_tester()
{
	const char *str_source = NULL;
	char *str_dup = ft_strdup(str_source);
	if (str_dup != NULL)
	{
		printf ("original string: %s\n", str_source);
		printf ("duplicate string: %s\n", str_dup);
		free(str_dup);
	}
	else
	{
		printf("Error duplicating string. \n");
	}
	return (0);
}

void	print_all(unsigned int index, char *character)
{
	printf ("index: %u, Character: %c\n", index, *character);
}

void	ft_striteri()
{
	char str[] = "I want to sleep, please";

	printf("Original string: %s\n", str);

	ft_striteri(str,&print_all);
	return (0);
}

void	ft_strjoin_tester()
{
	char *s1 = "Hello, ";
	char*s2 = "World!";
	char *result;

	result = ft_strjoin(s1, s2);
	if (result == NULL)
	{
		printf("Error: couldn't unify the strings. \n");
		return (1);
	}
	printf("Concatenation result %s\n", result);

	free(result);

	return (0);
}

void	ft_strlcat_tester()
{
    char source[] = "Batman is the dark knight";
    char final_dest []= "";

	printf("Original string: %s\n", source);
    printf("Before ft_strlcat: %s \n", final_dest);
	ft_strlcat(final_dest, source, 15);
	printf("After ft_strlcat = %s\n", final_dest);
	return (0);
}

void	ft_strlcpy_tester()
{
	char *src = NULL;
	char dest[50] = "Marventis on the top";

	printf("Before ft_strlcpy  = %s\n", dest);
	ft_strlcpy(dest, src, 15);
	printf("After del ft_strlcpy = %s\n", dest);
	return (0);
}

void	ft_strlen_tester()
{
   char a[] = "Hello Batipunteros";
   printf ("%d \n", ft_strlen(a));
   return(0);
}

char	c_toupper(unsigned int index, char c)
{
	if (index % 2 != 0)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
	}
	return (c);
}

void	ft_strmapi_tester()
{
	char str[] = "hello world";
	char *str_new = ft_strmapi(str, &c_toupper);

	printf("Original string: %s\n", str);
	printf("New string: %s\n", str_new);

	free (str_new);
	return (0);
}

void print_result( int res, char * p_string1, char * p_string2 )
{
  if ( res == 0 )
    printf( "\"%s\" is identical to \"%s\"\n", p_string1, p_string2);
  else if ( res < 0 )
    printf( "\"%s\" is less than \"%s\"\n", p_string1, p_string2 );
  else
    printf( "\"%s\" is greater than \"%s\"\n", p_string1, p_string2 );
}

void	ft_strncmp_tester()
{
  int  result;
  int  index = 3;

  char *string1 = NULL;
  char string2[] = "abicfg";

  void print_result( int, char *, char * );

  result = ft_strncmp( string1, string2, index);

  printf( "Comparison of each character\n" );
  printf( "  strncmp: " );
  print_result( result, string1, string2 );
  result = strncmp( string1, string2, index);
  printf( "\nComparison of only the first %i characters\n", index );
  printf( "  strncmp: " );
  print_result( result, string1, string2 );
}

void	ft_strnstr_tester()
{
	char str[] = "Hello world";
	char sb_str[] = "world";
	size_t len = 20;

	char *result = ft_strnstr(str, sb_str, len);

	if ((str == NULL) || (sb_str == NULL))
		printf("Error\n");
	else
		printf("first ocurrence in %s is at position %ld\n", str, result - str);
	return (0);
}

void	ft_strrchr_tester()
{
    char *test = NULL;
    char *ptr;
    int    character = 'g';
    ptr = ft_strrchr(test, character);
    printf ("The last appearance of the letter %c en '%s' is in %s\n",
	 character, test, ptr);
} 

void	ft_strtrim_tester()
{
	char const *s1 = "    I'm tired, i want to sleep  ";
	char const *set = " ";
	char *trimmed_str = ft_strtrim(s1, set);

	if (trimmed_str)
	{
		printf("Original string: '%s'\n", s1);
		printf("String after ft_strtrim: '%s'\n", trimmed_str);

		free(trimmed_str);
	}
	else
	{
		printf("error: the ft_ststrim fuction has return NULL\n");
	}
}

void	ft_substr_tester()
{
	char str[]= "hello";
	unsigned int start = 4294967295;
	size_t len = 0;

	char *sub = ft_substr(str, start, len);
	if (sub)
	{
		printf ("Substring: %s\n", sub);
		free(sub);
	}
	else
	{
		printf("Error getting subtring.\n");
	}
	return (0);
} 

void	ft_tolower_tester()
{
    int character = ft_tolower(65);

    printf ("Conversion: %d\n", character);
    return (0);
}

void ft_toupper_tester()
{
	int character = ft_toupper(76);

	printf("Ft_toupper: %d\n", character);
	return (0);
}  