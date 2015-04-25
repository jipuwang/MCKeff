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


double dis_x_plane(double x, double u, double x0);        //Calculate the distance to a plane perpendicular to x
double dis_y_plane(double y, double v, double y0);        //Calculate the distance to a plane perpendicular to y
double dis_z_plane(double z, double w, double z0);        //Calculate the distance to a plane perpendicular to z
double dis_z_cylinder(double x, double y, double u, double v, double x0, double y0, double R);        //Calculate the distance to a cylinder parallel to z
double dis_min(double x, double y, double z, double u, double v, double w, double x0, double y0, double z0, double R);      //Calculate the minimum distance to the surface.

#endif /* defined(___44_Project__Geometry__) */
