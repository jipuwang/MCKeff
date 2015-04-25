//
//  Xsection.h
//  544_Project
//
//  Created by Junjie Guo on 4/19/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#ifndef ___44_Project__Xsection__
#define ___44_Project__Xsection__

#include<stdio.h>
#include<cmath>

double Sigma(double c1, double c2, double c3, double E);      //Calculate the cross section
double Sigma_res(double c1, double c2, double c3, double E);        //Calculate the resonances cross section for U-238
double sigmaH(int i, double E);        //Calculate the microscopic cross section. i=1-Scatter or 2-Capture or 3-total
double sigmaO(int i, double E);       //Calculate the microscopic cross section. i=1-Scatter or 2-Capture or 3-total
double sigmaU235(int i, double E);        //Calculate the microscopic cross section. i=1-Scatter or 2-Capture or 3-Fission or 3-total
double sigmaU238(int i, double E);        //Calculate the microscopic cross section. i=1-Scatter or 2-Capture or 3-total
double Sigma_F(int i, double E);        //Calculate the Macroscopic cross section in Fuel. i=0-H, 1-O, 2-U235, 3-U238, 4-total
double Sigma_M(int i, double E);        //Calculate the Macroscopic cross section in Moderator. i=0-H, 1-O, 2-U235, 3-U238, 4-total

#endif /* defined(___44_Project__Xsection__) */
