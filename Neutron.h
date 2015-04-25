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


class Neutron{      //Neutron class
public:
    //Neutron();
    Neutron(double newx,double newy,double newz,double newE,double newOmegax,double newOmegay,double newOmegaz){
        x = newx; y = newy; z = newz;
        E = newE;
        Omegax = newOmegax; Omegay = newOmegay; Omegaz = newOmegaz;
        state = 1;
    };
    double getX(){return x;};
    double getY(){return y;};
    double getZ(){return z;};
    double getE(){return E;};
    double getOmegax(){return Omegax;};
    double getOmegay(){return Omegay;};
    double getOmegaz(){return Omegaz;};
    int getR(){return Region;};
    void capture();
    void scattering();
    void fission();
    bool state;

    
private:
    double x,y,z;       //Position
    double E;       //Energy
    double Omegax,Omegay,Omegaz;        //Direction
    int Region;     //Region 1-fuel 2-moderator
};


#endif /* defined(___44_Project__Neutron__) */
