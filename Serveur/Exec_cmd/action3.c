#include "cmd.h"

t_serveur	*cmdfork(t_serveur *s, int fd)
{
  printf("pfk #n\n");
}

t_serveur	*cmdslot(t_serveur *s, int fd)
{
  printf("Slot: ?");
}

t_serveur	*cmddie(t_serveur *s, int fd)
{
  pdi(s, s->ctab[fd].id);
  printf("%d You died!!!\n", fd);
}