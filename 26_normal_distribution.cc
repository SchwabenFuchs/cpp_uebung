# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;


class normal_generator
{
public:
    double z_1, z_2;
    bool rand_exists;

    normal_generator(){
        rand_exists = false;
    }

    double get(){
        if (rand_exists == true){
            rand_exists = false;
            return z_2;
        }
        else{
            double s, v_1, v_2;
            do{
            // S1
            v_1 = 2.0 * rand()/(double)RAND_MAX - 1;
            v_2 = 2.0 * rand()/(double)RAND_MAX - 1; 

            // S2
            s = pow(v_1, 2) + pow(v_2, 2);
            }
            // S3
            while(s>=1 or s==0);

            // S4
            z_1 = v_1 * sqrt(-2 * log(s)/s); 
            z_2 = v_2 * sqrt(-2 * log(s)/s);
            rand_exists = true;
            return z_1;
        }
    }
};

double mean(double rand_list[], int N){
    double m = 0;
    for (int i=0; i<N; i++){
        m += rand_list[i];
    }
    m = 1/N * m;
    return m;
}
    
double standart_deviation(double rand_list[], int N){
    double m = mean(rand_list, N);
    double sigma = 0;
    for (int i=0; i<N; i++){
        sigma += pow((rand_list[i] - m), 2);
    }
    sigma = sqrt(sigma/N);
    return sigma;
}

int main()
{
    normal_generator n;
    
    int N = 1e5;
    double rand_list[N];
    for (int i=0; i<N; i++){
        rand_list[i] = n.get();
    }

    cout << "mean: " << mean(rand_list, N) << "\n";
    cout << "standart deviation: " << standart_deviation(rand_list, N) << "\n\n\n";

    // How many values lie inside sigma1, sigma2 and sigma3 range?
    normal_generator x;
    double x_list[N];
    for (int i=0; i<N; i++){
        x_list[i] = x.get();
    }
    double sigma_x = standart_deviation(x_list, N);
    int amount_sigma1, amount_sigma2, amount_sigma3;
    for (int i=0; i<N; i++){
        if (abs(x_list[i]) < sigma_x){
            amount_sigma1 ++;
            amount_sigma2 ++;
            amount_sigma3 ++;
        }
        else if (abs(x_list[i]) < 2*sigma_x)
        {
            amount_sigma2 ++;
            amount_sigma3 ++;
        }
        else if (abs(x_list[i]) < 3*sigma_x){
            amount_sigma3 ++;
        }   
    }

    double p_sigma1 = amount_sigma1/(double)N;
    double p_sigma2 = amount_sigma2/(double)N;
    double p_sigma3 = amount_sigma3/(double)N;
    
    cout << "Percentage in 1-sigma range: " << p_sigma1 << endl;
    cout << "Percentage in 2-sigma range: " << p_sigma2 << endl;
    cout << "Percentage in 3-sigma range: " << p_sigma3 << endl;

    cout << "\n\n";
    return 0;
}