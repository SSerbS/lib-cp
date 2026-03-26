const double EPS = 1e-9;
#define FOR(n) for(int i = 0; i < n; i++)
#define double ll
int cmp(double x, double y){
    if(abs(x-y) < EPS) return 0;
    if(x < y) return -1;
    else return 1;
}

const double EPS = 1e-9;
#define FOR(n) for(int i = 0; i < n; i++)
//#define double ll
int cmp(double x, double y){
    if(abs(x-y) < EPS) return 0;
    if(x < y) return -1;
    else return 1;
}

struct Point{
    double x,y;
    Point(double x = 0, double y = 0) : x(x),y(y){}
    Point(const Point& p): x(p.x), y(p.y){}
    bool operator < (const Point &p) const {
        if(cmp(x, p.x) != 0) return x < p.x;
        return cmp(y, p.y) < 0;
    }
    bool operator == (const Point &p) const {return !cmp(x, p.x) && !cmp(y, p.y);}
    bool operator != (const Point &p) const {return !(p == *this);}

    // basic ops
    Point operator + (const Point& p) const {return Point(x+p.x,y+p.y);}
    Point operator - (const Point& p) const {return Point(x-p.x,y-p.y);}
    Point operator * (const double k) const {return Point(x*k,y*k);}
    Point operator / (const double k) const {return Point(x/k,y/k);}
};

double dot (const Point& p,const Point& q) { return p.x*q.x + p.y*q.y; }
double cross (const Point& p,const Point& q) { return p.x*q.y - p.y*q.x; }
double norm(const Point& p) { return hypot(p.x,p.y); }
double dist(const Point& p, const Point& q) { return hypot(p.x-q.x,p.y-q.y); }
double dist2(const Point& p, const Point& q) { return dot(p-q,p-q); }
Point normalize(const Point &p) { return p/hypot(p.x, p.y); }
double angle (const Point& p, Point& q) { return atan2(cross(p, q), dot(p, q)); }
double angle (const Point& p) { return atan2(p.y, p.x); }
