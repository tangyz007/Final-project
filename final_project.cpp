#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <fstream>


using namespace std;


void user_guide(){
	
	cout << "Welcome to weight control program" << endl;
	cout << "The personal information you inputed will give you:" << endl;
	cout << "	1.BMI(Body Mass Index),which represents your body status, depends on different ranges" << endl;
	cout << "	2.BMR(Basal Metabolic Rate),in general, how many calories you need to sustain your life" << endl;
	cout << "This program executes a seris of calculations based on your BMR" << endl;
	cout << "For more background information, go to WIKI@ 'BMR' or 'Calories'" << endl;
	cout << "According to activity level, we assume daily BMR is BMR + 500, which works for most people" << endl;
	cout << "For lose weight, the daily total calories should less than BMR + 500" << endl;
	cout << "For gain weight, the daily total calories should greater than BMR + 500" << endl;
	cout << "Also, this program can trace your daily calories input by food and calories consumption by exercise" << endl;
	cout << "Then, calculate your total calories to realize weight control" << endl;
	cout << "Besides above, the program can trace your basic nutrient material(protein, fat, carbohydrate, sugar)" << endl;
	cout << "And will tell you how many those basic nutrient materials you need" << endl;
	cout << "\nWeight Control Program designer: " << endl;
	cout << "\n\n			Hao Dong(hdmpf@mail.missouri.edu),copyright" << endl;
	cout << "\n\nDevelop as Mizzou ECE-3220 course project" << endl;
	cout << "\nProject Instructor: " << endl;
	cout << "\n\n			Dr. Luis Rivera(riveralui@missouri.edu)" << endl;
	cout << "\n\nThank you" << endl;
}

void help(){
	
	cout << "option details" << endl;
	cout << "(0)will display some explanations of this weight control program" << endl;
	cout << "(1)will display your personal information that you have inputed" << endl;
	cout << "(2)will give you your body status based on BMI and suggestion" << endl;
	cout << "(3)you can add food by seach the name of food and enter the servings" << endl;
	cout << "(4)you can add exercise by giving a sort of exercise options" << endl;
	cout << "(5)you can check your current status and program will give you the details about what you need" << endl;
	cout << "(6)after finishing today's progress, this program can predicte your weight based on your performance" << endl;
	cout << "(7)display current displaying instructions" << endl;
	cout << "(8)exit this program" << endl;
		
	
}

class personal_info{
	
	private:
	
	protected:
		double BMI;
		double height;
		double weight;
		double BMR;
		string name;
		int age;
		char gender;
		
	
	public:
		void personal_input();
		void BMI_calculation();
		double BMR_calculation();
		void printInfo();
		void suggest();
		void check_age();
		void check_height();
		void check_weight();	
		float getweight(){return (float)weight;};
};

void personal_info::personal_input(){
	cout << "Personal infomation:" << endl;
	
	cout << "Enter your name: " << endl;
	getline(cin,name);
	
	cout << "Enter your height in unit m: " << endl;
	
	while(cin >> height){
		try{
			check_height();
		}
		catch(const char* s){
			cout << s << endl;
			cout << "Enter your height in unit m: " << endl;
			continue;
		}
		catch(...){
			cout << "Don't kidding" << endl;
			cout << "Enter your height in unit m: " << endl;
			continue;
		}
		break;
	}
	
	cout << "Enter your weight in unit kg:" << endl;
	
	while(cin >> weight){
		try{
			check_weight();
		}
		catch(const char* s){
			cout << s << endl;
			cout << "Enter your weight in unit kg:" << endl;
			continue;
		}
		catch(...){
			cout << "Don't kidding" << endl;
			cout << "Enter your weight in unit kg:" << endl;
			continue;
		}
		break;
	}
	
	cout << "Enter your age in integer year: " << endl;
	
	while(cin >> age){
		try{
			check_age();
		}
		catch(const char* s){
			cout << s << endl;
			cout << "Enter your age in integer year: " << endl;
			continue;
		}
		catch(...){
			cout << "Don't kidding" << endl;
			cout << "Enter your age in integer year: " << endl;
			continue;
		}
		break;
	}
	
	cout << "Enter your gender, enter 'f' for female, enter 'm' for male: " << endl;
	
	while(cin >> gender){
		try {
			BMR_calculation();
		}
		catch(const char* s){
			cout << s << endl;
            cout << "Enter your gender, enter 'f' for female, enter 'm' for male: ";
            continue;
        }
		catch(...){
			cout << "Don't kidding" << endl;
			cout << "Enter your gender, enter 'f' for female, enter 'm' for male: ";
            continue;
		}
		break;
	}
}

