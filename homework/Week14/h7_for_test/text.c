#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
 
#define MAXN 100  
#define MAX_SEGMENTS 300  
#define MAX_X_EVENTS 200000  
#define EPS 1e-9  
  
typedef struct {  
    double x, y;  
} Point;  
  
typedef struct {  
    Point p1, p2;  
} Segment;  
  
Point triangles[MAXN][3];  
Segment segments[MAX_SEGMENTS];  
int seg_count;  
  
double x_events[MAX_X_EVENTS];  
int x_count;  
  
// 叉积  
double cross(const Point* o, const Point* a, const Point* b) {  
    return (a->x - o->x) * (b->y - o->y) - (a->y - o->y) * (b->x - o->x);  
}  
  
// 判断点是否在线段上（此处未直接使用，但保留结构清晰）  
int on_segment(Point p, Segment s) {  
    if (p.x >= (s.p1.x < s.p2.x ? s.p1.x : s.p2.x) - EPS &&  
        p.x <= (s.p1.x > s.p2.x ? s.p1.x : s.p2.x) + EPS &&  
        p.y >= (s.p1.y < s.p2.y ? s.p1.y : s.p2.y) - EPS &&  
        p.y <= (s.p1.y > s.p2.y ? s.p1.y : s.p2.y) + EPS) {  
        return 1;  
    }  
    return 0;  
}  
  
// 计算两条线段的交点，若存在则返回1，并存入res  
int segment_intersection(Segment s1, Segment s2, Point* res) {  
    double d = (s1.p1.x - s1.p2.x) * (s2.p1.y - s2.p2.y) - (s1.p1.y - s1.p2.y) * (s2.p1.x - s2.p2.x);  
    if (fabs(d) < EPS) {  
        return 0;  
    }  
  
    double t = ((s1.p1.x - s2.p1.x) * (s2.p1.y - s2.p2.y) - (s1.p1.y - s2.p1.y) * (s2.p1.x - s2.p2.x)) / d;  
    double u = -((s1.p1.x - s1.p2.x) * (s1.p1.y - s2.p1.y) - (s1.p1.y - s1.p2.y) * (s1.p1.x - s2.p1.x)) / d;  
  
    if (t >= -EPS && t <= 1.0 + EPS && u >= -EPS && u <= 1.0 + EPS) {  
        res->x = s1.p1.x + t * (s1.p2.x - s1.p1.x);  
        res->y = s1.p1.y + t * (s1.p2.y - s1.p1.y);  
        return 1;  
    }  
    return 0;  
}  
  
void add_x(double x) {  
    if (x_count < MAX_X_EVENTS) {  
        x_events[x_count++] = x;  
    }  
}  
  
int cmp_double(const void* a, const void* b) {  
    double da = *(const double*)a;  
    double db = *(const double*)b;  
    if (da < db) return -1;  
    if (da > db) return 1;  
    return 0;  
}  
  
int triangle_y_interval(int tri_idx, double xm, double* y1, double* y2) {  
    Point pts[3];  
    int i, j;  
    for (i = 0; i < 3; i++) {  
        pts[i] = triangles[tri_idx][i];  
    }  
  
    double ys[10];  
    int yc = 0;  
  
    for (i = 0; i < 3; i++) {  
        Point a = pts[i];  
        Point b = pts[(i+1)%3];  
        double x1 = a.x, y1_ = a.y;  
        double x2 = b.x, y2_ = b.y;  
  
        if (fabs(x1 - x2) < EPS) {  
            if (fabs(x1 - xm) < EPS) {  
                ys[yc++] = y1_;  
                ys[yc++] = y2_;  
            }  
        } else {  
            if ((x1 <= xm + EPS && xm <= x2 + EPS) ||  
                (x2 <= xm + EPS && xm <= x1 + EPS)) {  
                double y = y1_ + (y2_ - y1_) * (xm - x1) / (x2 - x1);  
                ys[yc++] = y;  
            }  
        }  
    }  
  
    if (yc < 2) return 0;  
  
    double unique_ys[10];  
    int uc = 0;  
    for (i = 0; i < yc; i++) {  
        int dup = 0;  
        for (j = 0; j < uc; j++) {  
            if (fabs(ys[i] - unique_ys[j]) < EPS) {  
                dup = 1;  
                break;  
            }  
        }  
        if (!dup) {  
            unique_ys[uc++] = ys[i];  
        }  
    }  
  
    if (uc < 2) return 0;  
  
    double ymin = unique_ys[0], ymax = unique_ys[0];  
    for (i = 1; i < uc; i++) {  
        if (unique_ys[i] < ymin) ymin = unique_ys[i];  
        if (unique_ys[i] > ymax) ymax = unique_ys[i];  
    }  
  
    *y1 = ymin;  
    *y2 = ymax;  
    return 1;  
}  
  
