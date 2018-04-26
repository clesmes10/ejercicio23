#include <iostream>
#include <cmath>
using namespace std;

void in(double *u, double xmin, double deltax, int n);
void evol(double *u, double *uv, int n, double deltax, double deltat, double C);
void primerpaso(double *u, double *uv, double *um, int n, double deltax, double deltat, double C);
void im(double *u, double xmin, double deltax, int n, double t);
void cop(double *u, double *uv, double *um, int n);

void in(double *u, double xmin, double deltax, int n){
  double x;
  int i;
  for(i=0; i<n; ++i){
    x = xmin + i*deltax;
    u[i] = sin(2*3.14*x);
  }
}
void im(double *u, double xmin, double deltax, int n, double t){
  double x;
  int i;
  for(i=0;i<n;i++){
    x = xmin +  i * deltax;
    cout << t << " " << x << " " << u[i] << endl;
  }
}

void primerpaso(double *u, double *uv, int n, double deltax, double deltat, double C){
  int i;
  double ka;
  ka = (C*C)*((deltat*deltat)/(deltax*deltax));
  for(i=1; i<n-1; ++i){
    u[i] =0.5*ka*(uv[i+1]-2*uv[i]+uv[i-1])+2*uv[i];
  }
}
void evol(double *u, double *uv, double *um, int n, double deltax, double deltat, double C){
  int i;
  double ka;
  ka = (C*C)*((deltat*deltat)/(deltax*deltax));
  for(i=1; i < n-1; ++i){
    um[i] = ka*(uv[i+1]-2*uv[i]+uv[i-1])+2*uv[i]-u[i];
  }
}
  
void cop(double *u, double *uv, double *um, int n){
  int i;
  for(i=0;i<n;i++){
    uv[i] = u[i];
    u[i] = um[i];
    
  }
}

int main(){
  double C = 0.1;
  double T = 0.5;
  double t = 0.0;
  double x = 3.0;
  double deltax = 0.01;
  double deltat = 0.00001;
  double *u;
  double *uv;
  double *um;
  double xmin = 0.0;
  double xmax = 2.0;
  int numerox = (xmax-xmin)/(deltax+1);
  um = new double[numerox];
  uv = new double[numerox];
  u = new double[numerox];
  in(uv, xmin, deltax, numerox);
  im(uv, xmin, deltax, numerox, t);
  while(T>t){
    primerpaso(u, uv, numerox, deltax, deltat, C);
    evol(u, uv, um, numerox, deltax, deltat, C); 
    cop(u, uv, um, numerox);
    t += deltat;
  }
  im(uv, xmin, deltax, numerox, t);

  return 0;
}