void personal_info::check_age(){
	if(age <= 0 ){
		throw"the age cannot less or equal than zero";
	}
	
	else if(age >= 150){
		throw(1);
	}
}

void personal_info::check_height(){
	if(height <= 0){
		throw"the height cannot less or equal than zero";
	}
	
	else if(height > 2.5){
		throw(2);
	}
}

void personal_info::check_weight(){
	if(weight <= 0){
		throw"the weight cannot less or equal than zero";
	}
	
	else if(weight > 1000){
		throw(3);
	}
	
	getweight();
}

void personal_info::BMI_calculation(){
	
	BMI = weight/(pow(height,2));
	
}

double personal_info::BMR_calculation(){
	
	if(gender == 'f' || gender == 'F'){
		BMR = (10 * weight) + (6.25 * height * 100) - (5 * double(age)) - 161;
	}
	else if(gender == 'm' || gender == 'M'){
		BMR = (10 * weight) + (6.25 * height * 100) - (5 * double(age))+ 5;
	}
	else{
		throw "Wrong gender input, enter again";
	}

	return BMR;
}

void personal_info::suggest(){
	
	cout << "According to your BMI " << BMI << endl;
	cout << "Your body current status is ";

	if(BMI < 16){
		cout << "Severe Thinness";
		cout << "\nWe recommand you to gain weight" << endl;
	}
	
	else if(16 <= BMI && BMI < 17){
		cout << "Moderate Thinness";
		cout << "\nWe recommand you to gain weight" << endl;
	}
	
	else if(17 <= BMI && BMI < 18.5){
		cout << "Mild Thinness";
		cout << "\nWe recommand you to gain weight" << endl;
	}
	
	else if(18.5 <= BMI && BMI < 25){
		cout << "Normal";
		cout << "\nWe recommand you to gain weight" << endl;
	}
	
	else if(25 <= BMI && BMI < 30){
		cout << "Overweight";
		cout << "\nWe recommand you to loss weight" << endl;
	}
	
	else if(30 <= BMI && BMI < 35){
		cout << "Obese Class I";
		cout << "\nWe recommand you to loss weight" << endl;
	}
	
	else if(35 <= BMI && BMI <  40){
		cout << "Obese Class II";
		cout << "\nWe recommand you to loss weight" << endl;
	}
	
	else{
		cout << "Obese Class III";
		cout << "\nWe recommand you to loss weight" << endl;
	}
}

void personal_info::printInfo(){
	
	
	cout << "\n\n\n******Display personal information******" << endl;
	cout << "Name: " << name << endl;
	cout << "Gender: " << gender << endl;
	cout << "Age: " << age << endl;
	cout << "Weight: " << weight << endl;
	cout << "Height: " << height << endl;
	cout << "BMI: " << BMI << endl;
	cout << "BMR: " << BMR << endl;
}


class Food{	
	private:
		string name;
		float  cal;
		float fat;
		float carb;
		float portein;
		float sugar;
	public:
		Food(string n, float ca, float t, float c, float p, float s){
			name = n;
			cal = ca;
			fat = t;
			carb = c;
			portein = p;
			sugar = s;
		}
    
		string getName()  {
			return name;
		}
		float getCal()  {
			return cal;
		}
		float getFat()  {
			return fat;
		}
		float getCarb()  {
			return carb;
		}
		float getPortein() {
			return portein;
		}
		float getSugar()  {
			return sugar;
		}
};


class BaseExercise{
	private:
	
	protected:
		int length;
		int *data;
		
	public:
		BaseExercise();
		BaseExercise(int L);
		~BaseExercise();
		int getLength(){ return length; };
		int getvalue(int index);
		virtual void print(){}
		
};




BaseExercise::BaseExercise(){
	length = 0;
	data = NULL;
		
}

