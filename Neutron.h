//
//  Neutron.h
//  544_Project
//
//  Created by Junjie Guo on 4/19/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#ifndef ___44_Project__Neutron__
#define ___44_Project__Neutron__

#include <stdio.h>
#include "Foundation.h"

#define pi 3.14159365359

const double A[4] = {1.00794, 15.9994, 235.0439299, 238.05078826};
const double m_n = 1.00866491600;
const double k_B = 8.6173324E-5;
const double T = 293.0;

class Neutron{      //Neutron class
public:
    //Neutron();
    Neutron(double newx,double newy,double newz,double newE,double newOmegax,double newOmegay,double newOmegaz){
        x = newx; y = newy; z = newz;
        E = newE;
        Omegax = newOmegax; Omegay = newOmegay; Omegaz = newOmegaz;
        weight = 1;
        Region = 1;
    };
    double getX(){return x;};
    double getY(){return y;};
    double getZ(){return z;};
    double getE(){return E;};
    double getOmegax(){return Omegax;};
    double getOmegay(){return Omegay;};
    double getOmegaz(){return Omegaz;};
    void change_R(){ Region = Region*-1;}
    int getR(){return Region;};
    void capture();
    void scattering(int i);     //i=0-H, 1-O, 2-U235, 3-U238
    void fission();
    
    
private:
    double x,y,z;       //Position
    double E;       //Energy
    double Omegax,Omegay,Omegaz;        //Direction
    int Region;     //Region 1-fuel -1-moderator
    double weight;
};


#endif /* defined(___44_Project__Neutron__) */
