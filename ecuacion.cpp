#include <iostream>
#include <fstream>
using namespace std;


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename);

float dzdt(float t, float y, float z, float omega);
float dydt(float t, float y, float z, float omega);

int main(){
  float omega=1.0;
  solve_equation_euler(0.0, 10000.0, omega/2, omega, "euler.dat");
  solve_equation_rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
  solve_equation_leapfrog(0.0, 10000.0, omega/2, omega, "leapfrog.dat");
  return 0;
}


float dydt(float t, float y, float z, float omega){
    return z + (omega*omega) * y * t;
}

float dzdt(float t, float y, float z, float omega){
     return y + z * t;
}


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float z=0;
  ofstream outfile;
  outfile.open(filename);
  
//crear variable temporal que guarde z, y viejito 

  while(t<t_end){   
    float z0=0;
    float y0=0;
      
    outfile << t << " " << y << endl;
    z= y0 - delta_t *omega * z0;
    y = y0 - delta_t * omega  * z;
    t = t + delta_t;
    y0=y;
    z0=z;
  }
  outfile.close();
}


void solve_equation_rk4{
  float y=1.0;
  float z=0;
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){   
    float z0=0;
    float y0=0;
      
    outfile << t << " " << y << endl;
    z= y0 - delta_t *omega * z0;
    y = y0 - delta_t * omega  * z;
    t = t + delta_t;
  }
  outfile.close();
}