typedef struct {  
    double l, r;  
} Interval;  
  
int cmp_interval(const void* a, const void* b) {  
    Interval* ia = (Interval*)a;  
    Interval* ib = (Interval*)b;  
    if (ia->l < ib->l) return -1;  
    if (ia->l > ib->l) return 1;  
    return 0;  
}  
  
int main() {  
    int n;  
    scanf("%d", &n);  
  
    seg_count = 0;  
    int i, j, t;  
    for (i = 0; i < n; i++) {  
        double x1, y1, x2, y2, x3, y3;  
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);  
        triangles[i][0].x = x1; triangles[i][0].y = y1;  
        triangles[i][1].x = x2; triangles[i][1].y = y2;  
        triangles[i][2].x = x3; triangles[i][2].y = y3;  
  
        segments[seg_count].p1 = triangles[i][0];  
        segments[seg_count].p2 = triangles[i][1];  
        seg_count++;  
        segments[seg_count].p1 = triangles[i][1];  
        segments[seg_count].p2 = triangles[i][2];  
        seg_count++;  
        segments[seg_count].p1 = triangles[i][2];  
        segments[seg_count].p2 = triangles[i][0];  
        seg_count++;  
    }  
  
    x_count = 0;  
    for (i = 0; i < n; i++) {  
        for (j = 0; j < 3; j++) {  
            add_x(triangles[i][j].x);  
        }  
    }  
  
    Point ip;  
    for (i = 0; i < seg_count; i++) {  
        for (j = i + 1; j < seg_count; j++) {  
            if (segment_intersection(segments[i], segments[j], &ip)) {  
                add_x(ip.x);  
            }  
        }  
    }  
  
    qsort(x_events, x_count, sizeof(double), cmp_double);  
    int unique_count = 0;  
    for (i = 0; i < x_count; i++) {  
        if (i == 0 || x_events[i] - x_events[i-1] > EPS) {  
            x_events[unique_count] = x_events[i];  
            unique_count++;  
        }  
    }  
    x_count = unique_count;  
  
    double total_area = 0.0;  
  
    for (i = 0; i < x_count - 1; i++) {  
        double x0 = x_events[i];  
        double x1 = x_events[i+1];  
        if (x1 - x0 < EPS) continue;  
  
        double xm = (x0 + x1) / 2.0;  
  
        Interval intervals[105];  
        int ic = 0;  
  
        for (t = 0; t < n; t++) {  
            double y_low, y_high;  
            if (triangle_y_interval(t, xm, &y_low, &y_high)) {  
                intervals[ic].l = y_low;  
                intervals[ic].r = y_high;  
                ic++;  
            }  
        }  
  
        if (ic == 0) continue;  
  
        qsort(intervals, ic, sizeof(Interval), cmp_interval);  
        double total_y = 0.0;  
        double cur_l = intervals[0].l, cur_r = intervals[0].r;  
        for (j = 1; j < ic; j++) {  
            if (intervals[j].l <= cur_r + EPS) {  
                if (intervals[j].r > cur_r) {  
                    cur_r = intervals[j].r;  
                }  
            } else {  
                total_y += cur_r - cur_l;  
                cur_l = intervals[j].l;  
                cur_r = intervals[j].r;  
            }  
        }  
        total_y += cur_r - cur_l;  
  
        total_area += total_y * (x1 - x0);  
    }  
  
    printf("%.2f\n", total_area);  
    return 0;  
}