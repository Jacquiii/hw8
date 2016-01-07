#include <iostream>
#include <cmath>


using namespace std;

void calculation(double q1, double q2, double p1, double p2, double dt, const int N);

int main(void){

   const double tEnd = 20*3.14;
   double dt = 0.0005;
   const int N = int(tEnd/dt + 0.5); //Aufrunden
   dt = tEnd/N;

   const double e = 0.6;

   double q1 = 1-e;
   double q2 = 0;
   double p1 = 0;
   double p2 = sqrt((1+e)/(1-e));

   double H;

   calculation(q1,q2,p1,p2,dt,N);

return 0;
}

void calculation(double q1, double q2, double p1, double p2, double dt, const int N){

  double q1neu = 0;
  double q2neu = 0;
  double p1neu = 0;
  double p2neu = 0;

  double t=0;

   for(int i=1;i<N;i++){

      p1neu = p1 - dt*( 1.0 /  pow( (pow(q1,2)+pow(q2,2) ), 3.0/2.0)) *q1;
      p2neu = p2 - dt*( 1.0 /  pow( (pow(q1,2)+pow(q2,2) ), 3.0/2.0)) *q2;

      q1neu = q1 + dt*p1neu;
      q2neu = q2 + dt*p2neu;

      p1 = p1neu;
      p2 = p2neu;
      q1 = q1neu;
      q2 = q2neu;

      double H = 0.5*( pow(p1, 2) + pow(p2, 2) ) - 1.0/( sqrt( pow(q1, 2)+pow(q2, 2) ));
      t+=dt;
      cout << t << "\t" << H << "\t" << p1 << "\t" << p2 << "\t" << q1 << "\t" << q2 <<  endl;

   }
}