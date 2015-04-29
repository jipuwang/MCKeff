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

#define source_number 1
#define iteration 1

const double delta_d = 1E-15;

using namespace std;

int main(int argc, const char * argv[]) {
    Initial();
    vector <Neutron> sourceBank(source_number);
    vector <Neutron> historyBank;
    vector <Neutron> fissionBank;
    double k = 1;
    double x0, y0, z0, R;
    double pitch = 10;
    x0 = pitch/2;
    y0 = pitch/2;
    z0 = 50;
    R = 1.5;
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
                        int isotope;
                        isotope = Col_iso(historyBank[0]);
                        //cout<<isotope<<endl;
                        int reaction;
                        reaction = Col_rea(historyBank[0], isotope);
                        //cout<<reaction<<endl;
                        switch (reaction) {     //1-Scatter or 2-Capture or 3-Fission
                            case 1:{
                                historyBank[0].setposition((historyBank[0].getX()+historyBank[0].getOmegax()*(dis_coll+delta_d)), (historyBank[0].getY()+historyBank[0].getOmegay()*(dis_coll+delta_d)), (historyBank[0].getZ()+historyBank[0].getOmegaz()*(dis_coll+delta_d)));
                                historyBank[0].scattering(isotope);
                                cout<<"Scatter"<<endl;
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
                                Neutron f(historyBank[0].getX(),historyBank[0].getY(),historyBank[0].getZ(),Watt_dis(),historyBank[0].getOmegax(),historyBank[0].getOmegay(),historyBank[0].getOmegaz());
                                for (int p = 0; p < nu; p++) {
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
                        cout<<"Surface"<<endl;
                        //cout<<historyBank[0].getX()<<endl;
                        //cout<<historyBank[0].getY()<<endl;
                        //cout<<"z"<<historyBank[0].getZ()<<endl;
                        boundary(historyBank[0], x0, y0, z0);
                        set_region(historyBank[0], R);
                        //cout<<"4"<<endl;
                    }
                    cout<<historyBank[0].getX()<<endl;
                    cout<<historyBank[0].getY()<<endl;
                }
                if(historyBank[0].getWeight() == 0){
                    historyBank.pop_back();
                }
            }
        }
        //k = fissionBank.size()/sourceBank.size();
        //sourceBank.clear();
        
        //cout<<fissionBank.size()<<endl;
        fissionBank.clear();
        
    }
    return 0;
}

