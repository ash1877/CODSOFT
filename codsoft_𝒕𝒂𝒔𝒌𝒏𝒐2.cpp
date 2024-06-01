#include<iostream>
using namespace std;
void showoptions()
{
    cout<< "CALCULATOR "<<std::endl;
    cout<< "1.Addition "<<std::endl;
  std::cout<< "2.Subtraction "<<std::endl;
  std::cout<< "3.Multiplication "<<std::endl;
  std::cout<< "4.Divition "<<std::endl;
    std::cout<<"5.Exit "<<endl;
  std::cout<<"choose a operation to perfrom!:"<<std::endl;
}

// to perform each operation 
// separate function ara created  below:

double add(double a,double b)
{
  return a + b;
}
double sub(double a,double b)
{
  return a - b;
}
double mul(double a,double b)
{
  return a * b;
}
double div(double a,double b)
{
  // to handle exception 
  if(b != 0)
    return a/b;
  
  else
  {
    std::cout<<"ERROR! Division by ZERO !!!"<<endl;
    return 0;
  }
  
}

// main 
int main()
{
  int choice;
  double num1,num2,result;

  do{

  showoptions();
    std::cin>>choice;

    if(choice >= 1 && choice < 5)
    {
      std::cout<<"Enter first number: ";
      std::cin>>num1;
      std::cout<<"Enter second number: ";
      std::cin>>num2;
    }

//using switch to check for 4 option and based on the option the choosen operation will be perfomed and printed as ouput!!
    
    switch(choice)
      {
        case 1:
        result = add(num1,num2); // call add function and store result in result variale.
        std::cout << "Result: "<<num1<<" + "<<num2<<" = "<<result<<endl;
        break;//to avoid printiing all the statements in switch break is used

        case 2:
        result = sub(num1,num2); 
        std::cout << "Result: "<<num1<<" - "<<num2<<" = "<<result<<endl;
        break;
        case 3:
        result = mul(num1,num2); 
        std::cout << "Result: "<<num1<<" * "<<num2<<" = "<<result<<endl;
        break;//to avoid printiing all the statements in switch break is used
        case 4:
        result = div(num1,num2); 
          if(num2 != 0)
        std::cout << "Result: "<<num1<<" / "<<num2<<" = "<<result<<endl;
        break;
        case 5:
        std::cout<<"Exiting..."<<endl;
        break;
        default: // to handle choices other than 1 2  3 4 5 
        std::cout<<"INVALID choice,please input valid  choice."<<endl;
        break;
    
  }

  
}while(choice != 5); // if choice is 5  and above loop ends
    
return 0;
}