BaseExercise::BaseExercise(int L){
	length = L;
	data = new int[L];
	FILE *f;
	if((f = fopen("exercise.txt","r")) == NULL){
		cout << "Exercise file doesn't exist" << endl;
	}
	else{
		int length1;
		fscanf(f,"%d", &length1);
		
		for(int i=0;i<length;++i){
			fscanf(f,"%d",data+i);
		}
	}
	if(data == NULL){
		cerr << "Error in memory allocation" << endl;
	}
	fclose(f);
	
}

BaseExercise::~BaseExercise(){
	delete[] data;
	
}

int BaseExercise::getvalue(int index){
	if(index < 0){		
		return(data[0]);
	}
	else if(index >= length){	
		return(data[length-1]);	
	}
	else{
		return(data[index]);
	}
}

class InputExercise : public BaseExercise{
	private:
		double *data2;
		double *value;
	public:
		InputExercise(int L);
		~InputExercise();
		
		double gettime(int index);
		int settime(int index, double time);
		
		void print();
		void Save_file();
		double calculate_sum();
		void check_time(double time);
		void check_index(int index);
};

InputExercise::InputExercise(int L) : BaseExercise(L){
	data2 = new double[L];
	
	if(data2 == NULL){
		cerr << "Error in memory allocation" << endl;
	}
	else{
		for(int i=0;i<L;i++){
			data2[i] == data[i];
		}
	}
	
}

InputExercise::~InputExercise(){
	delete data2;
	delete value;
}

double InputExercise::gettime(int index){
	if(index < 0){		
		return(data2[0]);
	}
	else if(index >= length){
		return(data2[length-1]);
	}		
	else{
		return(data2[index]);
	}
	
}

int InputExercise::settime(int index, double time){
	if((index < 0) || (index >= length)){
		
		return(-1);	
	}
	else {
		
		data2[index] += time; 
		return(0);
	}
}	


void InputExercise::print(){
	
	cout <<"(0)Running, 7 mph(8.5 min/mile)" << endl;
	cout <<"(1)Walking, 3 mph(walking with dog)" << endl;
	cout <<"(2)Swimming, butterfly, general" << endl;
	cout <<"(3)Basketball, game" << endl;
	cout <<"(4)Bicycling, 12-13.9 mph, moderate" << endl;
	cout <<"(5)Football, touch, flag, general" << endl;
	cout <<"(6)Golf, general" << endl;
	cout <<"(7)Soccer, casual, general" << endl;
	cout <<"(8)Skating, ice, general" << endl;
	cout <<"(9)Volleyball, competitive, in gym" << endl;
	cout <<"(10)Finsh adding exercises, back to main menu" << endl;
	
	
}

double InputExercise::calculate_sum(){
	double sum = 0;
	int len;
	
	FILE* f;
	
	if((f = fopen("value.txt", "r")) == NULL){
		cout << "value.txt file doen't exist" << endl;
	}
	else{
		
		fscanf(f,"%d",&len);
		
		value = new double[len];
		
		for(int i=0;i<len;i++){
			fscanf(f,"%lf",(value+i));
		}
		
		for(int i=0;i<len;i++){
			sum = sum + data2[i] * value[i];
		}
		
	}
		
	return sum;	
	
	
	
}

void InputExercise::Save_file() {
	
	FILE *f;
	
	if((f = fopen("exercise.txt", "w")) == NULL){
		cout << "can't write to file "<< endl;
	}
	
	fprintf(f, "%d\n", length);
	
	for(int i=0; i<length; i++){
		fprintf(f, "%d\n", int(data2[i]));
	}
	
	fclose(f);
	
}

void InputExercise::check_index(int index){
	
	if(index < 0 || index > (length-1)){
		
		throw "The option should be from '0' to '9' ";
	}
	
	
	
}

void InputExercise::check_time(double time){
	
	if(time < 0 || time >= 600 ){
		
		throw "The input time should be from '0' to '600'";
	}
	
	
}

class nutr_ratio{
	private:
		float cal;
		float fat;
		float carb;
		float protein;
		float sugar;
	public:
		float find_fat(float cal);
		float find_carb(float cal);
		float find_protein(float cal);
		float find_sugar(float cal);
		
};

float nutr_ratio::find_carb(float cal){
	
	carb = 0.4 * cal / 4;
	
	
	return carb;
}

