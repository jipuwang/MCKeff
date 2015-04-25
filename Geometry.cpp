//
//  Geometry.cpp
//  544_Project
//
//  Created by Junjie Guo on 4/20/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#include "Geometry.h"


double dis_x_plane(double x, double u, double x0){
    return (x0-x)/u;
}

double dis_y_plane(double y, double v, double y0){
    return (y0-y)/v;
}

double dis_z_plane(double z, double w, double z0){
    return (z0-z)/w;
}

double dis_z_cylinder(double x, double y, double u, double v, double x0, double y0, double R){
    double x1, y1, a, k, c, d;
    x1 = x-x0;
    y1 = y-y0;
    a = u*u+v*v;
    k = x1*u+y1*v;
    c = x1*x1+y1*y1-R*R;
    if (a == 0 || k*k-a*c < 0) {
        d = 100;       //No intersections with the cylinder
    } else {
        if (c < 0) {
            d = (-k+sqrt(k*k-a*c))/a;
        } else {
            if ((-k-sqrt(k*k-a*c)) > 0) {
                d = (-k-sqrt(k*k-a*c))/a;
            }
            else {
                d = 100;       //No intersections with the cylinder
            }
        }
    }
    return d;
}

double dis_min(double x, double y, double z, double u, double v, double w, double x0, double y0, double z0, double R){
    double d[7], m = 100;
    d[0] = dis_x_plane(x, u, x0);
    d[1] = dis_x_plane(x, u, -x0);
    d[2] = dis_y_plane(y, v, y0);
    d[3] = dis_y_plane(y, v, -y0);
    d[4] = dis_z_plane(z, w, z0);
    d[5] = dis_z_plane(z, w, -z0);
    d[6] = dis_z_cylinder(x, y, u, v, 0, 0, R);
    for (int i = 0; i < 7; i++) {
        if (d[i] > 0) {
            if (d[i] < m  ) {
                m = d[i];
            }
        }
    }
    return m;
}
