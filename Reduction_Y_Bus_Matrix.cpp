#include<bits/stdc++.h>
#include<complex>
using namespace std;

#define ll long long

int main()
{

	ll n=0,no_of_load_bus=0;
	cout << "Enter the number of busbars:\n";
	cin >> n;
	cout<<"Enter the number of P-Q buses\n";
	cin>>no_of_load_bus;

	ll reduced_size=n-no_of_load_bus;

	complex<double> arr[n][n],x,y,reduced_matrix[reduced_size][reduced_size];

	memset(arr, 0.0, sizeof arr);
	memset(arr, 0.0, sizeof reduced_matrix);

	cout<<"\nprinting arr matrix after memset"<<endl;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cout << arr[i][j]  << " ";
		}
		cout << "\n";
	}

	cout<<"\nprinting reduced_matrix after memset"<<endl;
	for (ll i = 0; i < reduced_size; i++)
	{
		for (ll j = 0; j < reduced_size; j++)
		{
			cout << reduced_matrix[i][j]  << " ";
		}
		cout << "\n";
	}

	double val = 0.0;
	double a,b;
	cout << "\nIf there is an impedance between busbar and ground(0),\nthen\n\n1. Enter the real and imaginary values"
	" separated by space\n2. Otherwise enter two 0's separated by space\n\n";
	for (ll i = 0; i < n; i++)
	{
		cout << "Enter the impedance value between " << i + 1 << " and " << 0 << ":\n";
		cin >> a>>b;
		arr[i][i] = {a,b};
	}

	//printing
	cout << "Printing the admittance matrix\n";
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cout << arr[i][j]  << " ";
		}
		cout << "\n";
	}

	//taking input for off-diagonal elements
	cout << "\nIf there is an impedance between the busbars,\nthen\n\n1. Enter the real and imaginary values"
	" separated by space\n2. Otherwise enter two 0's separated by space\n\n";
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			cout << "Enter the impedance value between " << i + 1 << " and " << j + 1 << ":\n";
			cin >> a>>b;
			arr[i][j] = {a,b};
			arr[j][i] = {a,b};
		}
	}

	//calculating admittance
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			x = arr[i][j];
			if (x == 0.0)
				continue;


            y = (1.0 / x) ;
			arr[i][j] = y;
		}
	}

	//calculating diagonal value

	for (ll i = 0; i < n; i++)
	{
		x = {0.0,0.0};
		for (ll j = 0; j < n; j++)
		{
			x += arr[i][j];
		}
		arr[i][i] = x;
	}

	//changing the sign
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			if (i != j && arr[i][j] != 0.0)arr[i][j] = -(arr[i][j]);
		}
	}

	//printing
	cout << "\nPrinting the admittance matrix\n";
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cout << arr[i][j]  << " ";
		}
		cout << "\n";
	}


	for(ll i=0;i<reduced_size;i++)
    {
        for(ll j=0;j<reduced_size;j++)
        {
            reduced_matrix[i][j]=(1.0/arr[n-1][n-1])*((arr[n-1][n-1]*arr[i][j])-(arr[i][n-1]*arr[n-1][j]));

        }
    }





	//printing
	cout << "\nPrinting the reduced admittance matrix\n";
	for (ll i = 0; i < reduced_size; i++)
	{
		for (ll j = 0; j < reduced_size; j++)
		{
			cout << reduced_matrix[i][j]  << " ";
		}
		cout << "\n";
	}

}
