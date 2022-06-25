#include<bits/stdc++.h>
#include<complex>
using namespace std;

#define ll long long

int main()
{

	int n=0;
	cout << "Enter the number of busbars:\n";
	cin >> n;

	complex<double> arr[n][n],x,y;

	memset(arr, 0.0, sizeof arr);

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cout << arr[i][j]  << " ";
		}
		cout << "\n";
	}

	double val = 0.0;
	double a,b;
	cout << "If there is an impedance between busbar and ground(0),\nthen\n\n1. Enter the real and imaginary values"
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
	cout << "If there is an impedance between the busbars,\nthen\n\n1. Enter the real and imaginary values"
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
	cout << "Printing the admittance matrix\n";
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cout << arr[i][j]  << " ";
		}
		cout << "\n";
	}

}