float nutr_ratio::find_protein(float cal){
	
	protein = 0.3 * cal / 4;
	
	return protein;
}

float nutr_ratio::find_fat(float cal){
	
	fat = 0.2 * cal / 9;
	
	return fat;
}

float nutr_ratio::find_sugar(float cal){
	
	sugar = 0.1 * cal / 4;
	
	return sugar;
}

class weight_prediction{
	
	private:
		
		
	public:
		float calculate_weight(float, float);
		float cal_diff;
		float weight_change;
		
		
};

float weight_prediction::calculate_weight(float fix_cal, float total_cal){
	
	cal_diff = total_cal - fix_cal;
	
		
	weight_change = cal_diff / 500 * 0.5;
		
	
	return weight_change;
}

int main(){
	
	double BMR_val, fix_BMR_val;
	personal_info c1;
	c1.personal_input();
	c1.BMI_calculation();
	BMR_val = c1.BMR_calculation();
	fix_BMR_val = BMR_val + 500;
	float weight = c1.getweight();
	vector<Food> foods;
	
	ifstream fin("foodlist.txt", ios::in);

    if (fin.fail()){
        cout << "Load file failed\n";
		cout << "Please check the data files and run the program again" << endl;
        return 0;
    }
    string name;
    float  cal1;
    float fat;
    float carb;
    float portein;
    float sugar;
    int serving_size;

    while (fin.eof() == false){
        fin >> name >> serving_size;
        if (fin.eof()){
            break;
        }
        fin >> cal1 >> fat >> carb >> portein >> sugar;
        Food food(name, cal1, fat, carb, portein, sugar);
        foods.push_back(food);
    }

    int choice;
    int i;
    cal1 = 0;
    carb = 0;
    fat = 0;
    portein = 0;
    sugar = 0;
    vector<int> numbers;
	int num;
	
	InputExercise t1(10);
	double cal2 =0;
	
	while(true){
		
		cout << "\n\n\n***** option menu *****" << endl;
		cout << "(0)Display user's guide" << endl;
		cout << "(1)Display personal information" << endl;
		cout << "(2)Display body status and suggestion" << endl;
		cout << "(3)Add food" << endl;
		cout << "(4)Add exercises" << endl;
		cout << "(5)Check today's status" << endl;
		cout << "(6)Weight prediction" << endl;
		cout << "(7)Help" << endl;
		cout << "(8)Exit" << endl;
		
		int option;
		cout << "Enter the option" << endl;
		cin >> option;
		
		switch(option){
			case 0: {
				
				user_guide();
				
				break;
			}
			case 1: {
				
				c1.printInfo();
				
				break;
			}
			
			case 2: {
				
				c1.suggest();
				
				break;
			}
			
			case 3: {
				
				cout << "Please input food name: ";
				cin >> name;
				
				cout << "Please input servings: ";
				cin >> num;
				
				for (i = 0; i < foods.size(); ++i){
					if (foods[i].getName() == name){
						sugar += foods[i].getSugar() * num;
						portein += foods[i].getPortein() * num;
						fat += foods[i].getFat() * num;
						cal1 += foods[i].getCal() * num;
						carb += foods[i].getCarb() * num;
						break;
					}
				}
				if (i == foods.size()){
					
					cout<< "The name of food doesn’t exist. You can update food data file by your own "<< endl;
				} 
				else{
					
					cout << "Add food successfully" << endl;
				}
				break;
			}
			
			case 4: {
				
				int index = 0;
				double time;

				t1.print();
				
				cout << "Enter the exercise(0~9)" << endl;
				
				while(cin >> index){
					try {
						t1.check_index(index);
					}
					catch(const char* s){
						cout << s << endl;
						cout << "Enter the exercise(0~9)" << endl;
						continue;
					}
					catch(...){
						cout << "Enter the exercise(0~9)" << endl;
						continue;
					}
					break;
				}
				
				cout << "Ener the duration in min" << endl;
				
				while(cin >> time){
					try{
						t1.check_time(time);
					}
					catch(const char* s){
						cout << s  << endl;
						cout << "Ener the duration in min" << endl;
						continue;
					}
					catch(...){
						cout << "Ener the duration in min" << endl;
						continue;
					}
					break;
				}
				t1.settime(index,time);
				t1.Save_file();	
					
				cal2 = t1.calculate_sum();
				cout << "Your total calories consumption by exercises is " << cal2 << " calories"<< endl;
				t1.Save_file();
				break;
			}
			
			case 5: {
				cout << "You need " << fix_BMR_val << " calories to maintain your weight" << endl;
				cout << "total calories intake by food now is " << cal1 <<" calories" << endl;
				cout << "total calories consumption by exercises now is " << cal2 <<" calories" << endl;
				cout << "You have gained:" << endl;
				cout << "Total fat: " << fat << " g" <<endl;
				cout << "Total carb: " << carb << " g" << endl;
				cout << "Total protein: " << portein << " g" << endl;
				cout << "Total sugar: " << sugar << " g" << endl;
				
				nutr_ratio g1;
				
				float fat_need;
				float carb_need;
				float sugar_need;
				float protein_need;
				
				int choice;
				
				cout << "(1)gain weight" << endl;
				cout << "(2)lose weight" << endl;
				
				cout << "Enter the choice:" << endl;
				cin >> choice;
				
				if(choice == 1){
					cout << "You need more than " << fix_BMR_val << " calories to gain weight" << endl;
					
					cout << "Your current total calories is " << cal1 - float(cal2) << " calories" << endl;
					
					fat_need = g1.find_fat(float(fix_BMR_val) + float(cal2));
					carb_need = g1.find_carb(float(fix_BMR_val)+ float(cal2));
					sugar_need = g1.find_sugar(float(fix_BMR_val)+ float(cal2));
					protein_need = g1.find_protein(float(fix_BMR_val)+ float(cal2));
					
					cout << "Check basic four nutrient material" << endl;
					cout << "You still need('-' sign means surplus)" << endl;
					
					cout << "	" << fat_need - fat << " g fat" << endl;
					cout << "	" << protein_need - portein << " g protein" << endl;
					cout << "	" << carb_need - carb << " g carb" << endl;
					cout << "	" << sugar_need - sugar << " g sugar" << endl;
				}
				else if(choice == 2){
					cout << "You need less than " << fix_BMR_val << " calories to gain weight" << endl;
					
					cout << "Your current total calories is " << cal1 - float(cal2) << " calories" << endl;
					
					fat_need = g1.find_fat(float(fix_BMR_val));
					carb_need = g1.find_carb(float(fix_BMR_val));
					sugar_need = g1.find_sugar(float(fix_BMR_val));
					protein_need = g1.find_protein(float(fix_BMR_val));
					
					cout << "Check basic four nutrient material" << endl;
					cout << "You still need('-' sign means surplus)" << endl;
					
					cout << "	" << fat_need - fat << " g fat" << endl;
					cout << "	" << protein_need - portein << " g protein" << endl;
					cout << "	" << carb_need - carb << " g carb" << endl;
					cout << "	" << sugar_need - sugar << " g sugar" << endl;
				}
				else{
					
					cout << "Wrong choice, back to main menu" << endl;
					
					break;
				}
				break;
			}
			
			case 6: {
				cout << "Warning" << endl;
				cout << "Weight prediction is based on your daily total calories" << endl;
				cout << "Make sure that you have finished today's progress" << endl;
				cout << "Do you wish to continue(y/n)?" << endl;
				
				char yn;
				cin >> yn;
				
				if(yn == 'y' || yn == 'Y'){
					weight_prediction w1;
					
					float weight_change = w1.calculate_weight(float(fix_BMR_val),cal1-float(cal2));
					
					cout << "If you do so like today, your weight will become " << weight + weight_change << " kg after one week" << endl; 
					

					
				}
				else if(yn == 'n' || yn == 'N'){
					
					cout << "return to main menu" << endl;
					
					break;
					
				}
				else{
					
					cout << "Error option, return to main menu" << endl;
					
					break;
				}
				
				break;
			}
			
			case 7: {
				
				help();
				
				break;
				
			}
			
			case 8: {
				
				exit(EXIT_SUCCESS);
				
				break;
				
			}
			
			default : {
				
				cout << "Wrong option, enter option again:" << endl;
				
				break;
			}
		}
	}
	
	return 0;
}