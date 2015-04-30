//
//  Neutron.cpp
//  544_Project
//
//  Created by Junjie Guo on 4/19/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#include "Neutron.h"


void Neutron::capture(){
    weight = 0;
}

void Neutron::scattering(int i){
    double beta, x, y, omega1, V_tilde, mu_tilde = 1, v, Omegax_T, Omegay_T, Omegaz_T, gamma_T;
    v = sqrt(2*E/m_n);
    
    beta = sqrt(m_n*A[i]/(2*k_B*T));
    y = beta*v;
    omega1 = sqrt(pi)*y/(2+sqrt(pi)*y);
    V_tilde = v;
    while (Uni_dis() > sqrt(v*v+V_tilde*V_tilde-2*v*V_tilde*mu_tilde)/(v+V_tilde)) {
        if (Uni_dis() < omega1) {
            x = G1_dis();
        } else {
            x = G2_dis();
        }
        V_tilde = x/beta;
        mu_tilde = Mu_dis();
    }
    gamma_T = Uni_gamma();
    Omegax_T = mu_tilde*Omegax+(Omegax*Omegaz*cos(gamma_T)-Omegay*sin(gamma_T))*sqrt((1-mu_tilde*mu_tilde)/(1-Omegaz*Omegaz));
    Omegay_T = mu_tilde*Omegay+(Omegay*Omegaz*cos(gamma_T)-Omegax*sin(gamma_T))*sqrt((1-mu_tilde*mu_tilde)/(1-Omegaz*Omegaz));
    Omegaz_T = mu_tilde*Omegaz-cos(gamma_T)*sqrt((1-mu_tilde*mu_tilde)*(1-Omegaz*Omegaz));
    
    
    double u_x, u_y, u_z;       //velocity of center of mass
    u_x = (v*Omegax + A[i]*V_tilde*Omegax_T)/(1+A[i]);
    u_y = (v*Omegay + A[i]*V_tilde*Omegay_T)/(1+A[i]);
    u_z = (v*Omegaz + A[i]*V_tilde*Omegaz_T)/(1+A[i]);
    
    double vc_x, vc_y, vc_z, vc, Omegax_c, Omegay_c, Omegaz_c, mu_c, gamma_c, Omegax_cprime, Omegay_cprime, Omegaz_cprime;
    vc_x = v*Omegax-u_x;
    vc_y = v*Omegay-u_y;
    vc_z = v*Omegaz-u_z;
    
    vc = sqrt(vc_x*vc_x+vc_y*vc_y+vc_z*vc_z);
    Omegax_c = vc_x/vc;
    Omegay_c = vc_y/vc;
    Omegaz_c = vc_z/vc;
    
    mu_c = Mu_dis();
    gamma_c = Uni_gamma();
    
    Omegax_cprime = mu_c*Omegax_c+(Omegax_c*Omegaz_c*cos(gamma_c)-Omegay_c*sin(gamma_c))*sqrt((1-mu_c*mu_c)/(1-Omegaz_c*Omegaz_c));
    Omegay_cprime = mu_c*Omegay_c+(Omegay_c*Omegaz_c*cos(gamma_c)-Omegax_c*sin(gamma_c))*sqrt((1-mu_c*mu_c)/(1-Omegaz_c*Omegaz_c));
    Omegaz_cprime = mu_c*Omegaz_c-cos(gamma_c)*sqrt((1-mu_c*mu_c)*(1-Omegaz_c*Omegaz_c));
    
    double v_labprime_x, v_labprime_y, v_labprime_z, v_labprime;
    v_labprime_x = vc*Omegax_cprime;
    v_labprime_y = vc*Omegay_cprime;
    v_labprime_z = vc*Omegaz_cprime;
    
    v_labprime = sqrt(v_labprime_x*v_labprime_x+v_labprime_y*v_labprime_y+v_labprime_z*v_labprime_z);
    
    E = m_n*v_labprime*v_labprime/2;
    Omegax = v_labprime_x/v_labprime;
    Omegay = v_labprime_y/v_labprime;
    Omegaz = v_labprime_z/v_labprime;
}

void Neutron::fission(){
    weight = 0;
}

Neutron::Neutron(){
    /*double r, theta, newz;
    r = Uni_dis()*1.5;
    theta = Uni_dis()*2*pi;
    newz = Uni_dis()*100-50;
    x = r*cos(theta);
    y = r*sin(theta);
    z = newz;*/
    x = 0;
    y = 0;
    z = 0;
    double mu, gamma;
    mu = Mu_dis();
    gamma = Uni_dis()*2*pi;
    Omegax = sqrt(1-mu*mu)*cos(gamma);
    Omegay = sqrt(1-mu*mu)*sin(gamma);
    Omegaz = mu;
    double newE;
    newE = Watt_dis();
    E = newE;
    weight = 1;
    Region = 1;
}

void Neutron::leak(){
    weight = 0;
}
