//
//  Foundation.cpp
//  544_Project
//
//  Created by Junjie Guo on 4/19/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#include "Foundation.h"


void Initial(){
    srand((unsigned)time(NULL));
}

double Uni_dis(){
    return (double)rand()/RAND_MAX;
}

double Exp_dis(double l){
    return -1/l*log(Uni_dis());
}

double G1_dis(){
    return sqrt(-log(Uni_dis())-log(Uni_dis())*pow(cos(pi/2*Uni_dis()),2));
}

double G2_dis(){
    return sqrt(-log(Uni_dis()*Uni_dis()));
}

double Mu_dis(){
    return 2*Uni_dis()-1;
}

double Watt_dis(){
    double a = 0.988, b = 2.249;
    double W;
    W = a*G1_dis();
    return W+a*a*b/4+(2*Uni_dis()-1)*sqrt(a*a*b*W);
}

int Nu_dis(){
    return (int)(2.45+Uni_dis());
}