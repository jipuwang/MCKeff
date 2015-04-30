//
//  main.cpp
//  544_Project
//
//  Created by Junjie Guo on 4/14/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <time.h>
#include <vector>

#include "Neutron.h"
#include "Foundation.h"
#include "Xsection.h"
#include "Geometry.h"

#define source_number 100000
#define iteration 40

const double delta_d = 1E-15;

using namespace std;

int main(int argc, const char * argv[]) {
    //Initial();
    vector <Neutron> sourceBank(source_number);
    vector <Neutron> historyBank;
    vector <Neutron> fissionBank;
    double k[iteration];
    double average_k[10];
    double x0, y0, z0, R;
    z0 = 50;
    R = 1.5;
    for (int r = 0; r < 20; r++) {
        double pitch = 0;
        pitch = 3.0 + r * 0.1;
        x0 = pitch/2;
        y0 = pitch/2;
        for (int o = 0; o < iteration; o++) {
            for (int q = 0; q < sourceBank.size(); q++) {
                historyBank.push_back(sourceBank[q]);
                while (historyBank.empty() == 0) {
                    while (historyBank[0].getWeight() != 0)
                    {
                        double dis_surface = 0, dis_coll = 0;
                        dis_surface = dis_min(historyBank[0], x0, y0, z0, R);
                        dis_coll = dis_collision(historyBank[0]);
                        //cout<<dis_surface<<endl;
                        //cout<<dis_coll<<endl;
                        if (dis_coll < dis_surface) {
                            historyBank[0].setposition((historyBank[0].getX()+historyBank[0].getOmegax()*(dis_coll+delta_d)), (historyBank[0].getY()+historyBank[0].getOmegay()*(dis_coll+delta_d)), (historyBank[0].getZ()+historyBank[0].getOmegaz()*(dis_coll+delta_d)));
                            int isotope;
                            isotope = Col_iso(historyBank[0]);
                            //cout<<isotope<<endl;
                            int reaction;
                            reaction = Col_rea(historyBank[0], isotope);
                            //cout<<reaction<<endl;
                            switch (reaction) {     //1-Scatter or 2-Capture or 3-Fission
                                case 1:{
                                    historyBank[0].scattering(isotope);
                                    //cout<<"Scatter"<<endl;
                                    //cout<<historyBank[0].getX()<<endl;
                                    //cout<<historyBank[0].getY()<<endl;
                                    //cout<<historyBank[0].getZ()<<endl;
                                    break;
                                }
                                case 2:{
                                    historyBank[0].capture();
                                    break;
                                }
                                case 3:{
                                    historyBank[0].fission();
                                    int nu;
                                    nu = Nu_dis();
                                    for (int p = 0; p < nu; p++) {
                                        double newmu, newgamma;
                                        newmu = Mu_dis();
                                        newgamma = Uni_dis()*2*pi;
                                        Neutron f(historyBank[0].getX(),historyBank[0].getY(),historyBank[0].getZ(),Watt_dis(),sqrt(1-newmu*newmu)*cos(newgamma),sqrt(1-newmu*newmu)*sin(newgamma),newmu);
                                        fissionBank.push_back(f);
                                    }
                                    //cout<<"!"<<endl;
                                    break;
                                }
                                default:
                                    break;
                            }
                        } else {
                            historyBank[0].setposition(historyBank[0].getX()+historyBank[0].getOmegax()*(dis_surface+delta_d), historyBank[0].getY()+historyBank[0].getOmegay()*(dis_surface+delta_d), historyBank[0].getZ()+historyBank[0].getOmegaz()*(dis_surface+delta_d));
                            //cout<<"Surface"<<endl;
                            //cout<<historyBank[0].getX()<<endl;
                            //cout<<historyBank[0].getY()<<endl;
                            //cout<<"z"<<historyBank[0].getZ()<<endl;
                            boundary(historyBank[0], x0, y0, z0);
                            set_region(historyBank[0], R);
                            //cout<<"4"<<endl;
                        }
                        //cout<<historyBank[0].getX()<<endl;
                        //cout<<historyBank[0].getY()<<endl;
                    }
                    if(historyBank[0].getWeight() == 0){
                        historyBank.pop_back();
                    }
                }
            }
            k[o] = (double)(fissionBank.size())/(double)(sourceBank.size());
            sourceBank.clear();
            long fissionBank_size;
            fissionBank_size = fissionBank.size();
            //cout<<k[o]<<endl;
            for (int r = 0; r < source_number; r++) {
                int index;
                index = floor(Uni_dis()*fissionBank_size);
                sourceBank.push_back(fissionBank[index]);
            }
            fissionBank.clear();
        }
        for (int s = 0; s < iteration; s++) {
            average_k[r] = average_k[r]+k[s]/iteration;
        }
        cout<<"pitch = "<<pitch<<endl;
        cout<<"keff = "<<average_k[r]<<endl;
    }
    
    return 0;
}

