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

double dis_min(Neutron n, double x0, double y0, double z0, double R){
    double d[7], m = 100;
    d[0] = dis_x_plane(n.getX(), n.getOmegax(), x0);
    d[1] = dis_x_plane(n.getX(), n.getOmegax(), -x0);
    d[2] = dis_y_plane(n.getY(), n.getOmegay(), y0);
    d[3] = dis_y_plane(n.getY(), n.getOmegay(), -y0);
    d[4] = dis_z_plane(n.getZ(), n.getOmegaz(), z0);
    d[5] = dis_z_plane(n.getZ(), n.getOmegaz(), -z0);
    d[6] = dis_z_cylinder(n.getX(), n.getY(), n.getOmegax(), n.getOmegay(), 0, 0, R);
    for (int i = 0; i < 7; i++) {
        if (d[i] > 0) {
            if (d[i] < m  ) {
                m = d[i];
            }
        }
    }
    return m;
}

void boundary(Neutron n, double x0, double y0, double z0){
    
    if (n.getX() >= x0) {
        n.setposition(2*x0-n.getX(), n.getY(), n.getZ());
        n.setdirection(-n.getOmegax(), n.getOmegay(), n.getOmegaz());
    }
    if (n.getX() <= -x0) {
        n.setposition(-2*x0-n.getX(), n.getY(), n.getZ());
        n.setdirection(-n.getOmegax(), n.getOmegay(), n.getOmegaz());
    }
    if (n.getY() >= y0) {
        n.setposition(n.getX(), 2*y0-n.getY(), n.getZ());
        n.setdirection(n.getOmegax(), -n.getOmegay(), n.getOmegaz());
    }
    if (n.getY() <= -y0) {
        n.setposition(n.getX(), -2*y0-n.getY(), n.getZ());
        n.setdirection(n.getOmegax(), -n.getOmegay(), n.getOmegaz());
    }
    if (n.getZ() >= z0) {
        n.setposition(n.getX(), n.getY(), 2*z0-n.getZ());
        n.setdirection(n.getOmegax(), n.getOmegay(), -n.getOmegaz());
    }
    if (n.getZ() <= -z0) {
        n.setposition(n.getX(), n.getY(), -2*z0-n.getZ());
        n.setdirection(n.getOmegax(), n.getOmegay(), -n.getOmegaz());
    }
}

void set_region(Neutron n, double R){
    if (sqrt(n.getX()*n.getX()+n.getY()*n.getY()) < R) {
        n.set_R(1);
    } else {
        n.set_R(-1);
    }
}