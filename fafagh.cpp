#include <iostream>
#include <string>
#include<limits>

using namespace std;

double convertFahrenheitToCelsius(double fahrenheight);
double kilometersToMiles(double kilometers);
void displayPatient(int patient);

int main(){
    string name,sex; 
    int age, totalNumberOfPatientsPerDay = 100;
    double temperatureInFahrenheit, temperatureInCelsius, distanceInKilometers;
    int index = 0;
    string names[totalNumberOfPatientsPerDay];
    string genders[totalNumberOfPatientsPerDay];
    int ages[totalNumberOfPatientsPerDay];
    double temperaturesInFahrenheit[totalNumberOfPatientsPerDay];
    double tempetauresInCelsius[totalNumberOfPatientsPerDay];
    double distanceInMiles[totalNumberOfPatientsPerDay];
    int malariaCount = 0;
    int coronaCount = 0;
    

    int patientsWithMalaria[totalNumberOfPatientsPerDay];
    int patientsWithCoronaVirus[totalNumberOfPatientsPerDay];

    do{
        try{
    cout<<"WELCOME TO FAFAGH CLINIC"<<endl;
    cout<<endl;
    cout<<endl;

    // Get full name of patient
    cout<<"Enter your full name: ";
    cin>>name;
   names[index] = name;
   while(1){
       if(cin.fail()){
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"You have entered wrong input"<<endl;
            cin>>name;
       }
       if(!cin.fail()){break;}
   }
    // Get sex of patient
    cout<<"Enter sex: ";
    cin>>sex;
    // Check if input is valid
     while(1){
       if(cin.fail()){
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"You have entered wrong input"<<endl;
            cin>>sex;
       }
       if(!cin.fail()){break;}
   }


    genders[index] = sex;
    

    // Get age of patient
    cout<<"Enter age: ";
    cin>>age;
    // validate input
     while(1){
       if(cin.fail()){
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"You have entered wrong input, try again: "<<endl;
            cin>>age;
       }
       if(!cin.fail()){break;}
   }
    ages[index] = age;
    
    
    // Get temperature of patient in fahrenheit
    cout<<"Enter temperature in fahrenheit: ";
     cin>>temperatureInFahrenheit;
    // validate input
     while(1){
       if(cin.fail()){
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"You have entered wrong input"<<endl;
            cin>>temperatureInFahrenheit;
       }
       if(!cin.fail()){break;}
   }

    temperaturesInFahrenheit[index] = temperatureInFahrenheit;
    temperatureInCelsius = convertFahrenheitToCelsius(temperatureInFahrenheit);
   
    tempetauresInCelsius[index] = temperatureInCelsius ;

    // Get distance traveled by patient in kilometers
    cout<<"Enter distance travelled in kilometers: ";
    cin>>distanceInKilometers;
    // validate input
     while(1){
       if(cin.fail()){
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"You have entered wrong input"<<endl;
            cin>>distanceInKilometers;
       }
       if(!cin.fail()){break;}
   }
    distanceInMiles[index] = kilometersToMiles(distanceInKilometers);

    // sort patients into lists
    if(temperatureInCelsius >= 38 && temperatureInCelsius <= 40){
        /*
        * adds index of patients with temperatures between 38 to 40 to a list
        */
        patientsWithMalaria[malariaCount] = index;
        malariaCount++;
    }else if(temperatureInCelsius > 40){
         /*
        * adds index of patients with temperatures greater 40 to a list
        */
        patientsWithCoronaVirus[coronaCount]  = index;
        coronaCount++;
    }
 cout<< "**********************************"<<endl;
       
    cout<<"Patients with temperature between 38 and 40 (Malaria) "<<endl;
     cout<< "**********************************"<<endl;
    for(int i = 0; i < malariaCount; i++){
         /*
        * get indices of patients from malaria list and display their details
        */
        int patient = patientsWithMalaria[i];
         cout<< " "<<endl;
        cout<< " "<<endl;
        cout<< "Full name: "<< names[patient]<<endl;
        cout<< "Sex: "<<sex[patient]<<endl;
        cout<< "Age: "<<ages[patient]<<endl;
        cout<< "Temperature In Celsius : "<<tempetauresInCelsius[patient]<<"degrees's"<<endl;
        cout<< "Temperature in Fahrenheit : "<< temperaturesInFahrenheit[patient]<<endl;
        cout<< "Distance covered in miles :"<<distanceInMiles[patient];
    }
     cout<< "**********************************"<<endl;

      cout<<"Patients with temperature greater than 40 (Corona) "<<endl;
     cout<< "**********************************"<<endl;
    for(int i = 0; i < coronaCount; i++){
         /*
        * get indices of patients from corona list and display their details
        */
        int patient = patientsWithCoronaVirus[i];
        cout<< "**********************************"<<endl;
        cout<< "**********************************"<<endl;
        cout<< "Full name: "<< names[patient]<<endl;
        cout<< "Sex: "<<sex[patient]<<endl;
        cout<< "Age: "<<ages[patient]<<endl;
        cout<< "Temperature In Celsius : "<<tempetauresInCelsius[patient]<<"degrees's"<<endl;
        cout<< "Temperature in Fahrenheit : "<< temperaturesInFahrenheit[patient]<<endl;
        cout<< "Distance covered in miles :"<<distanceInMiles[patient];
    }

     cout<< "**********************************"<<endl;
     cout<<endl;
     cout<< "         Limit Reached"<<endl;
     cout<<endl;
     cout<< "**********************************"<<endl;


    
    // increase index by 1
    index ++;
    }catch(const exception& e){
        cout<<e.what();
    }

    }while(index < totalNumberOfPatientsPerDay);


   



    return 0;
}

// *** Function definitions ***

// Convert temperature from fahrenheit to celsius
double convertFahrenheitToCelsius(double fahrenheight){
    return (fahrenheight - 32)* 5/9;
}

// Convert distance from kilomters to miles
double kilometersToMiles(double kilometers){
    return kilometers / 1.609;
}

