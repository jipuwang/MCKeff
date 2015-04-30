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

const double A[4] = {1.00794, 15.9994, 235.0439299, 238.05078826};      //Atom mass for 0-H, 1-O, 2-U235, 3-U238
const double m_n = 1.00866491600;       //Atom mass of neutron
const double k_B = 8.6173324E-11;       //Boltzmann constant in unit (MeV/K)
const double T = 293.0;     //Tempreture in

class Neutron{      //Neutron class
public:
    Neutron();      //Constructor function
    Neutron(double newx,double newy,double newz,double newE,double newOmegax,double newOmegay,double newOmegaz){
        x = newx; y = newy; z = newz;
        E = newE;
        Omegax = newOmegax; Omegay = newOmegay; Omegaz = newOmegaz;
        weight = 1;
        Region = 1;
    };      //Constructor function
    double getX(){return x;};       //Get the value of x
    double getY(){return y;};       //Get the value of y
    double getZ(){return z;};       //Get the value of z
    double getE(){return E;};       //Get the value of E
    double getOmegax(){return Omegax;};     //Get the value of Omegax
    double getOmegay(){return Omegay;};     //Get the value of Omegay
    double getOmegaz(){return Omegaz;};     //Get the value of Omegaz
    int getWeight(){return weight;}     //Get the value of weight
    void set_R(int newR){ Region = newR;}       //Set the region of the neutron
    int getR(){return Region;};     //Get the region of neutron
    void capture();     //Reaction of capture
    void scattering(int i);     //Reaction of scattering, i = isotope 0-H, 1-O, 2-U235, 3-U238
    void fission();     //Reaction of fission
    void setposition(double newx,double newy,double newz){x = newx; y = newy; z = newz;};       //Set the position of neutron
    void setdirection(double newOmegax, double newOmegay, double newOmegaz){        //Set the direction of neutron
        Omegax = newOmegax; Omegay = newOmegay; Omegaz = newOmegaz;
    }
    void leak();        //The neutron leak out of the boundary
    
private:
    double x,y,z;       //Position
    double E;       //Energy
    double Omegax,Omegay,Omegaz;        //Direction
    int Region;     //Region 1-fuel -1-moderator
    int weight;     //Weight of neutron
};


#endif /* defined(___44_Project__Neutron__) */
