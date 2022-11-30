#include"my_graph.h"
struct tag_simpleshape
{
	simpleshapetype_t		simpleshapetype;
	simpleshapebody_t		simpleshapebody;
};
union tag_simpleshapebody
{
	point_t		point;
	line_t		line;
	...
};

typedef glst_t  shapegroup_t;

struct tag_supershape
{
	supershapetype_t	supershapetype;
	supershapebody_t	supershapebody;
};
union tag_supershapebody
{
	simpleshape_t	simple;
	shapegroup_t	group;
};

struct tag_graph
{
	gstr_t		name;
	coordinate
	...
	=> graphhead_t	head;
	glst_t		shapelst;
};