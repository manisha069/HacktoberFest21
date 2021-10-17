# include <iostream>

class college_student {
    public:
int college_code;
};

class test :virtual public college_student {
public:
float percentage ;

};

class sports :virtual public college_student {
 public:
char grade;

};


class result:  public test , public sports {
 public:
 int get(){
std::cout<<"\nEnter college code :";
std::cin>>college_code ;
std::cout<<"\nEnter Percentage :";
std::cin>> percentage;
std::cout<<"\nEnter Grade :";
std::cin>> grade;

     return 0;
 }

 int display()
{
std::cout<<"\ncollege code :"<<college_code;
std::cout<<"\nPercentage :"<<percentage;
std::cout<<"\nGrade :"<<grade;
return 0;

}};


int main(){
    result r;
    r.get();
    r.display();

    return 0;
}




