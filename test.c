
#include "get_next_line.h"

char *check_static(char *sta)
{
    int i;
    i = 0;
    int j;
    j = 0;
    while (sta[i] != '\0')
    {
        if (sta[i] == '\n')
        {
            
            return (ft_substr(sta, 0, i));
        }
        else
            return (sta);
        i++;
    }
    
}

char *get_next_line(int fd)
{
    static char *sta;
    char *rst ;
    char *buffer;
    int len;
    int i;
    while (sta[i]=='\n')
        i++;
    
}
int main()
{
    char *toto;
    char *tot;
    toto = "eeeeeehoooooooo";
    tot = "eeeeeeh";
    printf("%s",(toto - tot));
    // if (!ft_strchr(toto,'h'))
    // {
    //     puts("yessssss");
    // }
    return 1;
    
}