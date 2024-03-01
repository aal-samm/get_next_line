// #include "get_next_line.h"

// int main (void)
// {
// 	int fd;
// 	char *next_line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("there is an error oppening the file");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (next_line == NULL)
// 		{
// 			printf("line = NULL\n");
// 			break;
// 		}
// 		printf("line = %s", next_line);
// 		free(next_line);
// 		next_line = NULL;
// 	}
// 	close (fd);
// 	return (0);
// }

// static variable when created is automatically initilized to 0
// when we need to deal with an int for example after the modification we add * and when us & when calling it 
// if we are talking about pointer we it becomes ** and we use &
// // char	*ft_append(char *line, char *main_buffer)
// // {
// // 	char	*appended;

// // 	appended = ft_strjoin_gnl(line, main_buffer);
// // 	free(line);
// // 	line = NULL;
// // 	return (appended);
// // }