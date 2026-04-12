#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class point 
{
 public:
 double x;
 double y;

 point (double xx,double yy):x(xx),y(yy){};
 point (){ x=0;y=0;}
 
};

class triangle 
{
   public:
   point a;
   point b;
   point c;
   point is;

   triangle (point aa,point bb,point cc,point dd):a(aa),b(bb),c(cc),is(dd){};
   bool judge ();
   friend double chacheng(point v1,point v2);
   
};

double chacheng (point v1,point v2)

    {
    return (v1.x*v2.y-v1.y*v2.x);
   }


bool triangle::judge() //用叉乘来判断在有向线段的左右
{
 point vec1 (b.x-a.x,b.y-a.y);
 point vec2 (c.x-b.x,c.y-a.y);
 point vec3 (a.x-c.x,a.y-c.y);

 point vecai (is.x-a.x,is.y-a.y);
 point vecbi (is.x-b.x,is.y-b.y);
 point vecci (is.x-c.x,is.y-c.y);

 if (chacheng(vec1,vecai)==0||chacheng(vec2,vecbi)==0||chacheng(vec3,vecci)==0)
 {
   return 0;
 }
 if (chacheng(vec1,vecai)<0&&chacheng(vec2,vecbi)<0&&chacheng(vec3,vecci)<0)
 return 1;
 if (chacheng(vec1,vecai)>0&&chacheng(vec2,vecbi)>0&&chacheng(vec3,vecci)>0)
 return 1;
 else
 return 0;


}

  

  

int main() {
	double x1, y1, x2, y2, x3, y3;
	double x, y;
	while (cin >> x1 >> y1) {
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		cin >> x >> y;
		point a(x1, y1);
		point b(x2, y2);
		point c(x3, y3);
		point m(x, y);
		triangle t(a, b, c, m);
		if (t.judge()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}