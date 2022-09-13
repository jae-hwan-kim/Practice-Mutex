#include "philo.h"

int check_ac(int ac)
{
    if (1 <= ac && 4 >= ac)
        write(STDERR_FILENO, "Error : No Enough Arguments\n", 28);
    else if (7 <= ac)
        write(STDERR_FILENO, "Error : Many Arguments\n", 23);
    else
        return (1);
    return (0);
}

int check_av(char **av)
{
    int index;
    int check;

    if (0 == av[1])
    {
        write(STDERR_FILENO, "Error : Need Philosophers\n", 26);
        return (0);
    }
    index = 1;
    while (0 != av[index])
    {
        check = 0;
        while (0 != av[index][check])
        {
            if ('-' == av[index][check])
            {
                write(STDERR_FILENO, "Error : Not Support Negative\n", 29);
                return (0);
            }
            if (('0' > av[index][check] || '9' < av[index][check]))
            {
                if ('+' != av[index][check])
                {
                    write(STDERR_FILENO, "Error : Use Number\n", 19);
                    return (0);
                }
            }
            check++;
        }
        index++;
    }
    return (1);
}

int check_param(int ac, char **av)
{
    if (check_ac(ac))
        if (check_av(av))
            return (1);
    return (0);
}
