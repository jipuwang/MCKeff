//
//  main.cpp
//  544_Project
//
//  Created by Junjie Guo on 4/14/15.
//  Copyright (c) 2015 Junjie Guo. All rights reserved.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

#include "Neutron.h"
#include "Foundation.h"
#include "Xsection.h"
#include "Geometry.h"


using namespace std;

int Col_iso(Neutron n);
int Col_rea(Neutron n, int i);      //i-isotope



int main(int argc, const char * argv[]) {
    Initial();
    vector <Neutron> n;
    double x0, y0;
    double pitch = 1;
    x0 = pitch/2;
    y0 = pitch/2;
    
    
    
    
    
    return 0;
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
        case 2:{
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
    switch (i) {
        case 0:{
            
            break;
        }
        case 1:{
            
            break;
        }
        case 2:{
        
            break;
        }
        case 3:{
            
            break;
        }
        default:
            break;
    }
    
    
    return
}