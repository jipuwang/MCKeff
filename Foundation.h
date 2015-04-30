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
double G1_dis();        //g1(x) = 4/sqrt(pi)*x^2*exp(-x^2)
double G2_dis();        //g2(x) = 2*x^3*exp(-x^2)
double Mu_dis();        //Sample mu from -1 to 1
double Watt_dis();      //Sample Watt distribution
int Nu_dis();       //Sample Nu for # of fission neutron
double Uni_gamma();     //Sample gamma from 0 to 2pi

#endif /* defined(___44_Project__Foundation__) */
