#include <math.h>

struct point
{
double x, y;
};
typedef struct point Point;



struct triangle
{
Point a, b, c;
};
typedef struct triangle Triangle;




void print_point(struct point a)
{
    printf("(%.2f, %.2f)", a.x, a.y);
}



void print_triangle(Triangle trian)
{
    printf("{(%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)}", trian.a.x, trian.a.y, trian.b.x, trian.b.y, trian.c.x,trian.c.y);
}



float distance(Point a, Point b)
{
    return sqrt(((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
//    printf("%.2f", dist);
}



float get_triangle_perimeter(const Triangle* pb)
{
    return (distance(pb->a, pb->b)+distance(pb->b, pb->c)+distance(pb->c, pb->a));
//    printf("%.2f", per);
}



float get_triangle_area(const Triangle* pb)
{
    float p = get_triangle_perimeter(pb)/2;
    return sqrt(p*(p-distance(pb->a, pb->b))*(p-distance(pb->b, pb->c)*(p-distance(pb->c, pb->a))));
}


Triangle moved_triangle(const Triangle* pb, Point r)
{
//    return {(pb->a.x + r.x,pb->a.x + r.y), (pb->b.x + r.x,pb->b.x + r.y), (pb->c.x + r.x,pb->c.x + r.y)};
    Triangle tr;
    tr.a.x = pb->a.x+r.x;
    tr.b.x = pb->b.x+r.x ;
    tr.c.x = pb->c.x+r.x ;
    tr.a.y = pb->a.y+r.y ;
    tr.b.y = pb->b.y+r.y ;
    tr.c.y = pb->c.y+r.y ;
    return tr;
}

void move_triangle(Triangle* pb, Point r)
{
    pb->a.x = pb->a.x+r.x;
    pb->b.x = pb->b.x+r.x ;
    pb->c.x = pb->c.x+r.x ;
    pb->a.y = pb->a.y+r.y ;
    pb->b.y = pb->b.y+r.y ;
    pb->c.y = pb->c.y+r.y ;
}



int main()
{


    struct point a = {2.1, 4.3};
    print_point(a);


    struct point b = {0.5, 2};
    struct point c = {0, 1.5};
    Triangle trian = {a, b, c};
    print_triangle(trian);
    printf("%.2f", distance(a,b));
    printf("\n%.2f", get_triangle_perimeter(&trian));
    printf("\n%.2f", get_triangle_area(&trian));
//    print_triangle(moved_triangle(&trian, {1.0,1.0}));
    Point r = {1.0,1.0};
    print_triangle(moved_triangle(&trian, r));
    move_triangle(&trian, r);
    print_triangle(trian);

}
