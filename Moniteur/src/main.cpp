//
// main.cpp for main in /home/vallee_c/Zappy/GraphEngine
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:46:58 2014 david vallee
// Last update Thu Jul 10 17:33:16 2014 david vallee
//

#include "graphEngine/GraphEngine.hpp"
#include "World/World.hpp"
#include "network/network.h"
#include "Option/option.h"

int		init_world(World *world, t_option *option, int ac, char **av)
{
  int		fd;

  fd = connect_to_server(option->ip, option->port);
  if (fd == -1)
    {
      printf("Fail to connect to server\n");
      return (-1);
    }
  printf("\nConnect to server %s with port : %d and Fd : %d\n\n", option->ip, option->port, fd);
  world->setFdServer(fd);
  send_msg(fd, "GRAPHICS\n");
  printf("<-GRAPHICS\n");
  while (world->load() == 0)
    ;
  return (0);
}

int		main(int ac, char ** av)
{
  t_option	option;
  World		world;

  default_value(&option);
  exec_opt(&option, ac, av);
  if (init_world(&world, &option, ac, av) == -1)
    return (0);
  graphEngine	window(world, option.x, option.y, option.fullscreen);
  window.init();
  int	i;
  int	r = 1;
  while (window.getKey() && r != -2)
    {
      i = 0;
      while (i < MAX_REQUETE_BY_UPDATE && (r = world.update()) > -1)
	  ++i;
      window.draw();
    }
  if (close(world.getFdServer()) != -1)
    std::cout << "Monitor Close safely" << std::endl;
  return (0);
}
