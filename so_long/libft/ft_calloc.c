/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneem <raneem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:41:46 by rabusala          #+#    #+#             */
/*   Updated: 2025/01/31 11:18:45 by raneem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size )

{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*int main()
{
    int *array = (int *)ft_calloc(10, sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "Memory allovampion failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);
    return 0;
}*/
