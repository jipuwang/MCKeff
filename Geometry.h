//
//  Geometry.h
//  544_Project
//
//  Created by Junjie Guo on 4/20/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#ifndef ___44_Project__Geometry__
#define ___44_Project__Geometry__

#include <stdio.h>
#include <cmath>
#include "Neutron.h"

double dis_x_plane(double x, double u, double x0);        //Calculate the distance to a plane perpendicular to x
double dis_y_plane(double y, double v, double y0);        //Calculate the distance to a plane perpendicular to y
double dis_z_plane(double z, double w, double z0);        //Calculate the distance to a plane perpendicular to z
double dis_z_cylinder(double x, double y, double u, double v, double x0, double y0, double R);        //Calculate the distance to a cylinder parallel to z
double dis_min(Neutron n, double x0, double y0, double z0, double R);      //Calculate the minimum distance to the surface.
void boundary(Neutron &n, double x0, double y0, double z0);     //Check if the neutron is out of the boundary, if it is out of boundary set back
void set_region(Neutron &n, double R);
#endif /* defined(___44_Project__Geometry__) */
