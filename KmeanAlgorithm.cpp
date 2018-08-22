#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

/*
 * Xhanti Singatha
 * SNGXHA002 
 */
 
using namespace std;

ofstream output_file;

int sum(vector<int> input){
    int total = 0;
    for (int i = 0; i < input.size(); i++){
        total += input[i];
    }
    return total;
}

vector<double> compute_mean(vector<int> xinput, vector<int> yinput, vector<double> kmean){
               vector<int> xcluster1;
	           vector<int> xcluster2;
	           vector<int> xcluster3;
              
               vector<int> ycluster1;
	           vector<int> ycluster2;
	           vector<int> ycluster3;
              
               vector<double> clusters;
              
               double distance1, distance2, distance3;
               double xcentriod1, xcentriod2, xcentriod3, ycentriod1, ycentriod2, ycentriod3;	
              
               std::string str_cluster1 = "Cluster 1: ";
               std::string str_cluster2 = "Cluster 2: ";
               std::string str_cluster3 = "Cluster 3: ";
              
	           for (int i = 0; i < xinput.size(); i++){
				   // computing the distances
	               distance1 = sqrt(pow(xinput[i]-kmean[0], 2) + pow(yinput[i]-kmean[3], 2));
	               distance2 = sqrt(pow(xinput[i]-kmean[1], 2) + pow(yinput[i]-kmean[4], 2));
	               distance3 = sqrt(pow(xinput[i]-kmean[2], 2) + pow(yinput[i]-kmean[5], 2));
                  
                  std::string str;
                  std:: stringstream str_num;
                  str_num << i+1;
                  str = str_num.str();
                  
                  // comparing the euclidean distances
                  if ((distance1 < distance2) && (distance1 < distance3)){
                     xcluster1.push_back(xinput[i]);
                     ycluster1.push_back(yinput[i]);
                     str_cluster1 += str + " " ;
                  }
       
                  else if ((distance2 < distance1) && (distance2 < distance3)){
                     xcluster2.push_back(xinput[i]);
                     ycluster2.push_back(yinput[i]);
                     str_cluster2 += str + " " ;
                  }
       
                  else if ((distance3 < distance1) && (distance3 < distance2)){
                     xcluster3.push_back(xinput[i]);
                     ycluster3.push_back(yinput[i]);
                     str_cluster3 += str + " " ;
                  }
       
	           }
	
              // mean for the first cluster
              double xsum1 = sum(xcluster1);
              xcentriod1 = xsum1/xcluster1.size();
              
              double ysum1 = sum(ycluster1);
              ycentriod1 = ysum1/ycluster1.size(); 
              
              output_file << str_cluster1 << "\n";
              output_file << "Centriod: " << "(" << xcentriod1 << ", " << ycentriod1 << ")" << "\n"; 
              output_file << "\n";
             
              // mean for the second cluster
              double xsum2 = sum(xcluster2);
              xcentriod2 = xsum2/xcluster2.size();
              
              double ysum2 = sum(ycluster2);
              ycentriod2 = ysum2/ycluster2.size();
              
              output_file << str_cluster2 << "\n";
              output_file << "Centriod: " << "(" << xcentriod2 << ", " << ycentriod2 << ")" << "\n";
              output_file << "\n";
              
              // mean for the third cluster
              double xsum3 = sum(xcluster3);
              xcentriod3 = xsum3/xcluster3.size();
              
              double ysum3 = sum(ycluster3);
              ycentriod3 = ysum3/ycluster3.size();
              
              output_file << str_cluster3 << "\n";
              output_file << "Centriod: " << "(" << xcentriod3 << ", " << ycentriod3 << ")" << "\n";
              output_file << "\n";
              
              clusters.push_back(xcentriod1);
              clusters.push_back(xcentriod2);
              clusters.push_back(xcentriod3);
              
              clusters.push_back(ycentriod1);
              clusters.push_back(ycentriod2);
              clusters.push_back(ycentriod3);
              
              return clusters;
}

int main() {
	
    output_file.open("output.txt");
   
	std::vector<int> x_input = {2,2,8,5,7,6,1,4};
	std::vector<int> y_input = {10,5,4,8,5,4,2,9};
    std::vector<double> k_mean = {2,5,1,10,8,2};

    vector<double> centriods;
    vector<double> new_centriods;
   
    //cout << "Hello There !" << "\n";
   
    double xcurrent_centriod1, xcurrent_centriod2, xcurrent_centriod3;
    double ycurrent_centriod1, ycurrent_centriod2, ycurrent_centriod3;
   
    double xnew_centriod1, xnew_centriod2, xnew_centriod3;
    double ynew_centriod1, ynew_centriod2, ynew_centriod3;
   
    int counter = 0;
    int iteration = 1;
   
    for (;;){
        output_file << "Iteration " << iteration << "\n";
        output_file << "\n";
          
        if (counter == 0){
           centriods = compute_mean(x_input, y_input, k_mean);
           new_centriods = centriods;
           xnew_centriod1 = centriods[0]; 
           xnew_centriod2 = centriods[1];
           xnew_centriod3 = centriods[2];
          
           ynew_centriod1 = centriods[3]; 
           ynew_centriod2 = centriods[4];
           ynew_centriod3 = centriods[5];
          
           xcurrent_centriod1 = xnew_centriod1;
           xcurrent_centriod2 = xnew_centriod2;
           xcurrent_centriod3 = xnew_centriod3;
          
           ycurrent_centriod1 = ynew_centriod1;
           ycurrent_centriod2 = ynew_centriod2;
           ycurrent_centriod3 = ynew_centriod3;
          
           counter++;
        }
       
        else {
           centriods = compute_mean(x_input, y_input, new_centriods);
           new_centriods  = centriods;
           xnew_centriod1 = centriods[0]; 
           xnew_centriod2 = centriods[1];
           xnew_centriod3 = centriods[2];
          
           ynew_centriod1 = centriods[3]; 
           ynew_centriod2 = centriods[4];
           ynew_centriod3 = centriods[5];
          
           if ((xnew_centriod1 == xcurrent_centriod1) && (xnew_centriod2 == xcurrent_centriod2) && (xnew_centriod3 == xcurrent_centriod3)){
               if ((ynew_centriod1 == ycurrent_centriod1) && (ynew_centriod2 == ycurrent_centriod2) && (ynew_centriod3 == ycurrent_centriod3)){
                  break;
               }
           }
          
           xcurrent_centriod1 = xnew_centriod1;
           xcurrent_centriod2 = xnew_centriod2;
           xcurrent_centriod3 = xnew_centriod3;
           
           ycurrent_centriod1 = ynew_centriod1;
           ycurrent_centriod2 = ynew_centriod2;
           ycurrent_centriod3 = ynew_centriod3;
         
        }
       
        iteration++;
    }
    
    output_file << "It needs 4 iterations to converge." << "\n";
    output_file.close();
    
    return 0;
}
