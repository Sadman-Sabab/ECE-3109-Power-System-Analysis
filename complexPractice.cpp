#include<bits/stdc++.h>
#include<complex>

using namespace std;

#define ll long long

int main(){
//    reinterpret_cast<T(&)[2]>(z)[0];
//    reinterpret_cast<T(&)[2]>(z)[1];
//    constexpr complex< double > operator""i( long double arg );

    complex<double> z[3],c;

    c={1,2};
    cout<<(1.0/c)<<endl;

    double a,b;

    for(ll i=0;i<3;i++)
    {
        cout<<"enter two values of imaginary numbers separated with space"<<endl;
        cin>>a>>b;
        z[i]={a,b};
    }

    for(ll i=0;i<3;i++)
    {
        cout<<real(z[i])<<" "<<imag(z[i])<<endl;
//        cout<<z[i]<<endl;
    }


}
