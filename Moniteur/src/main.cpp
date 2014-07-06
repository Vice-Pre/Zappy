//
// main.cpp for main in /home/vallee_c/Zappy/GraphEngine
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:46:58 2014 david vallee
// Last update Sun Jul  6 19:57:01 2014 david vallee
//

#include "../graphEngine/GraphEngine.hpp"
#include "World.hpp"
#include "../network/network.h"
#include "printfColor.h"
#include "option.h"

void	intro()
{
  printf("\n\n --------------- Welcome to Trantor ! ------------\n\n");
  printf("-> Rotate the camera with z,s,q,d \n-> Move with i,j,k,l\n");
  printf("-> Move Pikachu with Up arrow and rotate it with Right and Left arrow\n\n\n");
  printf("-----------------------------------------------------------\n\n\n");
}

int	main(int ac, char ** av)
{
  t_option	option;
  World		world;
  int		loading;
  int		fd;

  clrscr();
  default_value(&option);
  exec_opt(&option, ac, av);
  fd = connect_to_server(option.ip, option.port);
  if (fd == -1)
    {
      printf("Fail to connect to server\n");
      return (0);
    }
  world.setFdServer(fd);
  color(GREEN);
  printf("\n\nConnect to server %s with port : %s\n\n", av[1], av[2]);
  color(WHITE);
  load(world);

  graphEngine	window(world, option.x, option.y, option.fullscreen);
  window.init();
  while (window.getKey())
    window.draw();
  return (0);
}
