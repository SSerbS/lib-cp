bool isInside(const vector<Point> &hull, Point pt) {
    int n = hull.size();
    Point v0 = pt - hull[0], v1 = hull[1] - hull[0], v2 = hull[n-1] - hull[0];
    if(cross(v0,v1) > 0 || cross(v0,v2) < 0) {
        return false;
    }
    int l = 1, r = n - 1;
    while(l != r) {
        int mid = (l + r + 1) / 2;
        Point v0 = pt - hull[0], v1 = hull[mid] - hull[0];
        if(cross(v0,v1) < 0) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    v0 = hull[(l+1)%n] - hull[l], v1 = pt - hull[l];
    return cross(v0,v1) >= 0;
}
