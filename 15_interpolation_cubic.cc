#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    // declare variables
    string fname_in = "a15-spline-input.txt";
    string fname_out = "a15-spline-output.txt";
    const int output_size = 300;
    const int maxsize = 100;
    double x[maxsize], y[maxsize], lambda[maxsize], mu[maxsize], d[maxsize], m[maxsize], alpha[maxsize], beta[maxsize], gamma[maxsize], delta[maxsize], x_new[output_size], y_new[output_size];

    // read file
    ifstream dfile(fname_in);
    int size = 0;
    while ((dfile >> x[size] >> y[size]))
    {
        size++;
    }
    dfile.close();
    cout << "n: " << size << endl;

    // define LGS in matrix form
    for (int i = 1; i < size; i++)
    {
        lambda[i] = (x[i + 1] - x[i]) / (x[i + 1] - x[i - 1]);
        mu[i] = (x[i] - x[i - 1]) / (x[i + 1] - x[i - 1]);
        d[i] = 6.0 / (x[i + 1] - x[i - 1]) * ((y[i + 1] - y[i]) / (x[i + 1] - x[i]) - (y[i] - y[i - 1]) / (x[i] - x[i - 1]));
    }

    // boundary conditions
    lambda[0] = 0;
    mu[size - 1] = 0;
    d[0] = d[size - 1] = 0;

    // solve LGS
    mu[0] = 2;
    for (int i = 1; i < size; i++)
    {
        double f = -mu[i] / mu[i - 1];
        mu[i] = 2 + f * lambda[i - 1];
        d[i] += f * d[i - 1];
    }
    m[size - 1] = d[size - 1] / mu[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        m[i] = (d[i] - lambda[i] * m[i + 1]) / mu[i];
    }

    // get coefficients of cubic polynomials
    for (int i=0; i<size-1; i++){
        alpha[i] = y[i];
        beta[i] = (y[i+1] - y[i]) / (x[i+1] - x[i]) - (2 * m[i] + m[i+1])/ 6 * (x[i+1] - x[i]);
        gamma[i] = m[i] / 2;
        delta[i] = (m[i+1] - m[i]) / (6 * (x[i+1] - x[i]));
    }

    // calculate new x values 
    x_new [0] = x[0];
    double increments = (x[size-1] - x[0]) / output_size;
    for (int i=1; i <= output_size; i++)
    {
        x_new[i] = x_new[i-1] + increments;
    }

    // calculate new y values
    y_new [0] = y[0];
    for (int i=1; i <= output_size; i++){
        // find interval
        int j = size - 1;
        while (j >= 1 and x_new[i] < x[j]){
            j--;
        }
        double x_delta = x_new[i] - x[j];
        y_new[i] = x_delta * ( x_delta * (x_delta * delta[j] + gamma[j]) + beta[j]) + alpha[j];
    }
    
    // save to file
    ofstream efile(fname_out);
    for (int i=1; i <= output_size; i++){
        efile << x_new[i] << "  " << y_new[i] << endl;
    }
    efile.close();

    cout << "\n\n";
    return 0;
}