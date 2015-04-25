//
//  Foundation.h
//  544_Project
//
//  Created by Junjie Guo on 4/19/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#ifndef ___44_Project__Foundation__
#define ___44_Project__Foundation__

#include <stdio.h>
#include <cmath>
#include <time.h>
#include <iostream>

#define pi 3.14159365359

void Initial();     //Initialize the random generation
double Uni_dis();       //Generate unifrom distribution (0,1)
double Exp_dis(double l);       //Generate exponential distribution with lambda = l
double G1_dis();       //g1(x) = 4/sqrt(pi)*x^2*exp(-x^2)
double G2_dis();       //g2(x) = 2*x^3*exp(-x^2)
double Mu_dis();
double Watt_dis();
int Nu_dis();

#endif /* defined(___44_Project__Foundation__) */
