//
// Billboard.hpp for Billboard in /home/vallee_c/MiniEngine/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Wed Jun  4 21:15:56 2014 david vallee
// Last update Sat Jul  5 13:31:32 2014 david vallee
//

#ifndef BILLBOARD_HPP_
# define BILLBOARD_HPP_

# include "../AObject.hpp"
# include "../engine.h"

class	Billboard : public AObject
{
private:
  gdl::Texture *_texture;
  gdl::Geometry *_geometry;

  float		_time;
  float		nb_anime;
  int		anime;

  double	norme(glm::vec2 v);
  float		scalaire(const glm::vec2 &v1, const glm::vec2 &v2);

public:
  Billboard();
  Billboard(float x, float y, float z);
  Billboard(float x, float y, float z, float size, float nb);
  virtual ~Billboard() {}
  virtual void		LoadTexture(gdl::Texture *);
  virtual bool		initialize();
  virtual void		update(gdl::Clock const &, gdl::Input &);
  void			update(gdl::Clock const &clock, gdl::Input &input,
			       glm::vec3 v2, float vAnime);
  virtual void		draw(gdl::AShader &, gdl::Clock const &);
};

#endif /* !BILLBOARD_HPP_ */