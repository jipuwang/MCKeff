 //
//  Xsection.cpp
//  544_Project
//
//  Created by Junjie Guo on 4/19/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#include "Xsection.h"

double Sigma(double c1, double c2, double c3, double E){
    return (c1+c2/sqrt(E))*exp(c3*sqrt(E));
}

double Sigma_res(double c1, double c2, double c3, double E){
    double y;
    y = 2/c3*(E-c1);
    return c2*sqrt(c1/E)/(1+y*y);
}

double sigmaH(int i, double E){
    double s;
    switch (i) {
        case 1:
            s = Sigma(2e1,3e-3,-1.2,E);
            break;
        case 2:
            s = Sigma(0,8e-5,0,E);
            break;
        case 3:
            s = Sigma(2e1,3e-3,-1.2,E)
            +Sigma(0,8e-5,0,E);
            break;
        default:
            break;
    }
    return s;
}

double sigmaO(int i, double E){
    double s;
    switch (i) {
        case 1:
            s = Sigma(4,1.5e-4,-6e-1,E);
            break;
        case 2:
            s = Sigma(0,0,0,E);
            break;
        case 3:
            s = Sigma(4,1.5e-4,-6e-1,E)
            +Sigma(0,0,0,E);
            break;
        default:
            break;
    }
    return s;
}

double sigmaU235(int i, double E){
    double s;
    switch (i) {
        case 1:
            s = Sigma(1.5e1,1.5e-4,-4e-1,E);
            break;
        case 2:
            s = Sigma(4e-1,2.5e-3,-1,E);
            break;
        case 3:
            s = Sigma(8e-1,6.0e-2,0,E);
            break;
        case 4:
            s = Sigma(1.5e1,1.5e-4,-4e-1,E)
            +Sigma(4e-1,2.5e-3,-1,E)
            +Sigma(8e-1,6.0e-2,0,E);
            break;
        default:
            break;
    }
    return s;
}

double sigmaU238(int i, double E){
    double s;
    switch (i) {
        case 1:
            s = Sigma(9,1e-4,-1.6e-1,E);
            break;
        case 2:
            s = Sigma(1.8,4e-4,-1.5,E)
            +Sigma_res(6.6e-6,7e3,4e-8,E)
            +Sigma_res(2.2e-5,6e3,3e-8,E)
            +Sigma_res(3.8e-5,6.5e3,1e-7,E);
            break;
        case 3:
            s = Sigma(9,1e-4,-1.6e-1,E)
            +Sigma(1.8,4e-4,-1.5,E)
            +Sigma_res(6.6e-6,7e3,4e-8,E)
            +Sigma_res(2.2e-5,6e3,3e-8,E)
            +Sigma_res(3.8e-5,6.5e3,1e-7,E);
            break;
        default:
            break;
    }
    return s;
}

double Sigma_F(int i, double E){
    double S;
    switch (i) {
        case 0:
            S = 0;
            break;
        case 1:
            S = 4.7284e-2*(sigmaO(1,E)+sigmaO(2,E));
            break;
        case 2:
            S = 9.4567e-4*(sigmaU235(1,E)+sigmaU235(2,E)+sigmaU235(3,E));
            break;
        case 3:
            S = 2.2696e-2*(sigmaU238(1,E)+sigmaU238(2,E));
            break;
        case 4:
            S = 0
            +4.7284e-2*(sigmaO(1,E)+sigmaO(2,E))
            +9.4567e-4*(sigmaU235(1,E)+sigmaU235(2,E)+sigmaU235(3,E))
            +2.2696e-2*(sigmaU238(1,E)+sigmaU238(2,E));
            break;
        default:
            break;
    }
    return S;
    
}

double Sigma_M(int i, double E){
    double S;
    switch (i) {
        case 0:
            S = 6.6911e-2*(sigmaH(1,E)+sigmaH(2,E));
            break;
        case 1:
            S = 3.3455e-2*(sigmaO(1,E)+sigmaO(2,E));
            break;
        case 2:
            S = 0;
            break;
        case 3:
            S = 0;
            break;
        case 4:
            S = 6.6911e-2*(sigmaH(1,E)+sigmaH(2,E))
            +3.3455e-2*(sigmaO(1,E)+sigmaO(2,E))
            +0
            +0;
            break;
        default:
            break;
    }
    return S;
    
}


int Col_iso(Neutron n){
    int i;      //Isotope
    switch (n.getR()) {
        case 1:{
            double r, s = 0;
            r = Uni_dis()*Sigma_F(4, n.getE());
            for (int j = 0; j<4; j++) {
                s = s+Sigma_F(j, n.getE());
                if (r < s) {
                    i = j;
                    break;
                }
            }
            break;
        }
        case -1:{
            double r, s = 0;
            r = Uni_dis()*Sigma_M(4, n.getE());
            for (int j = 0; j<4; j++) {
                s = s+Sigma_M(j, n.getE());
                if (r < s) {
                    i = j;
                    break;
                }
            }
            break;
        }
        default:
            break;
    }
    return i;
}

int Col_rea(Neutron n, int i){
    int rea = 0;
    double r, s = 0;
    switch (i) {
        case 0:{
            r = Uni_dis()*sigmaH(3, n.getE());
            for (int j = 1; j<3; j++) {
                s = s + sigmaH(j, n.getE());
                if (r <= s) {
                    rea = j;
                    break;
                }
            }
            break;
        }
        case 1:{
            r = Uni_dis()*sigmaO(3, n.getE());
            for (int j = 1; j<3; j++) {
                s = s + sigmaO(j, n.getE());
                if (r <= s) {
                    rea = j;
                    break;
                }
            }
            break;
        }
        case 2:{
            r = Uni_dis()*sigmaU235(4, n.getE());
            for (int j = 1; j<4; j++) {
                s = s + sigmaU235(j, n.getE());
                if (r <= s) {
                    rea = j;
                    break;
                }
            }
            break;
        }
        case 3:{
            r = Uni_dis()*sigmaU238(3, n.getE());
            for (int j = 1; j<3; j++) {
                s = s + sigmaU238(j, n.getE());
                if (r <= s) {
                    rea = j;
                    break;
                }
            }
            break;
        }
        default:
            break;
    }
    return rea;
}

double dis_collision(Neutron n){
    double d;
    switch (n.getR()) {
        case 1:{
            d = Exp_dis(Sigma_F(4, n.getE()));
            break;
        }
        case -1:{
            d = Exp_dis(Sigma_M(4, n.getE()));
            break;
        }
        default:
            break;
    }
    return d;
}